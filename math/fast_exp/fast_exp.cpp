#include <cstdio>
#include <iostream>
using namespace std;

long long a, b;
long long p;

template <typename T>
T fast_exp(T a, T b, T p)
{
    T ans = 1;
    T base = a;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= base;
            ans %= p;
        }
        base *= base;
        base %= p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    freopen("./fast_exp.in", "r", stdin);
    cin >> a >> b;
    cin >> p;
    cout << fast_exp(a, b, p)<<"\n";
    return 0;
}