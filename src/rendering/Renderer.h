#pragma once

#include <SDL.h>

class Renderer
{
public:
    Renderer(int width, int height, const char* title);
    ~Renderer();

    void clear();
    void present();

    SDL_Renderer* getSDLRenderer();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};