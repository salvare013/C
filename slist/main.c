#include "list.h"

int main(void) {
  ListNode *n0 = BuyListNode(0);
  ListNode *n1 = BuyListNode(1);
  ListNode *n2 = BuyListNode(2);
  ListNode *n3 = BuyListNode(3);
  ListNode *n4 = BuyListNode(4);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  TraverseList(n0);
  InsertNode(n2, 666);
  TraverseList(n0);
  RemoveNode(n1);
  TraverseList(n0);
  int pos = FindNode(n0, 666);
  printf("pos:%d\n", pos);
  ListNode *ret = AccessNode(n0, pos);
  if (ret != NULL) {
    printf("pos-->data:%d\n", ret->data);
  } else {
    printf("not find\n");
  }
  // 堆上申请的内存一定要释放!
  DestoryList(&n0);

  return 0;
}