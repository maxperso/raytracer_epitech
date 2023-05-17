/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Vector3D.hpp"
#include "Matrix.hpp"
#include <cmath>

namespace RayTracer {

    class Ray {
        public:
            Math::Vector3D origin;
            Math::Vector3D direction;

            Ray() = default;
            Ray(const Math::Vector3D& origin, const Math::Vector3D& direction) : origin(origin), direction(direction) {}

            // Copy constructor
            Ray(const Ray& other) = default;

            // Move constructor
            Ray(Ray&& other) noexcept = default;

            // Copy assignment operator
            Ray& operator=(const Ray& other) = default;

            // Move assignment operator
            Ray& operator=(Ray&& other) noexcept = default;


            Math::Vector3D at(double t) const {
                return Math::Vector3D((origin + direction) * t);
            }


            // void transform(const Math::Matrix& m) {
            //     direction = m * direction;
            //     origin = m * origin;
            // }
    };
}

#endif /* !RAY_HPP_ */