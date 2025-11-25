#include <cstddef>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

class Graph {
 private:
  int V;                            // Number of vertices
  std::vector<std::list<int>> adj;  // Adjacency list

 public:
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  // Add edge to the graph
  void addEdge(int u, int v, bool undirected = true) {
    adj[u].push_back(v);
    if (undirected == true) {
      adj[v].push_back(u);  // comment for directed
    }
  }

  // Print the graph
  void Print_Graph() {
    for (int i = 0; i < V; ++i) {
      std::cout << "Vertex " << i << ": ";
      for (int neighbor : adj[i]) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }

  void __DFS_Stack__(size_t v, std::vector<bool>& visited) {
    visited[v] = true;
    std::stack<size_t> stack;
    stack.push(v);

    while (!stack.empty()) {
      int node = stack.top();
      stack.pop();
      std::cout << node << " ";

      // Visit all adjacent / neighbouring nodes nodes
      for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          stack.push(neighbor);
        }
      }
    }
  }

  // Depth First Search (DFS)
  void __DFS_Recursion__(int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";
    // Visit all the adjacent vertices of v
    for (int neighbor : adj[v]) {
      if (!visited[neighbor]) {
        __DFS_Recursion__(neighbor, visited);
      }
    }
  }

  // Find all connected components
  void __DFS_Explore__(int starv = 0, bool dfs_stack = true,
                       bool dfs_recursion = false) {
    std::vector<bool> visited(V, false);  // Keep track of visited vertices
    if (dfs_stack) {
      for (int i = starv; i < V; i++) {
        if (!visited[i]) {
          __DFS_Stack__(i, visited);
        }
      }
    } else if (dfs_recursion) {
      for (int i = starv; i < V; i++) {
        if (!visited[i]) {
          __DFS_Recursion__(i, visited);
        }
      }
    }
  }
};

int main() {
  Graph g(4);  // Create a graph with 5 vertices
  g.addEdge(0, 1, false);
  g.addEdge(1, 2, false);
  g.addEdge(2, 0, false);
  g.addEdge(2, 3, false);
  g.addEdge(3, 3, false);
  g.Print_Graph();
  g.__DFS_Explore__(false, true);
  return 0;
}
