#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
void merge(int A[], int m, int B[], int n) {
  if (n==0) return;
  if (m==0 && n!=0) {
    for (int i=0; i<n; i++) {
      A[i] = B[i];
    }
    return ;
  }
  int C[m];
  for (int i=0; i<m; i++) {
    C[i] = A[i];
  }
  int i= 0; int j=0;
  while (1) {
    if (C[i] > B[j]) {
      A[i+j] = B[j]; j++; }
    else {
      A[i+j] = C[i]; i++;
    }
    if (i==m || j==n) break;
  }
  if (i==m) {
    for (int k=i+j; k<m+n; k++) {
      A[k] = B[k-i];
    }
  }
  if (j==n) {
    for (int k=i+j; k<m+n; k++) {
      A[k] = C[k-j];
    }
  }
}
int main() {
  /*
  int A[4] = {1, 3, 5, 7};
  int B[4] = {2, 4, 6, 8};*/
  int A[0] = {};
  int B[5] = {1,2,3,4,5};
  merge(A, 0, B, 5);
  for (int i=0; i<8; i++) {
    printf("%d", A[i]);
  }
  return 0;
}
