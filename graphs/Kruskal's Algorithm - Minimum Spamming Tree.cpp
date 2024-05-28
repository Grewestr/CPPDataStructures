/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>
#include <algorithm>

#define V 5 // Number of vertices in the graph

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

// Function to find the root of the set in which element `i` belongs
int find(std::vector<Subset> &subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to do union of two sets of `x` and `y`
void Union(std::vector<Subset> &subsets, int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Function to implement Kruskal's algorithm
void kruskal(std::vector<Edge> &edges) {
    std::vector<Subset> subsets(V);
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    std::sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    std::vector<Edge> result;
    for (auto edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        if (x != y) {
            result.push_back(edge);
            Union(subsets, x, y);
        }
    }

    std::cout << "Edges in the minimum spanning tree:" << std::endl;
    for (auto edge : result)
        std::cout << edge.src << " -- " << edge.dest << " == " << edge.weight << std::endl;
}

int main() {
    // Initialize the graph with edges and weights
    std::vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    // Perform Kruskal's algorithm
    kruskal(edges);

    return 0;
}
