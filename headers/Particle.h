#ifndef PARTICLES_PARTICLE_H
#define PARTICLES_PARTICLE_H

#include <SDL_rect.h>

class Graphics;
class Input;

struct FloatPoint {
    float x, y;
};

class Particle {
public:
    Particle() = delete;
    Particle(int x, int y);
    ~Particle() = default;

    void update(Input &input);
    void draw(Graphics &graphics);

private:
    int getDistance(const SDL_Point *point) const;

    const SDL_Point origin;
    FloatPoint position;
    FloatPoint vector;

};

#endif //PARTICLES_PARTICLE_H
