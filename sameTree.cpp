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

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p==NULL && q==NULL)
    return true;
  else if (p==NULL || q==NULL)
    return false;
  else {
    return p->val==q->val && isSameTree(p->left, q->left) &&
      isSameTree(p->right, q->right);
  }
}

int main() {
  return 0;
}
