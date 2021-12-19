#pragma once

#include "MainPage.g.h"

namespace winrt::MazeGen::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        INT32 mazeHeight = 0, mazeWidth = 0, mazeWallWidth = 1, mazePathWidth = 2;
        MainPage();

        INT32 PathWidth();
        void PathWidth(INT32 value);

        void GenerateMaze(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void UpdateLog(std::wstring);
        void ClearLogs(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void NoText(winrt::Windows::UI::Xaml::Controls::TextBox const& sender, winrt::Windows::UI::Xaml::Controls::TextBoxBeforeTextChangingEventArgs const& args);
    };
}

namespace winrt::MazeGen::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
