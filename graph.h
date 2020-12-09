
#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <set>


class Graph{
    private:
      std::vector<std::vector<string>> airports;
      std::vector<std::vector<string>> routes;
      //std::map<string, std::vector<std::vector<string>>> map;
      std::map<std::string, std::map<std::string, double>> adj_list;
      //std::map<string, std::set<string>> map2;
    public:
      Graph();
      std::vector dfs();
      void dfs(std::string source_airport);
      Graph::getEdgeWeight(Vertex source, Vertex destination);
      std::set<std::string> visited;
      std::vector<std::string> path;
};