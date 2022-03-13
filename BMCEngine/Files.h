#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Files
{
public:
	std::string readFile(const char* directory);
private:
	void SkipBOM(std::istream &in);
};

