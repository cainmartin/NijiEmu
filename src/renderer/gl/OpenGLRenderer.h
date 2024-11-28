//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_OPENGLRENDERER_H
#define NIJIEMU_OPENGLRENDERER_H


#include "../interfaces/IRenderer.h"
#include "../../platform/interfaces/IPlatform.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <memory>

class OpenGLRenderer : public IRenderer
{
public:
    OpenGLRenderer();
    ~OpenGLRenderer() override;

    void Initialize(std::unique_ptr<IPlatform>& platform) override;
    void Draw() override;

private:
    HDC m_hdc;
    HWND m_hwnd;
    HGLRC m_hglrc;
    bool m_initialized;
};


#endif //NIJIEMU_OPENGLRENDERER_H
