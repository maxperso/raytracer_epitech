/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** IPrimitives.hpp
*/

#pragma once

#include <string>
#include <libconfig.h++>
#include <optional>
#include "Ray.hpp"

namespace RayTracer {
    class IPrimitives  {
        public:
            virtual ~IPrimitives() = default;
            virtual std::optional<double> hits(const Ray& ray) const = 0;
            virtual Math::Vector3D getNormal(const Math::Vector3D& position) const = 0;
            double distance;
        protected:
        private:
    };
}
