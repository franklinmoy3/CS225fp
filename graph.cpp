#include <string>
#include <set>

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

  adj_list.clear();
  //map2.clear();

  // Create two-way adj_list
  for(std::vector<std::string> route : routes){
    if(adj_list.find(route[0]) == adj_list.end()){
      std::map<std::string, double> new_list;
      adj_list[route[0]] = new_list;
    }
    (adj_list[route[0]])[route[2]] = parseInt(route[3]);
    if(adj_list.find(route[2]) == adj_list.end()){
      std::map<std::string, double> new_list;
      adj_list[route[2]] = new_list;
    }
    (adj_list[route[2]])[route[0]] = parseInt(route[3]);
  }
}

std::vector<std::string> Graph::dfs(){
  path.clear();
  visited.clear();
  return dfs("AER");
}

void Graph::dfs(std::string source_airport){
  //use set to keep track of visited points
  //use std::vector path to keep track of path
  std::vector<std::string> dest_airports;
  for(auto element : adj_list[source_airport]){
    dest_airports.push_back(element.first);
  }
  for(int i = 0; i < adj_list[source_airport].size(); i++){
    if(!visited.contains(dest_airports[i])){
      visited.insert(dest_airports[i]);
      path.push_back(dest_airports[i]);
      dfs(dest_airports[i]);
    }
    // if(visited.contains(map[source_airport][i][0]) && visited.contains(map[source_airport][i][1])){
    //   continue;
    // }
    // if(!visited.contains(map[source_airport][i][0])){
    //   visited.insert(map[source_airport][i][0]);
    //   path.push_back(map[source_airport][i][0]);
    //   dfs(map[source_airport][i][0], path);
    // }
    // if(!visited.contains(map[source_airport][i][1])){
    //   visited.insert(map[source_airport][i][1]);
    //   path.push_back(map[source_airport][i][1]);
    //   dfs(map[source_airport][i][1], path);
    // }
  }
}


int Graph::getEdgeWeight(Vertex source, Vertex destination)
{
    return adj_list[source][destination];
}