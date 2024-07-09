#include <vector>
using namespace std;

class UnionFind {
private:
    int count;
    vector<int> parent;
    vector<int> size;

public:
    // Constructor
    UnionFind(int n) : count(n), parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

private:
    // Find the root of node x with path compression
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  // Path compression
            x = parent[x];
        }
        return x;
    }

public:
    // Check if nodes p and q are connected
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    // Union operation
    void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        // Union by size
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    // Get the number of disjoint sets
    int getCount(){
        return count;
    }
};
