//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_IRENDERER_H
#define NIJIEMU_IRENDERER_H

#include "../../platform/interfaces/IPlatform.h"
#include <memory>

class IRenderer
{
public:
    virtual ~IRenderer() = default;
    virtual void Initialize(std::unique_ptr<IPlatform>& platform) = 0;
    virtual void Draw() = 0;
};
#endif //NIJIEMU_IRENDERER_H
