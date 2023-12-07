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

- Clone the repo and go to the Scripts folder

    ```console
    git clone https://github.com/CesareDev/SFML-Fractal.git
- Go to the `Sritps` folder

    ```console
    cd SFML-Fractal/Scripts
- Run the `winbuild.bat` file

    ```console
    winbuild.bat
- Return to the `SFML-Fractal` folder and open the `SFML-Fractal.sln` file with *Visual Studio (2022)*.
- Build the solution and run the application

***...Other platforms coming soon...***

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