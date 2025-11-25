#include <iostream>
#include <list>
#include <vector>

class Graph {
 private:
  int V;                            // Number of vertices
  std::vector<std::list<int>> adj;  // Adjacency list

 public:
  // Constructor to initialize the graph with V vertices
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  // Add edge to the graph
  void addEdge(int u, int v, bool undirected = true) {
    adj[u].push_back(v);
    if (undirected) {
      adj[v].push_back(u);  // For undirected graphs, add the reverse edge
    }
  }

  // Print the graph (for debugging purposes)
  void __Print_Graph__() {
    for (int i = 0; i < V; ++i) {
      std::cout << "Vertex " << i << ": ";
      for (int neighbor : adj[i]) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }

  // Recursive DFS function to explore the graph
  void dfs(int node, std::vector<bool>& visited, std::vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        dfs(neighbor, visited, component);
      }
    }
  }

  void findConnectedComponents() {
    std::vector<bool> visited(V, false);  // To keep track of visited nodes
    int number{0};

    // Traverse all nodes to find unvisited nodes
    for (int i = 0; i < V; ++i) {
      if (!visited[i]) {
        std::vector<int> component;
        dfs(i, visited, component);  // Start DFS for an unvisited node
        number++;                    // Increment connected components counter

        // Print the current connected component
        std::cout << "Component " << number << ": ";
        for (int node : component) {
          std::cout << node << " ";
        }
        std::cout << "\n";
      }
    }
    std::cout << "Number of Connected Components: " << number << std::endl;
  }
};

int main() {
  // Create a graph with 6 vertices
  Graph g(6);
  // Add edges (example for undirected graph)
  g.addEdge(0, 4);
  g.addEdge(0, 5);
  g.addEdge(1, 3);
  g.addEdge(2, 2);
  g.findConnectedComponents();

  return 0;
}
