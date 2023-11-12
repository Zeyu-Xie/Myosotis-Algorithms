#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructive Function
    UnionFind(int size) : parent(size), rank(size, 1)
    {
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    // Find one's parent
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Decide whether x and y are in different sets
    bool areConnected(int x, int y)
    {
        return find(x) == find(y);
    }

    // Combine two sets
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        // If x and y have already been in one set
        if (rootX == rootY)
            return;

        // If x and y are in different sets
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
        {
            parent[rootY] = parent[rootX];

            // Since rank[rootX] == rank [rootY], rank[rootX] will be added on 1
            rank[rootX]++;
        }
    }
};

// n: nodes number, m: edges number
int n, m;
int tmp1, tmp2;

int main()
{
    // Input
    freopen("./union_find.in", "r", stdin);
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        uf.unite(tmp1, tmp2);
    }

    for (int i = 0; i < n; i++)
        cout << uf.find(i) << " ";
    cout << "\n";

    return 0;
}