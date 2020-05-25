#include <iostream>

using namespace std;

#define endl "\n";
#define cin(x) cin >> x;
#define log(x) cout << x << "\n";
#define logs(x) cout << x << " ";

int dp[4][6];

int knapSack(int W, int weight[], int profit[], int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
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

    log(dp[size][W]);

    return 0;
}