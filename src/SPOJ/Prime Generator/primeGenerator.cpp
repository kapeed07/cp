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
#define ui unsigned int

bool isPrime(int number)
{
    if (number <= 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;

    int m = sqrt(number);
    for (int i = 3; i <= m; i += 2)
        if (number % i == 0)
            return false;

    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    int testCase;
    ui start;
    ui end;

    cin(testCase);

    while (testCase--)
    {
        cin(start);
        cin(end);

        for (ui i = start; i <= end; i++)
        {
            if (isPrime(i))
            {
                log(i);
            }
        }
        log("");
    }

    return 0;
}