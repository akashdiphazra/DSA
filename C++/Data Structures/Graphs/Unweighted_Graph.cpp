#include <assert.h>

#include <iostream>
#include <vector>

namespace Graph {
class Graph {
 private:
    int vertices;
    std::vector<std::vector<int>> adjlists;

 public:
    Graph(int v) {
        vertices = v;
        adjlists.resize(v);
    }

    void add_edge(int u, int v) {
        this->adjlists[u].push_back(v);
        this->adjlists[v].push_back(u); /* For undirected graph */
    }

    void print_graph() {
        for (int i = 0; i < vertices; i++) {
            std::cout << i << " ➡ ";
            for (auto v : adjlists[i]) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }
};
};  // namespace Graph

int main() {
    Graph::Graph g(6);
    g.add_edge(0, 1);
    g.add_edge(1, 5);
    g.add_edge(5, 4);
    g.add_edge(4, 0);
    g.add_edge(4, 3);
    g.add_edge(3, 2);
    g.add_edge(0, 2);
    g.print_graph();
    return 0;
}