#ifndef PARTICLES_APP_H
#define PARTICLES_APP_H

#include <vector>

class Graphics;
class Input;
class Particle;

class App {
public:
    App();
    ~App();

private:
    void appLoop();

    void update(Graphics &graphics, Input &input, int elapsedTime);
    void draw(Graphics &graphics);

    std::vector<std::vector<Particle*>> particles;
};

#endif //PARTICLES_APP_H
