//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_METALRENDERER_H
#define NIJIEMU_METALRENDERER_H

#include "../../platform/interfaces/IPlatform.h"
#include "../interfaces/IRenderer.h"
#include <memory>

class MetalRenderer : public IRenderer
{
public:
    MetalRenderer();
    ~MetalRenderer() override;

    void Initialize(std::unique_ptr<IPlatform>& platform) override;
    void Draw() override;

private:

};


#endif //NIJIEMU_METALRENDERER_H
