#include <iostream>
#include <queue>
#include <stack>
#include <vector>

namespace Topological_Sort {
class Graph {
 private:
  int vertices;
  std::vector<std::vector<int>> adjlists;

 public:
  Graph(int v) {
    vertices = v;
    adjlists.resize(v);
  }

  void add_edge(int u, int v) { adjlists[u].push_back(v); }

  void print_graph() {
    for (int i = 0; i < vertices; i++) {
      std::cout << i << " ➡ ";
      for (auto v : adjlists[i]) {
        std::cout << v << " ";
      }
      std::cout << std::endl;
    }
  }

  void Depth_First_Search(std::vector<std::vector<int>> adj, int v,
                          std::vector<bool> &visited, std::stack<int> &st) {
    visited[v] = true;
    for (auto u : adj[v]) {
      if (!visited[u]) {
        Depth_First_Search(adj, u, visited, st);
      }
    }
    st.push(v);
  }

  void topological_sort() {
    std::stack<int> mystack;
    std::vector<bool> visited(vertices, false);
    for (int i = 0; i < vertices; i++) {
      if (!visited[i]) {
        Depth_First_Search(adjlists, i, visited, mystack);
      }
    }
    std::cout << "\nTopological Sort: ";
    while (!mystack.empty()) {
      std::cout << mystack.top() << " ";
      mystack.pop();
    }
  }

  void Kahn_Algorithm() {
    std::vector<int> indgree(vertices, 0);
    std::queue<int> myqueue;

    // Calculate the in-degree for each vertex
    for (int u = 0; u < vertices; u++) {
      for (auto it : adjlists[u]) {
        indgree[it]++;
      }
    }

    // Push vertices with in-degree 0 into the queue
    for (int i = 0; i < vertices; i++) {
      if (indgree[i] == 0) {
        myqueue.push(i);
      }
    }

    int count = 0;
    std::vector<int> toporder;

    // Process vertices from the queue
    while (!myqueue.empty()) {
      int u = myqueue.front();
      myqueue.pop();
      toporder.push_back(u);
      count++;  // Increment count as we process a vertex

      // For each adjacent vertex, reduce the in-degree and push if it becomes 0
      for (auto it : adjlists[u]) {
        if (--indgree[it] == 0) {
          myqueue.push(it);
        }
      }
    }

    // If count doesn't match number of vertices, there's a cycle
    if (count != vertices) {
      std::cout << "\nCycle detected! Topological sort not possible.\n";
      return;
    }

    // Output the topological sort order
    std::cout << "\nTopological Sort: ";
    for (int i = 0; i < int(toporder.size()); i++) {
      std::cout << toporder[i] << " ";
    }
    std::cout << std::endl;
  }
};

}  // namespace Topological_Sort

int main() {
  Topological_Sort::Graph g(6);
  g.add_edge(5, 2);
  g.add_edge(5, 0);
  g.add_edge(4, 0);
  g.add_edge(4, 1);
  g.add_edge(2, 3);
  g.add_edge(3, 1);

  // Test Kahn's Algorithm
  g.Kahn_Algorithm();

  return 0;
}
