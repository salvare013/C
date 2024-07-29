#include "list.h"

ListNode *BuyListNode(listData_t data) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  if (node == NULL) {
    exit(-1);
  } else {
    node->data = data;
    node->next = NULL;
    return node;
  }
}
void TraverseList(const ListNode *pHead) {
  assert(pHead);
  ListNode *cur = (ListNode *)pHead;
  do {
    printf("%d ", cur->data);
    cur = cur->next;
  } while (cur != NULL);
  printf(("\n"));
}
void InsertNode(ListNode *dest, listData_t data) {
  assert(dest);
  ListNode *newNode = BuyListNode(data);
  newNode->next = dest->next;
  dest->next = newNode;
}
void RemoveNode(ListNode *dest) {
  assert(dest);
  if (dest->next == NULL) {
    return;
  }
  ListNode *tmp = dest->next->next;
  free(dest->next);
  dest->next = tmp;
}
ListNode *AccessNode(const ListNode *start, int index) {
  assert(start && index > 0);
  int count = 0;
  ListNode *cur = (ListNode *)start;
  do {
    count++;
    if (count == index) {
      return cur;
    }
    cur = cur->next;
  } while (cur != NULL);
  return NULL;
}
int FindNode(const ListNode *pHead, listData_t target) {
  assert(pHead);
  ListNode *cur = (ListNode *)pHead;
  int index = 0;
  do {
    index++;
    if (cur->data == target) {
      return index;
    }
    cur = cur->next;
  } while (cur != NULL);
  return -1;
}
void DestoryList(ListNode **ppHead) {
  assert(ppHead);
  ListNode *curNode = *ppHead;
  ListNode *nextNode = NULL;
  do {
    nextNode = curNode->next;
    free(curNode);
    curNode = nextNode;
  } while (nextNode != NULL);

  *ppHead = NULL;
}