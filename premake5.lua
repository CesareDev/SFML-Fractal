workspace "SFML-Fractal"
    configurations { "Debug", "Release" }
    architecture "x64" 

project "SFML-Fractal"
    location("SFML-Fractal")
    kind "ConsoleApp"
    language "C++"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"
    
    files { "**.h", "**.cpp", "**.glsl", "**.ttf" }

    defines { "SFML_STATIC" }

    includedirs { "SFML-Fractal/src" }
    includedirs { "Dependencies/include" }

    if _ACTION == "vs2022" then
        libdirs { "Dependencies/lib/vc" }
        links { 
            "winmm", 
            "vorbisenc", 
            "vorbisfile", 
            "vorbis", 
            "ogg", 
            "flac", 
            "gdi32", 
            "freetype", 
            "opengl32", 
            "sfml-main"
        }
    elseif _ACTION == "gmake2" then
        libdirs { "Dependencies/lib/mingw" }
        links { 
            "winmm:static", 
            "vorbisenc:static", 
            "vorbisfile:static", 
            "vorbis:static", 
            "ogg:static", 
            "flac:static", 
            "gdi32:static", 
            "freetype:static", 
            "opengl32:static", 
            "sfml-main:static" 
        }
    end

    filter "configurations:Debug"
        if _ACTION == "vs2022" then
            links { 
                "sfml-network-s-d", 
                "sfml-audio-s-d",
                "sfml-graphics-s-d",
                "sfml-window-s-d",
                "sfml-system-s-d"
            }
        elseif _ACTION == "gmake2" then
            links { 
                "sfml-network-s-d:static",
                "sfml-audio-s-d:static",
                "sfml-graphics-s-d:static",
                "sfml-window-s-d:static", 
                "sfml-system-s-d:static",
            }
        end
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        if _ACTION == "vs2022" then
            links { 
                "sfml-network-s",
                "sfml-audio-s",
                "sfml-graphics-s", 
                "sfml-window-s", 
                "sfml-system-s", 
            }
        elseif _ACTION == "gmake2" then
            links { 
                "sfml-network-s:static",
                "sfml-audio-s:static",
                "sfml-graphics-s:static", 
                "sfml-window-s:static", 
                "sfml-system-s:static", 
            }
        end

        defines { "NDEBUG" }
        optimize "On"