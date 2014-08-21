#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
  if (head == NULL)
    return head;
  if (head->next == NULL) {
    return head;
  }
  ListNode *tails = swapPairs(head->next->next);
  ListNode *next = head->next;
  next->next = head;
  head->next = tails;
  return next;
}

int main() {
  return 0;
}
