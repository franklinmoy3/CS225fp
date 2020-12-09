#include <iostream>
#include <vector>
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
	else if(argv[1] == "A*") {
		if(argc != 4) {
			std::cout << "Usage : ./finalproj A* sourceAirport destinationAirport";
			return 420; // hehe
		}
		else {

		}
	}

	// Prims has no args
	else if(argv[1] == "prims") {
		if(argc > 2) {
			std::cout << "Usage : ./finalproj prims";
			return 69420; // hehe
		}
		mainPrim.primsMST();
	}

	// DFS can have one arg (source airport) or no args
	else if(argv[1] == "dfs") {
		if(argc > 3) {
			std::cout << "Usage : ./finalproj dfs sourceAirport";
			return 1738; // hehe
		}
		if(argc == 2) {
			mainGraph.dfs();
		}
		else {
			mainGraph.path.clear();
			mainGraph.visited.clear();
			mainGraph.dfs(argv[2]);
		}
	}

	// Invalid arguments handler
	else {
		std::cout << "Your input couldn't be interpreted. Please follow the instructions in the README and try again.";
		return 69; // hehe
	}
	return 0;
}