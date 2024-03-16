#ifndef Game_hpp
#define Game_hpp
#include "SDL2/SDL.h"
#include  "SDL2/SDL_image.h"
#include <iostream>

class Game
{
private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    void movePlayer(SDL_Event event);

    bool running(){return isRunning;}
};

#endif
