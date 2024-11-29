//
// Created by cmartin on 2024/11/29.
//

#ifndef NIJIEMU_COLOR_H
#define NIJIEMU_COLOR_H

#include <cstdint>

namespace Core
{
    struct Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        Color() : r(255), g(255), b(255), a(255) {}
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : r(red), g(green), b(blue), a(alpha) {}

        bool operator==(const Color& color) const
        {
            return r == color.r &&
                   g == color.g &&
                   b == color.b &&
                   a == color.a;
        }
    };

}

#endif //NIJIEMU_COLOR_H
