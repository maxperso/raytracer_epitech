/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** DirectionalLight
*/

#pragma once

#include "ILight.hpp"
#include "Color.hpp"
#include "Vector3D.hpp"

namespace RayTracer {

    class DirectionalLight : public ILight {
    public:
        DirectionalLight(const Math::Vector3D& direction, const Color& color, double intensity)
            : direction_(direction.normalize()), color_(color), intensity_(intensity) {}

        Color getAmbientColor(const Material& material) const override {
            return Color(0, 0, 0);
        }

        Color getDiffuseColor(const Math::Vector3D& point, const Math::Vector3D& normal, const Material& material) const override {
            double diffuseIntensity = std::max(0.0, normal.dot(-direction_));
            return color_ * (material.diffuse_ * diffuseIntensity * intensity_);
        }

        Math::Vector3D getDirection(const Math::Vector3D& point) const override {
            return -direction_;
        }

        double getDistance(const Math::Vector3D& point) const override {
            return std::numeric_limits<double>::infinity();
        }

        Color getSpecularColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const Material& material) const override {
            Math::Vector3D reflectedDirection = Math::reflect(direction_, normal);
            double specularIntensity = std::max(0.0, reflectedDirection.dot(viewDirection));
            return color_ * (material.specular_ * pow(specularIntensity, material.shininess_) * intensity_);
        }

    private:
        Math::Vector3D direction_;
        Color color_;
        double intensity_;
    };

} // namespace RayTracer
