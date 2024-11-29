//
// Created by cmartin on 2024/11/25.
//

#include <iostream>
#include <stdexcept>
#include "Application.h"
#include "platform/PlatformFactory.h"
#include "renderer/Renderer.h"
#include "core/ResourceManager.h"

void Application::Initialize()
{
    m_platform = Platform::CreatePlatform();
    m_renderer = std::make_unique<Renderer::Renderer>();

    try
    {
        m_platform->Initialize();
        m_renderer->Initialize(m_platform);

        Core::ResourceManager::Initialize("c:/dev/emu/NijiEmu/");
    }
    catch (const std::exception &ex)
    {
        throw std::runtime_error("Unable to initialize the platform");
    }
}

void Application::Run()
{
    while (!m_platform->ShouldClose())
    {
        m_platform->PollEvents();
        m_renderer->Draw();
    }
}