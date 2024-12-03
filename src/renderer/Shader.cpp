//
// Created by cmartin on 2024/12/03.
//

#include "Shader.h"
#include "interfaces/IShader.h"
#include "gl/OpenGLShader.h"

namespace Renderer
{
    class Shader::ShaderImpl
    {
    public:
        ShaderImpl(const std::string& vs_source, const std::string& fs_source) {
// #define GL_SHADER
            m_shader = std::make_unique<OpenGLShader>(vs_source, fs_source);
// #endif
        }

        void Bind() { m_shader->Bind(); }
        void Unbind() { m_shader->Unbind(); }

    private:

        std::unique_ptr<IShader> m_shader;
    };

    void Shader::Bind()
    {
        m_impl->Bind();
    }

    void Shader::Unbind()
    {

    }

} // Renderer