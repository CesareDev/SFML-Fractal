workspace "SFML-Fractal"
    configurations { "Debug", "Release" }
    architecture "x64" 

project "SFML-Fractal"
    defines { "SFML_STATIC" }
    location("SFML-Fractal")
    kind "ConsoleApp"
    language "C++"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"
    
    files { "**.h", "**.cpp" }
    
    includedirs { "SFML-Fractal/src" }
    includedirs { "Dependencies/include" }
    libdirs { "Dependencies/lib" }

    links { "winmm" }
    links { "vorbisenc" }
    links { "vorbisfile" }
    links { "vorbis" }
    links { "ogg" }
    links { "flac" }
    links { "gdi32" }
    links { "freetype" }
    links { "opengl32" }
    links { "sfml-main" }

    filter "configurations:Debug"
        links { "sfml-system-s-d" }
        links { "sfml-window-s-d" }
        links { "sfml-graphics-s-d" }
        links { "sfml-audio-s-d" }
        links { "sfml-network-s-d" }

        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        links { "sfml-system-s" }
        links { "sfml-window-s" }
        links { "sfml-graphics-s" }
        links { "sfml-audio-s" }
        links { "sfml-network-s" }

        defines { "NDEBUG" }
        optimize "On"