/*
* Problem: Prime Generator
* Problem Link: https://www.spoj.com/status/PRIME1/
*/

#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

#define endl "\n";
#define cin(x) cin >> x;
#define log(x) cout << x << "\n";
#define logs(x) cout << x << " ";
#define ll long long int

bool isPrime[1000000001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    int testCase;
    ll start;
    ll end;

    memset(isPrime, true, 1000000001);

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (ll i = 2; i < sqrt(1000000001) + 1; i++)
    {
        if (isPrime[i])
        {
            ll j;
            j = i * 2;
            while (j < 1000000001)
            {
                isPrime[j] = 0;
                j *= 2;
            }
        }
    }

    cin(testCase);

    while (testCase--)
    {
        cin(start);
        cin(end);

        for (ll i = start; i <= end; i++)
        {
            if (isPrime[i])
            {
                log(i);
            }
        }
        log("");
    }

    return 0;
}