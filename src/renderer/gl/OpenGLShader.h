//
// Created by cmartin on 2024/12/03.
//

#ifndef NIJIEMU_OPENGLSHADER_H
#define NIJIEMU_OPENGLSHADER_H

#include <string>
#include <cstdint>
#include "../interfaces/IShader.h"

namespace Renderer
{
    class OpenGLShader : public IShader
    {
    public:
        OpenGLShader(const std::string& vs_source, const std::string& fs_source);
        virtual ~OpenGLShader() override;

        virtual void Bind() override;
        virtual void Unbind() override;

    private:
        uint32_t m_RendererId;
    };

} // Renderer

#endif //NIJIEMU_OPENGLSHADER_H
