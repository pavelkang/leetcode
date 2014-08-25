#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

int removeDuplicates(int A[], int n) {
  if (n<=2)
    return n;
  int lastVal = A[0];
  int currInd = 1;
  int length = 1;
  int acc = 1;
  while (currInd < n) {
    int val = A[currInd];
    if (val != lastVal) {
      acc = 1;
      A[length] = val;
      lastVal = val;
      length++;
    } else {
      if (acc==1) {
        A[length] = val; length++;
        acc++;
      }
    }
    currInd++;
  }
  return length;
}

int main() {
  int A[] = {1, 1, 1, 2, 2, 3}; int B[] = {1, 1, 1, 1};
  int answer = removeDuplicates(A, 6);
  printf("length is %d\n", answer);
  for (int i=0; i<answer; i++) {
    printf("%d ", A[i]);
  } printf("\n");
  return 0;
}
