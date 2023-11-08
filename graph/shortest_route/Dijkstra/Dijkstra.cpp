#define maxDist 1005

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, s;
int tmp1, tmp2, tmp3;
int tmpChoice;
bool isEnd = false;
int dist[105][105];
bool isBooked[105];

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

    // Initialize the booking info
    memset(isBooked, false, sizeof(isBooked));
    isBooked[s] = true;

    // Input lengths of the m directed edges
    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        dist[tmp1][tmp2] = tmp3;
    }

    while (!isEnd)
    {
        // Initalize the isEnd and tmpDist
        isEnd = true;
        tmpChoice = -1;

        // Find the closeset unbooked node to s
        for (int i = 0; i < n; i++)
        {

            // If node i has been booked
            if (isBooked[i])
                continue;

            // If node i is not reachable from node s
            else if (dist[s][i] >= maxDist)
                continue;

            // If node i has not been booked, but there is already another closer node
            else if (tmpChoice >= 0 && dist[s][tmpChoice] <= dist[s][i])
                continue;

            // Set the tmpChoice and the isEnd
            tmpChoice = i;
            isEnd = false;
        }

        // If no node needs consideration
        if (isEnd)
            break;

        // Book the node tmpChoice
        isBooked[tmpChoice] = true;

        // Renew the distances of unbooked nodes
        for (int i = 0; i < n; i++)
        {
            if (!isBooked[i])
                dist[s][i] = _min(dist[s][i], dist[s][tmpChoice] + dist[tmpChoice][i]);
        }
    }

    // Print the distances from node s to all nodes (Single source minimal route)
    for (int i = 0; i < n; i++)
        cout << dist[s][i] << " ";
    cout << "\n";

    return 0;
}