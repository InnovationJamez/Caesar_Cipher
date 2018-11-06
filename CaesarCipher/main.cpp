#include "Shift.h"

int main() {
	std::string input = "input.txt";
	std::string output = "output.txt";
	std::cout << "enter the name of the file you want to encrypt and the output file" << std::endl;
	std::cout << "make shure file is located inside of \"InputFiles folder\"" << std::endl;
	std::cin >> input >> output;
	Shift shiftObj(input, output);
}