#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int maxProfit(vector<int> &prices) {
  if (prices.size()<=1)
    return 0;
  int total = 0;
  for (int i=1; i<prices.size(); i++) {
    if (prices[i]>prices[i-1])
      total += prices[i] - prices[i-1];
  }
  return total;
}

int main() {

  return 0;
}
