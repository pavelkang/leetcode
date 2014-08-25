#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void sortColors(int A[], int n) {
  // [0, start) - 0
  // [start, end) - 1
  // [end, n) - 2
  int start = 0;
  int end = n-1;
  int ones = 0;
  while (start+ones<=end) {
    switch(A[start]) {
    case 0:
      start++; break;
    case 1:

      A[start] = A[start+ones];
      A[start+ones] = 1;
      ones += 1;
      break;
    case 2:
      A[start]=A[end];
      A[end]=2;
      end--; break;
    }
  }
}

int main() {
  int A[] = {0, 2, 1, 0, 1, 2, 0, 1, 0, 0};
  sortColors(A, 10);
  for (int i=0; i<10; i++) {
    printf("%d ", A[i]);
  } printf("\n");
  return 0;
}
