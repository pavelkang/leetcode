#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;
<<<<<<< HEAD
int minimumTotal(vector<vector<int> > &triangle) {
  int rows = triangle.size();
  if (rows == 1) {
    return triangle[0][0];
  }
  int dp[rows];
  for (int i=0; i<rows; i++) {
    dp[i] = triangle[rows-1][i];
  }
  for (int i=rows-2; i>=0; i--) {
    for (int j=0; j<i+1; j++) {
      dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
    }
  }
  return dp[0];
}
int main() {
  vector<vector<int> > triangle;
  vector<int> a; a.push_back(2);
  vector<int> b; b.push_back(3); b.push_back(4);
  vector<int> c; c.push_back(6); c.push_back(5); c.push_back(7);
  triangle.push_back(a);
  triangle.push_back(b);
  triangle.push_back(c);
  printf("%d\n", minimumTotal(triangle));
=======

int minimumTotal(vector<vector<int> > &triangle) {

}

int main() {
>>>>>>> 491dfd8f50c1bb1ec45ad16a6831e41d92c6a8a5
  return 0;
}
