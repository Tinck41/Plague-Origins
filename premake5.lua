workspace "Plague-Origins"
    architecture "x86"
    startproject "Plague-Origins"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}_%{cfg.system}-%{cfg.architecture}" 

include "vendor/imgui"
include "vendor/imgui-sfml"
include "vendor/dragonBones"
include "vendor/box2d"

project "Plague-Origins"
    location "./"
    kind "WindowedApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "stdafx.h"
    pchsource "src/stdafx.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "vendor/dragonBones/src",
        "vendor/EnTT/include",
        "vendor/SFML-2.5.1/include",
        "vendor/imgui",
        "vendor/imgui-sfml",
        "vendor/TGUI-0.9/include",
        "vendor/json/single_include/nlohmann",
        "vendor/box2d/include"
    }

    libdirs
    {
        "vendor/SFML-2.5.1/lib",
        "vendor/TGUI-0.9/lib"
    }

    links 
    { 
        "opengl32.lib",
        "freetype.lib",
        "winmm.lib",
        "gdi32.lib",
        "openal32.lib",
        "flac.lib",
        "vorbisenc.lib",
        "vorbisfile.lib",
        "vorbis.lib",
        "ogg.lib",
        "ws2_32.lib",
        "ImGui",
        "ImGui-SFML",
        "dragonBones",
        "box2d"
    }

    filter "system:windows"
        cppdialect "c++17"
        systemversion "latest"

        defines
        {
            "SFML_STATIC",
            "TGUI_STATIC"
        }

        postbuildcommands
        {
            ("{COPY} %{prj.location.relpath}openal32.dll %{cfg.targetdir}"),
        }
    
    filter "configurations:Debug"
        symbols "On"

        links 
        { 
            "sfml-audio-s-d.lib",
            "sfml-graphics-s-d.lib",
            "sfml-network-s-d.lib",
            "sfml-system-s-d.lib",
            "sfml-window-s-d.lib",
            "tgui-s-d.lib"
        }
    
    filter "configurations:Release"
        symbols "On"

        links 
        { 
            "sfml-audio-s.lib",
            "sfml-graphics-s.lib",
            "sfml-network-s.lib",
            "sfml-system-s.lib",
            "sfml-window-s.lib",
            "sfml-main.lib",
            "tgui-s.lib"
        }
    
    filter "configurations:Dist"
        symbols "On"

        links 
        { 
            "sfml-audio-s.lib",
            "sfml-graphics-s.lib",
            "sfml-network-s.lib",
            "sfml-system-s.lib",
            "sfml-window-s.lib",
            "sfml-main.lib",
            "tgui-s.lib"
        }
