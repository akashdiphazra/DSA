#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {
 private:
  int V;                            // Number of vertices
  std::vector<std::list<int>> adj;  // Adjacency list

 public:
  // Constructor
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  // Add edge to the graph
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // For an undirected graph
  }

  // Function to check if the graph is bipartite
  bool isBipartite() {
    // Array to store color of nodes. -1 means uncolored.
    std::vector<int> color(V, -1);

    // Queue for BFS
    std::queue<int> q;

    // We need to check each component of the graph
    for (int start = 0; start < V; ++start) {
      if (color[start] == -1) {  // If the node is uncolored, start a BFS
        q.push(start);
        color[start] = 0;  // Assign a color to the start node (0 or 1)

        // BFS traversal
        while (!q.empty()) {
          int node = q.front();
          q.pop();

          // Check all adjacent nodes
          for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
              // If the neighbor is uncolored, assign the opposite color
              color[neighbor] = 1 - color[node];
              q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
              // If the neighbor has the same color, it's not bipartite
              return false;
            }
          }
        }
      }
    }
    return true;
  }

  // Print the graph (adjacency list)
  void Print_Graph() {
    for (int i = 0; i < V; ++i) {
      std::cout << "Vertex " << i << ": ";
      for (int neighbor : adj[i]) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  // Create a graph with 4 vertices
  Graph g(4);

  // Add edges to the graph
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(0, 3);

  // Check if the graph is bipartite
  if (g.isBipartite()) {
    std::cout << "The graph is bipartite." << std::endl;
  } else {
    std::cout << "The graph is not bipartite." << std::endl;
  }

  return 0;
}
