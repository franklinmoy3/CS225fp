#include <string>
#include <unordered_set>

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

  map.clear();
  map2.clear();

  // Create two-way map
  for(std::vector<string> route : routes){
    if(!map2[route[0]].contains(route[1])){
      map[route[0]].push_back(route);
      map2[route[0]].insert(route[1]);
    }
    if(!map2[route[1]].contains(route[0])){
      map[route[1]].push_back(route);
      map2[route[1]].insert(route[0]);
    }
  }
}

std::vector<std::string> Graph::dfs(){
  path.clear();
  visited.clear();
  return dfs("AER");
}

std::vector<std::string> Graph::dfs(std::string source_airport){
  //use set to keep track of visited points
  //use std::vector path to keep track of path
  for(int i = 0; i < map[source_airport].size(); i++){
    if(visited.contains(map[source_airport][i][0]) && visited.contains(map[source_airport][i][1])){
      continue;
    }
    if(!visited.contains(map[source_airport][i][0])){
      visited.insert(map[source_airport][i][0]);
      path.push_back(map[source_airport][i][0]);
      dfs(map[source_airport][i][0], path);
    }
    if(!visited.contains(map[source_airport][i][1])){
      visited.insert(map[source_airport][i][1]);
      path.push_back(map[source_airport][i][1]);
      dfs(map[source_airport][i][1], path);
    }
  }
}


int Graph::getEdgeWeight(Vertex source, Vertex destination)
{
    return route[source][destination].getWeight();
}