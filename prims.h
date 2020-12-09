#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "graph.h"

class Prim{
    private:
        Graph graph;
    public:
        Prim(Graph g);
        void run();
};