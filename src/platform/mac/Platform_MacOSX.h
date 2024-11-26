#ifndef NIJIEMU_PLATFORM_MACOSX_H
#define NIJIEMU_PLATFORM_MACOSX_H

#ifdef __APPLE__

#include "../IPlatform.h"

// Forward declare Objective-C types
#ifndef __OBJC__
typedef struct objc_object NSApplication;
typedef struct objc_object NSWindow;
#endif

class Platform_MacOSX : public IPlatform
{
public:
    Platform_MacOSX();
    ~Platform_MacOSX() override;

    void Initialize() override;
    void PollEvents() override;
    [[nodiscard]] bool ShouldClose() const override;

private:
    bool m_shouldClose;
    NSApplication* m_application;
    NSWindow* m_window;
};

#endif // __APPLE__

#endif //NIJIEMU_PLATFORM_MACOSX_H