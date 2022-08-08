#include <iostream>
#include <new>
#include <vector>
#define MAX 20

namespace Graph_Adjacent_Matrix {
class Graph_1 {
 private:
    int vertices;
    int **adjlist;

 public:
    Graph_1(int v) {
        vertices = v;
        adjlist = new int *[vertices];
        for (int i = 0; i < vertices; i++) {
            adjlist[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjlist[i][j] = 0;
            }
        }
    }
    void add_edge(int u, int v) {
        adjlist[u][v] = 1;
        adjlist[v][u] = 1;
    }
    void print_graph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjlist[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
};

class Graph_2 {
 private:
    int vertices;
    int adjlist[20][20];

 public:
    Graph_2(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjlist[i][j] = 0;
            }
        }
    }
    void add_edge(int u, int v) {
        adjlist[u][v] = 1;
        adjlist[v][u] = 1;
    }
    void print_graph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjlist[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
};
};  // namespace Graph_Adjacent_Matrix

int main() {
    Graph_Adjacent_Matrix::Graph_2 g(6);
    g.add_edge(0, 4);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(1, 5);
    g.add_edge(2, 3);
    g.add_edge(2, 5);
    g.add_edge(5, 3);
    g.add_edge(5, 4);
    g.print_graph();
    return 0;
}