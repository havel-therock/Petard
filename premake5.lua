workspace "Petard"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Petard/vendor/GLFW/include"
IncludeDir["GLAD"] = "Petard/vendor/GLAD/include"
IncludeDir["imgui"] = "Petard/vendor/imgui"	
IncludeDir["glm"] = "Petard/vendor/glm"

include "Petard/vendor/GLFW"
include "Petard/vendor/GLAD"
include "Petard/vendor/imgui"

project "Petard"
	location "Petard"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "pdpch.h"
	pchsource "Petard/src/pdpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PD_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PD_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PD_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Petard/vendor/spdlog/include",
		"Petard/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Petard"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PD_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PD_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PD_DIST"
		runtime "Release"
		optimize "on"