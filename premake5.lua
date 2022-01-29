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
include "Petard/vendor/GLFW"
include "Petard/vendor/GLAD"

project "Petard"
	location "Petard"
	kind "SharedLib"
	language "C++"

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
		"%{IncludeDir.GLAD}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PD_PLATFORM_WINDOWS",
			"PD_BUILD_DLL"
		}

		--- change this in to prebuild comend before every gameproject

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PD_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PD_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PD_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Petard/src"
	}

	links
	{
		"Petard"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		-- defines "PD_DEBUG"
		buildoptions "/MDd"
		-- linkoptions { '/NODEFAULTLIB:"LIBCMT"' }
		symbols "On"

	filter "configurations:Release"
		-- defines "PD_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		-- defines "PD_DIST"
		buildoptions "/MD"
		optimize "On"