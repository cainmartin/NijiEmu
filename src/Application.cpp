//
// Created by cmartin on 2024/11/25.
//

#include "Application.h"
#include "platform/PlatformFactory.h"

bool Application::Initialize()
{
    m_platform = CreatePlatform();

    try
    {
        m_platform->Initialize();
    }
    catch (const std::exception &ex)
    {
        // TODO: Provide a platform independent way to print error messages / message boxes
#ifdef _WIN32
        MessageBoxA(nullptr, ex.what(), "Unhandled exception", MB_ICONERROR | MB_OK);
#elif __APPLE__
        // Apple equivalent
#endif
        return false;
    }

    return true;
}

void Application::Run()
{
    while (!m_platform->ShouldClose())
    {
        m_platform->PollEvents();
    }
}