#include <assert.h>

#include <iostream>
#include <stack>
#include <vector>

namespace Connected_Components {
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

    void explore(std::vector<std::vector<int>> adj, int u,
                 std::vector<bool> *visited) {
        (*visited)[u] = true;
        std::cout << u << " ";
        for (auto v : adj[u]) {
            if (!(*visited)[v]) {
                explore(adj, v, visited);
            }
        }
    }

    int getConnectedComponents() {
        int connected_components = 0;
        std::vector<bool> visited(vertices, false);
        for (int i = 0; i < vertices; i++) {
            if (!(visited[i])) {
                explore(adjlists, i, &visited);
                connected_components++;
                std::cout << std::endl;
            }
        }
        return connected_components;
    }
};  // namespace graph
};  // namespace Connected_Components

int main() {
    Connected_Components::Graph g(5);  // 5 vertices numbered from 0 to 4
    g.add_edge(1, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    int ans1 = g.getConnectedComponents();
    std::cout << "Number of connected compomemet: " << ans1 << std::endl;
    std::cout << std::endl;
    Connected_Components::Graph g1(6);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(3, 1);
    g1.add_edge(4, 5);
    int ans2 = g1.getConnectedComponents();
    std::cout << "Number of connected compomemet: " << ans2 << std::endl;
}