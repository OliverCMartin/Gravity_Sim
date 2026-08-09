#include "Renderer.h"

#include <iostream>

Renderer::Renderer(int width, int height, const char* title)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << '\n';
        return;
    }

    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: "
                  << SDL_GetError() << '\n';
        return;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == nullptr)
    {
        std::cerr << "SDL_CreateRenderer Error: "
                  << SDL_GetError() << '\n';
    }
}

Renderer::~Renderer()
{
    if (renderer != nullptr)
        SDL_DestroyRenderer(renderer);

    if (window != nullptr)
        SDL_DestroyWindow(window);

    SDL_Quit();
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::getSDLRenderer()
{
    return renderer;
}