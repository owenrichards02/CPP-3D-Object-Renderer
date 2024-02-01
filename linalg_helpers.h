#ifndef linalg_helpers
#define linalg_helpers
#include <vector>
#include "shape_structs.h"
#include <math.h>

//declarations
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

Matrix33 matrixMult44(Matrix33 m1, Matrix33 m2);
Matrix33 matrixMult33(Matrix33 m1, Matrix33 m2);
Matrix22 matrixMult22 (Matrix22 m1, Matrix22 m2);


//definitions
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

Matrix44 matrixMult44(Matrix44 m1, Matrix44 m2){

    Matrix44 m3 = {
        (m1.get(0,0) * m2.get(0,0) + m1.get(1,0) * m2.get(0,1) + m1.get(2,0) * m2.get(0,2) + m1.get(3,0) * m2.get(0,3)),   (m1.get(0,0) * m2.get(1,0) + m1.get(1,0) * m2.get(1,1) + m1.get(2,0) * m2.get(1,2) + m1.get(3,0) * m2.get(1,3)),    (m1.get(0,0) * m2.get(2,0) + m1.get(1,0) * m2.get(2,1) + m1.get(2,0) * m2.get(2,2) + m1.get(3,0) * m2.get(2,3)),    (m1.get(0,0) * m2.get(3,0) + m1.get(1,0) * m2.get(3,1) + m1.get(2,0) * m2.get(3,2) + m1.get(3,0) * m2.get(3,3)),  
        (m1.get(0,1) * m2.get(0,0) + m1.get(1,1) * m2.get(0,1) + m1.get(2,1) * m2.get(0,2) + m1.get(3,1) * m2.get(0,3)),   (m1.get(0,1) * m2.get(1,0) + m1.get(1,1) * m2.get(1,1) + m1.get(2,1) * m2.get(1,2) + m1.get(3,1) * m2.get(1,3)),    (m1.get(0,1) * m2.get(2,0) + m1.get(1,1) * m2.get(2,1) + m1.get(2,1) * m2.get(2,2) + m1.get(3,1) * m2.get(2,3)),    (m1.get(0,1) * m2.get(3,0) + m1.get(1,1) * m2.get(3,1) + m1.get(2,1) * m2.get(3,2) + m1.get(3,1) * m2.get(3,2)), 
        (m1.get(0,2) * m2.get(0,0) + m1.get(1,2) * m2.get(0,1) + m1.get(2,2) * m2.get(0,2) + m1.get(3,2) * m2.get(0,3)),   (m1.get(0,2) * m2.get(1,0) + m1.get(1,2) * m2.get(1,1) + m1.get(2,2) * m2.get(1,2) + m1.get(3,2) * m2.get(1,3)),    (m1.get(0,2) * m2.get(2,0) + m1.get(1,2) * m2.get(2,1) + m1.get(2,2) * m2.get(2,2) + m1.get(3,2) * m2.get(2,3)),    (m1.get(0,2) * m2.get(3,0) + m1.get(1,2) * m2.get(3,1) + m1.get(2,2) * m2.get(3,2) + m1.get(3,2) * m2.get(3,3)),
        (m1.get(0,3) * m2.get(0,0) + m1.get(1,3) * m2.get(0,1) + m1.get(2,3) * m2.get(0,2) + m1.get(3,3) * m2.get(0,3)),   (m1.get(0,3) * m2.get(1,0) + m1.get(1,3) * m2.get(1,1) + m1.get(2,3) * m2.get(1,2) + m1.get(3,3) * m2.get(1,3)),    (m1.get(0,3) * m2.get(2,0) + m1.get(1,3) * m2.get(2,1) + m1.get(2,3) * m2.get(2,2) + m1.get(3,3) * m2.get(2,3)),    (m1.get(0,3) * m2.get(3,0) + m1.get(1,3) * m2.get(3,1) + m1.get(2,3) * m2.get(3,2) + m1.get(3,3) * m2.get(3,3))

    };
    return m3;
}


