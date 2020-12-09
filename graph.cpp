#include <iostream>
#include <string>
#include <set>
#include <cmath>

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
  routes = parse_CSV("dataset/routes_simplified.csv");
  airports = parse_CSV("dataset/airports_simplified.csv");

  adj_list.clear();

  node_count = 0;

  // Create two-way adj_list
  for(std::vector<std::string> route : routes){
    if(adj_list.find(route[0]) == adj_list.end()){
      node_count++;
      std::map<std::string, double> new_list;
      adj_list[route[0]] = new_list;
    }
    (adj_list[route[0]])[route[2]] = std::stod(route[3]);
    if(adj_list.find(route[2]) == adj_list.end()){
      node_count++;
      std::map<std::string, double> new_list;
      adj_list[route[2]] = new_list;
    }
    (adj_list[route[2]])[route[0]] = std::stod(route[3]);
  }
}

void Graph::printDFS(){
  std::cout << "Generated DFS Traversal : " << std::endl;
  for(auto itr = visited.begin(); itr != visited.end(); ++itr) {
    std::cout << *itr << "->";
  }
}

void Graph::dfs(){
  path.clear();
  visited.clear();
  dfs("AER");
}

void Graph::dfs(std::string source_airport){
  //use set to keep track of visited points
  //use std::vector path to keep track of path
  std::vector<std::string> dest_airports;
  for(auto element : adj_list[source_airport]){
    dest_airports.push_back(element.first);
  }
  for(int i = 0; i < adj_list[source_airport].size(); i++){
    if(visited.find(dest_airports[i]) == visited.end()){
      visited.insert(dest_airports[i]);
      path.push_back(dest_airports[i]);
      dfs(dest_airports[i]);
    }
  }
}


double Graph::getEdgeWeight(std::string source, std::string destination){
    return adj_list[source][destination];
}

// Haversine formula used to find distance that will be used as the weights
  
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