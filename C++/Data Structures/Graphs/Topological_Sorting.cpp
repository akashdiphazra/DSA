#include <assert.h>

#include <iostream>
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
                            std::vector<bool>& visited, std::stack<int>& st) {
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
        std::cout << "Topological Sort: ";
        while (!mystack.empty()) {
            std::cout << mystack.top() << " ";
            mystack.pop();
        }
    }
};
};  // namespace Topological_Sort

int main() {
    Topological_Sort::Graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.topological_sort();
    return 0;
}