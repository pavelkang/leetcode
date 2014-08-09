#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

int singleNumber(int A[], int n) {
  map<int, int> table;
  for (int i=0; i<n; i++) {
    if (table.find(A[i])==table.end()) {
      table[A[i]] = 1;
    } else {
      table[A[i]] += 1;
    }
  }
  for (map<int, int>::const_iterator it = table.begin(); it!=table.end(); it++){
    if (it->second==1) {
      return it->first;
    }
  }
  // Should not come here
  return 0;
}

int main () {
  int A[] = {1, 1, 2, 2, 3, 3, 4, 2, 3, 1}; // answer = 4
  int answer = singleNumber(A, 10);
  printf("answer is %d\n", answer);
  return 0;
}
