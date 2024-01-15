#include <SDL2/SDL.h>
#include <iostream>
#include <array>
#include <vector>
#include "render.h"

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

    //set black BG
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    



    //define obj here
    std::vector<Point3D> shape = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1}}; //unit cube

    render_this(renderer, shape);

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



