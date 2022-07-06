#include <assert.h>

#include <iostream>
#include <queue>
#include <vector>

namespace Bipartite_Graph {
class Graph {
 private:
    int vertices;
    std::vector<std::vector<int>> adjlists;
    std::vector<int> side;
    std::vector<bool> visited;

 public:
    Graph(int v) {
        vertices = v;
        adjlists.resize(v);
        visited.resize(v, false);
        side.resize(v, -1);
    }

    void add_edge(int u, int v) {
        this->adjlists[u].push_back(v);
        this->adjlists[v].push_back(u); /* For undirected graph */
    }

    // For Iterative Approach
    bool Is_Bipartite_Iterative() {
        bool check = true;
        std::queue<int> q;
        for (int current_edge = 0; current_edge < vertices; ++current_edge) {
            if (side[current_edge] == -1) {
                q.push(current_edge);
                side[current_edge] = 0;
                while (q.size()) {
                    int current = q.front();
                    q.pop();
                    for (auto neighbour : adjlists[current]) {
                        if (side[neighbour] == -1) {
                            side[neighbour] = (1 ^ side[current]);
                            q.push(neighbour);
                        } else {
                            check &= (side[neighbour] != side[current]);
                        }
                    }
                }
            }
        }
        return check;
    }

    // For Recursive Approach
    bool Bipartite_Recursive(std::vector<std::vector<int>> adj, int v,
                             std::vector<bool> &vis, std::vector<int> &color) {
        for (int u : adj[v]) {
            if (vis[u] == false) {
                vis[u] = true;
                color[u] = !color[v];  // mark its color opposite to its parent
                if (!Bipartite_Recursive(adj, u, vis, color)) {
                    return false;
                }
            } else if (color[u] == color[v]) {
                return false;
            }
        }
        return true;
    }

    bool Is_Bipartite_Recursive(int startvertex) {
        visited[startvertex] = true;
        std::vector<int> color(vertices, -1);
        color[startvertex] = 0;
        if (Bipartite_Recursive(adjlists, startvertex, visited, color)) {
            return true;
        } else {
            return false;
        }
        return false;
    }
};
};  // namespace Bipartite_Graph

void test1() {
    std::cout << "For Iterative Solution\n" << std::endl;
    Bipartite_Graph::Graph g1(3);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 0);
    assert(g1.Is_Bipartite_Iterative() == false);
    std::cout << "TEST CASE 1: PASSED" << std::endl;
    Bipartite_Graph::Graph g2(4);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.add_edge(2, 3);
    g2.add_edge(3, 0);
    assert(g2.Is_Bipartite_Iterative() == true);
    std::cout << "TEST CASE 2: PASSED" << std::endl;
    Bipartite_Graph::Graph g3(5);
    g3.add_edge(0, 1);
    g3.add_edge(1, 2);
    g3.add_edge(2, 3);
    g3.add_edge(3, 4);
    assert(g3.Is_Bipartite_Iterative() == true);
    std::cout << "TEST CASE 3: PASSED" << std::endl;
}

void test2() {
    std::cout << "\nFor Recursive Solution\n" << std::endl;
    Bipartite_Graph::Graph g1(3);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 0);
    assert(g1.Is_Bipartite_Recursive(0) == false);
    std::cout << "TEST CASE 1: PASSED" << std::endl;
    Bipartite_Graph::Graph g2(4);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.add_edge(2, 3);
    g2.add_edge(3, 0);
    assert(g2.Is_Bipartite_Recursive(0) == true);
    std::cout << "TEST CASE 2: PASSED" << std::endl;
    Bipartite_Graph::Graph g3(5);
    g3.add_edge(0, 1);
    g3.add_edge(1, 2);
    g3.add_edge(2, 3);
    g3.add_edge(3, 4);
    assert(g3.Is_Bipartite_Recursive(0) == true);
    std::cout << "TEST CASE 3: PASSED" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}