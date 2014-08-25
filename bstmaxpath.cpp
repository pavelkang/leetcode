#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode *root) {
  if (root==NULL)
    return 0;
  int left = maxPathSum(root->left);
  int right = maxPathSum(root->right);
  left = left>0?left:0;
  right = right>0?right:0;
  return root->val + left + right;
}

int main() {

  return 0;
}
