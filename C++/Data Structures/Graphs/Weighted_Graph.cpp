#include <iostream>
#include <vector>

namespace Graph {
class Graph {
 private:
    int vertices;
    std::vector<std::vector<std::pair<std::uint64_t, std::uint64_t>>> adjlists;

 public:
    Graph(int v) {
        vertices = v;
        adjlists.resize(v);
    }
    void add_edge(int u, int v, int wt) {
        adjlists[u].push_back(std::make_pair(v, wt));
        adjlists[v].push_back(std::make_pair(u, wt));
    }
    void print_graph() {
        for (long long unsigned int i{0}; i < adjlists.size(); i++) {
            for (long long unsigned int j{0}; j < adjlists[i].size(); j++) {
                std::cout << i << " ⬅➡ " << adjlists[i][j].first << " ➡ "
                          << adjlists[i][j].second << std::endl;
            }
        }
    }
};
};  // namespace Graph

int main() {
    Graph::Graph g(5);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 4, 20);
    g.add_edge(1, 2, 30);
    g.add_edge(1, 3, 40);
    g.add_edge(1, 4, 50);
    g.add_edge(2, 3, 60);
    g.add_edge(3, 4, 70);
    g.print_graph();
    return 0;
}