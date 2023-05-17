/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** DiffuseLight
*/

#pragma once

#include "ILight.hpp"

namespace RayTracer {

    class DiffuseLight : public ILight {
    public:
    
        DiffuseLight(Color color, Math::Vector3D direction, double intensity)
            : color_(std::move(color)), direction_(std::move(direction)), intensity_(intensity) {}

        Color getAmbientColor(const RayTracer::Material& material) const override {
            return Color(0, 0, 0);
        }

        Color getDiffuseColor(const Math::Vector3D& point,const Math::Vector3D& normal , const RayTracer::Material& material) const override {
            return color_ * (intensity_ * std::max(0.0, direction_.dot(-getDirection(point)))) * material.diffuse_;
        }

        Math::Vector3D getDirection(const Math::Vector3D& point) const override {
            return direction_;
        }

        double getDistance(const Math::Vector3D& point) const override {
            return std::numeric_limits<double>::infinity();
        }

        virtual Color getSpecularColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::Material& material) const override 
        {
            return Color(0, 0, 0);
        }

    private:
        Color color_;
        Math::Vector3D direction_;
        double intensity_;
    };
    
} // namespace RayTracer
