#ifdef __APPLE__

#import <Cocoa/Cocoa.h>
#include "Platform_MacOSX.h"

Platform_MacOSX::Platform_MacOSX()
        : m_shouldClose(false), m_application(nullptr), m_window(nullptr)
{
}

@interface NijiEmuWindowDelegate : NSObject <NSWindowDelegate>
@property (nonatomic, assign) bool* shouldClose;
@end

@implementation NijiEmuWindowDelegate
- (BOOL)windowShouldClose:(NSWindow *)sender {
    *self.shouldClose = true;
    return YES;
}
@end

Platform_MacOSX::~Platform_MacOSX()
{
    if (m_window) {
        [m_window release];
    }
    if (m_application) {
        [m_application release];
    }
}

void Platform_MacOSX::Initialize()
{
    @autoreleasepool {
        // Ensure the application is created on the main thread
        m_application = [NSApplication sharedApplication];

        // Create the main window
        NSRect screenRect = [[NSScreen mainScreen] frame];
        NSRect windowRect = NSMakeRect(
                (screenRect.size.width - 800) / 2,
                (screenRect.size.height - 600) / 2,
                800, 600
        );

        m_window = [[NSWindow alloc] initWithContentRect:windowRect
                                               styleMask:NSWindowStyleMaskTitled |
                                                         NSWindowStyleMaskClosable |
                                                         NSWindowStyleMaskMiniaturizable |
                                                         NSWindowStyleMaskResizable
                                                 backing:NSBackingStoreBuffered defer:NO];
        [m_window setTitle:@"NijiEmu"];
        [m_window makeKeyAndOrderFront:nil];

        // Set up window delegate
        NijiEmuWindowDelegate* windowDelegate = [[NijiEmuWindowDelegate alloc] init];
        windowDelegate.shouldClose = &m_shouldClose;
        [m_window setDelegate:windowDelegate];

        // Ensure the application is activated and ready to receive events
        [m_application activateIgnoringOtherApps:YES];
    }
}

void Platform_MacOSX::PollEvents()
{
    @autoreleasepool {
        NSEvent* event;
        while ((event = [m_application nextEventMatchingMask:NSEventMaskAny
                                                   untilDate:[NSDate distantPast]
                                                      inMode:NSDefaultRunLoopMode
                                                     dequeue:YES])) {
            switch ([event type]) {
                case NSEventTypeKeyDown:
                    // Handle key down events if needed
                    break;

                case NSEventTypeKeyUp:
                    // Handle key up events if needed
                    break;

                case NSEventTypeMouseMoved:
                    // Handle mouse movement if needed
                    break;

                case NSEventTypeLeftMouseDown:
                case NSEventTypeRightMouseDown:
                    // Handle mouse button down events
                    break;

                case NSEventTypeLeftMouseUp:
                case NSEventTypeRightMouseUp:
                    // Handle mouse button up events
                    break;

                case NSEventTypeApplicationDefined:
                    // Application-specific events
                    break;

                default:
                    break;
            }

            // Process the event through the standard application event handling
            [m_application sendEvent:event];
            [m_application updateWindows];
        }

        // Periodically check if the window should close
        // This ensures responsiveness even if no events are occurring
        if (m_window && [m_window isVisible] == NO) {
            m_shouldClose = true;
        }
    }
}

bool Platform_MacOSX::ShouldClose() const
{
    return m_shouldClose;
}

#endif // __APPLE__