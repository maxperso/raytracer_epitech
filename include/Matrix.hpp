// /*
// ** EPITECH PROJECT, 2023
// ** Tek2
// ** File description:
// ** Matrix
// */

// #pragma once

// #include "Vector3D.hpp"
// #include <cstddef>

// namespace Math {

//     class Matrix {
//         public:
//             Matrix() {
//                 for (int i = 0; i < 4; i++) {
//                     for (int j = 0; j < 4; j++) {
//                         m_data[i][j] = 0;
//                     }
//                 }
//             }
    
//             Matrix(double arr[4][4]) {
//                 for (int i = 0; i < 4; i++) {
//                     for (int j = 0; j < 4; j++) {
//                         m_data[i][j] = arr[i][j];
//                     }
//                 }
//             }
    
//             Matrix operator*(const Matrix& other) const {
//                 Matrix result;
    
//                 for (int i = 0; i < 4; i++) {
//                     for (int j = 0; j < 4; j++) {
//                         for (int k = 0; k < 4; k++) {
//                             result.m_data[i][j] += m_data[i][k] * other.m_data[k][j];
//                         }
//                     }
//                 }
    
//                 return result;
//             }
    
//             Vector3D operator*(const Vector3D& p) const {
//                 return Vector3D(
//                     m_data[0][0]*p.x + m_data[0][1]*p.y + m_data[0][2]*p.z + m_data[0][3],
//                     m_data[1][0]*p.x + m_data[1][1]*p.y + m_data[1][2]*p.z + m_data[1][3],
//                     m_data[2][0]*p.x + m_data[2][1]*p.y + m_data[2][2]*p.z + m_data[2][3]
//                 );
//             }
    
//             Vector3D operator*(const Vector3D& v) const {
//                 return Vector3D(
//                     m_data[0][0]*v.x + m_data[0][1]*v.y + m_data[0][2]*v.z,
//                     m_data[1][0]*v.x + m_data[1][1]*v.y + m_data[1][2]*v.z,
//                     m_data[2][0]*v.x + m_data[2][1]*v.y + m_data[2][2]*v.z
//                 );
//             }
    
//             static Matrix translate(double x, double y, double z) {
//                 double arr[4][4] = {
//                     {1, 0, 0, x},
//                     {0, 1, 0, y},
//                     {0, 0, 1, z},
//                     {0, 0, 0, 1}
//                 };
    
//                 return Matrix(arr);
//             }
    
//             static Matrix scale(double x, double y, double z) {
//                 double arr[4][4] = {
//                     {x, 0, 0, 0},
//                     {0, y, 0, 0},
//                     {0, 0, z, 0},
//                     {0, 0, 0, 1}
//                 };
    
//                 return Matrix(arr);
//             }
    
//             static Matrix rotateX(double angle) {
//                 double s = std::sin(angle);
//                 double c = std::cos(angle);
    
//                 double arr[4][4] = {
//                     {1, 0, 0, 0},
//                     {0, c, -s, 0},
//                     {0, s, c, 0},
//                     {0, 0, 0, 1}
//                 };
    
//                 return Matrix(arr);
//             }
    
//             static Matrix rotateY(double angle) {
//                 double s = std::sin(angle);
//                 double c = std::cos(angle);
    
//                 double arr[4][4] = {
//                     {c, 0, s, 0},
//                     {0, 1, 0, 0},
//                     {-s, 0, c, 0},
//                     {0, 0, 0, 1}
//                 };
    
//                 return Matrix(arr);
//             }
    
//             static Matrix rotateZ(double angle) {
//                 double s = std::sin(angle);
//                 double c = std::cos(angle);
    
//                 double arr[4][4] = {
//                     {c, -s, 0, 0},
//                     {s, c, 0, 0},
//                     {0, 0, 1, 0},
//                     {0, 0, 0, 1}
//                 };
    
//                 return Matrix(arr);
//             }
    
//         private:
//             double m_data[4][4];
//         };
    
// }
