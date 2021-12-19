#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <opencv2/core.hpp>
#include <Maze.h>

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::MazeGen::implementation
{
	MainPage::MainPage()
	{
		InitializeComponent();
		OutputDebugString(L"hello there");
	}

	INT32 MainPage::PathWidth()
	{
		return mazePathWidth;
	}

	void MainPage::PathWidth(INT32  value)
	{
		mazePathWidth = value;
	}

	void MainPage::UpdateLog(std::wstring str) {
		winrt::param::hstring s = LogText().Text();
		LogText().Text(s + str + L"\n");
	}

	void MainPage::ClearLogs(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e) {
		LogText().Text(L"");
	}

	void MainPage::GenerateMaze(IInspectable const& sender, RoutedEventArgs const& e)
	{
		UpdateLog(L"Starting Maze generation ... ");
		mazeHeight = RowsInput().SelectedValue().try_as<INT32>().value_or(-1);
		mazeWidth = ColumnsInput().SelectedValue().try_as<INT32>().value_or(-1);
		if(WallWidthInput().Text().size() >0)mazeWallWidth = std::stoi((std::wstring)WallWidthInput().Text());
		if (PathWidthInput().Text().size() > 0)mazePathWidth = std::stoi((std::wstring)PathWidthInput().Text());

		std::wstring value = L"Maze Size : Columns : " + std::to_wstring(mazeHeight) + L" Rows : " + std::to_wstring(mazeWidth);
		UpdateLog(value);

		Maze maze = Maze(mazeHeight, mazeWidth, mazePathWidth, mazeWallWidth);
		std::wstring outputFile = maze.generateMaze();
		Media::Imaging::BitmapImage bitmapImage = Media::Imaging::BitmapImage(winrt::Windows::Foundation::Uri(outputFile));
		MazeImage().Source(bitmapImage);
		UpdateLog(L"File generated at : " + outputFile + L"\n");
	}

	void MainPage::NoText(Controls::TextBox const& sender, Controls::TextBoxBeforeTextChangingEventArgs const& args)
	{
		auto newText = args.NewText();
		args.Cancel(std::find_if_not(newText.begin(), newText.end(), std::isdigit) != newText.end());
	}
}






