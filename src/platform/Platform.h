//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_PLATFORM_H
#define NIJIEMU_PLATFORM_H

#ifdef _WIN32
#include "windows/Platform_Win32.h"
#elif __APPLE__
#include "mac/Platform_MacOSX.h"
#endif

#endif //NIJIEMU_PLATFORM_H
