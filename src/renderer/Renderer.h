//
// Created by cmartin on 2024/11/25.
//

#ifndef NIJIEMU_RENDERER_H
#define NIJIEMU_RENDERER_H

#include "interfaces/IRenderer.h"
#include <memory>

class Renderer
{
public:

    void Initialize(std::unique_ptr<IPlatform>& platform);
    void Draw();

private:
    std::unique_ptr<IRenderer> m_renderer;
};


#endif //NIJIEMU_RENDERER_H
