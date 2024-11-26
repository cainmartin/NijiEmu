//
// Created by cmartin on 2024/11/25.
//

#ifndef NIJIEMU_PLATFORM_WIN32_H
#define NIJIEMU_PLATFORM_WIN32_H

#include "IPlatform.h"
#include <windows.h>

class Platform_Win32 : public IPlatform
{
public:
    Platform_Win32();
    ~Platform_Win32() override;

    void Initialize() override;
    void PollEvents() override;
    [[nodiscard]] bool ShouldClose() const override;

private:
    HWND m_hwnd;
    bool m_shouldClose;

    static LRESULT CALLBACK StaticWndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
    LRESULT WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
};


#endif //NIJIEMU_PLATFORM_WIN32_H
