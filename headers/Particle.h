#ifndef PARTICLES_PARTICLE_H
#define PARTICLES_PARTICLE_H

#include <SDL_rect.h>

class Graphics;
class Input;

class Particle {
public:
    Particle() = delete;
    Particle(int x, int y);
    ~Particle() = default;

    void update(Input &input);
    void draw(Graphics &graphics);

private:
    int getDistance(const SDL_Point *point) const;

    // todo: use struct with float instead of int
    const SDL_Point origin;
    SDL_Point position;
    SDL_Point vector;

};

#endif //PARTICLES_PARTICLE_H
