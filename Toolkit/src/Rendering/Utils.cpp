#include "Rendering/Utils.h"
#include <fstream>
#include "CoreMinimal.h"

namespace toolkit {

	namespace utilities
	{
		std::string LoadFile(const char* path)
		{
			std::ifstream ifs(path);			
			if (ifs.is_open())
			{
                TK_CORE_INFO("Successfully loaded file: {}", path);
				std::string contents;
				ifs.seekg(0, std::ios::end);
				contents.resize(ifs.tellg());
				ifs.seekg(0, std::ios::beg);
				ifs.read(&contents[0], contents.size());
				ifs.close();
				return (contents);
			}
			else
			{
				TK_CORE_ERROR("FAILED TO OPEN FILE!");
				return { "" };
			}
		}
	} // namespace utilities
}