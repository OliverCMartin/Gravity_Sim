#pragma once

#include <SDL.h>
#include "Camera.h"
#include <SDL_ttf.h>
#include <string>

class Body;

class Renderer
{
public:
    Renderer(int width, int height, const char* title);
    ~Renderer();

    void clear();
    void present();

    void drawBody(const Body& body);

    void drawDebugInfo();

    Camera& getCamera();

    SDL_Renderer* getSDLRenderer();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    Camera camera;

    TTF_Font* font;
};



