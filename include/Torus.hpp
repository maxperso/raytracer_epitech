/*
** EPITECH PROJECT, 2023
** toruses hit function file
** File description:
** Torus
*/

#pragma once

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "IPrimitives.hpp"
#include <optional>
#include <vector>

namespace RayTracer {
    class Torus : public IPrimitives{
        public:
            Math::Vector3D torus_pos;
            double r;
            double R;
            double distance;
            Torus(Math::Vector3D torus_pos, double r, double R)
                : torus_pos(torus_pos), r(r), R(R) {};

            std::optional<double> hits(const Ray& ray) const override {
                Math::Vector3D origin = ray.origin - torus_pos;
                double a = pow(ray.direction.z, 2) + pow(ray.direction.y, 2) + pow(ray.direction.x, 2);
                double b = 2 * (ray.direction.z * origin.z + ray.direction.y * origin.y + ray.direction.x * origin.x);
                double c = pow(origin.z, 2) + pow(origin.y, 2) + pow(origin.x, 2) - pow(r, 2) - pow(R, 2);
                double delta = pow(b, 2) - 4 * a * c;
                std::optional<double> ray_unit;
                if (delta < 0)
                    return std::nullopt;
                double t1 = (-b - sqrt(delta)) / (2 * a);
                double t2 = (-b + sqrt(delta)) / (2 * a);
                if (t1 > 0 && t2 > 0) {
                    double hit_point = std::min(t1, t2);
                    Math::Vector3D point = ray.origin + hit_point * ray.direction;
                    if (point.x <= torus_pos.x && point.x >= torus_pos.x - R)
                        ray_unit = hit_point;
                } else if (t1 > 0) {
                    Math::Vector3D point = ray.origin + t1 * ray.direction;
                    if (point.x <= torus_pos.x && point.x >= torus_pos.x - R)
                        ray_unit = t1;
                } else if (t2 > 0) {
                    Math::Vector3D point = ray.origin + t2 * ray.direction;
                    if (point.x <= torus_pos.x && point.x >= torus_pos.x - R)
                        ray_unit = t2;
                }
                return ray_unit;
            }

            Math::Vector3D getNormal(const Math::Vector3D& position) const
            {
                double x = position.x - torus_pos.x;
                double y = position.y - torus_pos.y;
                double z = position.z - torus_pos.z;
                double fx = 4 * x * (x * x + y * y + z * z + R * R - r * r) - 8 * R * x * x;
                double fy = 4 * y * (x * x + y * y + z * z + R * R - r * r) - 8 * R * y * y;
                double fz = 4 * z * (x * x + y * y + z * z + R * R - r * r);
                Math::Vector3D normal(fx, fy, fz);
                return normal.normalize();
            }


        protected:
        private:
    };
}
