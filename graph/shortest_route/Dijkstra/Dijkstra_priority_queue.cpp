#define maxDist 1005

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node
{
public:
    int index;
    int dist;

    node(int idx)
    {
        index = idx;
        dist = maxDist;
    }

    node(int idx, int dst)
    {
        index = idx;
        dist = dst;
    }

    bool operator>(const node &other) const
    {
        return dist > other.dist;
    }
};

int n, m, s;
int tmp1, tmp2, tmp3;
int dist[105][105];
bool isBooked[105];

priority_queue<node, vector<node>, greater<node> > q;

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

    // Initialize the booking status
    memset(isBooked, false, sizeof(isBooked));
    isBooked[s] = true;

    // Input lengths of the m directed edges
    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        dist[tmp1][tmp2] = tmp3;
    }

    // Initialize the priority queue
    while (!q.empty())
        q.pop();
    for (int i = 0; i < n; i++)
        q.push(node(i, dist[s][i]));
    q.pop();

    while (!q.empty())
    {
        // Find the closeset unbooked node to s
        int tmpChoice = q.top().index;
        int tmpDist = q.top().dist;
        q.pop()

        // If all reachable nodes have been considered
        if(tmpDist >= maxDist) break;

        if()
    }

    //     // If no node needs consideration
    //     if (isEnd)
    //         break;

    //     // Book the node tmpChoice
    //     isBooked[tmpChoice] = true;

    //     // Renew the distances of unbooked nodes
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (!isBooked[i])
    //             dist[s][i] = _min(dist[s][i], dist[s][tmpChoice] + dist[tmpChoice][i]);
    //     }
    // }

    // // Print the distances from node s to all nodes (Single source minimal route)
    // for (int i = 0; i < n; i++)
    //     cout << dist[s][i] << " ";
    // cout << "\n";

    // return 0;
}