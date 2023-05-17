/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-maxime.gregoire
** File description:
** Config
*/


#include "Plane.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Cone.hpp"
#include "Torus.hpp"
#include "Vector3D.hpp"
#include "Color.hpp"
#include "IPrimitives.hpp"
#include "ILight.hpp"
#include <libconfig.h++>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#pragma once

namespace RayTracer {
    class Config {
        public:
            Config() = default;
            ~Config() = default;

            // Sphere variables
            struct Sphere_t {
                Math::Vector3D sphere_pos;
                double radius;
                int sphere_r, sphere_g, sphere_b;
            };
            std::vector<Sphere_t> spheres;
    
            // Plane variables
            struct Plane_t {
                Math::Vector3D plane_pos;
                Math::Vector3D plane_normal;
            };
            std::vector<Plane_t> planes;

            // Cylinder variables
            struct Cylinder_t {
                Math::Vector3D cylinder_pos;
                double radius;
                double height;
            };
            std::vector<Cylinder_t> cylinders;

            // Cone variables
            struct Cone_t {
                Math::Vector3D cone_pos;
                double radius;
                double height;
            };
            std::vector<Cone_t> cones;

            // Torus variables
            struct Torus_t {
                Math::Vector3D torus_pos;
                double r;
                double R;
            };
            std::vector<Torus_t> toruses;

            //Material variables
            struct Material_t {
                Color color_;
                int sphere_r, sphere_g, sphere_b;
                double ambient_;
                double diffuse_;
                double specular_;
                double shininess_;
            };
            std::vector<Material_t> materials;

            //PointLight variables
            struct PointLight_t {
                Math::Vector3D position_;
                Color color_;
            };
            std::vector<PointLight_t> pointLights;

            //DirectionalLight variables
            struct DirectionalLight_t {
                Math::Vector3D direction_;
                Color color_;
                double intensity;
            };
            std::vector<DirectionalLight_t> directionalLights;

            //DiffuseLight variables
            struct DiffuseLight_t {
                Color color_;
                Math::Vector3D direction_;
                double intensity_;
            };
            std::vector<DiffuseLight_t> diffuseLights;

            //AmbientLight variables
            struct AmbientLight_t {
                Color color_;
            };
            std::vector<AmbientLight_t> ambientLights;

            std::vector<std::shared_ptr<IPrimitives>> primitives;
            std::vector<std::shared_ptr<ILight>> lights;
            std::vector<std::shared_ptr<Material>> material;
            
            void getPrimitives(const std::string& file);
            void getLights(const std::string& file);
            void getMaterials(const std::string& file);
            void setPrimitives();
            void setMaterials();
            void setLights();

        protected:
        private:
    };
}
