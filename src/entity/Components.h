#ifndef COMPONENTS_H
#define COMPONENTS_H

namespace engine
{
    struct Transform
    {
        float x, y, z;
    };

    struct Physics
    {
        float vx, vy, vz;
        float ax, ay, az;
    };

    struct Graphics
    {
        float r, g, b, a;
    };
} // namespace engine
#endif