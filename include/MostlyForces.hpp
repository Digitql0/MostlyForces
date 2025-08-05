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
float getMagnitude(MF_vec2 vec);
float getDistance(MF_vec2 p1, MF_vec2 p2);
MF_vec2 getZerovec2();
MF_vec3 getZeroVec3();
MF_vec2 getSubtractedVec(MF_vec2 a, MF_vec2 b);
MF_vec2 getAddedVec(MF_vec2 a, MF_vec2 b);
MF_vec2 getScaledVec(MF_vec2 vec, float scalar);
MF_vec2 getNormalizedVec(MF_vec2 vec);

//Collision Detection
bool CheckCollisionPointInBox(MF_vec2 point, MF_rectangle box);
bool CheckCollisionCircles(MF_circle c1, MF_circle c2);
bool CheckCollisionRectangles(MF_rectangle r1, MF_rectangle r2);
bool CheckCollisionPointInCircle(MF_vec2 point, MF_circle c);
bool CheckCollisionCircleInRectangle(MF_circle c, MF_rectangle r);

//Collision Response
void ResponseCollisionCircles(MF_circle c1, MF_circle c2, MF_vec2& v1, MF_vec2& v2);

#endif
