#include <SDL2/SDL.h>
#include <iostream>
#include <array>

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
    //set black backg with green pen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    //draw box from just lines 
    int vertexMatrix[4][2] = {{50,50}, {50,100}, {100,50}, {100,100}};
    int edgesList[4][2] = {{0,1}, {0,2}, {1,3}, {2,3}};

    for (int i = 0; i < sizeof(edgesList) / sizeof(int) / 2; i++){
        //draws edge i
        int x1 = vertexMatrix[edgesList[i][0]][0];
        int y1 = vertexMatrix[edgesList[i][0]][1];
        int x2 = vertexMatrix[edgesList[i][1]][0];
        int y2 = vertexMatrix[edgesList[i][1]][1];
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

        std::cout << "[DRAWING] (" << x1 << "," << x2 << "), (" << y1 << "," << y2 << ")'\n'";
    }

    SDL_RenderPresent(renderer);
}

