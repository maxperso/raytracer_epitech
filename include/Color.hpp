/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** Color
*/

#pragma once

#include <iostream>
#include <algorithm>

namespace RayTracer {
    class Color  {
        public:
            // Attributs
            double r, g, b;
            // Constructeurs
            Color() : r(0.0), g(0.0), b(0.0) {}
            Color(double red, double green, double blue) : r(red), g(green), b(blue) {}

            // Accesseurs
            double red() const { return r; }
            double green() const { return g; }
            double blue() const { return b; }

            // Opérateurs arithmétiques
            Color operator+ (const Color& c) const { return Color(r + c.r, g + c.g, b + c.b); }
            Color operator* (double k) const { return Color(k * r, k * g, k * b); }
            Color operator* (const Color& c) const { return Color(r * c.r, g * c.g, b * c.b); }
            Color operator/(double scalar) const {
            return Color(r / scalar, g / scalar, b / scalar);
            }

            Color getColor() const {
                return *this;
            }

            Color& operator+=(const Color& other) 
            {
                r += other.r;
                g += other.g;
                b += other.b;
                return *this;
            }
            // Autres méthodes
            void clamp(); // Tronquer les valeurs des composantes à [0, 1]
            void print() const; // Afficher les valeurs des composantes
            void toRGB();

        private:
        };

        // Méthode pour tronquer les valeurs des composantes à [0, 1]
    inline void Color::clamp() {
        r = std::min(std::max(r / 255.0, 0.0), 1.0);
        g = std::min(std::max(g / 255.0, 0.0), 1.0);
        b = std::min(std::max(b / 255.0, 0.0), 1.0);
    }

    inline void Color::toRGB() {
        r = r * 255;
        g = g * 255;
        b = b * 255;
    }
    // Méthode pour afficher les valeurs des composantes
    inline void Color::print() const {
        std::cout << "(" << r << ", " << g << ", " << b << ")" << std::endl;
    }

}
