//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_IRENDERER_H
#define NIJIEMU_IRENDERER_H

class IRenderer
{
public:
    virtual ~IRenderer() = default;

    virtual void Draw() = 0;
};
#endif //NIJIEMU_IRENDERER_H
