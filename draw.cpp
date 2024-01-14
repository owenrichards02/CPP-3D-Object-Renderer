#include <SDL2/SDL.h>
#include <iostream>

void draw(SDL_Window* window, SDL_Renderer* renderer);

int main(int argc, char** argv){
    
    SDL_Window* window;
    SDL_Renderer* renderer;

    bool active = true;
    SDL_Event currentEvent;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        // returns -1 --> video error
        std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
    else
    {
        SDL_CreateWindowAndRenderer(1920, 1080, 0, &window, &renderer); 
    }
    
    draw(window, renderer);
    

    while (active)
    {
        SDL_WaitEvent(&currentEvent);
 
        switch (currentEvent.type)
        {
            case SDL_QUIT:
                active = false;
                break;
        }
    }
 
    SDL_Quit();

    return 0;
}

void draw(SDL_Window* window, SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}