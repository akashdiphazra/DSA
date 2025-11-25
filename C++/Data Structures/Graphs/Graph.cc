#include <iostream>
#include <list>
#include <map>
#include <vector>
#define MAX_VERTICES 4  // Maximum number of vertices in the graph

class Graph1 {
 private:
  int V;                            // Number of vertices
  std::vector<std::list<int>> adj;  // Adjacency list

 public:
  Graph1(int V) {
    this->V = V;
    adj.resize(V);
  }

  // Add edge to the graph
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // comment for a directed graph
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

  // Simplified print of the adjacency matrix
  void Print_Matrix_Graph() {
    // Create a matrix filled with 0s
    std::vector<std::vector<int>> matrix(V, std::vector<int>(V, 0));

    // Set 1s where edges exist
    for (int i = 0; i < V; ++i) {
      for (int neighbor : adj[i]) {
        matrix[i][neighbor] = 1;
      }
    }

    // Print the adjacency matrix
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        std::cout << matrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};

class Graph2 {
 private:
  int V;                                    // Number of vertices
  std::vector<std::vector<int>> adjMatrix;  // Adjacency matrix
  std::vector<std::vector<int>> adj;        // Adjacency matrix
 public:
  // Constructor to initialize graph with V vertices
  Graph2(int V) {
    this->V = V;
    adjMatrix.resize(V, std::vector<int>(V, 0));
    adj.resize(V);
  }

  // Add edge to both adjacency matrix and adjacency list
  void addEdge(int u, int v, bool undirected = true) {
    // Adjacency matrix update (for undirected graph)
    adjMatrix[u][v] = 1;
    if (undirected == true) {
      adjMatrix[v][u] = 1;  // comment for directed
    }

    // Adjacency list update (for undirected graph)
    adj[u].push_back(v);
    if (undirected == true) {
      adj[v].push_back(u);  // comment for directed
    }
  }

  // Print the adjacency matrix
  void printAdjMatrix() {
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        std::cout << adjMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  // Print the adjacency list
  void printAdjList() {
    std::cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
      std::cout << i << ": ";
      for (int neighbor : adj[i]) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }
};

// Weighted Graphs
class Graph3 {
 private:
  int V;  // Number of vertices
  // std::vector<std::list<std::pair<int, int>>> adj;
  // OR
  std::vector<std::vector<std::pair<int, int>>> adj;

 public:
  Graph3(int V) {
    this->V = V;
    adj.resize(V);
  }

  // Add weighted edge
  void addEdge(int u, int v, int weight, bool undirected = true) {
    adj[u].push_back({v, weight});
    if (undirected == true) {
      adj[v].push_back({u, weight});  // For undirected graph
    }
  }

  // Print the graph with weights
  void printGraph() {
    for (int i = 0; i < V; ++i) {
      std::cout << "Vertex (" << i << "): ";
      for (auto& neighbor : adj[i]) {
        std::cout << " (" << neighbor.first << ") -> " << neighbor.second;
      }
      std::cout << std::endl;
    }
  }
};

template <typename T>
class Graph4 {
 private:
  std::map<T, std::list<T>> adj;

 public:
  // Optional Constuctor
  Graph4() = default;
  /*
   Graph4(T V) {
     for (int i = 0; i < V; ++i) {
       adj[i] = std::list<T>();  // Initialize each vertex with an empty list
     }
   }
  */
  void addEdge(T u, T v, bool undirected = true) {
    adj[u].push_back(v);
    if (undirected == true) {
      adj[v].push_back(u);  // For undirected graph
    }
  }