/*  4x4 Matrix test

    Matrix44 M1 = {2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2};
    Matrix44 M2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    Matrix44 M3 = matrixMult44(M1, M2);

    std::cout << "M1: " << M1.get(0,0) << ", " << M1.get(1,0) << ", " << M1.get(2,0) << ", " << M1.get(3,0)
            << ", " << M1.get(0,1) << ", " << M1.get(1,1) << ", " << M1.get(2,1) << ", " << M1.get(3,1)
            << ", " << M1.get(0,2) << ", " << M1.get(1,2) << ", " << M1.get(2,2) << ", " << M1.get(3,2)
            << ", " << M1.get(0,3) << ", " << M1.get(1,3) << ", " << M1.get(2,3) << ", " << M1.get(3,3) << '\n';

    std::cout << "M2: " << M2.get(0,0) << ", " << M2.get(1,0) << ", " << M2.get(2,0) << ", " << M2.get(3,0)
            << ", " << M2.get(0,1) << ", " << M2.get(1,1) << ", " << M2.get(2,1) << ", " << M2.get(3,1)
            << ", " << M2.get(0,2) << ", " << M2.get(1,2) << ", " << M2.get(2,2) << ", " << M2.get(3,2)
            << ", " << M2.get(0,3) << ", " << M2.get(1,3) << ", " << M2.get(2,3) << ", " << M2.get(3,3) << '\n';

    std::cout << "M3: " << M3.get(0,0) << ", " << M3.get(1,0) << ", " << M3.get(2,0) << ", " << M3.get(3,0)
            << ", " << M3.get(0,1) << ", " << M3.get(1,1) << ", " << M3.get(2,1) << ", " << M3.get(3,1)
            << ", " << M3.get(0,2) << ", " << M3.get(1,2) << ", " << M3.get(2,2) << ", " << M3.get(3,2)
            << ", " << M3.get(0,3) << ", " << M3.get(1,3) << ", " << M3.get(2,3) << ", " << M3.get(3,3) << '\n'; */


Matrix33 matrixMult33(Matrix33 m1, Matrix33 m2){

    Matrix33 m3 = {
        (m1.get(0,0) * m2.get(0,0) + m1.get(1,0) * m2.get(0,1) + m1.get(2,0) * m2.get(0,2)),   (m1.get(0,0) * m2.get(1,0) + m1.get(1,0) * m2.get(1,1) + m1.get(2,0) * m2.get(1,2)),   (m1.get(0,0) * m2.get(2,0) + m1.get(1,0) * m2.get(2,1) + m1.get(2,0) * m2.get(2,2)),
        (m1.get(0,1) * m2.get(0,0) + m1.get(1,1) * m2.get(0,1) + m1.get(2,1) * m2.get(0,2)),   (m1.get(0,1) * m2.get(1,0) + m1.get(1,1) * m2.get(1,1) + m1.get(2,1) * m2.get(1,2)),   (m1.get(0,1) * m2.get(2,0) + m1.get(1,1) * m2.get(2,1) + m1.get(2,1) * m2.get(2,2)),
        (m1.get(0,2) * m2.get(0,0) + m1.get(1,2) * m2.get(0,1) + m1.get(2,2) * m2.get(0,2)),   (m1.get(0,2) * m2.get(1,0) + m1.get(1,2) * m2.get(1,1) + m1.get(2,2) * m2.get(1,2)),   (m1.get(0,2) * m2.get(2,0) + m1.get(1,2) * m2.get(2,1) + m1.get(2,2) * m2.get(2,2)),
    };
    return m3;
}

/* //3x3 matrix test

    Matrix33 M1 = {2,0,0,0,2,0,0,0,2};
    Matrix33 M2 = {1,2,3,4,5,6,7,8,9};
    Matrix33 M3 = matrixMult33(M1, M2);
    
    std::cout << "M1: " << M1.get(0,0) << M1.get(1,0) << M1.get(2,0) << M1.get(0,1) << M1.get(1,1) << M1.get(2,1) << M1.get(0,2) << M1.get(1,2) << M1.get(2,2) << '\n';
    std::cout << "M2: " << M2.get(0,0) << M2.get(1,0) << M2.get(2,0) << M2.get(0,1) << M2.get(1,1) << M2.get(2,1) << M2.get(0,2) << M2.get(1,2) << M2.get(2,2) << '\n';
    std::cout << "M3: " << M3.get(0,0) << M3.get(1,0) << M3.get(2,0) << M3.get(0,1) << M3.get(1,1) << M3.get(2,1) << M3.get(0,2) << M3.get(1,2) << M3.get(2,2) << '\n'; */


Matrix22 matrixMult22 (Matrix22 m1, Matrix22 m2){
    Matrix22 m3 = {
        (m1.get(0,0) * m2.get(0,0) + m1.get(1,0) * m2.get(0,1)), (m1.get(0,0) * m2.get(1,0) + m1.get(1,0) * m2.get(1,1)),
        (m1.get(0,1) * m2.get(0,0) + m1.get(1,1) * m2.get(0,1)), (m1.get(0,1) * m2.get(1,0) + m1.get(1,1) * m2.get(1,1))
    };
    return m3;
}


   /* 2x2 matrix test

    Matrix22 newM = {2,0,0,2};
    Matrix22 newM2 = {1,2,3,4};
    Matrix22 m3 = matrixMult22(newM, newM2);
    
    std::cout << "m3: " << m3.get(0,0) << m3.get(1,0) << m3.get(0,1) << m3.get(1,1);
    std::cout << "newM2: " << newM2.get(0,0) << newM2.get(1,0) << newM2.get(0,1) << newM2.get(1,1); */

#endif