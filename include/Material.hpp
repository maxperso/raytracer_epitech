/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** Material
*/

#pragma once

#include "Color.hpp"

namespace RayTracer {

    class Material {
    public:
        Material(const Color& color, double ambient, double diffuse, double specular, double shininess)
            : color_{color}, ambient_{ambient}, diffuse_{diffuse}, specular_{specular}, shininess_{shininess}
        {}

        Color color() const { return color_; }
        double ambient() const { return ambient_; }
        double diffuse() const { return diffuse_; }
        double specular() const { return specular_; }
        double shininess() const { return shininess_; }

        Color color_;
        double ambient_;
        double diffuse_;
        double specular_;
        double shininess_;
    private:
    };

} // namespace RayTracer
