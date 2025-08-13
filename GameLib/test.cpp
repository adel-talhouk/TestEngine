// STL includes
#include <iostream>

// Common includes
#include <Defines.h>

// Engine includes
#include <Rendering/WindowRenderer.h>
#include <String/String.h>
#include <Thread/Thread.h>

int main()
{
    WindowRenderer renderer;
    Thread renderer_thread(IF_DEBUG(String("Renderer")));

    renderer.Init();
    static bool sShouldRun = true;

    while (sShouldRun)
    {
        renderer.Update();
    }

    renderer.Shutdown();

    std::cin.get();
}