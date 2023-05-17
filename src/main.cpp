/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-maxime.gregoire
** File description:
** main_test
*/

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <filesystem>
#include "../include/IPrimitives.hpp"
#include "../include/Config.hpp"
#include "../include/Camera.hpp"
#include "../include/Sphere.hpp"
#include "../include/Ray.hpp"
#include "../include/Vector3D.hpp"
#include "../include/Plane.hpp"
#include "../include/Color.hpp"
#include "../include/ILight.hpp"
#include "../include/Material.hpp"

void error_handling(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        std::cerr << "\tSCENE_FILE: scene configuration" << std::endl;
        exit(84);
    }
    if (std::string(av[1]) == "--help") {
        std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
        exit(0);
    }
    if (!std::filesystem::exists(av[1])) {
        std::cerr << "Invalid scene file" << std::endl;
        exit(84);
    }
}

RayTracer::Color GetTotalAmbientLight(const std::vector<std::shared_ptr<RayTracer::ILight>>& lights, const RayTracer::Material& material)
{
    RayTracer::Color totalAmbientColor = RayTracer::Color();
    for (const auto& light : lights) {
        totalAmbientColor += light->getAmbientColor(material);
    }
    // std::cout << totalAmbientColor.r << " " << totalAmbientColor.g << " " << totalAmbientColor.b << std::endl;
    return totalAmbientColor;
}

RayTracer::Color GetTotalDiffuseColor(const RayTracer::Material& material, const Math::Vector3D& normal, const Math::Vector3D& position, const std::vector<std::shared_ptr<RayTracer::ILight>>& lights)
{
    RayTracer::Color totalDiffuseColor = RayTracer::Color(0, 0, 0);
    for (const auto& light : lights) {
        RayTracer::Color diffuseColor = light->getDiffuseColor(position, normal, material);
        Math::Vector3D lightDirection = light->getDirection(position);
        double dotProduct = normal.dot(lightDirection);
        if (dotProduct > 0) {
            totalDiffuseColor += material.color_ * diffuseColor * dotProduct;
        }
    }
    // std::cout << totalDiffuseColor.r << " " << totalDiffuseColor.g << " " << totalDiffuseColor.b << std::endl;
    return totalDiffuseColor;
}

RayTracer::Color GetTotalSpecularColor(const RayTracer::Material& material, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const Math::Vector3D& position, const std::vector<std::shared_ptr<RayTracer::ILight>>& lights)
{
    RayTracer::Color totalSpecularColor = RayTracer::Color();
    for (const auto& light : lights) {
        RayTracer::Color specularColor = light->getSpecularColor(position, viewDirection, normal, material);
        Math::Vector3D lightDirection = light->getDirection(position);
        double dotProduct = normal.dot(lightDirection);
        if (dotProduct > 0) {
            Math::Vector3D reflectionDirection = (2.0 * dotProduct * normal - lightDirection).normalize();
            double specularIntensity = pow(std::max(0.0, reflectionDirection.dot(-viewDirection)), material.specular_);
            totalSpecularColor += material.color_ * specularColor * specularIntensity;
        }
    }
    return totalSpecularColor;
}

RayTracer::Color Phong(const RayTracer::Material& material, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const Math::Vector3D& position, const std::vector<std::shared_ptr<RayTracer::ILight>>& lights)
{
    RayTracer::Color ambientColor = material.color_ * GetTotalAmbientLight(lights, material);
    RayTracer::Color diffuseColor = GetTotalDiffuseColor(material, normal, position, lights);
    RayTracer::Color specularColor = GetTotalSpecularColor(material, viewDirection, normal, position, lights);
    return ambientColor + diffuseColor + specularColor;
}

int distanceObj(const RayTracer::Ray& ray, const std::vector<std::shared_ptr<RayTracer::IPrimitives>>& prim)
{
    int closestPrimIndex = -1;
    double closestDistance = std::numeric_limits<double>::infinity();

    for (int i = 0; i < prim.size(); i++) {
        std::optional<double> distance = prim[i]->hits(ray);
        if (distance && distance.value() >= 0.0 && distance.value() < closestDistance) {
            closestPrimIndex = i;
            closestDistance = distance.value();
            prim[i]->distance = distance.value();
        }
    }
    return closestPrimIndex;
}

int main(int ac , char **av)
{
    RayTracer::Config config;
    RayTracer::Camera camera;

    error_handling(ac, av);
    camera.getCamera(av[1]);
    config.getPrimitives(av[1]);
    config.getMaterials(av[1]);
    config.getLights(av[1]);
    RayTracer::Camera cam = camera.setCamera();
    config.setPrimitives();
    config.setMaterials();
    config.setLights();
    //compare the size of the material vector and the primitive vector
    if (config.material.size() != config.primitives.size()) {
        std::cerr << "Error: the number of materials and primitives must be the same" << std::endl;
        return 84;
    }
    std::ofstream fout ("renders/scene.ppm");
    if(fout.fail()) return -1; // error
    fout << "P6\n";
    fout << camera.screen_width << " " << camera.screen_height << "\n";
    fout << "255\n";
    bool hit;
    int obj_number;
    for (int y = 0; y < camera.screen_height; ++y) {
        for (int x = 0; x < camera.screen_width; ++x) {
            double v = (-y + 1.0) / camera.screen_height;
            double u = (x + 1.0) / camera.screen_width;
            RayTracer::Ray r = cam.getRay(u, v);
            obj_number = distanceObj(r, config.primitives);
            if (obj_number != -1) {
                Math::Vector3D position = r.at(config.primitives[obj_number]->distance);
                Math::Vector3D normal = config.primitives[obj_number]->getNormal(position);
                RayTracer::Color pixelColor = Phong(*config.material[obj_number], r.direction, normal, position, config.lights);
                pixelColor.toRGB();
                fout << uint8_t(pixelColor.r);
                fout << uint8_t(pixelColor.g);
                fout << uint8_t(pixelColor.b);
            }
            else {
                fout << uint8_t(0.0);
                fout << uint8_t(0.0);
                fout << uint8_t(0.0);
            }
        }
    }
    fout.close();
    system("open renders/scene.ppm");
    return 0;
}
