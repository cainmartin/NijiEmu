#include <iostream>
#include "src/Application.h"

int main()
{
    std::cout << "Initializing Niji Emu - The ZX Spectrum emulator" << std::endl;

    Application app;
    if (app.Initialize())
    {
        app.Run();
    }

    return 0;
}
