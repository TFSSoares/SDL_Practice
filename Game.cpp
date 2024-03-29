#include "Game.hpp"

SDL_Texture *playerTex;
SDL_Rect srcR, destR;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;


    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems initialised"<< std::endl;

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if(window)
            std::cout << "Window created! " << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "Renderer created! " << std::endl;
        }

        isRunning = true;

        SDL_Surface *tmpSurface = IMG_Load("Images/Character.png");
        playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
        SDL_FreeSurface(tmpSurface);
    } else{
        isRunning = false;
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type){
    case SDL_QUIT:
        isRunning = false;
        break;
    
    case SDL_KEYDOWN:
        movePlayer(event);
        break;
    default:
        break;
    }

}

void Game::update()
{
    cnt = 10;
    
    destR.h = 64;
    destR.w = 64;

    //std::cout<<cnt<<std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    std::cout << "Game cleaned"<<std::endl;

}

void Game::movePlayer(SDL_Event event){
    const int movimentDistance = 10;

    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    switch (event.key.keysym.scancode)
    {
    case SDL_SCANCODE_UP:
        if( destR.y> 0){
            destR.y -= movimentDistance;
            //std::cout << destR.y<< windowHeight<<std::endl;
        }
        break;
    
    case SDL_SCANCODE_DOWN:
        if( destR.y < windowHeight-70){
            destR.y += movimentDistance;
            //std::cout << destR.y<<std::endl;
        }
        break;
    
    case SDL_SCANCODE_RIGHT:
        destR.x += movimentDistance;
        break;

    case SDL_SCANCODE_LEFT:
        destR.x -= movimentDistance;
        break;

    default:
       break;
    }

}