//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_OPENGLRENDERER_H
#define NIJIEMU_OPENGLRENDERER_H

#include "../IRenderer.h"

class OpenGLRenderer : public IRenderer
{
public:
    OpenGLRenderer();
    ~OpenGLRenderer() override;

    void Draw() override;

private:

};


#endif //NIJIEMU_OPENGLRENDERER_H