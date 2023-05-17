/*
** EPITECH PROJECT, 2023
** Cylinder function set up
** File description:
** Cylinder
*/

#pragma once

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "IPrimitives.hpp"
#include <optional>

namespace RayTracer {
    class Cylinder : public IPrimitives{
        public:
            Math::Vector3D cylinder_pos;
            double radius;
            double height;
            Cylinder(Math::Vector3D cylinder_pos, double radius, double height)
                : cylinder_pos(cylinder_pos), radius(radius), height(height) {};

            std::optional<double> hits(const Ray& ray) const override {
                // Compute the discriminant of the quadratic equation for ray-cylinder intersection.
                Math::Vector3D oc = ray.origin - cylinder_pos;
                double a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y;
                double b = 2 * (ray.direction.x * oc.x + ray.direction.y * oc.y);
                double c = oc.x * oc.x + oc.y * oc.y - radius * radius;
                double discriminant = b * b - 4 * a * c;
                if (discriminant < 0)
                    return std::nullopt;
                double t1 = (-b - sqrt(discriminant)) / (2 * a);
                double t2 = (-b + sqrt(discriminant)) / (2 * a);
                if (t1 < 0 && t2 < 0)
                    return std::nullopt;
                double t = (t1 < t2 && t1 >= 0) ? t1 : t2;
                double z = ray.origin.z + t * ray.direction.z;
                if (z < cylinder_pos.z - height/2 || z > cylinder_pos.z + height/2)
                    return std::nullopt;
                return t;
            }

            Math::Vector3D getNormal(const Math::Vector3D& point) const override {
                // Project the point onto the plane passing through the center of the cylinder and perpendicular to the y axis
                Math::Vector3D projection = Math::Vector3D(point.x, cylinder_pos.y, point.z);

                // Calculate the normal vector as the difference between the projection and the cylinder's center
                Math::Vector3D normal = projection - cylinder_pos;

                // Normalize the normal vector and return it
                return normal.normalize();
            }


        protected:
        private:
    };
}
