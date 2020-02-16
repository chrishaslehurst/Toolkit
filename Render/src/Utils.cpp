#include "Utils.h"
#include <fstream>

std::string utilities::LoadFile(const char* path)
{
	std::ifstream ifs(path);
	if (ifs.is_open())
	{
		std::string contents;
		ifs.seekg(0, std::ios::end);
		contents.resize(ifs.tellg());
		ifs.seekg(0, std::ios::beg);
		ifs.read(&contents[0], contents.size());
		ifs.close();
		return(contents);
	}
	else
	{
		return { "FAILED TO OPEN FILE!" };
	}
}
