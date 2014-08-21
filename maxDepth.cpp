#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

int maxDepth(TreeNode *root) {
  if (root==NULL)
    return 0;
  return 1+max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
  return 0;
}
