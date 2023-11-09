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

    // Constructive function
    Edge(int x, int y, int dist) : x(x), y(y), dist(dist) {}

    // Operator overloading
    bool operator<(const Edge &other) const
    {
        return dist < other.dist;
    }
};

int n, m;
int tmp1, tmp2, tmp3;
Edge edge[1005];

int main()
{
    
}