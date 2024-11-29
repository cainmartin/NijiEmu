//
// Created by cmartin on 2024/11/25.
//

#ifndef NIJIEMU_APPLICATION_H
#define NIJIEMU_APPLICATION_H

#include <memory>
#include "platform/interfaces/IPlatform.h"
#include "renderer/Renderer.h"

class Application
{
public:
    void Initialize();
    void Run();

private:
    std::unique_ptr<IPlatform> m_platform;
    std::unique_ptr<Renderer::Renderer> m_renderer;
};


#endif //NIJIEMU_APPLICATION_H
