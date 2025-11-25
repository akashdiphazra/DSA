#include <iostream>
#include <list>
#include <queue>
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
    if (undirected) {
      adj[v].push_back(u);  // For undirected graph
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

  // DFS Recursive function to check for cycle
  bool DFS_Recursion(int v, std::vector<bool>& visited, int parent) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
      if (!visited[neighbor]) {
        if (DFS_Recursion(neighbor, visited, v)) {
          return true;  // Cycle detected
        }
      } else if (neighbor != parent) {
        return true;  // Cycle detected
      }
    }
    return false;  // No cycle found
  }

  // BFS implementation to detect cycle in an undirected graph
  bool __BFS__(int start, std::vector<bool>& visited) {
    std::queue<int> q;               // Queue for BFS
    std::vector<int> parent(V, -1);  // Vector to store the parent of each node
    q.push(start);                   // Start BFS from the given node
    visited[start] = true;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      // Visit all neighbors of the current node
      for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          parent[neighbor] = node;  // Set the parent of this node
          q.push(neighbor);         // Add neighbor to the queue
        }
        // If the neighbor is visited and is not the parent, a cycle is detected
        else if (neighbor != parent[node]) {
          return true;  // Cycle detected
        }
      }
    }
    return false;  // No cycle found
  }

  // Function to check for cycles using DFS and BFS
  void Check_Cycle(bool bfs = true, bool dfs = false) {
    std::vector<bool> visited(
        V, false);  // Use a boolean vector to track visited nodes

    // DFS if selected
    if (dfs) {
      for (int i = 0; i < V; i++) {
        if (!visited[i]) {
          if (DFS_Recursion(i, visited, -1)) {
            std::cout << "Cycle detected using DFS." << std::endl;
            return;  // Exit after detecting a cycle
          }
        }
      }
    }

    // BFS if selected
    if (bfs) {
      visited.assign(V, false);  // Reset visited array to false
      for (int i = 0; i < V; i++) {
        if (!visited[i]) {
          if (__BFS__(i, visited)) {
            std::cout << "Cycle detected using BFS." << std::endl;
            return;  // Exit after detecting a cycle
          }
        }
      }
    }

    // If no cycle is detected using the selected methods
    std::cout << "No cycle detected in the graph." << std::endl;
  }
};

int main() {
  Graph g(5);

  // Add edges to the graph
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);  // This will create a cycle
  g.addEdge(1, 3);
  g.addEdge(3, 4);

  // Print the graph
  std::cout << "Graph adjacency list:" << std::endl;
  g.Print_Graph();

  std::cout << "\nCycle detection using BFS only:" << std::endl;
  g.Check_Cycle(true, false);  // Check using only BFS

  std::cout << "\nCycle detection using DFS only:" << std::endl;
  g.Check_Cycle(false, true);  // Check using only DFS

  return 0;
}
