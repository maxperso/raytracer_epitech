/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-maxime.gregoire
** File description:
** Config.cpp
*/

#include "../include/Config.hpp"
#include "../include/DiffuseLight.hpp"
#include "../include/PointLight.hpp"
#include "../include/AmbientLight.hpp"
#include "../include/DirectionalLight.hpp"
#include <ostream>
#include <iostream>

void RayTracer::Config::getPrimitives(const std::string& file) 
{
    libconfig::Config cfg;

    cfg.readFile(file.c_str());
    const libconfig::Setting& primitives = cfg.lookup("primitives");

    //spheres
    try {
        const libconfig::Setting& spheresSetting = primitives.lookup("spheres");

        for (int i = 0; i < spheresSetting.getLength(); i++) {
            const libconfig::Setting& sphereSetting = spheresSetting[i];
            Sphere_t newSphere;
            newSphere.sphere_pos.x = sphereSetting.lookup("x");
            newSphere.sphere_pos.y = sphereSetting.lookup("y");
            newSphere.sphere_pos.z = sphereSetting.lookup("z");
            newSphere.radius = sphereSetting.lookup("r");
            spheres.push_back(newSphere);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "spheres" field and continue parsing other fields
    }

    //planes
    try {
        const libconfig::Setting& planesSetting = primitives.lookup("planes");

        for (int i = 0; i < planesSetting.getLength(); i++) {
            const libconfig::Setting& planeSetting = planesSetting[i];
            Plane_t newPlane;
            newPlane.plane_pos.x = 0;
            newPlane.plane_pos.y = 0;
            newPlane.plane_pos.z = 0;
            newPlane.plane_normal.x = 0;
            newPlane.plane_normal.y = 0;
            newPlane.plane_normal.z = 0;
            if (std::string(planeSetting.lookup("axis")) == std::string("X")) {
                newPlane.plane_pos.x = 1;
                newPlane.plane_normal.x = planeSetting.lookup("position");
            }
            else if (std::string(planeSetting.lookup("axis")) == std::string("Y")) {
                newPlane.plane_pos.y = 1;
                newPlane.plane_normal.y = planeSetting.lookup("position");
            }
            else if (std::string(planeSetting.lookup("axis")) == std::string("Z")) {
                newPlane.plane_pos.z = 1;
                newPlane.plane_normal.z = planeSetting.lookup("position");
            }
            planes.push_back(newPlane);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "planes" field and continue parsing other fields
    }

    //cylinders
    try {
        const libconfig::Setting& cylindersSetting = primitives.lookup("cylinders");

        for (int i = 0; i < cylindersSetting.getLength(); i++) {
            const libconfig::Setting& cylinderSetting = cylindersSetting[i];
            Cylinder_t newCylinder;
            newCylinder.cylinder_pos.x = cylinderSetting.lookup("x");
            newCylinder.cylinder_pos.y = cylinderSetting.lookup("y");
            newCylinder.cylinder_pos.z = cylinderSetting.lookup("z");
            newCylinder.radius = cylinderSetting.lookup("r");
            newCylinder.height = cylinderSetting.lookup("h");
            cylinders.push_back(newCylinder);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "cylinders" field and continue parsing other fields
    }

    //cones
    try {
        const libconfig::Setting& conesSetting = primitives.lookup("cones");

        for (int i = 0; i < conesSetting.getLength(); i++) {
            const libconfig::Setting& coneSetting = conesSetting[i];
            Cone_t newCone;
            newCone.cone_pos.x = coneSetting.lookup("x");
            newCone.cone_pos.y = coneSetting.lookup("y");
            newCone.cone_pos.z = coneSetting.lookup("z");
            newCone.radius = coneSetting.lookup("r");
            newCone.height = coneSetting.lookup("h");
            cones.push_back(newCone);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "cones" field and continue parsing other fields
    }

    // toruses
    try {
        const libconfig::Setting& torusesSetting = primitives.lookup("toruses");

        for (int i = 0; i < torusesSetting.getLength(); i++) {
            const libconfig::Setting& torusSetting = torusesSetting[i];
            Torus_t newTorus;
            newTorus.torus_pos.x = torusSetting.lookup("x");
            newTorus.torus_pos.y = torusSetting.lookup("y");
            newTorus.torus_pos.z = torusSetting.lookup("z");
            newTorus.r = torusSetting.lookup("r");
            newTorus.R = torusSetting.lookup("R");
            toruses.push_back(newTorus);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "toruses" field and continue parsing other fields
    }
}

void RayTracer::Config::setPrimitives()
{
    //Set Spheres
    for (const auto& sphere : spheres) {
        auto s = std::make_shared<Sphere>(sphere.sphere_pos, sphere.radius);
        primitives.push_back(s);
    }

    //Set Planes
    for (const auto& plane : planes) {
        auto p = std::make_shared<Plane>(plane.plane_pos, plane.plane_normal);
        primitives.push_back(p);
    }

    //Set Cylinders
    for (const auto& cylinder : cylinders) {
        auto c = std::make_shared<Cylinder>(cylinder.cylinder_pos, cylinder.radius, cylinder.height);
        primitives.push_back(c);
    }

    //Set Cones
    for (const auto& cone : cones) {
        auto c = std::make_shared<Cone>(cone.cone_pos, cone.radius, cone.height);
        primitives.push_back(c);
    }

    //Set Toruses
    for (const auto& torus : toruses) {
        auto t = std::make_shared<Torus>(torus.torus_pos, torus.r, torus.R);
        primitives.push_back(t);
    }
}

void RayTracer::Config::getMaterials(const std::string& file)
{
    libconfig::Config cfg;

    cfg.readFile(file.c_str());
    const libconfig::Setting& materials1 = cfg.lookup("materials");

    try {
        const libconfig::Setting& objectsSetting = materials1.lookup("objects");

        for (int i = 0; i < objectsSetting.getLength(); i++) {
            const libconfig::Setting& objectSetting = objectsSetting[i];
            Material_t newMaterial;
            newMaterial.ambient_ = objectSetting.lookup("ambient");
            newMaterial.diffuse_ = objectSetting.lookup("diffuse");
            newMaterial.specular_ = objectSetting.lookup("specular");
            newMaterial.shininess_ = objectSetting.lookup("shininess");
            double r = objectSetting.lookup("color.r");
            double g = objectSetting.lookup("color.g");
            double b = objectSetting.lookup("color.b");
            newMaterial.color_ = Color(r, g, b);
            newMaterial.color_.clamp();
            materials.push_back(newMaterial);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "objects" field and continue parsing other fields
    }
}

void RayTracer::Config::setMaterials()
{
    for (const auto& material1 : materials) {
        auto m = std::make_shared<Material>(material1.color_, material1.ambient_, material1.diffuse_, material1.specular_, material1.shininess_);
        material.push_back(m);
    }
}

void RayTracer::Config::getLights(const std::string& file)
{
    libconfig::Config cfg;

    cfg.readFile(file.c_str());
    const libconfig::Setting& lights = cfg.lookup("lights");

    //point lights
    try {
        const libconfig::Setting& PointsSetting = lights.lookup("point_lights");

        for (int i = 0; i < PointsSetting.getLength(); i++) {
            const libconfig::Setting& PointSetting = PointsSetting[i];
            PointLight_t newPointLight;
            newPointLight.position_.x = PointSetting.lookup("position.x");
            newPointLight.position_.y = PointSetting.lookup("position.y");
            newPointLight.position_.z = PointSetting.lookup("position.z");
            double ra = PointSetting.lookup("Color.r");
            double ga = PointSetting.lookup("Color.g");
            double ba = PointSetting.lookup("Color.b");
            newPointLight.color_ = Color(ra, ga, ba);
            newPointLight.color_.clamp();
            pointLights.push_back(newPointLight);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "point_lights" field and continue parsing other fields
    }

    //directional lights
    try {
        const libconfig::Setting& DirectionalsSetting = lights.lookup("directional_lights");

        for (int i = 0; i < DirectionalsSetting.getLength(); i++) {
            const libconfig::Setting& DirectionalSetting = DirectionalsSetting[i];
            DirectionalLight_t newDirectionalLight;
            newDirectionalLight.direction_.x = DirectionalSetting.lookup("direction.x");
            newDirectionalLight.direction_.y = DirectionalSetting.lookup("direction.y");
            newDirectionalLight.direction_.z = DirectionalSetting.lookup("direction.z");
            newDirectionalLight.intensity = DirectionalSetting.lookup("intensity");
            double r = DirectionalSetting.lookup("color.r");
            double g = DirectionalSetting.lookup("color.g");
            double b = DirectionalSetting.lookup("color.b");
            newDirectionalLight.color_ = Color(r, g, b);
            newDirectionalLight.color_.clamp();
            directionalLights.push_back(newDirectionalLight);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "directional_lights" field and continue parsing other fields
    }

    //ambient lights
    try {
        const libconfig::Setting& AmbientsSetting = lights.lookup("ambient_lights");

        for (int i = 0; i < AmbientsSetting.getLength(); i++) {
            const libconfig::Setting& AmbientSetting = AmbientsSetting[i];
            AmbientLight_t newAmbientLight;
            double r = AmbientSetting.lookup("color.r");
            double g = AmbientSetting.lookup("color.g");
            double b = AmbientSetting.lookup("color.b");
            newAmbientLight.color_ = Color(r, g, b);
            newAmbientLight.color_.clamp();
            ambientLights.push_back(newAmbientLight);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "ambient_lights" field and continue parsing other fields
    }

    //diffuse lights
    try {
        const libconfig::Setting& DiffusesSetting = lights.lookup("diffuse_lights");

        for (int i = 0; i < DiffusesSetting.getLength(); i++) {
            const libconfig::Setting& DiffuseSetting = DiffusesSetting[i];
            DiffuseLight_t newDiffuseLight;
            double r = DiffuseSetting.lookup("color.r");
            double g = DiffuseSetting.lookup("color.g");
            double b = DiffuseSetting.lookup("color.b");
            newDiffuseLight.color_ = Color(r, g, b);
            newDiffuseLight.color_.clamp();
            newDiffuseLight.direction_.x = DiffuseSetting.lookup("direction.x");
            newDiffuseLight.direction_.y = DiffuseSetting.lookup("direction.y");
            newDiffuseLight.direction_.z = DiffuseSetting.lookup("direction.z");
            newDiffuseLight.intensity_ = DiffuseSetting.lookup("diffuseMult");
            diffuseLights.push_back(newDiffuseLight);
        }
    } catch (const libconfig::SettingNotFoundException&) {
        // Ignore missing "diffuse_lights" field and continue parsing other fields
    }
}

void RayTracer::Config::setLights()
{
    for (const auto& pointLight1 : pointLights) {
        auto p = std::make_shared<PointLight>(pointLight1.position_, pointLight1.color_);
        lights.push_back(p);
    }
    for (const auto& directionalLight1 : directionalLights) {
        auto d = std::make_shared<DirectionalLight>(directionalLight1.direction_, directionalLight1.color_, directionalLight1.intensity);
        lights.push_back(d);
    }
    for (const auto& ambientLight1 : ambientLights) {
        auto a = std::make_shared<AmbiantLight>(ambientLight1.color_);
        lights.push_back(a);
    }
    for (const auto& diffuseLight1 : diffuseLights) {
        auto d = std::make_shared<DiffuseLight>(diffuseLight1.color_, diffuseLight1.direction_, diffuseLight1.intensity_);
        lights.push_back(d);
    }
}
