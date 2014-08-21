#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;


int sqrt(int x) {
  // Should not happen
  if (x<0)
    return -1;
  if (x==0||x==1)
    return x;
  for (int i=x/2; i<x; i++) {
    if (i*i>x)
      return i-1;
  }
  // Should not happen
  return 0;
}

int main() {
  printf("%d\n", sqrt(1));
  printf("%d\n", sqrt(0));
  printf("%d\n", sqrt(19));
  printf("%d\n", sqrt(2147483647));
  return 0;
}
