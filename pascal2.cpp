#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;
vector<int> getRow(int rowIndex) {
  vector<int> result(rowIndex+1);
  if (rowIndex==0) {
    result[0] = 1; return result;
  }
  if (rowIndex==1) {
    result[0] = 1; result[1] = 1; return result;
  } else {
    result[0] = 1; result[1] = 2; result[2] = 1;
    if (rowIndex==2)
      return result;
    int currentLength = 3;
    while (currentLength<rowIndex+1) {
      result[0] = 1; result[currentLength] = 1;
      vector<int> temp(currentLength+1);
      temp[0] = 1; temp[currentLength] = 1;
      for (int i=1; i<currentLength; i++) {
        temp[i] = result[i-1] + result[i];
      }
      for (int i=0; i<currentLength+1; i++) {
        result[i] = temp[i];
      }
      currentLength += 1;
    }
  }
  return result;
}
int main() {
  int a = 4;
  vector<int> result = getRow(a);
  for (int i=0; i<result.size(); i++) {
    printf("%d ", result[i]);
  } printf("\n");
}
