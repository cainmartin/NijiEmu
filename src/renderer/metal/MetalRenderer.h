//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_METALRENDERER_H
#define NIJIEMU_METALRENDERER_H

#include "../IRenderer.h"

class MetalRenderer : public IRenderer
{
public:
    MetalRenderer();
    ~MetalRenderer() override;

    void Draw() override;

private:

};


#endif //NIJIEMU_METALRENDERER_H
