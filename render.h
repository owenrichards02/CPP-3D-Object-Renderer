#ifndef render
#define render

#include <SDL2/SDL.h>
#include <iostream>
#include <array>
#include <vector>


struct Point2D    {float x, y;};
struct Point3D    {float x, y, z;} ;
struct Edge2D       {Point2D p1, p2;};
struct Edge3D       {Point3D p1, p2;};
struct Shape3D      {std::vector<Point3D> verts; std::vector<Edge3D> edges;};


void draw(SDL_Renderer* renderer);
void draw2DEdges(SDL_Renderer* renderer, std::vector<Edge2D> edges);

void render_this(SDL_Renderer* renderer, Shape3D _shape){
    //set green pen
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    //change this to deal with Shape
    std::vector<Edge2D> _2D_edges = {{50, 50, 50, 100}, {50, 50, 100, 50}};
    draw2DEdges(renderer, _2D_edges);
}


void draw2DEdges(SDL_Renderer* renderer, std::vector<Edge2D> edges){
    for (Edge2D i : edges){
        SDL_RenderDrawLine(renderer, i.p1.x, i.p1.y, i.p2.x, i.p2.y);
    }
    SDL_RenderPresent(renderer);
}

//2D test function
void draw(SDL_Renderer* renderer){

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



#endif