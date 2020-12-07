#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

#include "readFromFile.h"

std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<std::vector<std::string>> parse_CSV(const std::string & filename) {
	// Create file stream and return vector
	std::ifstream fileStream(filename);
	std::string currLine;
	std::vector<std::vector<std::string>> out;

	// Read line by line from file (CSV) stream and place each token into output vector
	if (fileStream.is_open()) {
		while (std::getline(fileStream, currLine)) {
			std::istringstream currLineStream(currLine);
			std::string elem;
			std::vector<std::string> lineVec;
			while (std::getline(currLineStream, elem, ',')) {
				lineVec.push_back(elem);
			}
			out.push_back(lineVec);
		}
	}
	return out;
}