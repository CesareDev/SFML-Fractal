# SFML-Fractal

C++ application for rendering multiple fractal set using the [*SFML*](https://www.sfml-dev.org/index.php) libraries

## Description

In this application there are two types of fractal:

* [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set)
* [Julia set](https://en.wikipedia.org/wiki/Julia_set)

The implementatin uses two fragment shaders, one for each set, to optmize the calculus.

## Build

Clone the repo, open the **Visual Studio** solution, and build the **SFML-Fractal** project. 

## Usage

Command to use the application:
| Command                          | Action                       |
| :---------------------:          | :--------------------------: |
| Tab                              | Switch between fractals      |
| W,A,S,D                          | Move the camera              |
| &uarr; (Arrow up)                | Zoom in                      |
| &darr; (Arrow down)              | Zoom out                     |
| Left click & drag (Julia set)    | Choose the complex parameter |

## TO-DO
- [ ] Build system for other platforms
- [ ] Enhance the fractal colors
- [ ] Add more fractal