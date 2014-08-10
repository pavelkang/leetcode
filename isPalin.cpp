#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<math.h>
using namespace std;

bool isPalindrome(int x) {
  if (x==0)
    return true;
  int noOfDigits = 1;
  if (x<0)
    x = -x;
  printf("%d\n", x);
  while (1) {
    if ((int)(x/(pow(10,noOfDigits)))==0)
      break;
    else
      noOfDigits += 1;
  }
  for (int i=0; i<noOfDigits/2; i++) {
    int back = ((int)(x/pow(10,i)))%10;
    int front = ((int)(x/pow(10,noOfDigits-1-i)))%10;
    //printf("%d %d %d %d\n", back, front, i, noOfDigits);
    if (back!=front)
      return false;
  }
  return true;
}

int main() {
  if (isPalindrome(-2147447412))
    printf("YES\n");
  return 0;
}
