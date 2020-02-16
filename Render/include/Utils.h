// #todo-2020/01/27:  consider factoring this out into its own module with other shared functions (math, file io etc)
#include <stdint.h>
#include <string>

namespace kraken { namespace utilities {

	std::string LoadFile(const char* path);

}}