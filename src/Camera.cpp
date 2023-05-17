/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-maxime.gregoire
** File description:
** Camera.cpp
*/

#include "../include/Camera.hpp"

RayTracer::Camera RayTracer::Camera::setCamera()
{
    float w = screen_width;
    float h = screen_height;
    double aspect_ratio = w / h;
    double viewport_height = 2.0 * tan((camera_fov / 2.0) * M_PI / 180.0);
    double viewport_width = aspect_ratio * viewport_height;
    RayTracer::Camera cam(
        Math::Vector3D(camera_pos.x, camera_pos.y, camera_pos.z ),
        RayTracer::Rectangle3D(
            Math::Vector3D(camera_pos.x + 1.0, camera_pos.y - viewport_width / 2.0, camera_pos.z + viewport_height / 2.0),
            Math::Vector3D(0.0, viewport_width, 0.0),
            Math::Vector3D(0.0, 0.0, viewport_height)
        )
    );
    return cam;
}

void RayTracer::Camera::getCamera(const std::string& file)
{
    libconfig::Config cfg;
    try {
        cfg.readFile(file.c_str());
        libconfig::Setting& camera = cfg.lookup("camera");
        camera.lookupValue("fov", camera_fov);
        const libconfig::Setting& resolution = camera["resolution"];
        resolution.lookupValue("width", screen_width);
        resolution.lookupValue("height", screen_height);
        const libconfig::Setting& position = camera["position"];
        position.lookupValue("x", camera_pos.x);
        position.lookupValue("y", camera_pos.y);
        position.lookupValue("z", camera_pos.z);
        const libconfig::Setting& rotation = camera["rotation"];
        rotation.lookupValue("x", camera_rotation.x);
        rotation.lookupValue("y", camera_rotation.y);
        rotation.lookupValue("z", camera_rotation.z);
    }
    catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        exit(84);
    }
    catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() 
        << " - " << pex.getError() << std::endl;
        exit(84);
    }
}
