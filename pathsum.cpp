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
bool hasPathSum(TreeNode *root, int sum) {
  if (root==NULL)
    return false;
  if (root->left==NULL && root->right==NULL)
    return root->val == sum;
  if (root->left==NULL)
    return hasPathSum(root->right, sum-root->val);
  if (root->right==NULL)
    return hasPathSum(root->left, sum-root->val);
  // root has two children
  return (hasPathSum(root->left, sum-root->val) ||
          hasPathSum(root->right, sum-root->val));
}
int main() {
  TreeNode a(5);TreeNode b(4);
  TreeNode c(8);TreeNode d(11);
  TreeNode e(13);TreeNode f(4);
  TreeNode g(7);TreeNode h(2);
  TreeNode i(1);
  a.left=&b; a.right=&c; b.left=&d; d.left=&g;d.right=&h;
  c.left=&e;c.right=&f;f.right=&i;
  if (hasPathSum(&a, 22)) {
    printf("YES\n");
  }
  return 0;
}
