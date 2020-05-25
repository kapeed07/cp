#include <iostream>

using namespace std;

#define endl "\n";
#define cin(x) cin >> x;
#define log(x) cout << x << "\n";
#define logs(x) cout << x << " ";

int knapSack(int W, int weight[], int profit[], int size)
{
    if (W == 0 || size == 0)
    {
        return 0;
    }

    if (weight[size - 1] <= W)
    {
        return max(
            profit[size - 1] + knapSack(W - weight[size - 1], weight, profit, size - 1),
            knapSack(W, weight, profit, size - 1));
    }
    else
    {
        return knapSack(W, weight, profit, size - 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;

    int size = sizeof(profit) / sizeof(profit[0]);

    int result;

    result = knapSack(W, weight, profit, size);

    log(result);

    return 0;
}