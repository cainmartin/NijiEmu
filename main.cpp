#include <iostream>
#include "src/Application.h"

int main()
{
    std::cout << "Initializing Niji Emu - The ZX Spectrum emulator" << std::endl;

    Application app;

    try
    {
        app.Initialize();
    }
    catch(const std::runtime_error& ex)
    {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    app.Run();

    return EXIT_SUCCESS;
}
