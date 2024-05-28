/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>
#include <climits>

#define V 5 // Number of vertices in the graph
#define E 8 // Number of edges in the graph

struct Edge {
    int src, dest, weight;
};

// Function to print the shortest path from the source to all vertices
void printSolution(int dist[]) {
    std::cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        std::cout << i << " \t\t " << dist[i] << std::endl;
}

// Function to implement Bellman-Ford algorithm
void bellmanFord(std::vector<Edge> &edges, int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }

    printSolution(dist);
}

int main() {
    // Initialize the graph with edges and weights
    std::vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1},
        {4, 3, -3}
    };

    // Perform Bellman-Ford algorithm starting from vertex 0
    bellmanFord(edges, 0);

    return 0;
}
