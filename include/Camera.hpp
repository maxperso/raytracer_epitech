/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-maxime.gregoire
** File description:
** Camera.hpp
*/

#pragma once

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "Config.hpp"
#include "Rectangle3D.hpp"
#include <libconfig.h++>

namespace RayTracer {
    class Camera {
        public:

            Math::Vector3D origin;
            Rectangle3D screen;

            // Camera variables
            int screen_width, screen_height;
            Math::Vector3D camera_pos;
            Math::Vector3D camera_rotation;
            double camera_fov;

            ~Camera() = default;
            Camera() : origin(Math::Vector3D(0, 0, 0)), screen(Rectangle3D()) {}
            Camera(const Math::Vector3D& origin_, const Rectangle3D& screen_)
                : origin(origin_), screen(screen_) {}

            // get ray method
            Ray getRay(double u, double v) const {
                Math::Vector3D dest = screen.pointAt(u, v);
                Math::Vector3D dir = (dest - origin);
                return Ray(origin, dir);
            }

            // setter and getter
            void getCamera(const std::string& file);
            RayTracer::Camera setCamera();

    };
}
