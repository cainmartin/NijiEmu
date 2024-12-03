//
// Created by cmartin on 2024/12/03.
//

#ifndef NIJIEMU_SHADER_H
#define NIJIEMU_SHADER_H

#include <cstdint>
#include <memory>
#include <string>

namespace Renderer
{

class Shader
{
public:
    Shader(const std::string& vs_source, const std::string& fs_source);
    ~Shader() = default;

    void Bind();
    void Unbind();

private:
    class ShaderImpl;
    std::unique_ptr<ShaderImpl> m_impl;
};

} // Renderer

#endif //NIJIEMU_SHADER_H
