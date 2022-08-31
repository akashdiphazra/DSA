#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
constexpr int64_t INF = std::numeric_limits<int64_t>::max();

namespace Minimum_Spanning_Tree {
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
    for (long long unsigned int i = 0; i < adjlists.size(); i++) {
      for (long long unsigned int j = 0; j < adjlists[i].size(); j++) {
        std::cout << i << " ⬅➡ " << adjlists[i][j].first << " ➡ "
                  << adjlists[i][j].second << std::endl;
      }
    }
  }

  void Prim() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    int src = 0;
    std::vector<int64_t> key(vertices, INF);
    std::vector<int> parent(vertices, -1);
    std::vector<bool> mst(vertices, false);
    pq.push(std::make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      if (mst[u] == true) {
        continue;
      }
      mst[u] = true; // Include vertex in MST
      for (auto x : adjlists[u]) {
        int v = x.first;
        int weight = x.second;
        if (mst[v] == false && key[v] > weight) {
          key[v] = weight;
          pq.push(std::make_pair(key[v], v));
          parent[v] = u;
        }
      }
    }
    for (int i = 1; i < vertices; ++i) {
      printf("%d ⬅➡ %d ➡ %lld\n", parent[i], i, key[i]);
    }
  }
};
}; // namespace Minimum_Spanning_Tree

int main() {
  Minimum_Spanning_Tree::Graph g(9);
  g.add_edge(0, 1, 4);
  g.add_edge(0, 7, 8);
  g.add_edge(1, 2, 8);
  g.add_edge(1, 7, 11);
  g.add_edge(2, 3, 7);
  g.add_edge(2, 8, 2);
  g.add_edge(2, 5, 4);
  g.add_edge(3, 4, 9);
  g.add_edge(3, 5, 14);
  g.add_edge(4, 5, 10);
  g.add_edge(5, 6, 2);
  g.add_edge(6, 7, 1);
  g.add_edge(6, 8, 6);
  g.add_edge(7, 8, 7);
  g.Prim();
  return 0;
}
