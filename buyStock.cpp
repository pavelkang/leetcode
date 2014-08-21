#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int mins[99999];
int dp[99999];
int maxProfit(vector<int> &prices) {
  int l = prices.size();
  if (l<2) // Should not come here
    return 0;
  mins[0] = prices[0];
  int best = 0;
  for (int i=1; i<l; i++) {
    if (prices[i]<mins[i-1]) {
      mins[i] = prices[i];
    } else {
      mins[i] = mins[i-1];
      if (prices[i]-mins[i-1]>best) {
        best = prices[i]-mins[i-1];
      }
    }
  }
  return best;
}
int main() {
  vector<int> v;
  v.push_back(1); v.push_back(-1); v.push_back(4); v.push_back(9);
  v.push_back(2); v.push_back(10); v.push_back(-6); v.push_back(1);
  printf("%d\n", maxProfit(v));
  return 0;
}
