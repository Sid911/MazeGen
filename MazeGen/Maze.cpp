#include "pch.h"
#include "Maze.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>


std::wstring Maze::generateMaze()
{
	using namespace cv;
	winrt::Windows::Storage::StorageFolder installedLocation{ winrt::Windows::Storage::ApplicationData::Current().LocalFolder() };
	winrt::Windows::Storage::StorageFolder folder = installedLocation;
	auto file = folder.CreateFileAsync(L"maze.jpg");

	INT32 imageWidth = m_mazeWidth * 2 + m_mazeWidth + 1;
	INT32 imageHeight = m_mazeHeight * 2 + m_mazeHeight + 1;
	Mat mazeImage(imageWidth, imageHeight, CV_8UC3,Scalar(255,255,255));
	
	// generate grid
	for (size_t i = 0; i < imageWidth; i += m_pathWidth + 1)
	{
		line(mazeImage, Point(i, 0), Point(i, imageHeight - 1), Scalar(0,0,0));
	}
	for (size_t j = 0; j < imageHeight; j += m_pathWidth+1)
	{
		line(mazeImage, Point(0, j), Point(imageWidth - 1, j), Scalar(0,0,0));
	}
	auto FilePath = (std::wstring)folder.Path() + L"\\maze.bmp";
	cv::String str = std::string(FilePath.begin(), FilePath.end());
	std::vector<int> compression_params;
	compression_params.push_back(IMWRITE_JPEG_QUALITY);
	compression_params.push_back(100);

	imwrite(str, mazeImage);
	return FilePath;
}
