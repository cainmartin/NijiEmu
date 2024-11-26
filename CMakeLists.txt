cmake_minimum_required(VERSION 3.27)
project(NijiEmu)

set(CMAKE_CXX_STANDARD 20)

add_executable(NijiEmu main.cpp
        src/Application.cpp
        src/Application.h
        src/renderer/Renderer.cpp
        src/renderer/Renderer.h
        src/platform/Platform_Win32.cpp
        src/platform/Platform_Win32.h
        src/platform/IPlatform.h
        src/platform/PlatformFactory.h
        src/platform/Platform_MacOSX.cpp
        src/platform/Platform_MacOSX.h)

# Define UNICODE and _UNICODE for Windows Unicode support
if (WIN32)
    target_compile_definitions(NijiEmu PRIVATE UNICODE _UNICODE)
endif()