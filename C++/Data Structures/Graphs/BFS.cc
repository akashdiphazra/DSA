#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

class Graph1 {
 private:
  int V;
  std::vector<std::list<int>> adj;

 public:
  Graph1(int V) {
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
  void __Print_Graph__() {
    for (int i = 0; i < V; ++i) {
      std::cout << "Vertex " << i << ": ";
      for (int neighbor : adj[i]) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }

  void __BFS_Queue__(int start, std::vector<bool>& visited) {
    std::queue<int> q;  // Queue for BFS
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      std::cout << node << " ";  // Print the current node

      // Visit all adjacent nodes
      for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);  // Push to queue
        }
      }
    }
    std::cout << std::endl;
  }

  // Breadth first search using vector
  // Too much slow not recommended
  void __BFS_Vector__(int start, std::vector<bool>& visited) {
    std::vector<int> visited_nodes;  // Vector to simulate the queue
    visited[start] = true;
    visited_nodes.push_back(start);  // Push the start node into the vector

    std::cout << "BFS starting from vertex " << start << ": ";

    while (!visited_nodes.empty()) {
      int node = visited_nodes[0];  // Take the front of the "queue"
      visited_nodes.erase(visited_nodes.begin());
      std::cout << node << " ";

      // Visit all adjacent nodes
      for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          visited_nodes.push_back(neighbor);
        }
      }
    }
    std::cout << std::endl;
  }

  // Find all connected components using stack for BFS
  void __BFS_Explore__(int start = 0, bool bfs_queue = true,
                       bool bfs_vector = false) {
    std::vector<bool> visited(V, false);  // Keep track of visited vertices
    if (bfs_queue) {
      for (int i = start; i < V; i++) {
        if (!visited[i]) {
          __BFS_Queue__(i, visited);
        }
      }
    } else if (bfs_vector) {
      for (int i = start; i < V; i++) {
        if (!visited[i]) {
          __BFS_Vector__(i, visited);
        }
      }
    }
  }
};

template <typename T>
class Graph2 {
 private:
  std::map<T, std::list<T>> adj;  // Adjacency list using std::map

 public:
  Graph2() {}

  // Add edge to the graph
  void addEdge(T u, T v, bool undirected = true) {
    adj[u].push_back(v);
    if (undirected) {
      adj[v].push_back(u);  // Comment out for directed graph
    }
  }

  // BFS traversal using std::map
  void __BFS_Map__(T start, std::map<T, bool>& visited) {
    std::queue<T> q;  // Queue for BFS traversal
    visited[start] = true;
    q.push(start);

    std::cout << "BFS traversal starting from vertex " << start << ": ";

    while (!q.empty()) {
      T node = q.front();
      q.pop();  // Remove the front node from the queue

      std::cout << node << " ";  // Process the current node

      for (T neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);  // Enqueue unvisited neighbors
        }
      }
    }
    std::cout << std::endl;
  }

  // Print the graph (for visualization)
  void __Print_Graph__() {
    for (auto& pair : adj) {
      std::cout << pair.first << ": ";
      for (T neighbor : pair.second) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }

  void __BFS_Explore__(T start) {
    std::map<T, bool> visited;
    // First, start BFS from the given start vertex
    if (adj.find(start) != adj.end() && !visited[start]) {
      __BFS_Map__(start, visited);
    }
  }
};

int main2() {
  std::cout << "For Integer Graphs: " << std::endl;
  Graph2<int> g;  // Create a graph with 5 vertices
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 2);
  g.__Print_Graph__();
  g.__BFS_Explore__(0);

  std::cout << "For String Graphs: " << std::endl;
  Graph2<std::string> g2;  // Create a graph with string-based vertices

  // Add edges to the graph
  g2.addEdge("Gorakhpur", "Lucknow", false);
  g2.addEdge("Gorakhpur", "Kanpur", false);
  g2.addEdge("Lucknow", "Agra", false);
  g2.addEdge("Kanpur", "Agra", false);
  g2.addEdge("Lucknow", "Prayagraj", false);
  g2.addEdge("Agra", "Noida", false);

  // Print the graph's adjacency list
  std::cout << "Graph adjacency list:" << std::endl;
  g2.__Print_Graph__();
  g2.__BFS_Explore__("Kanpur");

  return 0;
}

int main1() {
  Graph1 g(5);  // Create a graph with 5 vertices
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 2);
  g.__Print_Graph__();
  std::cout << "Breath First Search: ";
  g.__BFS_Explore__(false, true);
  return 0;
}

int main() {
  main1();
  return 0;
}
