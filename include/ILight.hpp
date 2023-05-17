/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** ILight
*/

#pragma once
#pragma once

#pragma once

#pragma once

#include "Ray.hpp"
#include "Color.hpp"
#include "Vector3D.hpp"
#include "Material.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

namespace RayTracer {

    class ILight {
    public:
        virtual Color getAmbientColor(const RayTracer::Material& material) const = 0;
        virtual Color getDiffuseColor(const Math::Vector3D& point,const Math::Vector3D& normal , const RayTracer::Material& material) const = 0;
        virtual Math::Vector3D getDirection(const Math::Vector3D& point) const = 0;
        virtual double getDistance(const Math::Vector3D& point) const = 0;
        virtual Color getSpecularColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::Material& material) const = 0;
    };

} // namespace RayTracer
