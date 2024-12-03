//
// Created by cmartin on 2024/11/29.
//

#ifndef NIJIEMU_FILELOADER_H
#define NIJIEMU_FILELOADER_H

#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdint>
#include "ResourceManager.h"


namespace Core::FileLoader
{
    inline std::string LoadText(const std::filesystem::path& relativePath)
    {
        std::filesystem::path fullPath = ResourceManager::GetPath(relativePath);
        std::ifstream file(fullPath, std::ios::in);
        if (!file)
        {
            throw std::runtime_error("Unable to open file " + fullPath.string());
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        return buffer.str();
    }

    inline std::vector<char8_t> LoadBinary(const std::filesystem::path& relativePath)
    {
        std::filesystem::path fullPath = ResourceManager::GetPath(relativePath);
        std::ifstream file(fullPath, std::ios::binary | std::ios::ate);
        if (!file)
        {
            throw std::runtime_error("Unable to open file " + relativePath.string());
        }

        std::streamsize size = file.tellg();
        if (size < 0)
        {
            throw std::runtime_error("Invalid file size");
        }
        file.seekg(0, std::ios::beg);

        std::vector<char8_t> buffer(static_cast<size_t>(size));
        if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
        {
            throw std::runtime_error("Error reading file " + fullPath.string());
        }
        return buffer;
    }

    inline void SaveText(const std::filesystem::path& relativePath, const std::string& content)
    {
        std::filesystem::path fullPath = ResourceManager::GetPath(relativePath);
        std::ofstream file(fullPath, std::ios::out | std::ios::trunc);
        if (!file)
        {
            throw std::runtime_error("Could not open file " + fullPath.string() + " for writing.");
        }

        file << content;
        if (!file)
        {
            throw std::runtime_error("Error writing to file " + fullPath.string());
        }
    }

    inline void SaveBinary(const std::filesystem::path& relativePath, const std::vector<char8_t>& content)
    {
        std::filesystem::path fullPath = ResourceManager::GetPath(relativePath);
        std::ofstream file(fullPath, std::ios::out | std::ios::binary | std::ios::trunc);
        if (!file)
        {
            throw std::runtime_error("Could not open file " + fullPath.string() + " for writing.");
        }
        file.write(reinterpret_cast<const char *>(content.data()), static_cast<std::streamsize>(content.size()));
        if (!file)
        {
            throw std::runtime_error("Error writing to file " + fullPath.string());
        }
    }
}
// CORE

#endif //NIJIEMU_FILELOADER_H