  // Print the graph
  void printGraph() {
    for (auto& pair : adj) {
      std::cout << "Vertex " << pair.first << ": ";
      for (T neighbor : pair.second) {
        std::cout << "-> ";
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }
};

// This is sparse matrix it takes extra unused space and with time complexity
// O(n^2)
class Graph5 {
 public:
  // Number of vertices in the graph
  int vertices;
  // Adjacency matrix for the graph
  int** adjMatrix;
  // Constructor to initialize the graph with given vertices
  Graph5(int v) {
    vertices = v;

    // Dynamically allocate memory for the adjacency matrix
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
      adjMatrix[i] = new int[vertices];
    }

    // Initialize all the elements of the adjacency matrix to 0
    for (int i = 0; i < vertices; ++i) {
      for (int j = 0; j < vertices; ++j) {
        adjMatrix[i][j] = 0;
      }
    }
  }

  // Function to add an edge between vertex u and vertex v
  void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;  // For undirected graph, we set both [u][v] and [v][u]
  }

  // Function to display the adjacency matrix
  void displayGraph() {
    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < vertices; ++i) {
      for (int j = 0; j < vertices; ++j) {
        std::cout << adjMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  // Destructor to deallocate memory
  ~Graph5() {
    for (int i = 0; i < vertices; ++i) {
      delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
  }
};

class Graph6 {
 public:
  int adjMatrix[MAX_VERTICES][MAX_VERTICES];  // Adjacency matrix for the graph
  int vertices;

  // Constructor to initialize the graph with a fixed number of vertices
  Graph6(int v) {
    vertices = v;
    // Initialize the adjacency matrix to 0 (no edges)
    for (int i = 0; i < vertices; ++i) {
      for (int j = 0; j < vertices; ++j) {
        adjMatrix[i][j] = 0;
      }
    }
  }
  // Function to add an edge between vertex u and vertex v
  void addEdge(int u, int v, bool undirected = true) {
    if (u < vertices && v < vertices) {
      adjMatrix[u][v] = 1;
      if (undirected == true) {
        adjMatrix[v][u] = 1;
      }
    }
  }

  // Function to display the adjacency matrix
  void displayGraph() {
    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < vertices; ++i) {
      for (int j = 0; j < vertices; ++j) {
        std::cout << adjMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main1() {
  Graph1 g(4);  // Create a graph with 5 vertices
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.Print_Graph();
  printf("\n");
  g.Print_Graph();
  return 0;
}

int main2() {
  // Create a graph with 4 vertices
  Graph2 g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  // Print the adjacency matrix and adjacency list
  g.printAdjMatrix();
  std::cout << std::endl;
  g.printAdjList();
  return 0;
}

int main3() {
  Graph3 g(5);
  g.addEdge(0, 1, 10);
  g.addEdge(0, 4, 20);
  g.addEdge(1, 2, 30);
  g.addEdge(1, 3, 40);
  g.addEdge(1, 4, 50);
  g.addEdge(2, 3, 60);
  g.addEdge(3, 4, 70);
  g.printGraph();
  return 0;
}

int main4() {
  Graph4<std::string> g;  // Optional
  g.addEdge("Gorakhpur", "Lucknow", false);
  g.addEdge("Gorakhpur", "Kanpur", false);
  g.addEdge("Lucknow", "Agra", false);
  g.addEdge("Kanpur", "Agra", false);
  g.addEdge("Lucknow", "Prayagraj", false);
  g.addEdge("Agra", "Noida", false);
  g.printGraph();
  return 0;
}

int main5() {
  // Create a graph with 4 vertices
  Graph5 g(4);
  // Add some edges
  g.addEdge(0, 1);  // Add edge between vertex 0 and vertex 1
  g.addEdge(0, 2);  // Add edge between vertex 0 and vertex 2
  g.addEdge(1, 3);  // Add edge between vertex 1 and vertex 3
  // Display the graph's adjacency matrix
  g.displayGraph();

  return 0;
}

int main6() {
  // Create a graph with 4 vertices (0, 1, 2, 3)
  Graph6 g(4);
  // Add some edges
  g.addEdge(0, 1);  // Add edge between vertex 0 and vertex 1
  g.addEdge(0, 2);  // Add edge between vertex 0 and vertex 2
  g.addEdge(1, 3);  // Add edge between vertex 1 and vertex 3
  // Display the graph's adjacency matrix
  g.displayGraph();

  return 0;
}

int main() { main2(); }
