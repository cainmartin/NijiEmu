//
// Created by cmartin on 2024/11/25.
//

#include "Renderer.h"
#include "RendererFactory.h"

void Renderer::Initialize(std::unique_ptr<IPlatform>& platform)
{
    m_renderer = RENDERER::CreateRenderer();
    m_renderer->Initialize(platform);
}

void Renderer::Draw()
{
    m_renderer->Draw();
}