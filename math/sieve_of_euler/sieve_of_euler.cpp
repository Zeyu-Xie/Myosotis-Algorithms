#define maxLen 100000005

#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

// n: range, q: number of requests
int n, q;
// k: find the k-th prime number
int k;

// prime number: true, otherwise: false
bool is_prime[maxLen];
// prime[i]: the i-th prime number
int prime[maxLen];

int main()
{
    // Accelerate input
    std::ios::sync_with_stdio(false);

    // Init
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    int cnt = 0;

    // Input
    freopen("./sieve_of_euler.in", "r", stdin);
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && prime[j] <= n/i; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> k;
        cout << prime[k] << "\n";
    }

    return 0;
}