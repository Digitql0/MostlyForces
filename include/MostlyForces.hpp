#ifndef MOSTLYFORCES_HPP
#define MOSTLYFORCES_HPP

#include <cmath>

typedef struct {
    float x;
    float y;
    float w;
    float h;
} MF_rectangle;

typedef struct {
    float x;
    float y;
    float r;
} MF_circle;

typedef struct {
    float x1;
    float y1;
    float x2;
    float y2;
} MF_line;

typedef struct {
    float x;
    float y;
} MF_vec2;

typedef struct {
    float x;
    float y;
    float z;
} MF_vec3;

//Utitlity
float clampValue (float value, float min, float max);

//Vector Math
float MF_getMagnitude(MF_vec2 vec);
float MF_getDistance(MF_vec2 p1, MF_vec2 p2);
MF_vec2 MF_getZerovec2();
MF_vec3 MF_getZeroVec3();
MF_vec2 MF_getSubtractedVec(MF_vec2 a, MF_vec2 b);
MF_vec2 MF_getAddedVec(MF_vec2 a, MF_vec2 b);
MF_vec2 MF_getScaledVec(MF_vec2 vec, float scalar);
MF_vec2 MF_getNormalizedVec(MF_vec2 vec);

//Collision Detection
bool MF_checkCollisionPointInBox(MF_vec2 point, MF_rectangle box);
bool MF_checkCollisionCircles(MF_circle c1, MF_circle c2);
bool MF_checkCollisionRectangles(MF_rectangle r1, MF_rectangle r2);
bool MF_checkCollisionPointInCircle(MF_vec2 point, MF_circle c);
bool MF_checkCollisionCircleInRectangle(MF_circle c, MF_rectangle r);

//Collision Response
void MF_responseCollisionCircles(MF_circle c1, MF_circle c2, MF_vec2& v1, MF_vec2& v2);

#endif
