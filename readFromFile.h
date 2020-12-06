#pragma once
#include <string>

/** 
 * Reads a file into a string
 * @param filename The file to read from 
 * @return a string containing filename's contents
 */
std::string file_to_string(const std::string & filename);

/** 
 * Use to read airports.dat into a vector
 * @param filename The file to read from
 * @return a vector of vectors containing elements from each line from CSV
 */
std::vector<std::vector<std::string>> parse_airports(const std::string & filename);

/** 
 * Use to read routes.dat into a vector
 * @param filename The file to read from
 * @return a vector of vectors containing elements from each line from CSV
 */
std::vector<std::vector<std::string>> parse_routes(const std::string & filename);