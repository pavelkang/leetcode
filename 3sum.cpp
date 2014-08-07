#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

vector< vector<int> > twoSum(vector<int> &num, int start, int target) {
  vector< vector<int> > answer;
  if (start>=num.size()-1)
    return answer;
  map<int, int> table;
  table.clear();
  for (int i=start+1; i<num.size(); i++) {
    table[num[i]] = i;
  }
  for (int i=start+1; i<num.size(); i++) {
    if (table.find(target-num[i])!=table.end() && table[target-num[i]]!=i){
      int j = table[target-num[i]];
      vector<int> result;
      if (i<j) {
        result.push_back(i); result.push_back(j);
      } else {
        result.push_back(j); result.push_back(i);
      }
      answer.push_back(result);
    }
  }
  return answer;
}
vector< vector<int> > threeSum(vector<int> &num) {
  //sort(num.begin(), num.end());
  //num.erase(unique(num.begin(), num.end()), num.end());
  map< vector<int>, int > answers; answers.clear();
  vector< vector<int> > answer;
  if (num.size()<3)
    return answer;
  for (int i=0; i<num.size(); i++) {
    int target = -num[i];
    vector< vector<int> > twoAnswer = twoSum(num, i, target);
    for (int j=0; j<twoAnswer.size(); j++) {
      vector<int> result;
      i, twoAnswer[j][0], twoAnswer[j][1];
      vector<int> resultID;
      int sumi = num[i] + num[twoAnswer[j][0]] + num[twoAnswer[j][1]];
      int mini = min(min(num[i], num[twoAnswer[j][0]]),num[twoAnswer[j][1]]);
      int maxi = max(max(num[i], num[twoAnswer[j][0]]),num[twoAnswer[j][1]]);
      resultID.push_back(mini);
      resultID.push_back(sumi-(mini+maxi));
      resultID.push_back(maxi);
      if (answers.find(resultID)==answers.end()) {
        answer.push_back(resultID);
        answers[resultID] = 1;
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
