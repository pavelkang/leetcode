#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<math.h>
using namespace std;
int minPathSum(vector<vector<int> > &grid) {
  int m = grid.size(); int n = grid[0].size();
  int dp[m][n];
  dp[0][0] = grid[0][0];
  for (int d=1; d<=m+n-2; d++) {
    for (int i=0; i<=min(d, m-1); i++) {
      int j = min(n-1, d-i);
      printf("%d %d\n", i, j);
      if (i==0) {
        dp[i][j] = grid[i][j] + dp[i][j-1];
      } else if (j==0) {
        dp[i][j] = grid[i][j] + dp[i-1][j];
      } else {
        dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[m-1][n-1];
}

int main() {
  vector< vector<int> > test;
  vector<int> a; a.push_back(1); a.push_back(3); a.push_back(1);
  vector<int> b; b.push_back(1); b.push_back(5); b.push_back(1);
  vector<int> c; c.push_back(4); c.push_back(2); c.push_back(1);
  test.push_back(a); test.push_back(b); test.push_back(c);
  printf("answer is %d\n", minPathSum(test));
  return 0;
}
