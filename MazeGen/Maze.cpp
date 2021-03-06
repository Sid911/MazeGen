#include "pch.h"
#include "Maze.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>


std::wstring Maze::generateMaze()
{
	using namespace winrt::Windows;
	using namespace cv;

#define GridWallColor Scalar(59,54,42)
#define GridPathColor Scalar(244, 241, 212)

	// greenish = Scalar(150,184,150)
	// Baby Blue = Scalar(244,241,212)
	// Darkish Gray = Scalar(59,54,42)

	Storage::StorageFolder installedLocation{ Storage::ApplicationData::Current().LocalFolder() };
	Storage::StorageFolder folder = installedLocation;

	m_filePath = (std::wstring)folder.Path() + L"\\maze.bmp";

	INT32 imageWidth = m_mazeWidth * m_pathWidth + (m_mazeWidth * m_wallWidth) + m_wallWidth;
	INT32 imageHeight = m_mazeHeight * m_pathWidth + (m_mazeHeight * m_wallWidth) + m_wallWidth;

	//
	Mat mazeImage(imageHeight, imageWidth, CV_8UC3, GridPathColor);

	// generate grid

	for (size_t i = 0; i < imageWidth; i += m_pathWidth + m_wallWidth)
	{
		line(mazeImage, Point(i, 0), Point(i, imageHeight - 1), GridWallColor, m_wallWidth);
	}
	for (size_t j = 0; j < imageHeight; j += m_pathWidth + m_wallWidth)
	{
		line(mazeImage, Point(0, j), Point(imageWidth - 1, j), GridWallColor, m_wallWidth);
	}

	// Get start and end
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, m_mazeWidth - 1);
	int randomStartTop = distribution(generator);
	int randomExitBottom = distribution(generator);

	// Set the screenspace coordinates
	int mazeStart = m_pathWidth * randomStartTop + m_wallWidth * (randomStartTop + 1);
	int mazeEnd = m_pathWidth * randomExitBottom + m_wallWidth * (randomExitBottom + 1);
	std::string w = "Start : " + std::to_string(randomStartTop) + "\nEnd : " + std::to_string(randomExitBottom) + "\n";
	OutputDebugStringA(w.data());

	// kinda make openings (doesn't work well with wall Width more than 1
	line(mazeImage, Point(mazeStart, 0), Point(mazeStart + m_pathWidth - 1, 0), GridPathColor);
	line(mazeImage, Point(mazeEnd, imageHeight - 1), Point(mazeEnd + m_pathWidth - 1, imageHeight - 1), GridPathColor);

	//Draw using recursiveBacktracker
	_recursiveBacktracker(randomStartTop, mazeImage);
	writeImage(mazeImage);
	return m_filePath;
}

