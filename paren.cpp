#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void dfs(string s, int l, int r, int &n, vector<string> &answer) {
  if (l>n) return ;
  if (l==n&&r==n) {
    answer.push_back(s);}
  else {
    dfs(s+'(', l+1, r, n, answer);
    if (l>r) {
      dfs(s+')', l, r+1, n, answer);
    }
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> answer;
  if (n==0)
    return answer;
  else {
    dfs("", 0, 0, n, answer);
    return answer;
  }
}
int main() {
  vector<string> answer = generateParenthesis(3);
  for (int i=0; i<answer.size(); i++) {
    cout << answer[i] << endl;
  }
  return 0;
}
