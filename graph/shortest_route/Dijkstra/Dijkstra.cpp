#define maxDist 1005

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, s;
int tmp1, tmp2, tmp3;
int dist[105][105];

template <typename T>
T _min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

int main()
{
    freopen("./Dijkstra.in", "r", stdin);

    // Input n, m and s
    cin >> n >> m >> s;

    // Initialize the distances
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i != j)
                dist[i][j] = maxDist;
            else
                dist[i][j] = 0;
    }

    // Input lengths of the m directed edges
    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        dist[tmp1][tmp2] = tmp3;
    }

    while (true)
    {
    }

    // Print the distances from node s to all nodes (Single source minimal route)
    for (int i = 0; i < n; i++)
        cout << dist[s][i] << " ";
    cout << "\n";

    return 0;
}