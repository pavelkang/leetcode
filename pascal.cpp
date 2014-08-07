#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > generate(int numRows) {
  vector< vector<int> > answer;
  if (numRows==0) {
    return answer;
  }
  if (numRows==1) {
    vector<int> row; row.push_back(1);
    answer.push_back(row); return answer;
  }
  else {
    answer = generate(numRows-1);
    vector<int> lastRow = answer.back();
    vector<int> row;
    row.push_back(1);
    for (int i=0; i<lastRow.size()-1; i++) {
      row.push_back(lastRow[i]+lastRow[i+1]);
    }
    row.push_back(1);
    answer.push_back(row);
    return answer;
  }
}

int main() {
  vector< vector<int> > test = generate(5);
  for (int i=0; i<test.size(); i++) {
    for (int j=0; j<test[i].size(); j++) {
      printf("%d ", test[i][j]);
    }
    printf("\n");
  }
  return 0;
}
