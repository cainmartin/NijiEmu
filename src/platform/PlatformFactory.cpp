//
// Created by cmartin on 2024/11/28.
//

#include "PlatformFactory.h"

#ifdef _WIN32
#include "windows/Platform_Win32.h"
#elif __APPLE__
#include "mac/Platform_MacOSX.h"
#endif

namespace PLATFORM
{
    std::unique_ptr<IPlatform> CreatePlatform()
    {
#ifdef _WIN32
        return std::unique_ptr<IPlatform>(new Platform_Win32());
#elif __APPLE__
        return std::unique_ptr<IPlatform>(new Platform_MacOSX());
#endif
    }
}

