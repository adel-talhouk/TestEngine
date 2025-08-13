// STL includes
#include <iostream>

// Common includes
#include <Common/Defines.h>

// Engine includes
#include <CoreLib/Rendering/WindowRenderer.h>
#include <CoreLib/String/String.h>
#include <CoreLib/Thread/Thread.h>

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