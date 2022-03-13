#include "Files.h"

std::string Files::readFile(const char* directory)
{
	std::ifstream file(directory);
	SkipBOM(file);
	std::string lineContents;
	std::string fileContents;
	
	while (getline(file, lineContents)) {
		fileContents += lineContents + "\n";
	}

	file.close();
	return fileContents;
}

void Files::SkipBOM(std::istream& in)
{
	char test[3] = { 0 };
	in.read(test, 3);
	if ((unsigned char)test[0] == 0xEF &&
		(unsigned char)test[1] == 0xBB &&
		(unsigned char)test[2] == 0xBF)
	{
		return;
	}
	in.seekg(0);
}
