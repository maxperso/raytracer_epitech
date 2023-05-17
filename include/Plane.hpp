/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** Plane
*/

#pragma once

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "IPrimitives.hpp"
#include <optional>

namespace RayTracer {
    class Plane : public IPrimitives {
        public:
            Math::Vector3D normal;
            Math::Vector3D position;
            double distance;
            
            Plane(Math::Vector3D normal, Math::Vector3D position) 
                : normal(normal), position(position) {}

            std::optional<double> hits(const Ray& ray) const override {
                std::optional<double> ray_unit;
                double denom = normal.dot(ray.direction);
                if (std::abs(denom) > 1e-6) {
                    Math::Vector3D v = position - ray.origin;
                    double t = v.dot(normal) / denom;
                    if (t <= 0) {
                        return -1.0;
                    }
                    ray_unit = t;
                }
                return ray_unit;
            }

            Math::Vector3D getNormal(const Math::Vector3D& hit_point) const override {
                return normal;
            }
        };
} // namespace RayTracer