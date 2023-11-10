workspace "UTest"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    project "UTest"
        location "UTest"
        kind "StaticLib"
        language "C++"

        targetdir("build/" ..outputdir .. "/%{prj.name}")
        objdir("build-int/" ..outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/includes/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "%{prj.name}/includes"
        }

        links
        {
			Sandbox
        }

        filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
        }

        filter "configurations:Debug"
        defines "UTEST_DEBUG"
        symbols "on"

        filter "configurations:Release"
        defines "UTEST_RELEASE"
        optimize "on"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir("build/" ..outputdir .. "/%{prj.name}")
        objdir("build-int/" ..outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/includes/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "UTest/includes",
			"%{prj.name}/includes"
        }

        links
        {
            "UTest"
        }

        filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
        }

        filter "configurations:Debug"
        defines "UTEST_DEBUG"
        symbols "on"

        filter "configurations:Release"
        defines "UTEST_RELEASE"
        optimize "on"
