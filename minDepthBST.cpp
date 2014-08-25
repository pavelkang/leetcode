#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
  if (root==NULL)
    return 0;
  if (root->left==NULL&&root->right!=NULL)
    return 1+minDepth(root->right);
  if (root->left!=NULL&&root->right==NULL)
    return 1+minDepth(root->left);
  if (root->left==NULL&&root->right==NULL)
    return 1;
  return 1+min(minDepth(root->left), minDepth(root->right));
}

int main() {
  return 0;
}
