//
// Created by cmartin on 2024/11/25.
//

#ifdef _WIN32

#include "Platform_Win32.h"
#include <windows.h>
#include <stdexcept>

Platform_Win32::Platform_Win32()
: m_hwnd(nullptr)
, m_shouldClose(false)
{
}

Platform_Win32::~Platform_Win32()
{
    if (m_hwnd)
    {
        DestroyWindow(m_hwnd);
        m_hwnd = nullptr;
    }
}

void Platform_Win32::Initialize()
{
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = StaticWndProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = L"WindowsPlatformWindowClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if (!RegisterClassEx(&wc))
    {
        throw std::runtime_error("Failed to register window class");
    }

    m_hwnd = CreateWindowEx(
            0,
            wc.lpszClassName,
            L"Niji Emulator",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
            nullptr,
            nullptr,
            wc.hInstance,
            this
        );

    if (!m_hwnd)
    {
        DWORD error = GetLastError();
        throw std::runtime_error("Failed to register window class: " + std::to_string(error));
    }

    ShowWindow(m_hwnd, SW_SHOW);
    UpdateWindow(m_hwnd);
}

void Platform_Win32::PollEvents()
{
    // TODO: Need to add a callback or something for the game loop
    MSG msg = { nullptr };
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

bool Platform_Win32::ShouldClose() const
{
    return m_shouldClose;
}

LRESULT CALLBACK Platform_Win32::StaticWndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    Platform_Win32* p_this = nullptr;

    if (message == WM_NCCREATE)
    {
        CREATESTRUCT* p_create = reinterpret_cast<CREATESTRUCT*>(lparam);
        p_this = reinterpret_cast<Platform_Win32*>(p_create->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(p_this));
    }
    else
    {
        p_this = reinterpret_cast<Platform_Win32*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    }

    if (p_this)
    {
        return p_this->WndProc(hwnd, message, wparam, lparam);
    }
    else
    {
        return DefWindowProc(hwnd, message, wparam, lparam);
    }
}

LRESULT Platform_Win32::WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message)
    {
        case WM_CLOSE:
            m_shouldClose = true;
            break;

        case WM_KEYDOWN:
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, message, wparam, lparam);
    }

    return 0;
}

void* Platform_Win32::GetNativeLayer()
{
    return nullptr;
}

#endif // _WIN32