void Maze::_recursiveBacktracker(INT32 startIndex, cv::Mat& image) {
	using namespace std;
	using namespace cv;
	// helper lambdas
	auto offestGridValue = [&](INT32 x, INT32 y) {
		return mazeGrid[m_stack.top().first + y][m_stack.top().second + x];
	};

	auto BitwiseOrStackTop = [&](INT8 value, INT32 offsetX = 0, INT32 offsetY = 0) {
		mazeGrid[m_stack.top().first + offsetY][m_stack.top().second + offsetX] |= value;
	};

	auto DrawPathForOffset = [&](INT32 x, INT32 y) {
		INT32 currentX = m_stack.top().second, currentY = m_stack.top().first;
		INT32 offsetedX = currentX + x, offsetedY = currentY + y;

		Point currentPoint = _gridToScreenSpace(currentX, currentY, m_pathWidth / 2, m_pathWidth / 2);
		Point offsetedPoint = _gridToScreenSpace(offsetedX, offsetedY, m_pathWidth / 2, m_pathWidth / 2);
		line(image, currentPoint, offsetedPoint, GridWallColor, m_wallWidth, FILLED);
	};

	auto DrawPolyForOffset = [&](INT32 xGrid, INT32 yGrid) {
		INT32 currentX = m_stack.top().second, currentY = m_stack.top().first;
		vector<Point> points{
			_gridToScreenSpace(currentX,currentY,(m_pathWidth -1) * abs(xGrid) , (m_pathWidth - 1) * abs(yGrid) ),						//Top left
			_gridToScreenSpace(currentX,currentY,(m_pathWidth - 1) * abs(yGrid) ,(m_pathWidth - 1) * abs(xGrid)),						//Top Right
			_gridToScreenSpace(currentX + xGrid ,currentY + yGrid, (m_pathWidth - 1) * abs(xGrid), (m_pathWidth - 1) *abs(yGrid)),		//Bottom left
			_gridToScreenSpace(currentX + xGrid ,currentY + yGrid, (m_pathWidth - 1) * abs(yGrid), (m_pathWidth - 1) * abs(xGrid)),		//Bottom left
			};
		cv::fillConvexPoly(image, points, GridPathColor );
		//writeImage(image);
	};

	// initialize stuff for the first time
	m_stack.push(make_pair(0, startIndex)); // y , x
	BitwiseOrStackTop(CELL::CELL_VISITED);
	m_visited++;
	std::default_random_engine generator;

	while (m_visited != m_mazeHeight * m_mazeWidth)
	{
		// Get unvisited neighbours
		vector<int> neighbours;

		if (m_stack.top().first > 0 && (offestGridValue(0, -1) & CELL::CELL_VISITED) == 0) { neighbours.push_back(DIRECTION::NORTH); }				// North
		if (m_stack.top().first < m_mazeHeight - 1 && (offestGridValue(0, 1) & CELL::CELL_VISITED) == 0) { neighbours.push_back(DIRECTION::SOUTH); }	// South
		if (m_stack.top().second < m_mazeWidth - 1 && (offestGridValue(1, 0) & CELL::CELL_VISITED) == 0) { neighbours.push_back(DIRECTION::EAST); }		// East
		if (m_stack.top().second > 0 && (offestGridValue(-1, 0) & CELL::CELL_VISITED) == 0) { neighbours.push_back(DIRECTION::WEST); }				// West

		if (!neighbours.empty())
		{
			std::uniform_int_distribution<int> distribution(0, neighbours.size() - 1);
			int randInt = distribution(generator);
			int next_cell = neighbours[randInt % neighbours.size()];
			switch (next_cell)
			{
			case DIRECTION::NORTH:
				BitwiseOrStackTop(CELL::CELL_PATH_NORTH);
				BitwiseOrStackTop(CELL::CELL_PATH_SOUTH, 0, -1);
				DrawPolyForOffset(0, -1);
				m_stack.push(make_pair(m_stack.top().first - 1, m_stack.top().second));
				break;
			case DIRECTION::SOUTH:
				BitwiseOrStackTop(CELL::CELL_PATH_SOUTH);
				BitwiseOrStackTop(CELL::CELL_PATH_NORTH, 0, 1);
				DrawPolyForOffset(0, 1);
				m_stack.push(make_pair(m_stack.top().first + 1, m_stack.top().second));
				break;
			case DIRECTION::EAST:
				BitwiseOrStackTop(CELL::CELL_PATH_EAST);
				BitwiseOrStackTop(CELL::CELL_PATH_WEST, 1, 0);
				DrawPolyForOffset(1, 0);
				m_stack.push(make_pair(m_stack.top().first, m_stack.top().second + 1));
				break;
			case DIRECTION::WEST:
				BitwiseOrStackTop(CELL::CELL_PATH_WEST);
				BitwiseOrStackTop(CELL::CELL_PATH_EAST, -1, 0);
				DrawPolyForOffset(-1, 0);
				m_stack.push(make_pair(m_stack.top().first, m_stack.top().second - 1));
				break;
			default:
				break;
			}
			m_visited++;
			BitwiseOrStackTop(CELL::CELL_VISITED);
		}
		else {
			m_stack.pop();
		};
	};

}

cv::Point Maze::_gridToScreenSpace(double x, double y, double OffsetX, double OffsetY)
{
	return cv::Point((m_pathWidth * x + m_wallWidth * (x + 1)) + OffsetX, (m_pathWidth * y + m_wallWidth * (y + 1)) + OffsetY);
}

void Maze::writeImage(cv::Mat& image) {
	// Save Image of the thingy to local application storage
	std::vector<int> compression_params;
	compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
	compression_params.push_back(100);
	// Unsafe wstring to string conversion does not support all the chars if computer is in another language
	cv::String str = std::string(m_filePath.begin(), m_filePath.end());
	cv::imwrite(str, image);

}