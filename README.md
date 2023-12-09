# SFML-Fractal

C++ application for rendering multiple fractal sets using the [*SFML*](https://www.sfml-dev.org/index.php) library

## Description

In this application there are two types of fractal:

* [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set)
* [Julia](https://en.wikipedia.org/wiki/Julia_set)
* [Newton (Nova)](https://en.wikipedia.org/wiki/Newton_fractal)
* [Burning Ship](https://it.wikipedia.org/wiki/Burning_ship)
* [Magnet](https://paulbourke.net/fractals/magnet/)

The implementation uses fragment shaders, one for each set.

## Build

***Windows***

- Visual C++ 17 (2022) - 64 bit

    - Clone the repo and go to the Scripts folder

        ```console
        git clone https://github.com/CesareDev/SFML-Fractal.git
    - Go to the `Sritps` folder

        ```console
        cd SFML-Fractal/Scripts
    - Run the `build-vc.bat` file
    - 
        ```console
        build-vc.bat
    - Return to the `SFML-Fractal` folder and open the `SFML-Fractal.sln` file with *Visual Studio (2022)*.
    - Build the solution and run the application

- GCC 13.1.0 MinGW - 64 bit

    - Clone the repo and go to the Scripts folder

        ```console
        git clone https://github.com/CesareDev/SFML-Fractal.git
    - Go to the `Sritps` folder

        ```console
        cd SFML-Fractal/Scripts
    - Run the `build-mingw.bat` file

        ```console
        build-mingw.bat
    - Return to the `SFML-Fractal` folder and run `make`
        ```console
        make config=debug
        or
        make config=release
    - The binaris are in the `bin` folder
## Usage

Commands to use the application: (temporary)

| Command                       | Action                       |
| :---------------------------: | :--------------------------: |
| Tab                           | Switch between fractals      |
| W,A,S,D                       | Move the camera              |
| &uarr; (Arrow up)             | Zoom in                      |
| &darr; (Arrow down)           | Zoom out                     |
| Left click & drag (Julia set) | Choose the complex parameter |

## TO-DO

- [ ] Build system for other platforms
- [ ] Improve UI
- [x] Enhance coloring

## Credits

- [Coloring Algorithm](http://www.csharphelper.com/howtos/howto_mandelbrot_smooth.html)
- [SFML](https://github.com/SFML/SFML)
- [premake5](https://github.com/premake/premake-core)