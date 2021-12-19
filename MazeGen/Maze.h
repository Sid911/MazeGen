#include <pch.h>
#include <stack>
#include <iostream>
#include <opencv2/core.hpp>
enum CELL
{
	CELL_PATH_NORTH = 0x01,
	CELL_PATH_EAST = 0x02,
	CELL_PATH_SOUTH = 0x04,
	CELL_PATH_WEST = 0x08,
	CELL_VISITED = 0x010,
};
enum DIRECTION {
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
};
class Maze
{
private:
	INT32 m_mazeHeight, m_mazeWidth;
	double m_pathWidth, m_wallWidth;

	std::vector < std::vector<INT8>> mazeGrid;
	std::stack<std::pair<INT32, INT32>> m_stack;
	std::wstring m_filePath;
	INT32 m_visited;


public:
	Maze(INT32 height, INT32 width, INT32 pathWidth = 2, INT32 wallWidth = 1) {
		m_mazeHeight = height;
		m_mazeWidth = width;
		m_pathWidth = pathWidth;
		m_wallWidth = wallWidth;
		m_visited = 0;
		mazeGrid = std::vector<std::vector<INT8>>(m_mazeHeight, std::vector<INT8>(m_mazeWidth));
	};
	std::vector<std::vector<INT8>> getMaze() {
		return mazeGrid;
	}
	std::wstring generateMaze();
	void writeImage(cv::Mat& image);

	void _recursiveBacktracker(INT32 startIndex, cv::Mat &image);
	cv::Point _gridToScreenSpace(double x, double y, double OffsetX = 0, double OffsetY = 0);
};

