#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
 private:
  vector<int> parent, rank;

 public:
  // Constructor to initialize the disjoint set
  DisjointSet(int n) {
    parent.resize(n), rank.resize(n, 0);
    // Initially, each element is its own parent
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  // Find the representative of the set containing x (with path compression)
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
  }

  // Union of two sets containing x and y (with union by rank)
  void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      // Union by rank: attach the smaller tree under the root of the larger
      // tree
      if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
      } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
      } else {
        parent[rootY] = rootX;
        rank[rootX]++;  // Increase the rank of the new root
      }
    }
  }

  // Helper function to check if two elements are in the same set
  bool areInSameSet(int x, int y) { return find(x) == find(y); }
};

int main() {
  DisjointSet ds(10);

  // Performing some union operations
  ds.unionSets(1, 2);
  ds.unionSets(2, 3);
  ds.unionSets(4, 5);
  ds.unionSets(6, 7);
  ds.unionSets(5, 6);

  // Check if two elements are in the same set
  cout << "1 and 3 are in the same set: "
       << (ds.areInSameSet(1, 3) ? "Yes" : "No") << endl;
  cout << "2 and 4 are in the same set: "
       << (ds.areInSameSet(2, 4) ? "Yes" : "No") << endl;
  cout << "6 and 1 are in the same set: "
       << (ds.areInSameSet(6, 1) ? "Yes" : "No") << endl;

  // Performing some more union operations
  ds.unionSets(3, 4);

  // Check again after additional unions
  cout << "1 and 5 are in the same set: "
       << (ds.areInSameSet(1, 5) ? "Yes" : "No") << endl;

  return 0;
}
