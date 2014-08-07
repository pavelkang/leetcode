#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int longestValidParentheses(string s) {
  if (s.size() < 2) {
    return 0;
  }
  int last = -1;
  int maxLen = 0;
  stack<int> S;
  for (int i=0; i<s.size(); i++) {
    if (s[i]=='(') {
      S.push(i);
    }
    else {
      if (S.empty()) last = i;
      else {
        S.pop();
        if (S.empty()) {maxLen = max(i-last, maxLen);}
        else {maxLen = max(i-S.top(), maxLen);}
      }
    }
  }
  return maxLen;
}
int main () {
  string test = "()";
  printf("%d\n", longestValidParentheses(test));
  return 0;
}
