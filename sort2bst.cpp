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

void toBST(TreeNode *root, vector<int> &num, int start, int end) {
  if (start>=end)
    return ;
  if (start+1==end) {
    root->val = num[start];
    return ;
  }
  int mid = start+(end-start)/2;
  root->val = num[mid];
  TreeNode *left(0); TreeNode *right(0);
  root->left = left; root->right = right;
  toBST(root->left, num, start, mid);
  toBST(root->right, num, mid+1, end);
}

TreeNode *sortedArrayToBST(vector<int> &num) {
  if (num.size()==0)
    return NULL;
  TreeNode *root(num[num.size()/2]);
  TreeNode *left(0); TreeNode *right(0);
  root->left = left; root->right = right;
  toBST(left, num, 0, num.size()/2);
  toBST(right, num, num.size()/2+1, num.size());
  return root;
}

int main() {
  return 0;
}
