group "Examples"
	project "Memory"
		location "Memory"
		kind "ConsoleApp"
		
		files
		{
			"Memory/**.h",
			"Memory/**.hpp",
			"Memory/**.c",
			"Memory/**.cpp"
		}
		
		links
		{
			"Etanol"
		}