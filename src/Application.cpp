//
// Created by cmartin on 2024/11/25.
//

#include <iostream>
#include "Application.h"
#include "platform/PlatformFactory.h"
#include "renderer/Renderer.h"

bool Application::Initialize()
{
    m_platform = PLATFORM::CreatePlatform();
    m_renderer = std::make_unique<Renderer>();

    try
    {
        m_platform->Initialize();
        m_renderer->Initialize(m_platform);
    }
    catch (const std::exception &ex)
    {
        std::cout << "ERROR: Unable to initialize the platform\n";
        return false;
    }

    return true;
}

void Application::Run()
{
    while (!m_platform->ShouldClose())
    {
        m_platform->PollEvents();
        m_renderer->Draw();
    }
}