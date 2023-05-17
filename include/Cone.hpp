/*
** EPITECH PROJECT, 2023
** cone header file
** File description:
** Cone
*/

#pragma once

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "IPrimitives.hpp"
#include <optional>

namespace RayTracer {
    class Cone : public IPrimitives {
        public:
            Math::Vector3D cone_pos;
            double radius;
            double height;

            Cone(Math::Vector3D cone_pos, double radius, double height)
                : cone_pos(cone_pos), radius(radius), height(height) {}
            
            std::optional<double> hits(const Ray& ray) const override {
                std::optional<double> ray_unit;
                double a = pow(ray.direction.x, 2) + pow(ray.direction.y, 2) - pow(ray.direction.z, 2) * pow(radius / height, 2);
                double b = 2 * (ray.direction.x * (ray.origin.x - cone_pos.x) + ray.direction.y * (ray.origin.y - cone_pos.y) - ray.direction.z * (ray.origin.z - cone_pos.z) * pow(radius / height, 2));
                double c = pow(ray.origin.x - cone_pos.x, 2) + pow(ray.origin.y - cone_pos.y, 2) - pow(ray.origin.z - cone_pos.z, 2) * pow(radius / height, 2);
                double delta = pow(b, 2) - 4 * a * c;
                if (delta < 0)
                    return std::nullopt;
                double t1 = (-b - sqrt(delta)) / (2 * a);
                double t2 = (-b + sqrt(delta)) / (2 * a);
                if (t1 > 0 && t2 > 0) {
                    double hit_point = std::min(t1, t2);
                    Math::Vector3D point = ray.origin + hit_point * ray.direction;
                    if (point.z <= cone_pos.z && point.z >= cone_pos.z - height)
                        ray_unit = hit_point;
                } else if (t1 > 0) {
                    Math::Vector3D point = ray.origin + t1 * ray.direction;
                    if (point.z <= cone_pos.z && point.z >= cone_pos.z - height)
                        ray_unit = t1;
                } else if (t2 > 0) {
                    Math::Vector3D point = ray.origin + t2 * ray.direction;
                    if (point.z <= cone_pos.z && point.z >= cone_pos.z - height)
                        ray_unit = t2;
                }
                return ray_unit;
            }

            Math::Vector3D getNormal(const Math::Vector3D& hit_point) const {
                double k = radius / height;
                double dx = 2 * (hit_point.x - cone_pos.x);
                double dy = 2 * (hit_point.y - cone_pos.y);
                double dz = 2 * (hit_point.z - cone_pos.z) * (1 - k*k) - 2 * (hit_point.z - cone_pos.z);
                return Math::Vector3D(dx, dy, dz).normalize();
            }


        protected:
        private:
    };
}
