#pragma once

#include "core/assert.h"

template<typename T>
struct Vector2D
{
    T x, y;
    Vector2D() : x(0), y(0) {}
    Vector2D(T a, T b) : x(a), y(b) {}
    inline T& operator [](int i) { LUNAR_ASSERT(i < 2, "Invalid index"); return (&x)[i]; }
    inline const T& operator [](int i) const { LUNAR_ASSERT(i < 2, "Invalid index"); return (&x)[i]; }
    inline bool operator == (const Vector2D& v) const { return (x == v.x) && (y == v.y); }
    inline bool operator != (const Vector2D& v) const { return (x != v.x) || (y != v.y); }
};

template<typename T>
struct Vector3D
{
    T x, y, z;
    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(T a, T b, T c) : x(a), y(b), z(c) {}
};

using vec2 = Vector2D<float>;
using ivec2 = Vector2D<int>;

using vec3 = Vector3D<float>;
using ivec3 = Vector3D<int>;