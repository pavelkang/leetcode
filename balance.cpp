#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *right;
  TreeNode *left;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode *root) {
  if (root==NULL)
    return 0;
  return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(TreeNode *root) {
  if (root==NULL)
    return true;
  bool isBalHere = abs(getHeight(root->left)-getHeight(root->right)) <= 1;
  return isBalanced(root->left) && isBalanced(root->right) && isBalHere;
}

int main() {
  return 0;
}
