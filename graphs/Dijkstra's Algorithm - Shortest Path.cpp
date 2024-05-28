/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <climits>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the shortest path from the source to all vertices
void printSolution(int dist[]) {
    std::cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        std::cout << i << " \t\t " << dist[i] << std::endl;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0; // Distance of source vertex from itself is always 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Pick the minimum distance vertex from the set of vertices not yet processed
        sptSet[u] = true; // Mark the picked vertex as processed

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist); // Print the constructed distance array
}

int main() {
    // Initialize the adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 0, 0},
        {10, 0, 5, 0, 0},
        {0, 5, 0, 15, 0},
        {0, 0, 15, 0, 20},
        {0, 0, 0, 20, 0}
    };

    // Perform Dijkstra's algorithm starting from vertex 0
    dijkstra(graph, 0);

    return 0;
}
