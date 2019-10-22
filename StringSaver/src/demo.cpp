#include "StringSaver.h"

#include <vector>
#include <string>

#include <iostream>

int main() {
	std::vector<std::string> result = { "ax|yz", "b", "c", "d" };

	StringSaver::save("test.txt", result);
	std::vector<std::string> loadResult = StringSaver::load("test.txt");

	for (unsigned int i = 0; i < loadResult.size(); i++) {
		std::cout << "Loaded value: " << loadResult[i] << std::endl;
	}

	std::system("PAUSE");

	return 0;
}