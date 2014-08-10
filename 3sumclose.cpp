#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

int threeSumClosest(vector<int> &num, int target) {
  sort(num.begin(), num.end());
  const int INF = 1<<30;
  int best = INF;
  int l = num.size();
  for (int first=0; first<l-2; first++) {
    int second = first+1; int third = l-1;
    while (second<third) {
      int total = num[first] + num[second] + num[third];
      int dif = target - total;
      if (total<target) {
        if (dif < abs(best)) {
          best = dif;
        }
        second++;
      } else if (total==target) {
        return target;
      } else { // total > target
        if (-dif<abs(best)) {
          best = dif;
        }
        third--;
      }
    }
  }
  return target-best;
}

int main() {
  vector<int> num;
  num.push_back(-1);
  num.push_back(2);
  num.push_back(1);
  num.push_back(-4);
  printf("%d\n", threeSumClosest(num, 1));
  return 0;
}
