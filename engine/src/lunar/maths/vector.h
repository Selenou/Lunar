#pragma once

template<typename T>
struct Vector2D
{
    T x, y;
    Vector2D() : x(0), y(0) {}
    Vector2D(T x, T y) : x(x), y(y) {}
    inline bool operator == (const Vector2D& v) const { return (x == v.x) && (y == v.y); }
    inline bool operator != (const Vector2D& v) const { return (x != v.x) || (y != v.y); }
};

template<typename T>
struct Vector3D
{
    T x, y, z;
    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}
};

template<typename T>
struct Vector4D
{
    union
    {
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
    };
    Vector4D() : x(0), y(0), z(0), w(0) {}
    Vector4D(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
};

using vec2 = Vector2D<float>;
using ivec2 = Vector2D<int>;

using vec3 = Vector3D<float>;
using ivec3 = Vector3D<int>;

using vec4 = Vector4D<float>;
using ivec4 = Vector4D<int>;