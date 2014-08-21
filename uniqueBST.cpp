#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;
long long int facs[99999];
long long int fac(int x) {
  if (facs[x]!=0)
    return facs[x];
  facs[x] = x*fac(x-1);
  return facs[x];
}

long long int choose(int n, int k) {
  long result = 1;
  for (int i=k+1; i<=n; i++) {
    result *= i;
  }
  result = result/fac(n-k);
  return result;
}

int numTrees(int n) {
  facs[0] = 1;
  return (int)choose(2*n, n)/(n+1);
}

int main() {
  printf("%d\n", numTrees(9));
  return 0;
}
