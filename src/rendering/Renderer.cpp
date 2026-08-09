#include "Renderer.h"
#include "../physics/Body.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Renderer::Renderer(int width, int height, const char* title) : camera(width, height), font(nullptr)
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

    if (TTF_Init() != 0)
    {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << '\n';
    }

    font = TTF_OpenFont(
        "/System/Library/Fonts/Helvetica.ttc",
        18
    );

    if (font == nullptr) {
        std::cerr << "TTF_OpenFont Error: "
                  << TTF_GetError() << '\n';
    }

}


//Destructor
Renderer::~Renderer()
{
    if (font != nullptr)
        TTF_CloseFont(font);

    TTF_Quit();

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

//Camera

Camera& Renderer::getCamera() {
    return camera;
}


void Renderer::drawBody(const Body& body)
{
    double screenX = camera.worldToScreenX(body.getX());
    double screenY = camera.worldToScreenY(body.getY());

    double screenRadius = camera.worldToScreenRadius(body.getRadius());

    int x = static_cast<int>(screenX);
    int y = static_cast<int>(screenY);
    int radius = static_cast<int>(screenRadius);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect rect{
        x - radius,
        y - radius,
        radius * 2,
        radius * 2
    };

    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::drawDebugInfo()
{

    if (font == nullptr)
        return;

    std::ostringstream zoomText;
    zoomText << std::scientific << std::setprecision(2)
             << "Zoom: "
             << camera.getMetresPerPixel()
             << " m/pixel";

    std::ostringstream scaleText;
    scaleText << std::fixed << std::setprecision(1)
              << "Visual Scale: "
              << camera.getVisualScale()
              << "x";

    SDL_Color white = {255, 255, 255, 255};

    SDL_Surface* zoomSurface = TTF_RenderText_Blended(
        font,
        zoomText.str().c_str(),
        white
    );

    SDL_Surface* scaleSurface = TTF_RenderText_Blended(
        font,
        scaleText.str().c_str(),
        white
    );

    if (zoomSurface == nullptr || scaleSurface == nullptr)
    {
        if (zoomSurface)
            SDL_FreeSurface(zoomSurface);

        if (scaleSurface)
            SDL_FreeSurface(scaleSurface);

        return;
    }

    SDL_Texture* zoomTexture =
        SDL_CreateTextureFromSurface(renderer, zoomSurface);

    SDL_Texture* scaleTexture =
        SDL_CreateTextureFromSurface(renderer, scaleSurface);

    SDL_Rect zoomRect{
        10,
        10,
        zoomSurface->w,
        zoomSurface->h
    };

    SDL_Rect scaleRect{
        10,
        10 + zoomSurface->h + 5,
        scaleSurface->w,
        scaleSurface->h
    };

    SDL_RenderCopy(renderer, zoomTexture, nullptr, &zoomRect);
    SDL_RenderCopy(renderer, scaleTexture, nullptr, &scaleRect);

    SDL_DestroyTexture(zoomTexture);
    SDL_DestroyTexture(scaleTexture);

    SDL_FreeSurface(zoomSurface);
    SDL_FreeSurface(scaleSurface);
}


