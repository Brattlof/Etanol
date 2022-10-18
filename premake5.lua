workspace "Etanol"
	architecture "x86_64"
	staticruntime "on"
	language "C++"
	cppdialect "C++20"
	characterset "MBCS"
	
	targetdir ("%{wks.location}/Binaries/%{prj.name}/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")
	objdir ("%{wks.location}/Binaries/%{prj.name}/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")
	
	configurations
	{
		"Debug",
		"Release"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
	}
	
	includedirs
	{
		"%{wks.location}/Source",
	}
	
	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"
		
project "Etanol"
	location "Source"
	kind "StaticLib"
	
	files
	{
		"Source/**.c",
		"Source/**.cpp",
		"Source/**.h",
		"Source/**.hpp"
	}
	
include "Examples"