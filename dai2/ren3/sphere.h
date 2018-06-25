#ifndef SPHERE_H
#define SPHERE_H
#include <cmath>
#include "vec3.h"
#include "ray.h"
class Sphere {
    public:
        Vec3 center; //中心位置
        double radius; //半径

        //コンストラクタ
        Sphere(const Vec3& center, double radius) : center(center), radius(radius) {};

        //与えられたRayが球に衝突するかどうか判定する
        bool intersect(const Ray& ray) const {
            double d_norm = ray.direction.length();
            double oc_norm = (ray.origin - center).length();

            //二次方程式の係数
            double a = d_norm*d_norm;
            double b = 2*dot(ray.direction, ray.origin - center);
            double c = oc_norm*oc_norm - radius*radius;
            double D = b*b - 4*a*c;

            //解の候補
            double t1 = (-b - std::sqrt(D))/(2*a);
            double t2 = (-b + std::sqrt(D))/(2*a);

            //距離がマイナスになっているものは除外する
            double t = t1;
            if(t < 0) {
                t = t2;
                if(t < 0) return false;
            }

            return true;
        };
};
#endif
