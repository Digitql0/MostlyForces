#ifndef MOSTLYFORCES_HPP
#define MOSTLYFORCES_HPP

#include <cmath>

typedef struct {
    float x;
    float y;
    float w;
    float h;
} Rectangle;

typedef struct {
    float x;
    float y;
    float r;
} Circle;

typedef struct {
    float x1;
    float y1;
    float x2;
    float y2;
} Line;

typedef struct {
    float x;
    float y;
} Vec2;

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

//Utitlity
float clampValue (float value, float min, float max);

//Vector Math
float getMagnitude(Vec2 vec);
float getDistance(Vec2 p1, Vec2 p2);
Vec2 getZeroVec2();
Vec3 getZeroVec3();
Vec2 getSubtractedVec(Vec2 a, Vec2 b);
Vec2 getAddedVec(Vec2 a, Vec2 b);
Vec2 getScaledVec(Vec2 vec, float scalar);
Vec2 getNormalizedVec(Vec2 vec);

//Collision Detection
bool CheckCollisionPointInBox(Vec2 point, Rectangle box);
bool CheckCollisionCircles(Circle c1, Circle c2);
bool CheckCollisionRectangles(Rectangle r1, Rectangle r2);
bool CheckCollisionPointInCircle(Vec2 point, Circle c);
bool CheckCollisionCircleInRectangle(Circle c, Rectangle r);

//Collision Response
void ResponseCollisionCircles(Circle c1, Circle c2, Vec2& v1, Vec2& v2);

#endif
