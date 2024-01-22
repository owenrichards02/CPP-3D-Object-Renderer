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
    //unit cube example
    std::vector<Point3D> shapeVerts = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1}}; 
    std::vector<Edge3D> shapeEdges = {{shapeVerts[0], shapeVerts[1]}, {shapeVerts[0], shapeVerts[3]}, {shapeVerts[0], shapeVerts[4]}, {shapeVerts[1], shapeVerts[2]}, {shapeVerts[1], shapeVerts[5]}, {shapeVerts[2], shapeVerts[3]}, {shapeVerts[2], shapeVerts[6]}, {shapeVerts[3], shapeVerts[7]}, {shapeVerts[4], shapeVerts[5]}, {shapeVerts[4], shapeVerts[7]}, {shapeVerts[5], shapeVerts[6]}, {shapeVerts[6], shapeVerts[7]}};
    Shape3D _shape = {shapeVerts, shapeEdges};

    render_this(renderer, _shape);

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



