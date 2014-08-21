#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int dp[99999];
int maxSubArray(int A[], int n) {
  if (n==0) { // Should not happen
    return 0;}
  dp[0] = A[0];
  int best = dp[0];
  for (int i=1; i<n; i++) {
    if (dp[i-1]>=0) {
      dp[i] = A[i] + dp[i-1];
    } else {
      dp[i] = A[i];
    }
    if (dp[i]>best) {
      best = dp[i];
    }
  }
  return best;
}

int main() {
  int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  printf("%d\n", maxSubArray(A, 9));
  return 0;
}
