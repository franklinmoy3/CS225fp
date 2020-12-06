#pragma once
#include <string>

/** 
 * Reads a file into a string
 * @param filename The file to read from 
 * @return a string containing filename's contents
 */
std::string file_to_string(const std::string & filename);

/** 
 * Reads a file into a vector
 * @param filename The file to read from
 * @return a vector of vectors containing elements from each line from CSV
 */
std::vector<std::vector<std::string>> file_to_vector(const std::string & filename);