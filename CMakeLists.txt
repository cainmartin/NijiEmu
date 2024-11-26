cmake_minimum_required(VERSION 3.27)
project(NijiEmu LANGUAGES CXX OBJCXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(NijiEmu main.cpp
        src/Application.cpp
        src/Application.h
        src/renderer/Renderer.cpp
        src/renderer/Renderer.h
        src/platform/windows/Platform_Win32.cpp
        src/platform/windows/Platform_Win32.h
        src/platform/mac/Platform_MacOSX.h
        src/platform/mac/Platform_MacOSX.mm
        src/platform/IPlatform.h
        src/platform/PlatformFactory.h)

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

