
#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>


class Graph{
    private:
      std::vector<std::vector<string>> airports;
      std::vector<std::vector<string>> routes;
      std::map<string, std::vector<std::vector<string>>> map;
      std::map<string, std::set<string>> map2;
    public:
      Graph();
      std::vector dfs();
      std::vector dfs(std::string source_airport, std::vector<string> path);
      Graph::getEdgeWeight(Vertex source, Vertex destination);
      std::unordered_set<string> visited;
      std::vector<string> path;
};