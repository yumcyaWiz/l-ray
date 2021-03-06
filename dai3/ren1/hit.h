#ifndef HIT_H
#define HIT_H
#include "vec3.h"
class Hit {
    public:
        double t;
        Vec3 hitPos;
        Vec3 hitNormal;

        Hit() {};
        Hit(double t, const Vec3& hitPos, const Vec3& hitNormal) : t(t), hitPos(hitPos), hitNormal(hitNormal) {};
};
#endif
