# Fractol

Fractol is a the first graphical project of 42. It is a tool designed to explore and visualize fractals.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)

## Introduction

Fractals are fascinating mathematical objects that exhibit intricate patterns at every scale. Fractol provides a platform to generate, visualize, and explore various types of fractals. Whether you're a mathematician, a computer scientist, or simply curious about fractals, Fractol offers an intuitive interface to interact with these mesmerizing structures.

## Features

- **Fractal Generation**: Generate popular fractals such as Mandelbrot Set and Julia Set
- **Interactive Visualization**: Zoom and explore fractals in real-time to discover their intricate details.

## Installation

To install Fractol, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/Bussiereg/fractol.git
    ```

2. Navigate to the project directory:

    ```bash
    cd fractol
    ```

3. Build the project with the following command: make

4. Run the executable generated after the build process.
   - Mandelbrot set:
   ```bash
    ./fractol Mandelbrot
    ```
   
   - Julia set : you can generate different fractol playing with the 2 parameters after the Julia argument.
     For instance the 2 following example creates nice fractals:
     
    ```bash
    ./fractol Julia -0.8 0.156
    ```
    
    ```bash
    ./fractol Julia 0 1
    ```
   

