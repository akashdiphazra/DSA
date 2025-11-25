#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Graph {
 private:
  int V;
  std::vector<std::vector<std::pair<int, int>>> adj;

 public:
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  // Add weighted edge (undirected by default)
  void addEdge(int u, int v, int weight, bool undirected = true) {
    adj[u].push_back({v, weight});
    if (undirected) {
      adj[v].push_back({u, weight});  // For undirected graph
    }
  }

  // Print the graph with weights (for visualization/debugging)
  void printGraph() const {
    for (int i = 0; i < V; ++i) {
      std::cout << "Vertex (" << i << "): ";
      for (auto& neighbor : adj[i]) {
        std::cout << " (" << neighbor.first << ") -> " << neighbor.second;
      }
      std::cout << std::endl;
    }
  }

  // Function to print the edges in the MST
  void printMSTEdges(const std::vector<int>& parent) const {
    std::cout << "Edges in the MST:" << std::endl;
    for (int i = 1; i < V; i++) {
      int u{parent[i]}, v{i}, weight{0};
      // Find the weight of the edge between u and v
      for (const auto& neighbor : adj[u]) {
        if (neighbor.first == v) {
          weight = neighbor.second;
          break;
        }
      }
      std::cout << u << " - " << v << " with weight " << weight << std::endl;
    }
  }

  // Prim's Algorithm to find MST and its minimum cost, starting from a given
  // vertex
  int Prim(int start_vertex = 0) {
    // Priority queue to maintain edges with respect to weights
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        Q;
    std::vector<bool> marked(V, false);  // Track vertices included in MST
    std::vector<int> parent(V, -1);      // Track parent of each vertex
    int minimum_cost = 0;                // Total cost of the MST

    // Start with the given start_vertex (default is vertex 0)
    Q.push(std::make_pair(0, start_vertex));  // Push (weight, vertex) pair

    while (!Q.empty()) {
      // Select the edge with minimum weight (the vertex with the smallest edge
      // weight)
      std::pair<int, int> p = Q.top();  // (edge_weight, vertex)
      Q.pop();
      int x = p.second;  // Get the vertex of the edge

      // If the vertex is already included in MST, skip it
      if (marked[x]) {
        continue;
      }

      // Add the edge weight to the total minimum cost
      minimum_cost += p.first;
      marked[x] = true;  // Mark the vertex as part of the MST

      // Explore all adjacent vertices of the current vertex
      for (const std::pair<int, int>& neighbor : adj[x]) {
        int y = neighbor.first;        // Adjacent vertex
        int weight = neighbor.second;  // Edge weight

        // If the adjacent vertex is not yet in the MST, add it to the priority
        // queue
        if (!marked[y]) {
          Q.push(std::make_pair(
              weight, y));  // Push (edge_weight, vertex) pair to the queue
          parent[y] = x;    // Set the parent of vertex y as x
        }
      }
    }
    // Print the MST edges
    printMSTEdges(parent);
    // Return the total minimum cost of the MST
    return minimum_cost;
  }
};

int main() {
  // Create a graph with 5 vertices
  Graph g(5);

  // Add edges to the graph (undirected graph)
  g.addEdge(0, 1, 2);
  g.addEdge(0, 2, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 3, 2);
  g.addEdge(3, 4, 1);
  g.addEdge(4, 2, 2);

  // Print the graph
  g.printGraph();

  // Ask the user for the starting vertex (optional)
  // Run Prim's Algorithm to find MST and its minimum cost
  int minimum_cost = g.Prim();
  std::cout << "The minimum cost of the MST is: " << minimum_cost << std::endl;

  return 0;
}
