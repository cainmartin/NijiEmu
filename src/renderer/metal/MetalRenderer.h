//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_METALRENDERER_H
#define NIJIEMU_METALRENDERER_H

#include "../../platform/interfaces/IPlatform.h"
#include "../interfaces/IRenderer.h"
#include <memory>
#include "../../core/Color.h"

namespace Renderer
{
    class MetalRenderer : public Renderer::IRenderer
    {
    public:
        MetalRenderer();

        ~MetalRenderer() override;

        void Initialize(std::unique_ptr<IPlatform> &platform) override;
        void BeginDraw() override;
        void Draw() override;
        void DrawPixel(int x, int y, const Core::Color& color) override;
        void EndDraw() override;

    private:

    };

}
#endif //NIJIEMU_METALRENDERER_H
