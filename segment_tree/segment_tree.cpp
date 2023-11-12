#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class SegmentTreeNode
{
public:
    int start, end;
    int sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int s, int e) : start(s), end(e), sum(0), left(nullptr), right(nullptr) {}
};

class SegmentTree
{
public:
    SegmentTree(vector<int> &nums)
    {
        root = buildTree(nums, 0, nums.size());
    }

    int query(int i, int j)
    {
        return query(root, i, j);
    }

    void update(int i, int val)
    {
        update(root, i, val);
    }

private:
    SegmentTreeNode *root;

    SegmentTreeNode *buildTree(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return nullptr;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start + 1 >= end)
            root->sum = nums[start];
        else
        {
            int mid = (start + end) / 2;
            root->left = buildTree(nums, start, mid);
            root->right = buildTree(nums, mid, end);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }

    int query(SegmentTreeNode *root, int i, int j)
    {
        if (!root || root->end <= i || root->start > j)
            return 0;
        if (root->start >= i && root->end <= j)
            return root->sum;
        return query(root->left, i, j) + query(root->right, i, j);
    }

    void update(SegmentTreeNode *root, int i, int val)
    {
        if (!root || root->end <= i || root->start > i)
            return;
        if (root->start == i && root->end == i + 1)
        {
            root->sum = val;
            return;
        }
        update(root->left, i, val);
        update(root->right, i, val);
        root->sum = root->left->sum + root->right->sum;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 7, 9};

    SegmentTree st(nums);

    cout << "Sum in range [0, 3): " << st.query(0, 3) << endl;

    st.update(2, 10);

    cout << "Sum in range [0, 3): " << st.query(0, 3) << endl;

    return 0;
}