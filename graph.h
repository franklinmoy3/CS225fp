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
      std::vector<std::vector<std::string>> airports;
      std::vector<std::vector<std::string>> routes;
      std::map<std::string, std::map<std::string, double>> adj_list;
    public:
      Graph();
      void dfs();
      void dfs(std::string source_airport);
      void printDFS();
      double getEdgeWeight(std::string source, std::string destination);
      std::set<std::string> visited;
      std::vector<std::string> path;
      long double distance(long double lat1, long double long1, long double lat2, long double long2);
      long double deg2rad(long double degree);
      int node_count;
};
