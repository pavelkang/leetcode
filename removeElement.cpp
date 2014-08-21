#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int removeElement(int A[], int n, int elem) {
  if (n==0)
    return 0;
  int currIndex = 0;
  int newLength = 0;
  while (currIndex<n) {
    if (elem==A[currIndex]) {
    } else {
      A[newLength] = A[currIndex];
      newLength += 1;
    }
    currIndex += 1;
  }
  return newLength;
}
int main() {
  int A[] = {1, 3, 1, 2, 1, 4, 1};
  int answer = removeElement(A, 7, 1);
  printf("%d\n", answer);
  for (int i=0; i<answer; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}
