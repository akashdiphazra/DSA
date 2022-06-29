#include <assert.h>

#include <iostream>
#include <stack>
#include <vector>

namespace Depth_First_Search_Recursive {
class Graph {
 private:
    int vertices;
    std::vector<std::vector<int>> adjlists;
    std::vector<bool> visited;

 public:
    Graph(int v) {
        vertices = v;
        adjlists.resize(v);
        visited.resize(v);
    }

    void add_edge(int u, int v) {
        this->adjlists[u].push_back(v);
        //  this->adjlists[v].push_back(u);     /* For undirected graph */
    }

    void DFS_Recursive(int startveretex) {
        visited[startveretex] = true;
        std::cout << startveretex << " ";
        for (auto it : adjlists[startveretex]) {
            if (!visited[it]) {
                DFS_Recursive(it);
            }
        }
    }
};
};  // namespace Depth_First_Search_Recursive

namespace Depth_First_Search_Iterative {
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

    std::vector<int> DFS_Iterative(int startveretex) {
        std::vector<bool> visited(vertices, false);
        std::vector<int> nodes;
        std::stack<int> st;
        st.push(startveretex);
        while (!st.empty()) {
            int currentnode = st.top();
            st.pop();
            if (!visited[currentnode]) {
                visited[currentnode] = true;
                nodes.push_back(currentnode);
                // std::cout << currentnode << " ";
            }
            for (auto it : adjlists[currentnode]) {
                if (!visited[it]) {
                    st.push(it);
                }
            }
        }
        return nodes;
    }
};
};  // namespace Depth_First_Search_Iterative

int main() {
    Depth_First_Search_Iterative::Graph g(5);  // Total 5 vertices in graph
    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 4);
    std::vector<int> res{0, 3, 2, 1, 4};
    assert(g.DFS_Iterative(0) == res);
    std::cout << "DFS Iterative" << std::endl;
    std::cout << "TEST CASE 1 : PASSED " << std::endl;
    return 0;
}