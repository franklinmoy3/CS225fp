#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>


#include "prims.h"

Prims::Prims(Graph g){
    adj_list = g;
    node_count = g.node_count;
}

// A C++ program for Prim's Minimum  
// Spanning Tree (MST) algorithm. The program is  
// for adjacency matrix representation of the graph  
  
// Number of vertices in the graph  
// #define V 5  
  
// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST  
std::string minKey(std::map<std::string, int> key, std::map<std::string, bool> mstSet){  
    // Initialize min value  
    int min = INT_MAX;
    std::string min_index;  
  
    for (auto v : mstSet){
        if (v.second == false && key[v.first] < min){
            min = key[v.first];
            min_index = v.first;
        }
    }
  
    return min_index;  
}  
  
// A utility function to print the  
// constructed MST stored in parent[]  
void printMST(std::map<std::string, std::string> parent)  
{  
    std::cout<<"Edge \tWeight\n";
    for(auto airport : adj_list){
        std::cout<<parent[airport.first]<<" - "<<airport.first<<" \t"<<(adj_list[airport.first])[parent[airport.first]]<<" \n";
    }
    // for (int i = 1; i < node_count; i++){
    //     std::cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
    // }
}
  
// Function to construct and print MST for  
// a graph represented using adjacency  
// matrix representation  
void primsMST()  
{  
    // Array to store constructed MST  
    //int parent[V];
    std::map<std::string, std::string> parent;
      
    // Key values used to pick minimum weight edge in cut  
    //int key[V];
    std::map<std::string, int> key;
      
    // To represent set of vertices included in MST  
    //bool mstSet[V];
    std::map<std::string, bool> mstSet;
  
    // Initialize all keys as INFINITE 

    // for (int i = 0; i < V; i++){ 
    //     key[i] = INT_MAX, mstSet[i] = false;  
    // }
  
    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key["AER"] = 0;
    parent["AER"] = "(Ignore Parent of First Airport)"; // First node is always root of MST
  
    // The MST will have V vertices  
    for (int count = 0; count < node_count - 1; count++) 
    {  
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        std::string u = minKey(key, mstSet);  
  
        // Add the picked vertex to the MST Set  
        mstSet[u] = true;  
  
        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST  
        for (auto v : adj_list[u]){
            // graph[u][v] is non zero only for adjacent vertices of m  
            // mstSet[v] is false for vertices not yet included in MST  
            // Update the key only if graph[u][v] is smaller than key[v]  
            if (mstSet[v.first] == false && v.second < key[v.first]){
                parent[v.first] = u;
                key[v.first] = v.second;  
            }
        }
    }  
  
    // print the constructed MST  
    printMST(parent);  
}  
