#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

class Interval
{
public:
    double left;
    double right;

    Interval()
    {
        left = 0;
        right = 0;
    }

    Interval(double a, double b)
    {
        left = a;
        right = b;
    }

    bool operator<(const Interval &other) const
    {
        return right < other.right;
    }
};

int n;
int num = 0;
double tmp1, tmp2;
Interval tmpInterval;
Interval interval[1005];

int main()
{
    freopen("./T1.in", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp1 >> tmp2;
        interval[i] = Interval(tmp1, tmp2);
    }

    sort(interval, interval + n);

    tmpInterval = interval[0];
    num = 1;

    for (int i = 1; i < n; i++)
    {
        if (interval[i].left >= tmpInterval.right)
        {
            num++;
            tmpInterval = interval[i];
            cout << tmpInterval.left << " " << tmpInterval.right << "\n";
        }
    }

    cout << num << "\n";

    return 0;
}