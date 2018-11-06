#pragma once

#include<string>
#include<fstream>
#include<iostream>
#include<vector>

class Shift
{
private:
	int index;
	std::vector<char> alphabet {'a','b','c','d','e','f','g','h','i','j','k','l','m',
								'n','o','p','q','r','s','t','u','v','w','x','y','z'};
	std::vector<char> ALPHABET {'A','B','C','D','E','F','G','H','I','J','K','L','M',
								'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	std::string inputFileName, inputString, outputFileName;
	std::fstream inputFile, outputFile;
public:
	Shift(std::string inFile, std::string outFile);
	~Shift();
	void readFile();
	void closeInputFile();
	bool upperCheck(char letter);
	bool lowerCheck(char letter);
	void shiftString();
	void writeFile();
	void closeOutputFile();
};

