#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <fstream>

#include "graph.h"
#include "readFromFile.h"

/*
edges in strings represents the routes
the edges are stored in vectors
stops represent the weights of the graph
*/

Graph::Graph(){

  /* When parsing the CSV, be sure not to create
     airport nodes that have already been made.
  */
  routes = parse_CSV("dataset/routes_simplified.csv");  // FORMAT: sourceAirport,destAirport,numStops
  airports_temp = parse_CSV("dataset/airports_simplified.csv");  //FORMAT: airport,latitude,longitude

  adj_list.clear();

  node_count = 0;

  for(std::vector<std::string> an_airport : airports_temp){
    if(airports.find(an_airport[0]) == airports.end()){
      std::vector<std::string> new_vector;
      airports[an_airport[0]] = new_vector;
    }
    airports[an_airport[0]].push_back(an_airport[1]);
    airports[an_airport[0]].push_back(an_airport[2]);
  }
  
  // Create two-way adj_list

  for(std::vector<std::string> route : routes){
    //std::cout << route[0] << " " << route[1] << " " << route[2] << std::endl;
    if(airports.find(route[0]) == airports.end() || airports.find(route[1]) == airports.end()){
      continue;
    }
    if(adj_list.find(route[0]) == adj_list.end()){
      node_count++;
      std::map<std::string, double> new_list;
      adj_list[route[0]] = new_list;
    }
    long double lat1 = std::stold((airports[route[0]])[0]);
    long double long1 = std::stold((airports[route[0]])[1]);
    long double lat2 = std::stold((airports[route[1]])[0]);
    long double long2 = std::stold((airports[route[1]])[1]);
    (adj_list[route[0]])[route[1]] = distance(lat1, long1, lat2, long2);
    if(adj_list.find(route[1]) == adj_list.end()){
      node_count++;
      std::map<std::string, double> new_list;
      adj_list[route[1]] = new_list;
    }
    (adj_list[route[1]])[route[0]] = distance(lat1, long1, lat2, long2);
  }
}

void Graph::printDFS(){
  // Open file stream to write to file
  std::ofstream outFile("dfs_output.txt");
  // Write DFS path to file 
  outFile << "Generated DFS Traversal : " << std::endl;
  for(auto itr = path.begin(); itr != path.end(); ++itr) {
    outFile << *itr << "->" << std::endl;
  }
  outFile << "End of traversal";
  outFile.close();
  // Print message to terminal
  std::cout << "DFS traversal written to dfs_output.txt" << std::endl;
}

void Graph::dfs(){
  // Clear path and visited vectors just in case there's leftovers
  path.clear();
  visited.clear();
  // Run the DFS traversal with the default starting airport: ORD
  dfs("ORD");
}

// Only 3257 nodes exist in the graph, and only 3231 nodes are traversed in DFS. WHY?

void Graph::dfs(std::string source_airport){
  //use set to keep track of visited points
  //use std::vector path to keep track of path
  visited.insert(source_airport);
  path.push_back(source_airport);
  std::vector<std::string> dest_airports;
  for(auto element : adj_list[source_airport]){
    dest_airports.push_back(element.first);
  }
  for(size_t i = 0; i < adj_list[source_airport].size(); i++){
    if(visited.find(dest_airports[i]) == visited.end()){
      dfs(dest_airports[i]);
    }
  }
}

// Haversine formula used to find great-circle distance that will be used as edge weights
long double distance(long double lat1, long double long1, long double lat2, long double long2){ 
    lat1 = deg2rad(lat1); 
    long1 = deg2rad(long1); 
    lat2 = deg2rad(lat2); 
    long2 = deg2rad(long2);
    long double dist = pow(sin((lat2-lat1)/2), 2) + cos(lat1)*cos(lat2)*pow(sin((long2-long1)/2), 2); 
    dist = 2*asin(sqrt(dist));
    dist = dist*6371; // Radius of Earth in km
    return dist;
}

long double deg2rad(long double degree){
    return (degree*(M_PI/180));
}