#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "graph.h"

class Prims{
    private:
        Graph adj_list;
        int node_count;
    public:
        Prims(Graph g);
        void primsMST();
        void printMST(std::map<std::string, std::string> parent);
        std::string minKey(std::map<std::string, int> key, std::map<std::string, bool> mstSet);
};