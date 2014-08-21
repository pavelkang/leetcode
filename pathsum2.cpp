#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > pathSum(TreeNode *root, int sum) {
  vector<vector<int> > answer;
  // Base case
  if (root==NULL)
    return answer;
  if (root->left==NULL && root->right==NULL && sum==root->val) {
    vector<int> result; result.push_back(root->val);
    answer.push_back(result); return answer;
  }
  // Recursion
  vector<vector<int> > left = pathSum(root->left, sum-root->val);
  vector<vector<int> > right = pathSum(root->right, sum-root->val);
  vector<int> result;
  for (int i=0; i<left.size(); i++) {
    result = left[i];
    result.insert(result.begin(), root->val);
    answer.push_back(result);
  }
  for (int i=0; i<right.size(); i++) {
    result = right[i];
    result.insert(result.begin(), root->val);
    answer.push_back(result);
  }
  return answer;
}

int main() {
  TreeNode a(5); TreeNode b(4); TreeNode c(8); TreeNode d(11);
  TreeNode e(13); TreeNode f(4); TreeNode g(7); TreeNode h(2);
  TreeNode i(5); TreeNode j(1);
  a.left = &b; a.right = &c; b.left = &d; c.left=&e; c.right=&f;
  d.left = &g; d.right = &h; f.left = &i; f.right=&j;
  vector< vector<int> >answer = pathSum(&a, 22);
  for (int i=0; i<answer.size(); i++) {
    for (int j=0; j<answer[i].size(); j++) {
      printf("%d ", answer[i][j]);
    }
    printf("\n");
  }
  return 0;
}
