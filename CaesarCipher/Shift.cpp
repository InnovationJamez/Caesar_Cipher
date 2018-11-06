#include "Shift.h"

Shift::Shift(std::string inFile, std::string outFile)
	:inputFileName(inFile), outputFileName(outFile)
{
	inputFile.open("C:/Users/lehoej/Desktop/Visual Studio/CaesarCipher/InputFiles/" + inputFileName, std::ofstream::in);
	outputFile.open("C:/Users/lehoej/Desktop/Visual Studio/CaesarCipher/OutputFiles/" + outputFileName, std::ofstream::out | std::ofstream::trunc);

	if (inputFile.is_open() && this->outputFile.is_open())
	{
		readFile();
		closeInputFile();
		shiftString();
		writeFile();
		closeOutputFile();
	}
	else {
		std::cout << "error opening files" << std::endl;
	}
}

Shift::~Shift(){
}

void Shift::readFile(){
	inputString.assign((std::istreambuf_iterator<char>(inputFile)),
		(std::istreambuf_iterator<char>()));
}

void Shift::closeInputFile() {
	inputFile.close();
}

void Shift::shiftString() {
	for (int i = 0; i < (int)inputString.size(); i++) {
		if (upperCheck(inputString[i])) {
			inputString[i] = ALPHABET[index + 1];
		}if (lowerCheck(inputString[i])) {
			inputString[i] = alphabet[index + 1];
		}
	}
}

bool Shift::upperCheck(char letter) {
	for (int i = 0; i < (int)ALPHABET.size(); i++) {
		if (letter == ALPHABET[i]) {
			index = i;
			if (index == 25) {
				index = 0;
			}
			return true;
		}
	}
	return false;
}

bool Shift::lowerCheck(char letter) {
	for (int i = 0; i < (int)alphabet.size(); i++) {
		if (letter == alphabet[i]) {
			index = i;
			if (index == 25) {
				index = 0;
			}
			return true;
		}
	}
	return false;
}

void Shift::writeFile() {
	for (int i = 0; i < (int)inputString.size(); i++) {
		outputFile << inputString[i];
	}
}

void Shift::closeOutputFile() {
	outputFile.close();
}