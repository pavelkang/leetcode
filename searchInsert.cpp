#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

int searchInsert(int A[], int n, int target) {
  int i = 0;
  while (A[i]<target && i<n) {
    i += 1;
  }
  return i;
}

int main() {
  int A[] = {1,3,5,6};
  printf("%d\n", searchInsert(A, 4, 5));
  printf("%d\n", searchInsert(A, 4, 2));
  printf("%d\n", searchInsert(A, 4, 7));
  printf("%d\n", searchInsert(A, 4, 0));
  return 0;
}
