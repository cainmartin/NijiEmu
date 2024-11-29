//
// Created by Cain Martin on 2024/11/28.
//

#include <memory>
#ifdef _WIN32
#include "gl/OpenGLRenderer.h"
#elif __APPLE__
#include "metal/MetalRenderer.h"
#endif

namespace Renderer
{
    std::unique_ptr<IRenderer> CreateRenderer()
    {
    #ifdef _WIN32
        return std::unique_ptr<IRenderer>(new OpenGLRenderer());
    #elif __APPLE__
        return std::unique_ptr<IRenderer>(new MetalRenderer());
    #endif
    }
}

