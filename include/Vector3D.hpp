/*
** EPITECH PROJECT, 2023
** Tek2
** File description:
** Point3D
*/

#pragma once

#include <cmath>

namespace Math {
    class Vector3D {
        public:
            double x, y, z;
    
            Vector3D() : x(0), y(0), z(0) {}
            Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
            Vector3D(const Vector3D& other) = default;
            Vector3D(Vector3D&& other) = default;
            Vector3D& operator=(const Vector3D& other) = default;
            Vector3D& operator=(Vector3D&& other) = default;
            ~Vector3D() = default;
    
            double length() const {
                return std::sqrt(x * x + y * y + z * z);
            }
    
            double dot(const Vector3D& other) const {
                return x * other.x + y * other.y + z * other.z;
            }
    
            Vector3D operator+(const Vector3D& other) const {
                return Vector3D(x + other.x, y + other.y, z + other.z);
            }

            Vector3D& operator+=(const Vector3D& other) {
                x += other.x;
                y += other.y;
                z += other.z;
                return *this;
            }

            Vector3D operator+(double t) const {
                return Vector3D(x + t, y + t, z + t);
            }
    
            Vector3D operator-(const Vector3D& other) const {
                return Vector3D(x - other.x, y - other.y, z - other.z);
            }

            Vector3D operator-() const {
                return Vector3D(-x, -y, -z);
            }

            Vector3D& operator-=(const Vector3D& other) {
                x -= other.x;
                y -= other.y;
                z -= other.z;
                return *this;
            }
    
            Vector3D operator*(double scalar) const {
                return Vector3D(x * scalar, y * scalar, z * scalar);
            }
    
            Vector3D& operator*=(double scalar) {
                x *= scalar;
                y *= scalar;
                z *= scalar;
                return *this;
            }

            Vector3D operator*(const Vector3D& other) {
                x *= other.x;
                y *= other.y;
                z *= other.z;
                return *this;
            }
    
            Vector3D operator/(double scalar) const {
                return Vector3D(x / scalar, y / scalar, z / scalar);
            }
            
            Vector3D& operator/=(double scalar) {
                x /= scalar;
                y /= scalar;
                z /= scalar;
                return *this;
            }

            Vector3D normalize() const {
                double len = length();
                if (len != 0) {
                    return *this / len;
                }
                return Vector3D();
            }

            double lengthSquared() const {
                return x * x + y * y + z * z;
            }



    };

        inline Vector3D operator-=(const Vector3D& p1, const Vector3D& p2) {
            return Vector3D(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
        }

        inline Vector3D operator*(const double scalar, const Vector3D& vec) 
        {
            return Vector3D(scalar * vec.x, scalar * vec.y, scalar * vec.z);
        }

        inline Vector3D reflect(const Math::Vector3D& incident, const Math::Vector3D& normal)
        {
            return incident - 2 * incident.dot(incident) * normal;
        }
}
