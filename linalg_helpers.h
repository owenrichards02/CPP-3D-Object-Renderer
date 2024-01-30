#ifndef linalg_helpers
#define linalg_helpers
#include <vector>
#include "shape_structs.h"
#include <math.h>

float dotProd3D(Vector3D v1, Vector3D v2);
float dotProd2D(Vector2D v1, Vector2D v2);

float magnitude3D(Vector3D v);
float magnitude2D(Vector2D v);

float angleBetweenVecs2D(Vector2D v1, Vector2D v2);  //radians
float angleBetweenVecs3D(Vector3D v1, Vector3D v2);  //radians

float crossProd2D(Vector2D v1, Vector2D v2);
Vector3D crossProd3d(Vector3D v1, Vector3D v2);

Vector3D euclid_normalise3D(Vector3D v);
Vector2D euclid_normalise2D(Vector2D v);

Vector3D addVecs3D(Vector3D v1, Vector3D v2);
Vector3D subVecs3D(Vector3D v1, Vector3D v2);
Vector2D addVecs2D(Vector2D v1, Vector2D v2);
Vector2D subVecs2D(Vector2D v1, Vector2D v2);

float dotProd2D(Vector2D v1, Vector2D v2){
    return (v1.x * v2.x) + (v1.y * v2.y);
}

float dotProd3D(Vector3D v1, Vector3D v2){
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float magnitude3D(Vector3D v){
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) );
}

float magnitude2D(Vector2D v){
    return sqrt(pow(v.x, 2) + pow(v.y, 2) );
}

float angleBetweenVecs2D(Vector2D v1, Vector2D v2){
    float arg = dotProd2D(v1, v2) / (magnitude2D(v1) * magnitude2D(v2));
    return acos(arg);
}

float angleBetweenVecs3D(Vector3D v1, Vector3D v2){
    float arg = dotProd3D(v1, v2) / (magnitude3D(v1) * magnitude3D(v2));
    return acos(arg);
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

float crossProd2D(Vector2D v1, Vector2D v2){
    return v1.x * v2.y - v2.x * v1.y;
}

Vector3D crossProd3D(Vector3D v1, Vector3D v2){
    //basically the 3x3 determinant
    return {(v1.y * v2.z) - (v1.z * v2.y), (v1.z * v2.x) - (v1.x * v2.z), (v1.x * v2.y) - (v1.y * v2.x)};
}

Vector3D addVecs3D(Vector3D v1, Vector3D v2){
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

Vector3D subVecs3D(Vector3D v1, Vector3D v2){
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

Vector2D addVecs2D(Vector2D v1, Vector2D v2){
    return {v1.x + v2.x, v1.y + v2.y};
}

Vector2D subVecs2D(Vector2D v1, Vector2D v2){
    return {v1.x - v2.x, v1.y - v2.y};
}

#endif