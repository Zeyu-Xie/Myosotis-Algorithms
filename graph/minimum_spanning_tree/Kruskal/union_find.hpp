#pragma once
#include <vector>

class UnionFind
{
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    // Constructive Function
    UnionFind(int size);

    // Find one's parent
    int find(int x);

    // Decide whether x and y are in different sets
    bool areConnected(int x, int y);

    // Combine two sets
    void unite(int x, int y);
};