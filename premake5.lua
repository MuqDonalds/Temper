workspace "Temper"
	architecture "x64"

	configurations
	{

		"Debug",
		"Release",
		"Dist"

	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Temper"
	location "Temper"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/3rdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


		defines
		{
			"TP_PLATFORM_WINDOWS",
			"TEMPER_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "TP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TP_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "TP_DIST"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
	}

	includedirs
	{
		"Temper/3rdParty/spdlog/include",
		"Temper/source"
	}

	links
	{
		"Temper"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TP_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "TP_DIST"
		symbols "On"
