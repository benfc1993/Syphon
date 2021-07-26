workspace "Syphon"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Syphon/vendor/GLFW/include"

include "Syphon/vendor/GLFW"

project "Syphon"
	location "Syphon"
	kind "sharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sypch.h"
	pchsource "Syphon/src/sypch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SY_PLATFORM_WINDOWS",
			"SY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}


	filter "configurations:Debug"
		defines "SY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SY_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "consoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Syphon/vendor/spdlog/include",
		"Syphon/src"
	}

	links
	{
		"Syphon"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SY_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SY_DIST"
		optimize "On"