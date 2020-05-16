/*
* Problem: Maximum Area Histogram
* Learning Link: https://www.youtube.com/watch?v=J2X70jj_I1o
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

vector<int> nextSmallestElementFromLeft(vector<int> &input)
{
  stack<pii> stack;
  vi result;
  int size = input.size();

  for (int index = 0; index < size; index++)
  {
    if (stack.empty())
    {
      result.pb(-1);
    }
    else if (!stack.empty() && stack.top().first < input[index])
    {
      result.pb(stack.top().second);
    }
    else
    {
      while (!stack.empty() && stack.top().first >= input[index])
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

vector<int> nextSmallestElementFromRight(vector<int> &input)
{
  stack<pii> stack;
  vi result;
  int size = input.size();
  int pseudoIndex = input.size();

  for (int index = size - 1; index >= 0; index--)
  {
    if (stack.empty())
    {
      result.pb(pseudoIndex);
    }
    else if (!stack.empty() && stack.top().first < input[index])
    {
      result.pb(stack.top().second);
    }
    else
    {
      while (!stack.empty() && stack.top().first >= input[index])
      {
        stack.pop();
      }
      if (stack.empty())
      {
        result.pb(pseudoIndex);
      }
      else
      {
        result.pb(stack.top().second);
      }
    }
    stack.push(mp(input[index], index));
  }

  reverse(result.begin(), result.end());

  return result;
}

int getMaximumAreaHistogram(vi input, vi &leftSmallestIndex, vi &rightSmallestIndex)
{
  vi areaVector;

  for (int i = 0; i < leftSmallestIndex.size(); i++)
  {
    areaVector.pb((rightSmallestIndex[i] - leftSmallestIndex[i] - 1) * input[i]);
  }

  return *max_element(areaVector.begin(), areaVector.end());
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  vi input;
  vi leftSmallestIndex;
  vi rightSmallestIndex;

  int testCase;
  int sizeOfInput;
  int num;
  int result;

  cin(testCase);

  while (testCase--)
  {
    cin(sizeOfInput);
    input = getVectorInput(sizeOfInput);
    leftSmallestIndex = nextSmallestElementFromLeft(input);
    rightSmallestIndex = nextSmallestElementFromRight(input);
    result = getMaximumAreaHistogram(input, leftSmallestIndex, rightSmallestIndex);
    log(result);
  }

  return 0;
}
