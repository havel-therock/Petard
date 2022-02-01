project "GLAD"
	kind "StaticLib"
	language "C"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{project_name}")
	objdir ("bin-int/" .. outputdir .. "/%{project_name}")

	files
	{
		"include/glad/glad.h",
		"include/KHR/.khrplatform.h",
		"src/glad.c"
	}

	includedirs
	{
		"include"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

	filter "system:windows"
		systemversion "latest"
		