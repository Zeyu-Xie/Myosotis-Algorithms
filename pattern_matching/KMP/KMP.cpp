#define maxLen 1000005

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string str1, str2;
int lps[maxLen];
int len1, len2;

int main()
{
    // Init
    freopen("./KMP.in", "r", stdin);
    memset(lps, 0, sizeof(lps));

    // Input
    cin >> str1 >> str2;
    len1 = str1.length();
    len2 = str2.length();

    // Step 1: Build the table[] array
    int len = 0;
    int tmp = 1;
    while (tmp < len2)
    {
        if (str2[len] == str2[tmp])
        {
            len++;
            lps[tmp] = len;
            tmp++;
        }
        else
        {
            if (len > 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[tmp] = 0;
                tmp++;
            }
        }
    }

    // Step2: Match with lps[]
    int p1 = 0;
    int p2 = 0;
    while (p1 < len1)
    {
        if (str1[p1] == str2[p2])
        {
            p1++;
            p2++;
            if (p2 >= len2)
            {
                // Matched
                cout << p1 - p2 << "\n";
                p2 = lps[p2 - 1];
            }
        }
        else
        {
            if (p2 > 0)
                p2 = lps[p2 - 1];
            else
                p1++;
        }
    }

    return 0;
}