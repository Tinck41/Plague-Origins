project "imgui-sfml"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"*.h",
        "*.cpp"
	}

	includedirs
    {
        "../SFML-2.5.1/include",
        "../imgui"
    }

	libdirs
    {
        "../SFML-2.5.1/lib"
    }

	links 
    { 
        "opengl32.lib",
        "freetype.lib",
        "winmm.lib",
        "gdi32.lib",
        "imgui"
    }

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"

		defines
        {
            "SFML_STATIC"
        }

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

		links 
        { 
            "sfml-graphics-s-d.lib",
            "sfml-system-s-d.lib",
            "sfml-window-s-d.lib",
        }

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

		links 
        { 
            "sfml-graphics-s.lib",
            "sfml-system-s.lib",
            "sfml-window-s.lib"
        }