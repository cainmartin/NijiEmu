//
// Created by cmartin on 2024/11/29.
//

#ifndef NIJIEMU_FILELOADER_H
#define NIJIEMU_FILELOADER_H

#include <filesystem>
#include <string>
#include <vector>
#include <cstdint>
#include "ResourceManager.h"

namespace Core
{
namespace FileLoader
{
    inline std::string LoadText(const std::filesystem::path& relativePath)
    {
        std::filesystem::path fullPath = ResourceManager::GetPath(relativePath);
    }

    inline std::vector<char8_t> LoadBinary(const std::filesystem::path& relativePath)
    {

    }

    inline void SaveText(const std::filesystem::path& relativePath, const std::string& content)
    {

    }

    inline void SaveBinary(const std::filesystem::path& relativePath, const std::vector<char8_t>& content)
    {

    }
}
} // CORE

#endif //NIJIEMU_FILELOADER_H
