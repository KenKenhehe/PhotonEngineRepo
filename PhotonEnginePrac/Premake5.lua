workspace "PhotonEngineSln"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PhotonEngine"
	location "PhotonEngine"
	
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"PH_BUILD_DLL",
			"PH_PLATFORM_WINDOWS"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
		}

	filter "configurations: Debug"
		defines "PH_DEBUG"
		symbols "On"


	filter "configurations: Release"
		defines "PH_RELEASE"
		optimize "On"

	filter "configurations: Dist"
		defines "PH_DIST"
		optimize "On"

project "Game"
	location "Game"
	kind "consoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"PhotonEngine/vendor/spdlog/include",
		"PhotonEngine/src"
	}

	links{
		"PhotonEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"PH_PLATFORM_WINDOWS"
		}

	filter "configurations: Debug"
		defines "PH_DEBUG"
		symbols "On"


	filter "configurations: Release"
		defines "PH_RELEASE"
		optimize "On"

	filter "configurations: Dist"
		defines "PH_DIST"
		optimize "On"
		

	