/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** Sphere
*/

#include "Vector3D.hpp"
#include "Matrix.hpp"
#include "IPrimitives.hpp"
#include "Ray.hpp"
#include <optional>

#pragma once

namespace RayTracer {

    class Sphere : public IPrimitives {
        private:
            Math::Vector3D m_center;
            double m_radius;
        public:
            double distance;
            
            Sphere(const Math::Vector3D &center, double radius)
                : m_center(center), m_radius(radius) {}

            Math::Vector3D center() const
            {
                return m_center;
            }

            double radius() const
            {
                return m_radius;
            }

            std::optional<double> hits(const Ray& ray) const override
            {
                Math::Vector3D oc = ray.origin - this->m_center;
                double a = ray.direction.dot(ray.direction);
                double b = 2.0 * oc.dot(ray.direction);
                double c = oc.dot(oc) - this->m_radius * this->m_radius;
                double discriminant = b * b - 4.0 * a * c;
                std::optional<double> ray_unit1;
                std::optional<double> ray_unit2;
                if (discriminant < 0.0) {
                    return -1.0;
                } else {
                    ray_unit1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
                    ray_unit2 = (-b + std::sqrt(discriminant)) / (2.0 * a);
                    if (ray_unit1 <= ray_unit2) {
                        return ray_unit1;
                    } else {
                        return ray_unit2;
                    }
                }
            }

            Math::Vector3D getNormal(const Math::Vector3D& position) const
            {
                return (position - m_center).normalize();
            }
    };

} // namespace RayTracer
