#ifndef NIJIEMU_PLATFORM_MACOSX_H
#define NIJIEMU_PLATFORM_MACOSX_H

#include "../interfaces/IPlatform.h"
// Forward declaration of NSView
#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#else
class NSView;
#endif

// Forward declare Objective-C types
#ifndef __OBJC__
typedef struct objc_object NSApplication;
typedef struct objc_object NSWindow;
typedef struct objc_object NSOpenGLContext;
#endif

class Platform_MacOSX : public IPlatform
{
public:
    Platform_MacOSX();
    ~Platform_MacOSX() override;

    void Initialize() override;
    void PollEvents() override;
    [[nodiscard]] bool ShouldClose() const override;

    void* GetNativeLayer() override;

private:
    bool m_shouldClose;
    NSApplication* m_application;
    NSWindow* m_window;
    NSView* m_view;
};

#endif //NIJIEMU_PLATFORM_MACOSX_H