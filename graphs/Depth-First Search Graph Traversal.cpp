/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>

#define V 5 // Number of vertices in the graph

// Function to perform DFS traversal
void DFSUtil(int v, bool visited[], std::vector<int> adj[]) {
    visited[v] = true; // Mark the current node as visited
    std::cout << v << " "; // Print the visited node

    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, visited, adj); // Recur for all the vertices adjacent to this vertex
        }
    }
}

void DFS(std::vector<int> adj[], int start) {
    bool visited[V] = {false}; // Mark all the vertices as not visited
    DFSUtil(start, visited, adj); // Call the recursive helper function to print DFS traversal
}

int main() {
    // Create an array of vectors to represent the adjacency list
    std::vector<int> adj[V];

    // Add edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    // Perform DFS traversal starting from vertex 2
    DFS(adj, 2);

    return 0;
}
