#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <fstream>
#include <limits.h>

#include "landmark.h"

Landmark::Landmark(Graph & g){
    graph = g;
    node_count = g.node_count;
    adj_list = g.adj_list;
}

// void Landmark::printLandmarkPath(std::vector<std::string> path){
    // std::ofstream outFile("landmark_output.txt");
    // outFile << "Generated Landmark Path" << std::endl;
//     for(auto airport : path){
//         outFile << airport << "->" << std::endl;
//     }
//     outFile << "End landmark path: Destination reached";
//     outFile.close();
// }

void Landmark::printLandmarkPath(std::map<std::string, std::string> parent)
{  
    // Open output file for writing
    std::ofstream outFile("landmark_output.txt");
    outFile << "Generated Landmark Path" << std::endl;
    // Print out all edges and weights in the MST
    std::string airport = "JFK";
    while(airport != "None"){
        outFile << airport << " - " << parent[airport] << " \t" << (adj_list[airport])[parent[airport]] << " \n";
    }
    outFile.close();
}

// Returns the closest airport that the current airport has a direct flight to.
std::string Landmark::minDistance(std::map<std::string, double> key, std::map<std::string, bool> sptMap) {
    double min_dist = INT_MAX;
    std::string min_index;

    for(auto v : key) {
        if(v.second < min_dist && sptMap[v.first] == false) {
            min_dist = v.second;
            min_index = v.first;
        }
    }
    return min_index;
}

void Landmark::findLandmarkPath() {
    findLandmarkPath("ORD", "JFK", "CMI"); // source, destination, and landmark
}

void Landmark::findLandmarkPath(std::string source, std::string destination, std::string landmark){
    landmarkPath.push_back(source);
    findLandmarkPathHelper(source, landmark);
    landmarkPath.clear();
    findLandmarkPathHelper(landmark, destination);
    std::cout << "Landmark path written to landmark_output.txt" << std::endl;
}

// Basically an adaptation of Dijkstra's SSSP
void Landmark::findLandmarkPathHelper(std::string sourceAirport, std::string destAirport) {
    // Map of distances from source airport, holds shortest distance from source to airport (each airport is a key)
    std::map<std::string, double> dist;
    // Map (shortest-path tree) describing whether or not a certain vertex was visited
    std::map<std::string, bool> sptMap;
    // Parent array used to keep track of the path
    std::map <std::string, std::string> parent;

    //Initialize sptMap to all false
    for(auto itr = graph.airports.begin(); itr != graph.airports.end(); ++itr) {
        //dist.insert({itr->first, INT_MAX});
        sptMap.insert({itr->first, false});
    }

    // Distance between source and itself is zero
    dist[sourceAirport] = 0;
    parent[sourceAirport] = "None";

    // Run search until we get to our destination
    while(sptMap[destAirport] == false) {
        // Get the airport closest to the current airport and traverse to it
        std::string u = minDistance(dist, sptMap);
        sptMap[u] = true;
        
        // Update the distance of the vertices adjacent to the traversed vertex
        for(auto v : adj_list[u]) {
            // If the distances data structure does not have the node connected to u
            // and it is unvisited, insert the new node into key with its value
            // as INT_MAX
            if(dist.find(v.first) == dist.end() && sptMap[v.first] == false) {
                dist.insert({v.first, INT_MAX});
            }
            // Only update the distance of the adjacent airport if it is not visited already
            if(sptMap[v.first] == false && v.second + dist[u] < dist[v.first]) {
                parent[v.first] = u;
                dist[v.first] = dist[u] + v.second;
            }
        }
        // Push the visited vertex into the landmark path record
        //landmarkPath.push_back(u);
    }
    printLandmarkPath(parent);
}