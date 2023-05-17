/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-maxime.gregoire
** File description:
** Rectangle3D
*/

#pragma once

#include <cmath>
#include "Vector3D.hpp"

namespace RayTracer {
    class Rectangle3D {
        public:
            Math::Vector3D origin;
            Math::Vector3D bottom_side;
            Math::Vector3D left_side;

            Rectangle3D() = default;
            Rectangle3D(const Math::Vector3D& origin_, const Math::Vector3D& bottom_side_, const Math::Vector3D& left_side_)
                : origin(origin_), bottom_side(bottom_side_), left_side(left_side_) {}

            Math::Vector3D pointAt(double u, double v) const {
                return origin + bottom_side * u + left_side * v;
            }
    };
}
