#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
string lcp(vector<string> &strs) {
  if (strs.size()<1)
    return "";
  if (strs.size()==1)
    return strs[0];
  string answer;
  int currInd = 0; char currChar; bool found = false;
  for(currInd=0; currInd<strs[0].size(); currInd++) {
    currChar = strs[0].c_str()[currInd];
    int i;
    for (i=1; i<strs.size(); i++) {
      if (currInd>=strs[i].size()) {found=true; break;}
      char a = strs[i].c_str()[currInd];
      if (a!=currChar) {
        found = true; break;
      }
    }
    if (found) {break;}
    if (i==strs.size()) {
      answer += currChar;
    }
  }
  return answer;
}

int main() {
  vector<string> test;
  /*
  test.push_back(string("Haello"));
  test.push_back(string("Haello Kitty"));
  test.push_back(string("Haello World"));*/
  printf("%s\n", lcp(test).c_str());
  return 0;
}
