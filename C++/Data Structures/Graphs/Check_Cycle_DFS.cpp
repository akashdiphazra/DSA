// https://csacademy.com/app/graph_editor/
#include <assert.h>

#include <iostream>
#include <stack>
#include <vector>

namespace Iterataive_DFS_Cycles {
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

    bool DFS_Iterative(std::vector<std::vector<int>> adj, int start,
                       std::vector<bool> vis) {
        std::vector<int> parent(vertices, -1);
        std::stack<int> mystack;
        mystack.push(start);
        vis[start] = true;
        while (!mystack.empty()) {
            int u = mystack.top();
            mystack.pop();
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    mystack.push(v);
                    vis[v] = true;
                    parent[v] = u;
                } else if (parent[u] != v) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Check_Cycle_DFS() {
        std::vector<bool> visited(vertices, false);
        for (int i = 0; i < vertices; i++)
            if (!visited[i] && DFS_Iterative(adjlists, i, visited))
                return true;
        return false;
    }
};
};  // namespace Iterataive_DFS_Cycles

namespace Recursive_DFS_Cycles {
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

    bool Recursive_DFS(int v, std::vector<bool> visited, int parent) {
        if (visited[v] == false) {
            visited[v] = true;
            for (auto it : adjlists[v]) {
                if (!visited[it]) {
                    if (Recursive_DFS(it, visited, v)) {
                        return true;
                    }
                } else if (it != parent)
                    return true;
            }
        }
        return false;
    }

    bool Check_Cycle_DFS() {
        std::vector<bool> visited(vertices, false);
        for (int u = 0; u < vertices; u++) {
            if (!visited[u] && (Recursive_DFS(u, visited, -1))) {
                return true;
            }
        }
        return false;
    }
};
};  // namespace Recursive_DFS_Cycles

void test1() {
    std::cout << "\tITERATIVE DFS PROCESS" << std::endl;
    Iterataive_DFS_Cycles::Graph g1(3);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    assert(g1.Check_Cycle_DFS() == false);
    std::cout << "Test Case 1: Passed" << std::endl;
    Iterataive_DFS_Cycles::Graph g2(5);
    g2.add_edge(1, 0);
    g2.add_edge(0, 2);
    g2.add_edge(2, 1);
    g2.add_edge(0, 3);
    g2.add_edge(3, 4);
    assert(g2.Check_Cycle_DFS() == true);
    std::cout << "Test Case 2: Passed" << std::endl;
    Iterataive_DFS_Cycles::Graph g3(7);
    g3.add_edge(0, 1);
    g3.add_edge(1, 2);
    g3.add_edge(2, 0);
    g3.add_edge(2, 5);
    g3.add_edge(3, 5);
    assert(g3.Check_Cycle_DFS() == true);
    std::cout << "Test Case 3: Passed" << std::endl;
    Iterataive_DFS_Cycles::Graph g4(6);
    g4.add_edge(0, 1);
    g4.add_edge(1, 5);
    g4.add_edge(5, 4);
    g4.add_edge(4, 0);
    g4.add_edge(4, 3);
    g4.add_edge(3, 2);
    g4.add_edge(0, 2);
    assert(g4.Check_Cycle_DFS() == true);
    std::cout << "Test Case 4: Passed" << std::endl;

    Iterataive_DFS_Cycles::Graph g5(4);
    g5.add_edge(0, 1);
    g5.add_edge(1, 2);
    g5.add_edge(2, 0);
    g5.add_edge(2, 3);
    assert(g5.Check_Cycle_DFS() == true);
    std::cout << "Test Case 5: Passed" << std::endl;

    Iterataive_DFS_Cycles::Graph g6(4);
    g6.add_edge(0, 1);
    g6.add_edge(1, 2);
    g6.add_edge(2, 3);
    assert(g6.Check_Cycle_DFS() == false);
    std::cout << "Test Case 6: Passed" << std::endl;
}

void test2() {
    std::cout << "\n\tRECURSIVE DFS PROCESS" << std::endl;
    Recursive_DFS_Cycles::Graph g1(3);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    assert(g1.Check_Cycle_DFS() == false);
    std::cout << "Test Case 1: Passed" << std::endl;
    Recursive_DFS_Cycles::Graph g2(5);
    g2.add_edge(1, 0);
    g2.add_edge(0, 2);
    g2.add_edge(2, 1);
    g2.add_edge(0, 3);
    g2.add_edge(3, 4);
    assert(g2.Check_Cycle_DFS() == true);
    std::cout << "Test Case 2: Passed" << std::endl;
    Recursive_DFS_Cycles::Graph g3(7);
    g3.add_edge(0, 1);
    g3.add_edge(1, 2);
    g3.add_edge(2, 0);
    g3.add_edge(2, 5);
    g3.add_edge(3, 5);
    assert(g3.Check_Cycle_DFS() == true);
    std::cout << "Test Case 3: Passed" << std::endl;
    Recursive_DFS_Cycles::Graph g4(6);
    g4.add_edge(0, 1);
    g4.add_edge(1, 5);
    g4.add_edge(5, 4);
    g4.add_edge(4, 0);
    g4.add_edge(4, 3);
    g4.add_edge(3, 2);
    g4.add_edge(0, 2);
    assert(g4.Check_Cycle_DFS() == true);
    std::cout << "Test Case 4: Passed" << std::endl;

    Recursive_DFS_Cycles::Graph g5(4);
    g5.add_edge(0, 1);
    g5.add_edge(1, 2);
    g5.add_edge(2, 0);
    g5.add_edge(2, 3);
    assert(g5.Check_Cycle_DFS() == true);
    std::cout << "Test Case 5: Passed" << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}
