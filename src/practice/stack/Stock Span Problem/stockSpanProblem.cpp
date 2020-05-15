/*
* Problem: Stock Span Problem
* Parent Problem: Nearest Greater From Left
* Learning Link: https://www.youtube.com/watch?v=p9T-fE1g1pU
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define endl "\n";
#define cin(x) cin >> x;
#define log(x) cout << x << "\n";
#define logs(x) cout << x << " ";
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

void printVectorInput(vector<int> &input)
{
  int sizeOfInput = input.size();
  for (int i = 0; i < sizeOfInput; i++)
  {
    logs(input[i]);
  }
  cout << endl;
}

vector<int> getVectorInput(int sizeOfInput)
{
  int num;
  vector<int> input;
  for (int i = 0; i < sizeOfInput; i++)
  {
    cin(num);
    input.pb(num);
  }
  return input;
}

vector<int> getNextLargestElementFromLeft(vector<int> &input)
{
  stack<pii> stack;
  vector<int> result;
  int size = input.size();

  for (int index = 0; index < size; index++)
  {
    if (stack.empty())
    {
      result.pb(-1);
    }
    else if (!stack.empty() && stack.top().first > input[index])
    {
      result.pb(stack.top().second);
    }
    else
    {
      while (!stack.empty() && stack.top().first <= input[index])
      {
        stack.pop();
      }
      if (stack.empty())
      {
        result.pb(-1);
      }
      else
      {
        result.pb(stack.top().second);
      }
    }
    stack.push(mp(input[index], index));
  }

  return result;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  vector<int> input;
  vector<int> result;

  int testCase;
  int sizeOfInput;

  cin(testCase);

  while (testCase--)
  {
    cin(sizeOfInput);
    input = getVectorInput(sizeOfInput);
    result = getNextLargestElementFromLeft(input);
    for (int i = 0; i < sizeOfInput; i++)
    {
      result[i] = i - result[i];
    }

    printVectorInput(result);
  }

  return 0;
}