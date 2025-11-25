#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class KruskalMST {
 private:
  vector<int> parent, rank;
  vector<pair<int, pair<int, int>>> edges;  // {weight, {u, v}}
  int nodes;

 public:
  // Constructor: Initialize the number of nodes and ranks
  KruskalMST(int nodes) {
    this->nodes = nodes;
    parent.resize(nodes);
    rank.resize(nodes, 0);

    // Initially, each node is its own parent
    for (int i = 0; i < nodes; ++i) {
      parent[i] = i;
    }
    edges.reserve(100);  // Reserve space for up to 100 edges (can be adjusted)
  }

  // Find with path compression
  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]);  // Path compression
    }
    return parent[u];
  }

  // Union by rank
  void join(int u, int v) {
    int rootU = find(u);  // Call find once for each node
    int rootV = find(v);

    if (rootU != rootV) {
      // Union by rank
      if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
      } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
      } else {
        parent[rootV] = rootU;
        rank[rootU]++;  // Increase rank if they are of equal height
      }
    }
  }

  // Add an edge with weight
  void addEdge(int u, int v, int weight) { edges.push_back({weight, {u, v}}); }

  // Kruskal's algorithm to find the MST
  void kruskal() {
    int mstWeight = 0;

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    cout << "Edges in the MST:\n";
    int edgeCount = 0;
    for (auto& edge : edges) {
      int weight = edge.first;
      int u = edge.second.first;
      int v = edge.second.second;

      // If u and v are in different sets, add the edge to the MST
      if (find(u) != find(v)) {
        mstWeight += weight;
        cout << u << " -- " << v << " == " << weight << endl;
        join(u, v);
        edgeCount++;
      }
    }

    // Handle the case when no MST is possible (graph is disconnected)
    if (edgeCount != nodes - 1) {
      cout << "The graph is disconnected, and no MST can be formed." << endl;
    } else {
      cout << "Total weight of MST: " << mstWeight << endl;
    }
  }
};

int main1() {
  int nodes = 6;
  KruskalMST kruskal(nodes);

  // Add edges
  kruskal.addEdge(0, 1, 4);
  kruskal.addEdge(0, 2, 4);
  kruskal.addEdge(1, 2, 2);
  kruskal.addEdge(1, 3, 5);
  kruskal.addEdge(2, 3, 5);
  kruskal.addEdge(2, 4, 7);
  kruskal.addEdge(3, 4, 6);
  kruskal.addEdge(3, 5, 9);
  kruskal.addEdge(4, 5, 3);

  // Run Kruskal's algorithm
  kruskal.kruskal();

  return 0;
}

int main2() {
  KruskalMST g(9);
  // Add edges
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);

  // Run Kruskal's algorithm
  g.kruskal();

  return 0;
}

int main() {
  main1();
  return 0;
}
