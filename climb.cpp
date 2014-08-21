#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;
int dp[99999];
int cs(int n) {
  if (dp[n]!=0)
    return dp[n];
  dp[n] = cs(n-1) + cs(n-2);
  return dp[n];
}
int climbStairs(int n) {
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  return cs(n);
}
int main() {

  return 0;
}
