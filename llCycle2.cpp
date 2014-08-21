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
map<ListNode *, bool>table;
ListNode *detectCycle(ListNode *head) {
  if (head==NULL)
    return NULL;
  if (table.find(head)==table.end()) {
    table[head] = true;
    detectCycle(head->next);
  } else {
    return head;
  }
}

int main() {
  ListNode a(0);
  ListNode b(1);
  ListNode c(2);
  ListNode d(3);
  a.next = &b; b.next = &c; c.next = &d; d.next = &c;
  ListNode *answer = detectCycle(&a);
  if (answer==NULL)
    printf("NULL\n");
  else
    printf("%d\n", answer->val);
  return 0;
}
