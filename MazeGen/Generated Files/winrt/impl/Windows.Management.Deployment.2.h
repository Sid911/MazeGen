// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.211028.7

#pragma once
#ifndef WINRT_Windows_Management_Deployment_2_H
#define WINRT_Windows_Management_Deployment_2_H
#include "winrt/impl/Windows.ApplicationModel.2.h"
#include "winrt/impl/Windows.Management.Deployment.1.h"
WINRT_EXPORT namespace winrt::Windows::Management::Deployment
{
    struct DeploymentProgress
    {
        winrt::Windows::Management::Deployment::DeploymentProgressState state;
        uint32_t percentage;
    };
    inline bool operator==(DeploymentProgress const& left, DeploymentProgress const& right) noexcept
    {
        return left.state == right.state && left.percentage == right.percentage;
    }
    inline bool operator!=(DeploymentProgress const& left, DeploymentProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AddPackageOptions : winrt::Windows::Management::Deployment::IAddPackageOptions
    {
        AddPackageOptions(std::nullptr_t) noexcept {}
        AddPackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IAddPackageOptions(ptr, take_ownership_from_abi) {}
        AddPackageOptions();
    };
    struct __declspec(empty_bases) AppInstallerManager : winrt::Windows::Management::Deployment::IAppInstallerManager
    {
        AppInstallerManager(std::nullptr_t) noexcept {}
        AppInstallerManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IAppInstallerManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForSystem();
    };
    struct __declspec(empty_bases) AutoUpdateSettingsOptions : winrt::Windows::Management::Deployment::IAutoUpdateSettingsOptions
    {
        AutoUpdateSettingsOptions(std::nullptr_t) noexcept {}
        AutoUpdateSettingsOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IAutoUpdateSettingsOptions(ptr, take_ownership_from_abi) {}
        AutoUpdateSettingsOptions();
        static auto CreateFromAppInstallerInfo(winrt::Windows::ApplicationModel::AppInstallerInfo const& appInstallerInfo);
    };
    struct __declspec(empty_bases) DeploymentResult : winrt::Windows::Management::Deployment::IDeploymentResult,
        impl::require<DeploymentResult, winrt::Windows::Management::Deployment::IDeploymentResult2>
    {
        DeploymentResult(std::nullptr_t) noexcept {}
        DeploymentResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IDeploymentResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageAllUserProvisioningOptions : winrt::Windows::Management::Deployment::IPackageAllUserProvisioningOptions
    {
        PackageAllUserProvisioningOptions(std::nullptr_t) noexcept {}
        PackageAllUserProvisioningOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IPackageAllUserProvisioningOptions(ptr, take_ownership_from_abi) {}
        PackageAllUserProvisioningOptions();
    };
    struct __declspec(empty_bases) PackageManager : winrt::Windows::Management::Deployment::IPackageManager,
        impl::require<PackageManager, winrt::Windows::Management::Deployment::IPackageManager2, winrt::Windows::Management::Deployment::IPackageManager3, winrt::Windows::Management::Deployment::IPackageManager4, winrt::Windows::Management::Deployment::IPackageManager5, winrt::Windows::Management::Deployment::IPackageManager6, winrt::Windows::Management::Deployment::IPackageManager7, winrt::Windows::Management::Deployment::IPackageManager8, winrt::Windows::Management::Deployment::IPackageManager9, winrt::Windows::Management::Deployment::IPackageManager10>
    {
        PackageManager(std::nullptr_t) noexcept {}
        PackageManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IPackageManager(ptr, take_ownership_from_abi) {}
        PackageManager();
        using winrt::Windows::Management::Deployment::IPackageManager::AddPackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager3>::AddPackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager5>::AddPackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager6>::AddPackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager10>::ProvisionPackageForAllUsersAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager6>::ProvisionPackageForAllUsersAsync;
        using winrt::Windows::Management::Deployment::IPackageManager::RegisterPackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager3>::RegisterPackageAsync;
        using winrt::Windows::Management::Deployment::IPackageManager::RemovePackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager2>::RemovePackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager6>::RequestAddPackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager7>::RequestAddPackageAsync;
        using winrt::Windows::Management::Deployment::IPackageManager::StagePackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager2>::StagePackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager3>::StagePackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager5>::StagePackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager6>::StagePackageAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager2>::StageUserDataAsync;
        using impl::consume_t<PackageManager, winrt::Windows::Management::Deployment::IPackageManager3>::StageUserDataAsync;
    };
    struct __declspec(empty_bases) PackageManagerDebugSettings : winrt::Windows::Management::Deployment::IPackageManagerDebugSettings
    {
        PackageManagerDebugSettings(std::nullptr_t) noexcept {}
        PackageManagerDebugSettings(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IPackageManagerDebugSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageUserInformation : winrt::Windows::Management::Deployment::IPackageUserInformation
    {
        PackageUserInformation(std::nullptr_t) noexcept {}
        PackageUserInformation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IPackageUserInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageVolume : winrt::Windows::Management::Deployment::IPackageVolume,
        impl::require<PackageVolume, winrt::Windows::Management::Deployment::IPackageVolume2>
    {
        PackageVolume(std::nullptr_t) noexcept {}
        PackageVolume(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IPackageVolume(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RegisterPackageOptions : winrt::Windows::Management::Deployment::IRegisterPackageOptions
    {
        RegisterPackageOptions(std::nullptr_t) noexcept {}
        RegisterPackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IRegisterPackageOptions(ptr, take_ownership_from_abi) {}
        RegisterPackageOptions();
    };
    struct __declspec(empty_bases) StagePackageOptions : winrt::Windows::Management::Deployment::IStagePackageOptions
    {
        StagePackageOptions(std::nullptr_t) noexcept {}
        StagePackageOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Deployment::IStagePackageOptions(ptr, take_ownership_from_abi) {}
        StagePackageOptions();
    };
}
#endif
