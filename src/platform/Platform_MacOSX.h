//
// Created by cmartin on 2024/11/26.
//

#ifndef NIJIEMU_PLATFORM_MACOSX_H
#define NIJIEMU_PLATFORM_MACOSX_H

#include "IPlatform.h"

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
};


#endif //NIJIEMU_PLATFORM_MACOSX_H
