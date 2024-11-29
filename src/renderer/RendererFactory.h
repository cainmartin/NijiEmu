//
// Created by cmartin on 2024/11/27.
//

#ifndef NIJIEMU_RENDERERFACTORY_H
#define NIJIEMU_RENDERERFACTORY_H

namespace Renderer
{
    std::unique_ptr<IRenderer> CreateRenderer();
}



#endif //NIJIEMU_RENDERERFACTORY_H
