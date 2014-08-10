#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

vector< vector<int> > threeSum(vector<int> &num) {
  sort(num.begin(), num.end());
  map< vector<int>, bool >table; table.clear();
  /*for (int i=0; i<num.size(); i++) {
    printf("%d ", num[i]);
    } printf("\n");*/
  int l = num.size();
  vector< vector<int> > answer;
  if (l<3)
    return answer;
  for (int first=0; first<l-2; first++) {
    int target = -num[first];
    int second = first+1; int third = l-1;
    while(third>second){
      if (num[second]+num[third]==target) {
        vector<int> result;
        result.push_back(num[first]); result.push_back(num[second]);
        result.push_back(num[third]);
        if (table.find(result)==table.end()) {
          answer.push_back(result);
          table[result] = true;
        }
        second += 1; third -= 1;
      } else if (num[second] + num[third] > target) {
        third -= 1;
      } else { // <
        second += 1;
      }
    }
  }
  return answer;
}
int main() {
  vector<int> test;
  test.push_back(-1);  test.push_back(0);  test.push_back(1);
  test.push_back(2);  test.push_back(-1);   test.push_back(-4);
  vector< vector<int> > answer =  threeSum(test);
  for (int i=0; i<answer.size(); i++) {
    vector<int> result = answer[i];
    printf("<%d %d %d>\n", result[0], result[1], result[2]);
  }
  return 0;
}
