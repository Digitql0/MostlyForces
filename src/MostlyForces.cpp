#include "MostlyForces.hpp"

float MF_clampValue(float value, float min, float max) {
  if (value <= min) return min;
  if (value >= max) return max;
  return value;
}

bool MF_checkCollisionPointInBox(MF_vec2 point, MF_rectangle box) {
  bool xOverlap = point.x > box.x && point.x < box.x + box.w;
  bool yOverlap = point.y > box.y && point.y < box.y + box.h;
  return xOverlap && yOverlap;
}

float MF_getMagnitude(MF_vec2 vec) {
  return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

float MF_getDistance(MF_vec2 p1, MF_vec2 p2) {
  MF_vec2 distanceArrow;
  distanceArrow.x = p2.x - p1.x;
  distanceArrow.y = p2.y - p1.y;

  return MF_getMagnitude(distanceArrow);
}

bool MF_checkCollisionCircles(MF_circle c1, MF_circle c2) {
  return MF_getDistance((MF_vec2){c1.x, c1.y}, (MF_vec2){c2.x, c2.y}) <
         c1.r + c2.r;
}

bool MF_checkCollisionRectangles(MF_rectangle r1, MF_rectangle r2) {
  bool xOverlap = r1.x + r1.w > r2.x && r1.x < r2.x + r2.w;
  bool yOverlap = r1.y + r1.h > r2.y && r1.y < r2.y + r2.h;

  return xOverlap && yOverlap;
}

bool MF_checkCollisionPointInCircle(MF_vec2 point, MF_circle c) {
  return MF_getDistance(point, (MF_vec2){c.x, c.y}) < c.r;
}

bool MF_checkCollisionCircleInRectangle(MF_circle c, MF_rectangle r) {
  float closestX = MF_clampValue(c.x, r.x, r.x + r.w);
  float closestY = MF_clampValue(c.y, r.y, r.y + r.h);

  return MF_checkCollisionPointInCircle((MF_vec2){closestX, closestY}, c);
}

MF_vec2 MF_getSubtractedVec(MF_vec2 a, MF_vec2 b) {
  return (MF_vec2){a.x - b.x, a.y - b.y};
}

MF_vec2 MF_getAddedVec(MF_vec2 a, MF_vec2 b) {
  return (MF_vec2){a.x + b.x, a.y + b.y};
}

MF_vec2 MF_getScaledVec(MF_vec2 vec, float scalar) {
  if (scalar == 0.0f) return (MF_vec2){0.0f, 0.0f};
  return (MF_vec2){vec.x * scalar, vec.y * scalar};
}

MF_vec2 MF_getNormalizedVec(MF_vec2 vec) {
  return MF_getScaledVec(vec, 1 / MF_getMagnitude(vec));
}

MF_vec2 MF_getZeroVec2() { return (MF_vec2){0, 0}; }

MF_vec3 MF_getZeroVec3() { return (MF_vec3){0, 0, 0}; }

void MF_responseCollisionCircles(MF_circle c1, MF_circle c2, MF_vec2& v1,
                                 MF_vec2& v2) {
  auto m1 = MF_getMagnitude(v1);
  auto m2 = MF_getMagnitude(v2);

  auto p1 = (MF_vec2){c1.x, c1.y};
  auto p2 = (MF_vec2){c2.x, c2.y};

  v1 = MF_getScaledVec(MF_getNormalizedVec(MF_getSubtractedVec(p1, p2)), m1);
  v2 = MF_getScaledVec(MF_getNormalizedVec(MF_getSubtractedVec(p2, p1)), m2);
}
