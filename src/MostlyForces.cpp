#include "MostlyForces.hpp"

float clampValue (float value, float min, float max) {
    if (value <= min) return min;
    if (value >= max) return max;
    return value;
}

bool CheckCollisionPointInBox(Vec2 point, Rectangle box) {
    bool xOverlap = point.x > box.x && point.x < box.x + box.w;
    bool yOverlap = point.y > box.y && point.y < box.y + box.h;
    return xOverlap && yOverlap;
}

float getMagnitude(Vec2 vec) {
    return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

float getDistance(Vec2 p1, Vec2 p2) {
    Vec2 distanceArrow;
    distanceArrow.x = p2.x - p1.x;
    distanceArrow.y = p2.y - p1.y;

    return getMagnitude(distanceArrow);
}

bool CheckCollisionCircles(Circle c1, Circle c2) {
    return getDistance((Vec2){c1.x, c1.y}, (Vec2){c2.x, c2.y}) < c1.r + c2.r;
}

bool CheckCollisionRectangles(Rectangle r1, Rectangle r2) {
    bool xOverlap = r1.x + r1.w > r2.x && r1.x < r2.x + r2.w;
    bool yOverlap = r1.y + r1.h > r2.y && r1.y < r2.y + r2.h;

    return xOverlap && yOverlap;
}

bool CheckCollisionPointInCircle(Vec2 point, Circle c) {
    return getDistance(point, (Vec2){c.x, c.y}) < c.r;
}

bool CheckCollisionCircleInRectangle(Circle c, Rectangle r) {
    float closestX = clampValue(c.x, r.x, r.x + r.w);
    float closestY = clampValue(c.y, r.y, r.y + r.h);

    return CheckCollisionPointInCircle((Vec2){closestX, closestY}, c);
}

Vec2 getSubtractedVec(Vec2 a, Vec2 b) {
    return (Vec2){a.x - b.x, a.y - b.y};
}

Vec2 getAddedVec(Vec2 a, Vec2 b) {
    return (Vec2){a.x + b.x, a.y + b.y};
}

Vec2 getScaledVec(Vec2 vec, float scalar) {
    if (scalar == 0.0f) return (Vec2){0.0f, 0.0f};
    return (Vec2){vec.x * scalar, vec.y * scalar};
}

Vec2 getNormalizedVec(Vec2 vec) {
    return getScaledVec(vec, 1/getMagnitude(vec));
}

