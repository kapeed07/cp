/*
* Problem: Nearest Greater to left || Next Largest Element From Left
* Learning Link: https://www.youtube.com/watch?v=T5s96ynzArg
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
  stack<int> stack;
  vector<int> result;
  int size = input.size();

  for (int index = 0; index < size; index++)
  {
    if (stack.empty())
    {
      result.pb(-1);
    }
    else if (!stack.empty() && stack.top() > input[index])
    {
      result.pb(stack.top());
    }
    else
    {
      while (!stack.empty() && stack.top() <= input[index])
      {
        stack.pop();
      }
      if (stack.empty())
      {
        result.pb(-1);
      }
      else
      {
        result.pb(stack.top());
      }
    }
    stack.push(input[index]);
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
  int num;

  cin(testCase);

  while (testCase--)
  {
    cin(sizeOfInput);
    input = getVectorInput(sizeOfInput);
    result = getNextLargestElementFromLeft(input);
    printVectorInput(result);
  }

  return 0;
}
