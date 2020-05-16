/*
* Problem: Minimum Element In Stack With Extra Space
* Learning Link: https://www.youtube.com/watch?v=asf9P2Rcopo
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define endl "\n";
#define cin(x) cin >> x;
#define log(x) cout << x << "\n";
#define logs(x) cout << x << " ";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define si stack<int>
#define pii pair<int, int>

si s;
si ss;

int pop()
{
  int ans = -1;
  if (s.empty())
  {
    return -1;
  }
  ans = s.top();
  s.pop();

  if (ans == ss.top())
  {
    ss.pop();
  }
}

void push(int num)
{
  s.push(num);

  if (ss.empty() || num <= ss.top())
  {
    ss.push(num);
  }
}

int getMin()
{
  return ss.empty() ? -1 : ss.top();
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  push(1);
  push(2);
  push(0);
  pop();

  log(getMin());

  return 0;
}
