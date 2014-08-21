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

bool hasCycle(ListNode *head) {
  if (head==NULL)
    return false;
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (fast != NULL) {
    if (fast->next==NULL)
      return false;
    if (fast==slow)
      return true;
    fast = fast->next->next;
    slow = slow->next;
  }
  return false;
}

int main() {
  ListNode a(0);
  ListNode b(1);
  ListNode c(2);
  ListNode d(3);
  a.next = &b; b.next = &c; c.next = &d; d.next = &a;
  if (hasCycle(&a))
    printf("YES\n");
  return 0;
}
