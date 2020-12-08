#include <string>
#include <vector>

#include "catch/catch.hpp"
#include "../readFromFile.h"


TEST_CASE("parse_CSV correctly parses a small sample") {
	std::vector<std::vector<std::string>> res = parse_CSV("tests/testParse.csv");
	std::vector<std::vector<std::string>> expected = { {"akshayb3", "1", },
													   {"fmoy3", "2"}, 
													   {"vg12", "3"} };
	
	REQUIRE(3 == res.size());

	for (int i = 0; i < res.size(); i++) {
		REQUIRE(expected[i] == res[i]);
	}
}

