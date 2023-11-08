#define maxDist 1005

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, s;
int tmp1, tmp2, tmp3;

// The original distance
int dist[105][105];
// The calculated distance from s to all
int _dist[105];
// Whether considered as the head of the priority queue
bool isBooked[105];
// Queues containing all "neibours"
queue<int> edge[105];

// A new class for sorting the nodes in the priority queue
class node
{
public:
    int index;

    node(int idx)
    {
        index = idx;
    }

    bool operator>(const node &other) const
    {
        return _dist[index] > _dist[other.index];
    }
};

// The priority queue recording and sorting the unconsidered nodes (May adds nodes repeatedly)
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
    for (int i = 0; i < n; i++)
        _dist[i] = maxDist;
    _dist[s] = 0;

    // Initialize the edge queue
    for (int i = 0; i < n; i++)
    {
        while (!edge[i].empty())
            edge[i].pop();
    }

    // Initialize the booking status
    memset(isBooked, false, sizeof(isBooked));
    isBooked[s] = true;

    // Initialize the priority queue
    while (!q.empty())
        q.pop();
    q.push(node(s));

    // Input lengths of the m directed edges
    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        dist[tmp1][tmp2] = tmp3;
        edge[tmp1].push(tmp2);
    }

    while (!q.empty())
    {
        // Find the closeset unbooked node to s
        int tmpChoice = q.top().index;
        int tmpDist = _dist[tmpChoice];
        q.pop();

        // Pop all the same nodes
        while (!q.empty() && q.top().index == tmpChoice)
            q.pop();

        // Renew the booking status
        isBooked[tmpChoice] = true;

        // If all reachable nodes have been considered
        if (tmpDist >= maxDist)
            break;

        // Renew the distances of the unbooked nodes
        while (!edge[tmpChoice].empty())
        {
            int _tmpChoice = edge[tmpChoice].front();
            edge[tmpChoice].pop();
            if (!isBooked[_tmpChoice])
            {
                _dist[_tmpChoice] = _min(_dist[_tmpChoice], _dist[tmpChoice] + dist[tmpChoice][_tmpChoice]);
                q.push(_tmpChoice);
            }
        }
    }

    // Print the distances
    for (int i = 0; i < n; i++)
        cout << _dist[i] << " ";
    cout << "\n";
    return 0;
}