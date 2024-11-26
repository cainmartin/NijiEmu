//
// Created by cmartin on 2024/11/26.
//

#ifndef NIJIEMU_PLATFORMFACTORY_H
#define NIJIEMU_PLATFORMFACTORY_H

#include "Platform.h"
#include "interfaces/IPlatform.h"
#include <memory>

std::unique_ptr<IPlatform> CreatePlatform()
{
#ifdef _WIN32
    return std::unique_ptr<IPlatform>(new Platform_Win32());
#elif __APPLE__
    return std::unique_ptr<IPlatform>(new Platform_MacOSX());
#endif
}

#endif //NIJIEMU_PLATFORMFACTORY_H
