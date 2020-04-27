#pragma once
#include <iostream>
#include <string>
#include <fstream>
/// <summary>
/// Had help from micheal with file reading;
/// </summary>
class fileReader
{

public:
	static void readFile(const std::string t_fileName);
	static void writefile(const std::string t_fileName,std::string t_passedIninfo);
};

