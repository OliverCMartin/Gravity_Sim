#include "rendering/Renderer.h"

int main()
{
    Renderer renderer(1280, 720, "Gravity Simulator");

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;

            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
        }

        renderer.clear();

        // Draw simulation here

        renderer.present();
    }

    return 0;
}