#ifndef PARTICLES_GRAPHICS_H
#define PARTICLES_GRAPHICS_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics {
public:
    Graphics();
    ~Graphics();

    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha);
    void drawPixel(int x, int y);
    void flip();
    void clear();

    SDL_Renderer* getRenderer() const;
    SDL_Window* getWindow() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    std::map<std::string, SDL_Surface*> spriteSheets;
};

#endif //PARTICLES_GRAPHICS_H
