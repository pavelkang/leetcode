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
  ListNode(int x): val(x), next(NULL){}
};

ListNode *deleteDuplicates(ListNode *head) {
  if (head==NULL)
    return head;
  ListNode *headTemp = head;
  ListNode *lastPoint = head;
  int lastVal = head->val;
  ListNode *currPoint = head->next;
  while (currPoint!=NULL) {
    if (currPoint->val==lastVal) {
      currPoint = currPoint->next;
    } else {
      lastPoint->next = currPoint;
      lastPoint = currPoint;
      lastVal = currPoint->val;
    }
  }
  lastPoint->next = NULL;
  return headTemp;
}

int main() {
  ListNode a(1);
  ListNode b(1);
  ListNode c(2);
  ListNode d(2);
  ListNode e(3);
  a.next = &b; b.next = &c; c.next = &d; d.next = &e;
  ListNode *answer = deleteDuplicates(&a);
  if (answer==NULL)
    printf("NULL\n");
  else {
    while (answer!=NULL) {
      printf("%d - ", answer->val);
      answer = answer->next;
    }
  }
  return 0;
}
