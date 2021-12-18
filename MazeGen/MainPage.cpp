#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <opencv2/core.hpp>
#include <Maze.h>

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::MazeGen::implementation
{
    INT32 mazeHeight = 0, mazeWidth = 0 , mazeWallWidth= 1, mazePathWidth = 2;
    MainPage::MainPage()
    {
        InitializeComponent();
        OutputDebugString(L"hello there");
        srand(314);
        auto r = rand();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::UpdateLog(std::wstring str) {
        winrt::param::hstring s = LogText().Text();
        LogText().Text(s + str + L"\n");
    }

    void MainPage::ClearLogs(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e) {
        LogText().Text(L"");
    }

    void MainPage::GenerateMaze(IInspectable const& sender,RoutedEventArgs const& e)
    {
        UpdateLog(L"Starting Maze generation ... ");
        mazeHeight = HeightInput().SelectedValue().try_as<INT32>().value_or(-1);
        mazeWidth = WidthInput().SelectedValue().try_as<INT32>().value_or(-1);
        mazeWallWidth = WallWidthInput().Value();
        mazePathWidth = PathWidthInput().Value();

        std::wstring value = L"Maze Size : Columns : " + std::to_wstring(mazeHeight) + L" Rows : " + std::to_wstring(mazeWidth);
        UpdateLog(value);

        Maze maze = Maze(mazeHeight, mazeWidth);
        std::wstring outputFile = maze.generateMaze();
        UpdateLog(L"File generated at : "+outputFile + L"\n");
    }
}





