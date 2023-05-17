/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** AmbientLight
*/

#pragma once

#include "ILight.hpp"

namespace RayTracer {

    class AmbiantLight : public ILight {
    public:
        AmbiantLight(const Color& color)
            : color_(color) {}

        virtual Color getAmbientColor(const RayTracer::Material& material) const override { return color_ * material.ambient_ * material.color_; }
        virtual Color getDiffuseColor(const Math::Vector3D& point,const Math::Vector3D& normal , const RayTracer::Material& material) const override { return Color(0, 0, 0); }
        virtual Math::Vector3D getDirection(const Math::Vector3D& point) const override { return Math::Vector3D(0, 0, 0); }
        virtual double getDistance(const Math::Vector3D& point) const override { return 0; }
        virtual Color getSpecularColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::Material& material) const override { return Color(0, 0, 0); }

        Color color_;
    private:
    };

} // namespace RayTracer
