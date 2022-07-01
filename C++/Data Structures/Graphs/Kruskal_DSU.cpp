#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
const int mx = 1e6 + 5;

std::array<int64_t, mx> parent;
int64_t node, edge;
std::vector<std::pair<int64_t, std::pair<int64_t, int64_t>>> edges;

void initial() {
    for (int i = 0; i < node + edge; ++i) {
        parent[i] = i;
    }
}

int root(int i) {
    while (parent[i] != i) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void join(int x, int y) {
    int root_x = root(x);  // Disjoint set union by rank
    int root_y = root(y);
    parent[root_x] = root_y;
}

int64_t kruskal() {
    int64_t mincost = 0;
    for (int i = 0; i < edge; ++i) {
        int64_t x = edges[i].second.first;
        int64_t y = edges[i].second.second;
        if (root(x) != root(y)) {
            mincost += edges[i].first;
            join(x, y);
        }
    }
    return mincost;
}

int main() {
    int from = 0, to = 0, cost = 0, totalcost = 0;
    std::cin >> node >> edge;  // Enter the nodes and edges
    initial();                 // Initialise the parent array
    for (int i = 0; i < edge; ++i) {
        std::cin >> from >> to >> cost;
        edges.emplace_back(make_pair(cost, std::make_pair(from, to)));
        totalcost += cost;
    }
    sort(edges.begin(), edges.end());
    std::cout << kruskal() << std::endl;
    edges.clear();
    return 0;
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
// 37 ans
