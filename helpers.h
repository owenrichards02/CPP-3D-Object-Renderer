#ifndef helpers
#define helpers
#include <vector>
#include "shape_structs.h"
#include <math.h>

float dotProd3D(Vector3D v1, Vector3D v2);
float dotProd2D(Vector2D v1, Vector2D v2);

Vector3D euclid_normalise3D(Vector3D v);
Vector2D euclid_normalise2D(Vector2D v);

float magnitude3D(Vector3D v);
float magnitude2D(Vector2D v);

float dotProd2D(Vector2D v1, Vector2D v2){
    return (v1.x * v2.x) + (v1.y * v2.y);
}

float dotProd3D(Vector3D v1, Vector3D v2){
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector3D euclid_normalise3D(Vector3D v){
    float m = magnitude3D(v);
    v.x = v.x / m;
    v.y = v.y / m;
    v.z = v.z / m;
    return v;
}

Vector2D euclid_normalise2D(Vector2D v){
    float m = magnitude2D(v);
    v.x = v.x / m;
    v.y = v.y / m;
    return v;
}



float magnitude3D(Vector3D v){
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) );
}

float magnitude2D(Vector2D v){
    return sqrt(pow(v.x, 2) + pow(v.y, 2) );
}


#endif