#include <algorithm>
#include <array>
#include <atomic>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
constexpr int64_t INF = std::numeric_limits<int64_t>::max();

namespace Shortest_Path {
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
    void Dijkstra(int src) {
        /// n denotes the number of vertices in graph
        int n = adjlists.size();

        /// setting all the distances initially to INF
        std::vector<int64_t> dist(n, INF);

        /// creating a min heap using priority queue
        /// first element of pair contains the distance
        /// second element of pair contains the vertex
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;

        /// pushing the source vertex 's' with 0 distance in min heap
        pq.push(std::make_pair(0, src));

        /// marking the distance of source as 0
        dist[src] = 0;

        while (!pq.empty()) {
            /// second element of pair denotes the node / vertex
            int currentNode = pq.top().second;

            /// first element of pair denotes the distance
            int currentDist = pq.top().first;

            pq.pop();

            /// for all the reachable vertex from the currently exploring vertex
            /// we will try to minimize the distance
            for (std::pair<int, int> edge : adjlists[currentNode]) {
                /// minimizing distances
                if (currentDist + edge.second < dist[edge.first]) {
                    dist[edge.first] = currentDist + edge.second;
                    pq.push(std::make_pair(dist[edge.first], edge.first));
                }
            }
        }
        for (int i = 0; i < vertices; ++i)
            std::cout << i << " ➡ " << dist[i] << std::endl;
    }
};
};  // namespace Shortest_Path

int main() {
    Shortest_Path::Graph g(9);
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
    g.print_graph();
    std::cout << "Dijkstra Algorithm: " << std::endl;
    g.Dijkstra(0);
    return 0;
}