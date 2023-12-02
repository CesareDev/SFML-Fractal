# SFML-Fractal

C++ application for rendering multiple fractal sets using the [*SFML*](https://www.sfml-dev.org/index.php) library

## Description

In this application there are two types of fractal:

* [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set)
* [Julia](https://en.wikipedia.org/wiki/Julia_set)
* [Newton (Nova)](https://en.wikipedia.org/wiki/Newton_fractal)
* [Burning Ship](https://it.wikipedia.org/wiki/Burning_ship)

The implementatin uses fragment shaders, one for each set.

## Build

Clone the repo, open the **Visual Studio** solution, and build the **SFML-Fractal** project. 

## Usage

Command to use the application:
| Command                       | Action                       |
| :---------------------------: | :--------------------------: |
| Tab                           | Switch between fractals      |
| W,A,S,D                       | Move the camera              |
| &uarr; (Arrow up)             | Zoom in                      |
| &darr; (Arrow down)           | Zoom out                     |
| Left click & drag (Julia set) | Choose the complex parameter |

## Coloring

Formula used for coloring the fractal: `sin(freq * index + phase)` taken by [this post](https://www.paridebroggi.com/blogpost/2015/05/06/fractal-continuous-coloring/)

**Change fractal color**

| Key                        | Action                                |
| :------------------------: | :-----------------------------------: |
| R + F + (&uarr; or &darr;) | change `freq` of the *RED* channel    |
| R + P + (&uarr; or &darr;) | change `phase` of the *RED* channel   |
| G + F + (&uarr; or &darr;) | change `freq` of the *GREEN* channel  |
| G + P + (&uarr; or &darr;) | change `phase` of the *GREEN* channel |
| B + F + (&uarr; or &darr;) | change `freq` of the *BLUE* channel   |
| B + P + (&uarr; or &darr;) | change `phase` of the *BLUE* channel  |

## TO-DO

- [ ] Build system for other platforms

## Credits

- [SFML](https://github.com/SFML/SFML)
