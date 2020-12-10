#include <iostream>
#include <vector>
#include <cstring>
#include "graph.h"
#include "a_star.h"
#include "prims.h"
#include "readFromFile.h"

int main(int argc, const char * argv[]) {
	Graph mainGraph;
	Prims mainPrim(mainGraph);
	// PLACE A_STAR VAR HERE
	
	// argv[1] is the first argument, so on...
	// No arguments passed, run all three algos at once with default args
	if(argc == 1) {
		mainGraph.dfs();
		mainGraph.printDFS();
		mainPrim.primsMST();
		// PLACE A_STAR TRAV HERE
	}

	// A* needs two args
	else if(std::strcmp(argv[1], "A*") == 0) {
		if(argc != 4) {
			std::cout << "Usage : ./finalproj A* sourceAirport destinationAirport" << std::endl;
			return 420; // hehe
		}
		else {
			// @TODO
		}
	}

	// Prims has no args
	else if(std::strcmp(argv[1], "prims") == 0) {
		if(argc > 2) {
			std::cout << "Usage : ./finalproj prims" << std::endl;
			return 69420; // hehe
		}
		mainPrim.primsMST();
	}

	// DFS can have one arg (source airport) or no args
	else if(std::strcmp(argv[1], "dfs") == 0) {
		if(argc > 3) {
			std::cout << "Usage : ./finalproj dfs sourceAirport" << std::endl;
			return 1738; // hehe
		}
		if(argc == 2) {
			mainGraph.dfs();
			mainGraph.printDFS();
		}
		else {
			mainGraph.path.clear();
			mainGraph.visited.clear();
			mainGraph.dfs(argv[2]);
			mainGraph.printDFS();
		}
	}

	// Invalid arguments handler
	else {
		std::cout << "Invalid input. Please follow the instructions in the README and try again." << std::endl;
		return 69; // hehe
	}
	return 0;
}