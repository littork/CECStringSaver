#include "StringSaver.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

std::vector<std::string> StringSaver::split(const std::string& strToSplit, const char& delimiter) {
	std::stringstream ss(strToSplit);
	std::string item;
	std::vector<std::string> splittedStrings;
	bool consume = false;
	while (std::getline(ss, item, delimiter))
	{
		if (consume) {
			consume = false;
			splittedStrings[splittedStrings.size() - 1] = splittedStrings[splittedStrings.size() - 1] + delimiter + item;
			continue;
		}

		if (item.at(item.length() - 1) == '\\') {
			consume = true;
		}
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}

std::string StringSaver::encode(const std::string& input, const char& delimiter) {
	std::string resultantString = "";

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == delimiter) {
			resultantString += '\\';
		}
		
		resultantString += input[i];
	}

	return resultantString;
}

std::string StringSaver::decode(const std::string& input, const char& delimiter) {
	std::string resultantString = "";

	for (int i = 0; i < input.length(); i++) {
		if (input.length() - 1 > i && input[i] == '\\' && input[i + 1] == delimiter) {
			resultantString += delimiter;
			i++;
			continue;
		}

		resultantString += input[i];
	}

	return resultantString;
}

void StringSaver::save(const std::string& path, const std::vector<std::string>& data, const char& delimiter) {
	std::ofstream file;
	file.open(path);
	for (unsigned int i = 0; i < data.size(); i++) {
		file << encode(data[i], delimiter);
		if (data.size() - 1 != i) {
			file << delimiter;
		}
	}
	file.close();
}

std::vector<std::string> StringSaver::load(const std::string& path, const char& delimiter) {
	std::ifstream file;
	file.open(path);

	std::string readResult = "";
	std::string line;
	while (std::getline(file, line)) {
		readResult += line;
	}
	file.close();

	std::vector<std::string> splitResult = split(readResult, delimiter);

	for (unsigned int i = 0; i < splitResult.size(); i++) {
		splitResult[i] = decode(splitResult[i], delimiter);
	}

	return splitResult;
}