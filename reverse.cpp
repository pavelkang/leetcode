#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

int reverse(int x) {
  bool isNeg = false;
  if (x<0) {
    isNeg = true;
    x = -x; // make x positive
  }
  int result = 0;
  while (x>0) {
    int mod = x%10;
    x = x/10;
    result = result*10 + mod;
  }
  if (isNeg)
    result = -result;
  return result;
}

int main() {
  printf("%d\n", reverse(123));
  printf("%d\n", reverse(100));
  printf("%d\n", reverse(-123));
  return 0;
}
