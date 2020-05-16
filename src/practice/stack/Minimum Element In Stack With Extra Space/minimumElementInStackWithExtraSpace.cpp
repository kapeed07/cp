/*
* Problem: Rain Water Trapping
* Learning Link: https://www.youtube.com/watch?v=FbGG2qpNp4U
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

int getMaximumRainWaterTrapped(vi &input)
{
  int size = input.size();
  int totalWatterTrapped = 0;

  vi maxFromLeft(size);
  vi maxFromRight(size);

  maxFromLeft[0] = input[0];
  maxFromRight[size - 1] = input[size - 1];

  for (int i = 1; i < size; i++)
  {
    maxFromLeft[i] = max(maxFromLeft[i - 1], input[i]);
  }

  for (int i = size - 2; i > 0; i--)
  {
    maxFromRight[i] = max(input[i], maxFromLeft[i + 1]);
  }

  for (int i = 0; i < size; i++)
  {
    totalWatterTrapped += min(maxFromRight[i], maxFromLeft[i]) - input[i];
  }

  return totalWatterTrapped;
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

  int testCase;
  int sizeOfInput;
  int result;

  cin(testCase);

  while (testCase--)
  {
    cin(sizeOfInput);
    input = getVectorInput(sizeOfInput);
    result = getMaximumRainWaterTrapped(input);
    log(result);
  }

  return 0;
}
