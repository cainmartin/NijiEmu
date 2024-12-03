//
// Created by cmartin on 2024/12/03.
//

#ifndef NIJIEMU_ISHADER_H
#define NIJIEMU_ISHADER_H

class IShader
{
public:
    virtual ~IShader() = default;

    virtual void Bind() = 0;
    virtual void Unbind() = 0;
};

#endif //NIJIEMU_ISHADER_H
