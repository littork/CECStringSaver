#pragma once

#include <vector>
#include <string>

#include <fstream>

class StringSaver {
public:
	static void save(const std::string& path, const std::vector<std::string>& data, const char& delimiter = '|');
	static std::vector<std::string> load(const std::string& path, const char& delimiter = '|');
private:
	static std::vector<std::string> split(const std::string& strToSplit, const char& delimiter);
private:
	static std::string encode(const std::string& input, const char& delimiter = '|');
	static std::string decode(const std::string& input, const char& delimiter = '|');
};