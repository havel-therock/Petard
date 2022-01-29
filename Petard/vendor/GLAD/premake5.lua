project "GLAD"
	kind "StaticLib"
	language "C"

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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		buildoptions "/MD"
		optimize "On"

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"