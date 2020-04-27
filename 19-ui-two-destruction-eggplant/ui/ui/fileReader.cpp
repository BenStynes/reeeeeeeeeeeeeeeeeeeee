#include "fileReader.h"

void fileReader::readFile(const std::string t_fileName)
{
	std::ifstream inputFile;
	inputFile.open("Shaders//" + t_fileName);

	if (inputFile.is_open())
	{
		std::string fileInfo;
		std::string line;


		while (std::getline(inputFile, line))
		{
			int length = line.length();

			int size = line.size();

			for (int charachter = 0; charachter < length; charachter++)
			{

				if (line[charachter] == '\\' && (charachter + 1) < size)
				{
					if (line[charachter + 1] == 'n')
					{
						fileInfo += '\n';
					}
					else if (line[charachter + 1] == 'r')
					{
						fileInfo += '\r';
					}

					charachter++;
				}

				else
				{
					fileInfo += line[charachter];
				}
			}


		}
		inputFile.close();

		
	}
	else
	{
		throw(std::exception{ "Couldnt opem the shader file." });
	}

}

void fileReader::writefile(const std::string t_fileName,std::string t_passedIninfo)
{
	std::ofstream myfile;
	myfile.open(t_fileName);
	myfile << t_passedIninfo;
	myfile.close();
}
