cmake_minimum_required(VERSION 3.27)
if (APPLE)
project(NijiEmu LANGUAGES C CXX OBJCXX)
else ()
    project(NijiEmu LANGUAGES C CXX)
endif ()

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    message("Using GLAD for OpenGL support")
    # GLAD library
    add_library(glad STATIC vendor/glad/src/glad.c)
    target_include_directories(glad PRIVATE vendor/glad/include)
endif()

# Platform-specific source files
if (WIN32)
    message("Including Windows platform sources")
    list(APPEND PLATFORM_SOURCES
            src/platform/windows/Platform_Win32.cpp
            src/renderer/gl/OpenGLRenderer.cpp
    )
elseif (APPLE)
    message("Including macOS platform sources")
    message("OpenGL renderer currently in use - TODO: Replace with metal renderer")
    list(APPEND PLATFORM_SOURCES
            src/platform/mac/Platform_MacOSX.mm
            src/renderer/metal/MetalRenderer.mm
    )
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

list(APPEND COMMON_SOURCES
    main.cpp
    src/Application.cpp
    src/platform/PlatformFactory.cpp
    src/renderer/Renderer.cpp
    src/renderer/RendererFactory.cpp
    src/core/ResourceManager.cpp
)

add_executable(NijiEmu
    ${COMMON_SOURCES}
    ${PLATFORM_SOURCES}
)

if (WIN32)
# Include directories for the target (if not set globally)
target_include_directories(NijiEmu PRIVATE
        src
        vendor/glad/include
        # Add other include directories as needed
)

# Link libraries
target_link_libraries(NijiEmu PRIVATE glad)
endif()

if(APPLE)
    target_include_directories(NijiEmu PRIVATE vendor/metal-cpp/include)

    # Link the Cocoa framework
    target_link_libraries(NijiEmu PRIVATE "-framework Cocoa")
    # Ensure Objective-C++ is used for .mm files
    # set_source_files_properties(src/platform/mac/Platform_MacOSX.mm PROPERTIES LANGUAGE OBJCXX)

    # Link against the required frameworks
    target_link_libraries(NijiEmu PRIVATE
            "-framework Foundation"
            "-framework QuartzCore"
            "-framework Cocoa"
            "-framework Metal"
            "-framework MetalKit"
    )
endif()

# Define UNICODE and _UNICODE for Windows Unicode support
if (WIN32)
    target_link_libraries(NijiEmu PRIVATE opengl32)
    target_compile_definitions(NijiEmu PRIVATE UNICODE _UNICODE)
endif()

