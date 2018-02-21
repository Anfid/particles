#include <SDL.h>

#include "Graphics.h"
#include "globals.h"

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(globals::WINDOW_WIDTH, globals::WINDOW_HEIGHT, 0, &this->window, &this->renderer);
    SDL_SetWindowTitle(this->window, "Particles");
}

Graphics::~Graphics() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}

void Graphics::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha) {
    SDL_SetRenderDrawColor(this->renderer, r, g, b, alpha);
}

void Graphics::drawPixel(int x, int y) {
    SDL_RenderDrawPoint(this->renderer, x, y);
}

void Graphics::flip() {
    SDL_RenderPresent(this->renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->renderer;
}

SDL_Window* Graphics::getWindow() const {
    return this->window;
}
