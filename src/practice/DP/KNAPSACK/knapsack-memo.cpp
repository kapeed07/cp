#include <iostream>

using namespace std;

#define endl "\n";
#define cin(x) cin >> x;
#define log(x) cout << x << "\n";
#define logs(x) cout << x << " ";

int dp[6][4];

int knapSack(int W, int weight[], int profit[], int size)
{

    if (W == 0 || size == 0)
    {
        return 0;
    }

    if (dp[W][size] != -1)
    {
        return dp[W][size];
    }

    if (weight[size - 1] <= W)
    {
        return dp[W][size] = max(
                   profit[size - 1] + knapSack(W - weight[size - 1], weight, profit, size - 1),
                   knapSack(W, weight, profit, size - 1));
    }
    else
    {
        return dp[W][size] = knapSack(W, weight, profit, size - 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int profit[] = {6, 10, 12};
    int weight[] = {1, 2, 3};
    int W = 5;

    memset(dp, -1, sizeof(dp));

    int size = sizeof(profit) / sizeof(profit[0]);

    knapSack(W, weight, profit, size);

    log(dp[W][size]);

    return 0;
}