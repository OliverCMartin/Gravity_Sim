#include "rendering/Renderer.h"
#include "physics/Body.h"
#include "iostream"

int main()
{
    Renderer renderer(1000, 1000, "Gravity Simulator");

    Body earth(5.972e24, 6.371e6);
    earth.setPosition(1.496e11, 0);

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }

                if (event.key.keysym.sym == SDLK_EQUALS)
                {
                    renderer.getCamera().zoomIn();
                }

                if (event.key.keysym.sym == SDLK_MINUS)
                {
                    renderer.getCamera().zoomOut();
                }

                if (event.key.keysym.sym == SDLK_RIGHTBRACKET)
                {
                    renderer.getCamera().increaseVisualScale();
                }

                if (event.key.keysym.sym == SDLK_LEFTBRACKET)
                {
                    renderer.getCamera().decreaseVisualScale();
                }
            }
        }

        earth.update();

        renderer.clear();

        renderer.drawBody(earth);

        renderer.drawDebugInfo();

        renderer.present();
    }

    return 0;
}