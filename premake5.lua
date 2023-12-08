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
        links { "winmm", "vorbisenc", "vorbisfile", "vorbis", "ogg", "flac", "gdi32", "freetype", "opengl32", "sfml-main" }
    end
    if _ACTION == "gmake2" then
        libdirs { "Dependencies/lib/mingw" }
        links { "winmm:static", "vorbisenc:static", "vorbisfile:static", "vorbis:static", "ogg:static", "flac:static", "gdi32:static", "freetype:static", "opengl32:static", "sfml-main:static" }
    end

    filter "configurations:Debug"
        if _ACTION == "vs2022" then
            links { "sfml-system-s-d", "sfml-window-s-d", "sfml-graphics-s-d", "sfml-audio-s-d","sfml-network-s-d" }
        end
        if _ACTION == "gmake2" then
            links { "sfml-system-s-d:static", "sfml-window-s-d:static", "sfml-graphics-s-d:static", "sfml-audio-s-d:static", "sfml-network-s-d:static" }
        end
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        if _ACTION == "vs2022" then
            links { "sfml-system-s", "sfml-window-s", "sfml-graphics-s", "sfml-audio-s", "sfml-network-s" }
        end
        if _ACTION == "gmake2" then
            links { "sfml-system-s:static", "sfml-window-s:static", "sfml-graphics-s:static", "sfml-audio-s:static", "sfml-network-s:static" }
        end

        defines { "NDEBUG" }
        optimize "On"