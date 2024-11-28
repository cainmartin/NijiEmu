//
// Created by cmartin on 2024/11/28.
//

#ifndef NIJIEMU_DEFINES_H
#define NIJIEMU_DEFINES_H

// WGL_ARB_extensions_string
#ifndef WGL_ARB_extensions_string
#define WGL_ARB_extensions_string 1
#endif

// WGL_ARB_pixel_format
#ifndef WGL_ARB_pixel_format
#define WGL_ARB_pixel_format 1
#define WGL_NUMBER_PIXEL_FORMATS_ARB       0x2000
#define WGL_DRAW_TO_WINDOW_ARB             0x2001
#define WGL_SUPPORT_OPENGL_ARB             0x2010
#define WGL_DOUBLE_BUFFER_ARB              0x2011
#define WGL_PIXEL_TYPE_ARB                 0x2013
#define WGL_TYPE_RGBA_ARB                  0x202B
#define WGL_COLOR_BITS_ARB                 0x2014
#define WGL_RED_BITS_ARB                   0x2015
#define WGL_GREEN_BITS_ARB                 0x2017
#define WGL_BLUE_BITS_ARB                  0x2019
#define WGL_ALPHA_BITS_ARB                 0x201B
#define WGL_DEPTH_BITS_ARB                 0x2022
#define WGL_STENCIL_BITS_ARB               0x2023
#endif

// WGL_ARB_create_context
#ifndef WGL_ARB_create_context
#define WGL_ARB_create_context 1
#define WGL_CONTEXT_MAJOR_VERSION_ARB      0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB      0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB        0x2093
#define WGL_CONTEXT_FLAGS_ARB              0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB       0x9126
#endif

// WGL_CONTEXT_PROFILE_MASK_ARB values
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB   0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002

// WGL_CONTEXT_FLAGS_ARB bits
#define WGL_CONTEXT_DEBUG_BIT_ARB          0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002

// WGL extension function pointer types
typedef HGLRC (WINAPI *PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC hDC, HGLRC hShareContext, const int *attribList);
typedef BOOL (WINAPI *PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList,
                                                      UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
typedef const char *(WINAPI *PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC hdc);

// Function pointers
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = nullptr;


#endif //NIJIEMU_DEFINES_H
