#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

int singleNumber(int A[], int n) {
  int answer = 0;
  for (int i=0; i<n; i++) {
    answer = answer ^ A[i];
  }
  return answer;
}

int main () {
  int A[] = {1, 2, 3, 4, 2, 3, 1}; // answer = 4
  int answer = singleNumber(A, 7);
  printf("answer is %d\n", answer);
  return 0;
}
