cmake_minimum_required(VERSION 3.27)
if (APPLE)
project(NijiEmu LANGUAGES CXX OBJCXX)
else ()
    project(NijiEmu LANGUAGES CXX)
endif ()

set(CMAKE_CXX_STANDARD 20)

# Platform-specific source files
if (WIN32)
    message("Including Windows platform sources")
    list(APPEND SOURCES
            src/platform/windows/Platform_Win32.cpp
            src/platform/windows/Platform_Win32.h
    )
elseif (APPLE)
    message("Including macOS platform sources")
    message("OpenGL renderer currently in use - TODO: Replace with metal renderer")
    list(APPEND SOURCES
            src/platform/mac/Platform_MacOSX.h
            src/platform/mac/Platform_MacOSX.mm
            src/renderer/metal/MetalRenderer.mm
            src/renderer/metal/MetalRenderer.h
    )
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

add_executable(NijiEmu main.cpp
        src/Application.cpp
        src/Application.h
        src/renderer/Renderer.cpp
        src/renderer/Renderer.h
        src/platform/IPlatform.h
        src/platform/PlatformFactory.h
        # For now - OpenGL will be both Mac and Windows until the metal renderer is working
        src/renderer/gl/OpenGLRenderer.cpp
        src/renderer/gl/OpenGLRenderer.h
        src/renderer/RendererFactory.h
        src/renderer/IRenderer.h
        ${SOURCES}
)

if(APPLE)
    # Link the Cocoa framework
    target_link_libraries(NijiEmu PRIVATE "-framework Cocoa")
    # Ensure Objective-C++ is used for .mm files
    set_source_files_properties(src/platform/mac/Platform_MacOSX.mm PROPERTIES LANGUAGE OBJCXX)
endif()

# Define UNICODE and _UNICODE for Windows Unicode support
if (WIN32)
    target_compile_definitions(NijiEmu PRIVATE UNICODE _UNICODE)
endif()

