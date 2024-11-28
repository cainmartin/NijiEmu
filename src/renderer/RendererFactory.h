//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_RENDERERFACTORY_H
#define NIJIEMU_RENDERERFACTORY_H

#include <memory>
#include "gl/OpenGLRenderer.h"
#include "metal/MetalRenderer.h"

std::unique_ptr<IRenderer> CreateRenderer()
{
#ifdef _WIN32
    return std::unique_ptr<IRenderer>(new OpenGLRenderer());
#elif __APPLE__
    return std::unique_ptr<IRenderer>(new OpenGLRenderer());
    // return std::unique_ptr<IRenderer>(new MetalRenderer());
#endif
}

#endif //NIJIEMU_RENDERERFACTORY_H
