#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

double findSingle(int A[], int m) {
  if (m==0)
    return (double)0;
  if (m%2==0)
    return (double)(A[m/2-1]+A[m/2])/(2.0f);
  else
    return (double)(A[m/2]);
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
  if (m==0) return findSingle(B, n);
  if (n==0) return findSingle(A, m);
  int i=0; int j=0;
  int first, second;
  while (i+j<=(m+n)/2) {
    if (A[i]<B[j]) {
      if (i+j==(m+n)/2-1)
        first = A[i];
      if (i+j==(m+n)/2)
        second = A[i];
      i++;
    } else {
      if (i+j==(m+n)/2-1)
        first = B[j];
      if (i+j==(m+n)/2)
        second = B[j];
      j++;
    }
    if (i==m||j==n)
      break;
  }
  if (i==m) {
    while (i+j<=(m+n)/2) {
      if (i+j==(m+n)/2-1)
        first = B[j];
      if (i+j==(m+n)/2)
        second = B[j];
      j++;
    }
  }
  if (j==n) {
    while (i+j<=(m+n)/2) {
      if (i+j==(m+n)/2-1)
        first = A[i];
      if (i+j==(m+n)/2)
        second = A[i];
      i++;
    }
  }
  if ((m+n)%2==0)
    return (double)((first+second)/2.0);
  else
    return (double)second;
}

int main() {
  int A[] = {1,3,5,7,9};
  int B[] = {2,4,6,8,10};
  printf("A B : %lf\n", findMedianSortedArrays(A, 5, B, 5)); // 5.5
  int C[] = {2,4,6,8};
  int a[] = {1};
  int b[] = {2};
  int c[] = {};
  printf("A C : %lf\n", findMedianSortedArrays(A,5,C,4)); //5.0
  printf("%lf\n", findMedianSortedArrays(a,1,b,1));
  printf("%lf\n", findMedianSortedArrays(a,1,c,0));
  return 0;
}
