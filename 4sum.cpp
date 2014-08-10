#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

vector< vector<int> > threeSum(vector<int> &num, int start, int aim) {
  map< vector<int>, bool >table;
  int l = num.size();
  vector< vector<int> > answer;
  if (l-start<3)
    return answer;
  for (int first=start; first<l-2; first++) {
    int target = aim-num[first];
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

vector<vector<int> > fourSum(vector<int> &num, int target) {
  vector<vector<int> > answer;
  map<vector<int>, bool> table;
  int l = num.size();
  if (l<4)
    return answer;
  sort(num.begin(), num.end());
  for (int first=0; first<l-3; first++) {
    int newTarget = target - num[first];
    vector< vector<int> > partialResult = threeSum(num, first+1, newTarget);
    for (int i=0; i<partialResult.size(); i++) {
      vector<int> result(4); result[0] = num[first];
      result[1] = partialResult[i][0];result[2] = partialResult[i][1];
      result[3] = partialResult[i][2];
      if (table.find(result)==table.end()) {
        answer.push_back(result);
        table[result] = true;
      }
    }
  }
  return answer;
}
int main() {
  int s[] = {1, 0, -1, 0, -2, 2};
  vector<int> test(6);
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
