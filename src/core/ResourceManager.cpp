//
// Created by cmartin on 2024/11/29.
//

#include "ResourceManager.h"

namespace Core
{
    std::filesystem::path ResourceManager::m_basePath;

    void ResourceManager::Initialize(const std::filesystem::path& basePath)
    {
            if (!std::filesystem::exists(basePath) || !std::filesystem::is_directory(basePath))
            {
                throw std::runtime_error("Invalid resource base path: " + basePath.string());
            }
            m_basePath = std::filesystem::absolute(basePath);
    }

    std::filesystem::path ResourceManager::GetPath(const std::filesystem::path& relativePath)
    {
        if (relativePath.is_absolute())
        {
            return relativePath;
        }

        return m_basePath / relativePath;
    }

} // CORE