#include <assert.h>

#include <iostream>
#include <queue>
#include <vector>

namespace Breadth_First_Search {
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
        //  this->adjlists[v].push_back(u);     /* For undirected graph */
    }

    std::vector<int> BFS(int startvertex) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;
        std::vector<int> nodes;
        visited[startvertex] = true;
        q.push(startvertex);
        while (!q.empty()) {
            int currentnode = q.front();
            nodes.push_back(currentnode);
            // std::cout << currentnode << " ";
            q.pop();
            for (std::vector<int>::iterator it = adjlists[currentnode].begin();
                 it != adjlists[currentnode].end(); it++) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
        return nodes;
    }
};
};  // namespace Breadth_First_Search

void test() {
    /* Directed Graph */
    Breadth_First_Search::Graph g1(4);
    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    g1.add_edge(1, 2);
    g1.add_edge(2, 0);
    g1.add_edge(2, 3);
    g1.add_edge(3, 3);
    std::vector<int> res1{2, 0, 3, 1};
    assert(res1 == g1.BFS(2));
    std::cout << "TEST CASE 1 : PASSED" << std::endl;
    /* Undirected Graph */
    // Breadth_First_Search::Graph g2(5);
    // g2.add_edge(0, 1);
    // g2.add_edge(0, 2);
    // g2.add_edge(0, 3);
    // g2.add_edge(1, 2);
    // g2.add_edge(2, 4);
    // g2.add_edge(3, 3);
    // g2.add_edge(4, 4);
    // std::vector<int> res2{0, 1, 2, 3, 4};
    // assert(res2 == g2.BFS(0));
    // std::cout << "TEST CASE 2 : PASSED" << std::endl;
}

int main() {
    test();
    return 0;
}