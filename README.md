# RayTracer EPITECH 2023
**Second year project at Epitech.**

*Name: Raytracer* | 
*Language: C++*

## Description

Raytracer is a feature-rich program that implements ray tracing, a technique used to generate realistic digital images by simulating the inverse path of light. The program can generate images from a file that describes the scene configuration. It supports various primitives, transformations, lights, materials, and scene setup options to create visually appealing and detailed renderings.

## Features

_Mandatory:_

* Primitives: Supports spheres and planes.
* Transformations: Includes translation.
* Light: Provides directional light and ambient light.
* Material: Supports flat color.
* Scene Configuration: Allows adding primitives to the scene, setting up lighting, and configuring the camera.
* Interface: No graphical user interface (GUI), outputs images in PPM file format.

_Should:_

* Primitives: Supports cylinders and cones.
* Transformations: Includes rotation.
* Light: Enables drop shadows.

_Could:_

* Primitives: Supports limited cylinders, limited cones, torus, tangle cube, triangles, and loading OBJ files.
* Fractals: Provides options for fractal shapes such as Möbius strip.
* Transformations: Includes scaling, shearing, transformation matrices, and scene graph for hierarchical transformations.
* Light: Supports multiple directional lights, multiple point lights, colored light, and the Phong reflection model.
* Material: Includes transparency, refraction, reflection, texturing from files, procedural generation of a chessboard texture, Perlin noise texture, and normal mapping.
* Scene Configuration: Allows importing a scene within a scene, setting up anti-aliasing through super-sampling or adaptive super-sampling, and implementing optimizations such as space partitioning, multithreading, and clustering.

_Interface:_

* Provides the option to display the image during and after generation.
* Supports the option to exit during or after image generation.
* Offers a scene preview using a basic and fast renderer.
* Supports automatic reload of the scene when the file changes.

## How to use

*Compilation*

```bash
make
```

*Execution*

```bash
./raytracer [scene]
```

## Scenes
<img width="1390" alt="Capture d’écran 2023-05-17 à 16 16 14" src="https://github.com/maxperso/raytracer_epitech/assets/91894666/48f45dc9-3143-4025-bcb5-8b301aa41daa">
<img width="1390" alt="Capture d’écran 2023-05-17 à 16 15 51" src="https://github.com/maxperso/raytracer_epitech/assets/91894666/66b2bd63-21b4-4964-86aa-ff556c243cb1">
<img width="1394" alt="Capture d’écran 2023-05-17 à 16 16 42" src="https://github.com/maxperso/raytracer_epitech/assets/91894666/da0bb188-7a0a-44ca-8b0d-c5d185df2625">
<img width="1388" alt="Capture d’écran 2023-05-17 à 16 19 34" src="https://github.com/maxperso/raytracer_epitech/assets/91894666/b39a3e7c-37a7-471e-8559-efa09ba560f4">


## Credit
### made with
 - [Mathis LEGRAND](https://github.com/MathisLegrandGit)
 - [Virgile ARNOUX](https://github.com/Virgile0110)
 - [Maxime GREGOIRE](https://github.com/maxperso)
