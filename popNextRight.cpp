#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *right;
  TreeLinkNode *left;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
  if (root==NULL || root->left==NULL)
    return ;
  if (root->left->left==NULL) {
    root->left->next = root->right;
    return ;
  }
  TreeLinkNode *l = root->left; TreeLinkNode *r = root->right;
  while (l!=NULL) {
    l->next = r;
    l = l->right; r = r->left;
  }
  connect(root->left);
  connect(root->right);
}

int main() {
  return 0;
}
