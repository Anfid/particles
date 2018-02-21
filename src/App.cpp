#include "SDL.h"

#include "globals.h"
#include "Graphics.h"
#include "Input.h"
#include "App.h"
#include "Particle.h"

namespace {
    const int FPS = 100;
    const int TIME_TO_UPDATE = 1000 / FPS;
}

App::App() {
    for (int x = 0; x < globals::FIELD_WIDTH; ++x) {
        this->particles.push_back(std::vector<Particle*>());
        for (int y = 0; y < globals::FIELD_HEIGHT; ++y) {
            this->particles[x].push_back(new Particle(x * 3, y * 3));
        }
    }

    this->appLoop();
}

App::~App() {
    for (int x = 0; x < globals::FIELD_WIDTH; ++x) {
        for (int y = 0; y < globals::FIELD_HEIGHT; ++y) {
            delete particles[x][y];
        }
    }
    this->particles.clear();
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
    static int timeSinceFrame;
    timeSinceFrame += elapsedTime;
    if (timeSinceFrame >= TIME_TO_UPDATE) {
        for (auto row : particles) {
            for (auto particle : row) {
                particle->update(input);
            }
        }
        this->draw(graphics);

        timeSinceFrame -= TIME_TO_UPDATE;
    }
}

void App::draw(Graphics &graphics) {
    SDL_SetRenderDrawColor(graphics.getRenderer(), 0, 0, 0, 0);
    graphics.clear();

    graphics.setColor(200, 200, 200, 255);
    for (auto row : particles) {
        for (auto particle : row) {
            particle->draw(graphics);
        }
    }

    graphics.flip();
    graphics.clear();
}
