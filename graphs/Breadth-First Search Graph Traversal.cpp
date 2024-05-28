/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>
#include <queue>

#define V 5 // Number of vertices in the graph

// Function to perform BFS traversal
void BFS(std::vector<int> adj[], int start) {
    bool visited[V] = {false}; // Mark all the vertices as not visited
    std::queue<int> q; // Create a queue for BFS

    visited[start] = true; // Mark the current node as visited
    q.push(start); // Enqueue the current node

    while (!q.empty()) {
        int v = q.front(); // Dequeue a vertex from queue
        std::cout << v << " "; // Print the dequeued vertex
        q.pop();

        for (int i : adj[v]) {
            if (!visited[i]) {
                visited[i] = true; // Mark the adjacent vertex as visited
                q.push(i); // Enqueue the adjacent vertex
            }
        }
    }
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

    // Perform BFS traversal starting from vertex 2
    BFS(adj, 2);

    return 0;
}
