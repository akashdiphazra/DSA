#include <iostream>
#include <queue>
#include <stack>
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
        //     this->adjlists[v].push_back(u);
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
    bool is_cyclic(std::vector<std::vector<int>> adj, int s, int V,
                   std::vector<bool>& vis) {
        std::vector<int> parent(V, -1);
        std::queue<int> q;
        vis[s] = true;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    parent[v] = u;
                } else if (parent[u] != v) {
                    return true;
                }
            }
        }
        return false;
    }
    bool Check_Cycle() {
        std::vector<bool> visited(vertices, false);
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && is_cyclic(adjlists, i, vertices, visited)) {
                return true;
            }
        }
        return false;
    }
};
};  // namespace Graph

int main() {
    Graph::Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.add_edge(4, 4);
    g.print_graph();
    std::cout << g.Check_Cycle() << std::endl;
    return 0;
}
