//
// Created by cmartin on 2024/11/29.
//

#ifndef NIJIEMU_RESOURCEMANAGER_H
#define NIJIEMU_RESOURCEMANAGER_H

#include <filesystem>

namespace Core
{

    class ResourceManager
    {
    public:
        ResourceManager() = delete;
        ~ResourceManager() = delete;
        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager&) = delete;

        static void Initialize(const std::filesystem::path& basePath);
        static std::filesystem::path GetPath(const std::filesystem::path& relativePath);

    private:
        static std::filesystem::path m_basePath;
    };

} // CORE

#endif //NIJIEMU_RESOURCEMANAGER_H
