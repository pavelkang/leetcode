#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;
vector<vector<int> > fourSum(vector<int> &num, int target) {
  sort(num.begin(), num.end());

}
int main() {
  int s[] = {1, 0, -1, 0, -2, 2};
  vector<int> test[6];
  for (int i=0; i<6; i++) {
    test[i] = s[i];
  }
  vector<vector<int> > answer = fourSum(test, 0);
  for (int i=0; i<answer.size(); i++) {
    for (int j=0; j<answer[i].size();j++) {
      printf("%d ", answer[i][j]);
    }
    printf("\n");
  }
  return 0;
}
