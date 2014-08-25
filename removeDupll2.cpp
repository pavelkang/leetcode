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

ListNode *deleteDuplicates(ListNode *head) {
  if (head==NULL||head->next==NULL)
    return head;
  if (head->val != head->next->val) { // single
    ListNode *partial = deleteDuplicates(head->next);
    head->next = partial;
    return head;
  }
  ListNode *curr = head;
  int lastVal = curr->val;
  while (curr!=NULL&&curr->val==lastVal) {
    curr = curr->next;
  }
  return deleteDuplicates(curr);
}

int main() {
  ListNode a(1); ListNode b(2); ListNode c(3);
  ListNode d(3); ListNode e(4); ListNode f(4); ListNode g(5);
  a.next = &b; b.next = &c; c.next = &d; d.next = &e; e.next = &f; f.next=&g;
  ListNode *answer = deleteDuplicates(&a);
  while (answer != NULL) {
    printf("%d ", answer->val); answer = answer->next;
  }
  return 0;
}
