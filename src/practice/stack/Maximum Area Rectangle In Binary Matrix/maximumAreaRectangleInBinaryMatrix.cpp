/*
* Problem: Maximum Area Rectangle In Binary Matrix
* Learning Link: https://www.youtube.com/watch?v=St0Jf_VmG_g
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
#define vii vector<vi>
#define si stack<int>
#define pii pair<int, int>

void printVectorInput(vi &input)
{
  int sizeOfInput = input.size();
  for (int i = 0; i < sizeOfInput; i++)
  {
    logs(input[i]);
  }
  cout << endl;
}

vi getVectorInput(int sizeOfInput)
{
  int num;
  vi input;
  for (int i = 0; i < sizeOfInput; i++)
  {
    cin(num);
    input.pb(num);
  }
  return input;
}

vii get2dVectorInput(int rows, int columns)
{
  int temp;
  vii input;

  for (int i = 0; i < rows; i++)
  {
    vi row;

    for (int j = 0; j < columns; j++)
    {
      cin(temp);
      row.pb(temp);
    }
    input.pb(row);
  }
  return input;
}

vi nextSmallestElementFromLeft(vi &input)
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

vi nextSmallestElementFromRight(vi &input)
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

int maximumAreaRectangleInBinaryMatrix(vii &input)
{
  vi leftSmallestIndex;
  vi rightSmallestIndex;

  int maxArea = 0;
  int area = 0;

  for (int i = 1; i < input.size(); i++)
  {
    for (int j = 0; j < input[i].size(); j++)
    {
      if (input[i][j] != 0)
      {
        input[i][j] = input[i - 1][j] + input[i][j];
      }
    }
  }

  for (int i = 0; i < input.size(); i++)
  {
    leftSmallestIndex = nextSmallestElementFromLeft(input[i]);
    rightSmallestIndex = nextSmallestElementFromRight(input[i]);
    area = getMaximumAreaHistogram(input[i], leftSmallestIndex, rightSmallestIndex);
    maxArea = max(maxArea, area);
  }

  return maxArea;
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
  int rows;
  int columns;
  int result;
  vii input;

  cin(testCase);

  while (testCase--)
  {
    cin(rows);
    cin(columns);
    input = get2dVectorInput(rows, columns);
    result = maximumAreaRectangleInBinaryMatrix(input);
    log(result);
  }

  return 0;
}
