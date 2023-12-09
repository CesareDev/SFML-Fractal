workspace "SFML-Fractal"
    configurations { "Debug", "Release" }
    architecture "x64" 

project "SFML-Fractal"
    location("SFML-Fractal")
    kind "ConsoleApp"
    language "C++"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"
    
    files { "**.h", "**.hpp", "**.cpp", "**.glsl", "**.ttf" }

    defines { "SFML_STATIC" }

    includedirs { "SFML-Fractal/src" }
    includedirs { "Dependencies/include" }

    filter "configurations:Debug"
        if _ACTION == "vs2022" then
            libdirs { "Dependencies/lib/vc" }
            links { 
                "sfml-main-d",
                "sfml-graphics-s-d",
                "sfml-system-s-d",
                "sfml-window-s-d",
                "sfml-audio-s-d",
                "opengl32",
                "winmm",
                "gdi32",
                "openal32",
                "flac",
                "vorbisenc",
                "vorbisfile",
                "vorbis",
                "ogg",
                "freetype"
            }
        elseif _ACTION == "gmake2" then
            libdirs { "Dependencies/lib/mingw" }
            links { 
                "sfml-main-d:static",
                "sfml-network-s-d:static",
                "sfml-audio-s-d:static",
                "sfml-graphics-s-d:static",
                "sfml-window-s-d:static", 
                "sfml-system-s-d:static",
                "opengl32:static",
                "winmm:static", 
                "gdi32:static", 
                "openal32:static",
                "flac:static", 
                "vorbisenc:static", 
                "vorbisfile:static", 
                "vorbis:static", 
                "ogg:static", 
                "freetype:static", 
            }
        end
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        if _ACTION == "vs2022" then
            libdirs { "Dependencies/lib/vc" }
            links { 
                "sfml-main",
                "sfml-graphics-s",
                "sfml-system-s",
                "sfml-window-s",
                "sfml-audio-s",
                "opengl32",
                "winmm",
                "gdi32",
                "openal32",
                "flac",
                "vorbisenc",
                "vorbisfile",
                "vorbis",
                "ogg",
                "freetype"
            }
        elseif _ACTION == "gmake2" then
            libdirs { "Dependencies/lib/mingw" }
            links { 
                "sfml-main:static",
                "sfml-network-s:static",
                "sfml-audio-s:static",
                "sfml-graphics-s:static",
                "sfml-window-s:static", 
                "sfml-system-s:static",
                "opengl32:static",
                "winmm:static", 
                "gdi32:static", 
                "openal32:static",
                "flac:static", 
                "vorbisenc:static", 
                "vorbisfile:static", 
                "vorbis:static", 
                "ogg:static", 
                "freetype:static", 
            }
        end
        defines { "NDEBUG" }
        optimize "On"