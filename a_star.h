#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "graph.h"

class Astar{
    private:
        Graph graph;
        int node_count;
    public:
        Astar(Graph g);
};