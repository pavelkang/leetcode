#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  if (l1==NULL&&l2==NULL)
    return NULL;
  if (l1==NULL)
    return l2;
  if (l2==NULL)
    return l1;
  ListNode *answer; ListNode *curr; ListNode *left; ListNode *right;
  if (l1->val < l2->val) {
    answer = l1;
    curr = l1;
    left = l1->next;
    right= l2;
  } else {
    answer = l2;
    curr = l2;
    left = l1;
    right= l2->next;
  }
  while (left!=NULL && right!=NULL) {
    if (left->val < right->val) {
      curr->next = left;
      left = left->next;
    } else {
      curr->next = right;
      right = right->next;
    }
    curr = curr->next;
  }
  if (left==NULL) {
    curr->next = right;
  } else if (right==NULL){
    curr->next = left;
  }
  return answer;
}
int main() {
  ListNode a(0); ListNode b(1);
  ListNode c(2); ListNode d(3);
  ListNode e(4);
  a.next = &d; d.next = &e;
  b.next = &c;
  ListNode *answer = mergeTwoLists(&a, &b);
  while (answer != NULL) {
    printf("%d - ", answer->val);
    answer = answer->next;
  }
  return 0;
}
