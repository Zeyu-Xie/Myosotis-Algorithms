#include <cstdio>
#include <iostream>
#include <algorithm>

// Import union find data structure
#include "union_find.hpp"

using namespace std;

class Edge
{
public:
    int x;
    int y;
    int dist;

    // Constructive functions
    Edge() : x(0), y(0), dist(0) {}
    Edge(int x, int y, int dist) : x(x), y(y), dist(dist) {}

    // Operator overloading
    bool operator<(const Edge &other) const
    {
        return dist < other.dist;
    }
};

int n, m;
int tmp1, tmp2, tmp3;
int num = 0;
Edge edge[1005];

int main()
{
    freopen("./minimum_spanning_tree.in", "r", stdin);
    cin >> n >> m;

    UnionFind uf(m);

    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        edge[i] = Edge(tmp1, tmp2, tmp3);
    }

    sort(edge, edge + m);

    for (int i = 0; i < m; i++)
    {
        int x = edge[i].x;
        int y = edge[i].y;
        int dist = edge[i].dist;

        // If x and y have already been connected
        if (uf.areConnected(x, y))
            continue;

        // If the number of chosen edges is enough
        if (num >= n - 1)
            break;

        cout << "(" << x << ", " << y << ") " << dist << " ";
        cout << "\n";
    }

    return 0;
}