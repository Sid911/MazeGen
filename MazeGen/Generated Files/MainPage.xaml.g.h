﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#pragma once


namespace winrt::MazeGen::implementation
{
    using IInspectable = ::winrt::Windows::Foundation::IInspectable;

    template <typename D, typename ... I>
    struct MainPageT : public ::winrt::MazeGen::implementation::MainPage_base<D,
        ::winrt::Windows::UI::Xaml::Markup::IComponentConnector,
        ::winrt::Windows::UI::Xaml::Markup::IComponentConnector2,
        I...>
    {
        using base_type = typename MainPageT::base_type;
        using base_type::base_type;
        using class_type = typename MainPageT::class_type;

        void InitializeComponent();
        void Connect(int32_t connectionId, IInspectable const& target);
        ::winrt::Windows::UI::Xaml::Markup::IComponentConnector GetBindingConnector(int32_t connectionId, IInspectable const& target);
        void UnloadObject(::winrt::Windows::UI::Xaml::DependencyObject const& dependencyObject);
        void DisconnectUnloadedObject(int32_t connectionId);

        ::winrt::Microsoft::UI::Xaml::Controls::NavigationView navigation()
        {
            return _navigation;
        }
        void navigation(::winrt::Microsoft::UI::Xaml::Controls::NavigationView value)
        {
            _navigation = value;
        }

        ::winrt::Windows::UI::Xaml::Controls::ComboBox WidthInput()
        {
            return _WidthInput;
        }
        void WidthInput(::winrt::Windows::UI::Xaml::Controls::ComboBox value)
        {
            _WidthInput = value;
        }

        ::winrt::Windows::UI::Xaml::Controls::ComboBox HeightInput()
        {
            return _HeightInput;
        }
        void HeightInput(::winrt::Windows::UI::Xaml::Controls::ComboBox value)
        {
            _HeightInput = value;
        }

        ::winrt::Microsoft::UI::Xaml::Controls::NumberBox PathWidthInput()
        {
            return _PathWidthInput;
        }
        void PathWidthInput(::winrt::Microsoft::UI::Xaml::Controls::NumberBox value)
        {
            _PathWidthInput = value;
        }

        ::winrt::Microsoft::UI::Xaml::Controls::NumberBox WallWidthInput()
        {
            return _WallWidthInput;
        }
        void WallWidthInput(::winrt::Microsoft::UI::Xaml::Controls::NumberBox value)
        {
            _WallWidthInput = value;
        }

        ::winrt::Windows::UI::Xaml::Controls::Button GenerateButton()
        {
            return _GenerateButton;
        }
        void GenerateButton(::winrt::Windows::UI::Xaml::Controls::Button value)
        {
            _GenerateButton = value;
        }

        ::winrt::Windows::UI::Xaml::Controls::TextBlock LogText()
        {
            return _LogText;
        }
        void LogText(::winrt::Windows::UI::Xaml::Controls::TextBlock value)
        {
            _LogText = value;
        }
        
    protected:
        bool _contentLoaded{false};

    private:
        struct MainPage_obj1_Bindings;

        ::winrt::Microsoft::UI::Xaml::Controls::NavigationView _navigation{nullptr};
        ::winrt::Windows::UI::Xaml::Controls::ComboBox _WidthInput{nullptr};
        ::winrt::Windows::UI::Xaml::Controls::ComboBox _HeightInput{nullptr};
        ::winrt::Microsoft::UI::Xaml::Controls::NumberBox _PathWidthInput{nullptr};
        ::winrt::Microsoft::UI::Xaml::Controls::NumberBox _WallWidthInput{nullptr};
        ::winrt::Windows::UI::Xaml::Controls::Button _GenerateButton{nullptr};
        ::winrt::Windows::UI::Xaml::Controls::TextBlock _LogText{nullptr};
    };
}

