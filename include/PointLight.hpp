/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** PointLight
*/
#pragma once

#include "ILight.hpp"

namespace RayTracer {

    class PointLight : public ILight {
    public:
        PointLight(const Math::Vector3D& position, const Color& color)
            : position_(position), color_(color) {}

        virtual Color getAmbientColor(const RayTracer::Material& material) const override { return Color(0, 0, 0); }

        virtual Color getDiffuseColor(const Math::Vector3D& point,const Math::Vector3D& normal , const RayTracer::Material& material) const override {
            Math::Vector3D lightDirection = getDirection(point);
            double diffuseIntensity = lightDirection.dot(normal);
            if (diffuseIntensity > 0) {
                diffuseIntensity *= material.diffuse_;
                return color_ * diffuseIntensity;
            }
            return Color(0, 0, 0);
        }

        virtual Math::Vector3D getDirection(const Math::Vector3D& point) const override { return (position_ - point).normalize(); }

        virtual double getDistance(const Math::Vector3D& point) const override { return (position_ - point).length(); }

        virtual Color getSpecularColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::Material& material) const override {
            Math::Vector3D lightDirection = getDirection(point);
            Math::Vector3D reflectionDirection = Math::reflect(lightDirection, normal);
            double specularIntensity = reflectionDirection.dot(viewDirection);
            if (specularIntensity > 0) {
                specularIntensity = pow(specularIntensity, material.shininess_);
                return color_ * material.specular_ * specularIntensity;
            }
            return Color(0, 0, 0);
        }

        Math::Vector3D position_;
        Color color_;

        double attenuationConstant_ = 1.0;
        double attenuationLinear_ = 0.0045;
        double attenuationQuadratic_ = 0.0075;
    };

} // namespace RayTracer
