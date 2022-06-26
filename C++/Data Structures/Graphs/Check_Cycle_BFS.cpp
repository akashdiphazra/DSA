// https://csacademy.com/app/graph_editor/
#include <assert.h>

#include <iostream>
#include <queue>
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

    bool BFS_Iterative(std::vector<std::vector<int>> adj, int s, int vert,
                       std::vector<bool>& visited) {
        std::vector<int> parent(vert, -1);
        std::queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adjlists[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    parent[v] = u;
                } else if (parent[u] != v)
                    return true;
            }
        }
        return false;
    }

    bool Check_Cycle_BFS() {
        std::vector<bool> visited(vertices, false);
        for (int i = 0; i < vertices; i++)
            if (!visited[i] && BFS_Iterative(adjlists, i, vertices, visited))
                return true;
        return false;
    }
};
};  // namespace Graph

void test() {
    Graph::Graph g1(3);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    assert(g1.Check_Cycle_BFS() == false);
    std::cout << "Test Case 1: Passed" << std::endl;
    Graph::Graph g2(5);
    g2.add_edge(1, 0);
    g2.add_edge(0, 2);
    g2.add_edge(2, 1);
    g2.add_edge(0, 3);
    g2.add_edge(3, 4);
    assert(g2.Check_Cycle_BFS() == true);
    std::cout << "Test Case 2: Passed" << std::endl;
    Graph::Graph g3(7);
    g3.add_edge(0, 1);
    g3.add_edge(1, 2);
    g3.add_edge(2, 0);
    g3.add_edge(2, 5);
    g3.add_edge(3, 5);
    assert(g3.Check_Cycle_BFS() == true);
    std::cout << "Test Case 3: Passed" << std::endl;
    Graph::Graph g4(6);
    g4.add_edge(0, 1);
    g4.add_edge(1, 5);
    g4.add_edge(5, 4);
    g4.add_edge(4, 0);
    g4.add_edge(4, 3);
    g4.add_edge(3, 2);
    g4.add_edge(0, 2);
    assert(g4.Check_Cycle_BFS() == true);
    std::cout << "Test Case 4: Passed" << std::endl;
}

int main() {
    test();
    return 0;
}
