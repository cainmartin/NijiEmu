//
// Created by cmartin on 2024/11/26.
//

#ifndef NIJIEMU_IPLATFORM_H
#define NIJIEMU_IPLATFORM_H

class IPlatform
{
public:
    virtual ~IPlatform() = default;
    virtual void Initialize() = 0;
    virtual void PollEvents() = 0;
    [[nodiscard]] virtual bool ShouldClose() const = 0;
};

#endif //NIJIEMU_IPLATFORM_H
