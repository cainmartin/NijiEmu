//
// Created by cmartin on 2024/11/27.
//

#include "OpenGLRenderer.h"
#include "Defines.h"
#include <glad/glad.h>
#include <stdexcept>
#include <iostream>

namespace Renderer
{
    OpenGLRenderer::OpenGLRenderer()
    {

    }

    OpenGLRenderer::~OpenGLRenderer()
    {

    }

    void OpenGLRenderer::Initialize(std::unique_ptr<IPlatform> &platform)
    {
        m_hwnd = static_cast<HWND>(platform->GetNativeLayer());
        m_hdc = GetDC(m_hwnd);

        // Simple Pixel Format
        PIXELFORMATDESCRIPTOR pfd = {};
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;
        pfd.iLayerType = PFD_MAIN_PLANE;

        int pixelFormat = ChoosePixelFormat(m_hdc, &pfd);
        if (pixelFormat == 0) {
            throw std::runtime_error("Failed to choose pixel format");
        }

        if (!SetPixelFormat(m_hdc, pixelFormat, &pfd)) {
            throw std::runtime_error("Failed to set pixel format");
        }

        HGLRC tempContext = wglCreateContext(m_hdc);
        if (!tempContext) {
            throw std::runtime_error("Failed to create temporary context");
        }

        if (!wglMakeCurrent(m_hdc, tempContext)) {
            wglDeleteContext(tempContext);
            throw std::runtime_error("Failed to make temporary OpenGL context current");
        }

        if (!gladLoadGL()) {
            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(tempContext);
            throw std::runtime_error("Failed to initialize GLAD");
        }

        // Load WGL extension functions
        wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) wglGetProcAddress("wglGetExtensionsStringARB");
        if (wglGetExtensionsStringARB) {
            const char *extensions = wglGetExtensionsStringARB(m_hdc);
            if (strstr(extensions, "WGL_ARB_create_context") == nullptr ||
                strstr(extensions, "WGL_ARB_pixel_format") == nullptr) {
                wglMakeCurrent(NULL, NULL);
                wglDeleteContext(tempContext);
                throw std::runtime_error("Required extensions not available");
            }
        } else {
            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(tempContext);
            throw std::runtime_error("Failed to load extension wglGetExtensionsStringARB");
        }

        wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress(
                "wglCreateContextAttribsARB");
        wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) wglGetProcAddress("wglChoosePixelFormatARB");
        if (!wglCreateContextAttribsARB || !wglChoosePixelFormatARB) {
            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(tempContext);
            throw std::runtime_error("Failed to load required WGL functions");
        }

        // Did not set a specific pixel format

        int contextAttribs[] =
                {
                        WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
                        WGL_CONTEXT_MINOR_VERSION_ARB, 3,
                        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
                        0
                };

        m_hglrc = wglCreateContextAttribsARB(m_hdc, 0, contextAttribs);
        if (!m_hglrc) {
            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(tempContext);
            throw std::runtime_error("Failed to create OpenGL context");
        }

        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(tempContext);

        if (!wglMakeCurrent(m_hdc, m_hglrc)) {
            wglDeleteContext(m_hglrc);
            throw std::runtime_error("Failed to make OpenGL context current");
        }

        // Window surface setup - move this elsewhere
        RECT rect;
        if (GetClientRect(m_hwnd, &rect)) {
            int width = rect.right - rect.left;
            int height = rect.bottom - rect.top;
            glViewport(0, 0, width, height);
        }

        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            throw std::runtime_error("OpenGL error during initialization");
        }

        std::cout << "Initialized the OpenGL renderer\n";
    }

    void OpenGLRenderer::BeginDraw()
    {

    }

    void OpenGLRenderer::Draw()
    {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        SwapBuffers(m_hdc);
    }

    void OpenGLRenderer::DrawPixel(int x, int y, const Core::Color& color)
    {

    }

    void OpenGLRenderer::EndDraw()
    {

    }
}