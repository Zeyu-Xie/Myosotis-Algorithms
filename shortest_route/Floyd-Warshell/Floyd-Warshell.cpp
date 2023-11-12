#define maxDist 1005

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;
int tmp1, tmp2, tmp3;
int dist[105][105];
bool hasNegativeCircle = false;

template <typename T>
T _min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

int main()
{
    // Input the number of nodes and edges
    freopen("./Floyd-Warshell.in", "r", stdin);
    cin >> n >> m;

    // Initialize the distance to maxDist = 1005
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                dist[i][j] = maxDist;
            else
                dist[i][j] = 0;
        }
    }

    // Input lengths of m edges
    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        dist[tmp1][tmp2] = tmp3;
    }

    // The main process of the Floyd-Warshell Algorithm
    for (int trans = 0; trans < n; trans++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == trans || j == trans)
                    continue;
                else
                    dist[i][j] = _min(dist[i][j], dist[i][trans] + dist[trans][j]);
            }
    }

    // Decide whether the graph contains a negative circle
    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
        {
            hasNegativeCircle = true;
            break;
        }
    }

    // Print the result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << "\n";
    }

    // Print wether this graph has a negative circle
    cout << "Have negative circle: " << (hasNegativeCircle ? "Yes" : "No");
    cout << "\n";

    return 0;
}