//
// Created by cmartin on 2024/11/26.
//

#include "Platform_MacOSX.h"

Platform_MacOSX::Platform_MacOSX()
: m_shouldClose(false)
{

}

Platform_MacOSX::~Platform_MacOSX()
{

}

void Platform_MacOSX::Initialize()
{

}

void Platform_MacOSX::PollEvents()
{

}

bool Platform_MacOSX::ShouldClose() const
{
    return m_shouldClose;
}