#include "SDL.h"

#include "Graphics.h"
#include "Input.h"
#include "App.h"

namespace {
    const int FPS = 100;
    const int TIME_TO_UPDATE = 1000 / FPS;
}

App::App() {
    this->appLoop();
}

App::~App() {

}

void App::appLoop() {
    SDL_Event event;
    Graphics graphics;
    Input input;

    int LAST_UPDATE_TIME = SDL_GetTicks();
    while (true) {
        input.beginNewFrame(event);

        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
            break;
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(graphics, input, ELAPSED_TIME_MS);
        LAST_UPDATE_TIME = CURRENT_TIME_MS;
    }
}

void App::update(Graphics &graphics, Input &input, int elapsedTime) {
    if (elapsedTime > TIME_TO_UPDATE) {
        this->draw();
    }
}

void App::draw() {

}
