#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

#include "readFromFile.h"

std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<std::vector<std::string>> parse_airports(const std::string & filename) {
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

std::vector<std::vector<std::string>> parse_routes(const std::string & filename) {
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
			/* In routes.dat, there's irrelevant data (everything that not the airport code strings and # of stops).
			   We want to ignore that irrelevant data by erasing it from the vector after that line is parsed
			   before we push it to the output vector. Duplicates are possible and will be ignored if found. 
			   The below is a naive approach to this.
			*/
			lineVec.erase(lineVec.begin(), lineVec.begin() + 2);
			lineVec.erase(lineVec.begin() + 1, lineVec.begin() + 2);
			lineVec.erase(lineVec.begin() + 2, lineVec.begin() + 4);
			lineVec.erase(lineVec.begin() + 3, lineVec.end());
			std::sort(out.begin(), out.end(), 
					  [] (const std::vector<std::string> & lhs, const std::vector<std::string> & rhs)
					  {
						  return lhs[0] < rhs[0];
					  });
			if(std::find(out.begin(), out.end(), lineVec) == out.end())
				out.push_back(lineVec);
		}
	}
	return out;
} 