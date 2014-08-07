#include<map>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
  vector<int> answer;
  map<int, int> table;
  table.clear();
  for (int i=0; i<numbers.size(); i++) {
    table[numbers[i]] = i;
  }
  for (int i=0; i<numbers.size(); i++) {
    if (table.find((target-numbers[i])) != table.end()) {
      int j = table[target-numbers[i]];
      if (i<j) {
        answer.push_back(i+1); answer.push_back(j+1); return answer;
      } else {
        answer.push_back(j+1); answer.push_back(i+1); return answer;
      }
    }
  }
  return answer;
}

int main() {
  vector<int> V;
  V.push_back(3);
  V.push_back(2);
  V.push_back(4);
  printf("V: <%d %d %d>\n", V[0], V[1], V[2]);
  vector<int> answer = twoSum(V, 6);
  printf("answer: <%d %d>\n", answer[0], answer[1]);
  return 0;
}
