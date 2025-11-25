#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {
 private:
  int V;
  std::vector<std::list<int>> adj;

 public:
  Graph(int V) : V(V), adj(V) {}

  void addEdge(int u, int v, bool undirected = true) {
    adj[u].push_back(v);
    if (undirected) adj[v].push_back(u);
  }

  void Print_Graph() {
    for (int i = 0; i < V; ++i) {
      std::cout << "Vertex " << i << ": ";
      for (int neighbor : adj[i]) std::cout << neighbor << " ";
      std::cout << std::endl;
    }
  }

  void Print_Cycle(const std::vector<int>& parent, int u, int v) {
    std::vector<int> path_u, path_v;
    int cur = u;
    while (cur != -1) {
      path_u.push_back(cur);
      cur = parent[cur];
    }
    cur = v;
    while (cur != -1) {
      path_v.push_back(cur);
      cur = parent[cur];
    }
    std::reverse(path_u.begin(), path_u.end());
    std::reverse(path_v.begin(), path_v.end());
    int i = 0, n = std::min(path_u.size(), path_v.size());
    while (i < n && path_u[i] == path_v[i]) ++i;
    --i;
    std::cout << "Cycle found: ";
    for (int j = int(path_u.size()) - 1; j > i; --j)
      std::cout << path_u[j] << " ";
    std::cout << path_u[i] << " ";
    for (int j = i + 1; j < int(path_v.size()); ++j)
      std::cout << path_v[j] << " ";
    std::cout << u << std::endl;
  }

  // Recursive DFS cycle detection
  bool DFS_Recursion(int node, std::vector<bool>& visited, int parentNode) {
    static std::vector<int> parent(V, -1);
    visited[node] = true;
    parent[node] = parentNode;
    for (auto neighbor : adj[node]) {
      if (!visited[neighbor]) {
        if (DFS_Recursion(neighbor, visited, node)) return true;
      } else if (neighbor != parentNode) {
        Print_Cycle(parent, node, neighbor);
        return true;
      }
    }
    return false;
  }

  // BFS with queue cycle detection
  bool __BFS__(int start, std::vector<bool>& visited) {
    std::vector<int> parent(V, -1);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          parent[neighbor] = node;
          q.push(neighbor);
        } else if (parent[node] != neighbor) {
          Print_Cycle(parent, node, neighbor);
          return true;  // cycle detected
        }
      }
    }
    return false;  // no cycle
  }

  // Combined cycle checker
  void Check_Cycle(bool bfs = true, bool dfs = false) {
    std::vector<bool> visited(V, false);

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
      visited.assign(V, false);  // Reset visited vector
      for (int i = 0; i < V; i++) {
        if (!visited[i]) {
          if (__BFS__(i, visited)) {
            std::cout << "Cycle detected using BFS." << std::endl;
            return;  // Exit after detecting a cycle
          }
        }
      }
    }

    std::cout << "No cycle detected in the graph." << std::endl;
  }
};

int main() {
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);  // cycle
  g.addEdge(1, 3);
  g.addEdge(3, 4);

  std::cout << "Graph adjacency list:" << std::endl;
  g.Print_Graph();

  std::cout << "\nCycle check (DFS recursion):" << std::endl;
  g.Check_Cycle(false, true);

  std::cout << "\nCycle check (BFS queue):" << std::endl;
  g.Check_Cycle(true, false);

  std::cout << "\nCycle check (BFS and DFS):" << std::endl;
  g.Check_Cycle(true, true);

  return 0;
}
