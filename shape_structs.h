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
    float m00, m01, m02, m03,
        m10, m11, m12, m13,
        m20, m21, m22, m23,
        m30, m31, m32, m33;
};

struct Matrix33
{
    float m00, m01, m02,
        m10, m11, m12,
        m20, m21, m22;
};

struct Matrix22
{
    float m00, m01,
        m10, m11;
};

struct Matrix22_2 {       
    float m[2][2] = {};
    float get(int row, int col){
        return m[col][row];
    };
    float set(int row, int col, float val){
        m[col][row] = val;
    };
};



#endif