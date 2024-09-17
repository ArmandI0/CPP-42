#include <iostream>
#include <fstream>
#include <string>

std::string	replace(std::string str, size_t pos, size_t lenght, std::string word)
{
	std::string NewStr;
	std::string	Tmp;

	NewStr.assign(str, 0, pos);
	NewStr.append(word);
	Tmp.assign(str, pos + lenght, str.length());
	NewStr.append(Tmp);
	return NewStr;
}

int main(int ac, char **av)
{

	if (ac != 4)
		return (1);
	std::string	str;
	std::string out;
	int	pos;
	std::ifstream infile(av[1]);
	std::string s_word = av[2];
	if(infile)
	{
		while(getline(infile, str))
		{
			while((pos = str.find(s_word)) != -1)
				str = replace(str, pos, s_word.length(), av[3]);
			out.append(str);
			out.append("\n");
		}
		std::string OutfileName;
		OutfileName.append(av[1]);
		OutfileName.append(".replace");

		std::ofstream outfile(OutfileName.c_str());
		outfile << out;
		return 0;
	}
	std::cout << "Bad infile" << std::endl;
}