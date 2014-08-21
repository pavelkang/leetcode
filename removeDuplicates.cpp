#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

int removeDuplicates(int A[], int n) {
  if (n==0||n==1)
    return n;
  int lastVal = A[0];
  int newLength = 1;
  int currIndex = 1;
  while (currIndex<n) {
    if (lastVal==A[currIndex]) {
      // Nothing
    } else {
      A[newLength] = A[currIndex];
      newLength += 1;
      lastVal = A[currIndex];
    }
    currIndex+=1;
  }
  return newLength;
}

int main() {
  int A[5] = {1, 1, 2, 3, 3};
  int answer = removeDuplicates(A, 5);
  printf("%d\n", answer);
  for (int i =0; i<answer; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}
