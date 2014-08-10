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
int sumNumbers(TreeNode *root) {
  if (root==NULL)
    return 0;
  if (root->left == NULL && root->right == NULL) {
    return root->val;
  }
  if (root->left == NULL) {
    return 10*(root->val)+sumNumbers(root->right);
  }
  if (root->right == NULL) {
    return 10*(root->val)+sumNumbers(root->left);
  }
  return 20*(root->val) + sumNumbers(root->left) + sumNumbers(root->right);
}
int main() {
  struct TreeNode root(1);
  struct TreeNode leaf1(2);
  struct TreeNode leaf2(3);
  struct TreeNode leaf3(0);
  //root.left = &leaf1; root.right = &leaf2;
  root.left = &leaf3;
  printf("%d\n", sumNumbers(&root));
  return 0;
}
