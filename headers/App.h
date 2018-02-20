#ifndef PARTICLES_APP_H
#define PARTICLES_APP_H

class App {
public:
    App();
    ~App();

private:
    void appLoop();

    void update(Graphics &graphics, Input &input, int elapsedTime);
    void draw();
};

#endif //PARTICLES_APP_H
