//
// Created by cmartin on 2024/11/26.
//

#ifndef NIJIEMU_PLATFORMFACTORY_H
#define NIJIEMU_PLATFORMFACTORY_H

#include "interfaces/IPlatform.h"
#include <memory>

namespace PLATFORM
{
    std::unique_ptr<IPlatform> CreatePlatform();
}

#endif //NIJIEMU_PLATFORMFACTORY_H
