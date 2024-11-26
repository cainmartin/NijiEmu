//
// Created by cmartin on 2024/11/25.
//

#ifndef NIJIEMU_APPLICATION_H
#define NIJIEMU_APPLICATION_H

#include <memory>
#include "platform/IPlatform.h"

class Application
{
public:
    [[nodiscard]] bool Initialize();
    void Run();

private:
    std::unique_ptr<IPlatform> m_platform;
};


#endif //NIJIEMU_APPLICATION_H
