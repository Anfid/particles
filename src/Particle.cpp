#include "Particle.h"

#include <cmath>

#include "Graphics.h"
#include "Input.h"

Particle::Particle(int x, int y) :
    origin{x, y},
    position{x, y},
    vector{0, 0}
{}

void Particle::update(Input &input) {
    int distanceToPointer = this->getDistance(input.getMousePos());
    if (distanceToPointer < 40) {
        this->vector.x += (this->position.x - input.getMousePos()->x) * (40 - distanceToPointer) / 7;
        this->vector.y += (this->position.y - input.getMousePos()->y) * (40 - distanceToPointer) / 7;
    }
    if (this->position.x != this->origin.x || this->position.y != this->origin.y) {
        this->vector.x -= (this->position.x - this->origin.x) / 5;
        this->vector.y -= (this->position.y - this->origin.y) / 5;
    }
    this->vector.x *= 0.1;
    this->vector.y *= 0.1;
    this->position.x += this->vector.x;
    this->position.y += this->vector.y;

}

void Particle::draw(Graphics &graphics) {
    graphics.drawPixel(lroundf(this->position.x), lroundf(this->position.y));
}

int Particle::getDistance(const SDL_Point *point) const {
    return (int)std::sqrt(std::pow(std::abs(this->position.x - point->x), 2) +
                          std::pow(std::abs(this->position.y - point->y), 2));
}
