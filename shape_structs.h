#ifndef shape_structs
#define shape_structs

#include <vector>


struct Point2D      {float x, y;};
struct Point3D      {float x, y, z;} ;
struct Vector2D     {float x, y;};
struct Vector3D     {float x, y, z;} ;
struct Edge2D       {Point2D p1, p2;};
struct Edge3D       {Point3D p1, p2;};
struct Shape3D      {std::vector<Point3D> verts; std::vector<Edge3D> edges;};

struct Matrix44
{
    float m[4][4] = {};

    float get(int col, int row){
        return m[row][col];
    };

    void set(int col, int row, float val){
        m[row][col] = val;
    };
};

struct Matrix33
{
    float m[3][3] = {};

    float get(int col, int row){
        return m[row][col];
    };

    void set(int col, int row, float val){
        m[row][col] = val;
    };
};


struct Matrix22 {       
    float m[2][2] = {};

    float get(int col, int row){
        return m[row][col];
    };

    void set(int col, int row, float val){
        m[row][col] = val;
    };
};



#endif