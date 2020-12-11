#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <fstream>
#include <limits.h>

#include "landmark.h"
#include "prims.h"

Landmark::Landmark(Graph g){
    Graph = g;
    node_count = g.node_count;
}

void Landmark::BFS(airport1, airport2){
    // call BFS on MST from Prims
    visited.insert(airport1);
    path.push_back(airport1);
    for(auto element : adj_list[airport1]){
        adj_list.push_back(element.first);
    }
    for(size_t i = 0; i < adj_list[airport1].size(); i++){
        if(visited.find(adj_list[i]) == visited.find(adj_list[airport2])){
        BFS(adj_list[i]);
        }
    }
}

void Landmark::printLandmarkPath(path){
    std::ofstream outFile("landmark_output.txt");
    for(auto airport : adj_list){
        outFile << parent[airport.first] << " - " << airport.first << " \t" << (adj_list[airport.first])[parent[airport.first]] << " \n";
    }
    outFile.close();
    std::cout << "Landmark path written to landmark_output.txt" << std::endl;
}

void Landmark::landmark(source, landmark, destination){
    path1 = BFS(source, landmark);
    path2 = BFS(landmark, destination);
    printLandmarkPath(path1+path2);
}