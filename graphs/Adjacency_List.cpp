/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>

#define V 5 // Number of vertices in the graph

// Function to add an edge to the adjacency list
void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the adjacency list
void printGraph(std::vector<int> adj[]) {
    for (int i = 0; i < V; i++) {
        std::cout << "Vertex " << i << ":";
        for (int j : adj[i]) {
            std::cout << " -> " << j;
        }
        std::cout << std::endl;
    }
}

int main() {
    // Create an array of vectors to represent the adjacency list
    std::vector<int> adj[V];

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Print the adjacency list
    printGraph(adj);

    return 0;
}
