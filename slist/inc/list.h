#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define listData_t int
typedef struct ListNode {
  listData_t data;
  struct ListNode *next;
} ListNode;

ListNode *BuyListNode(listData_t data);
void TraverseList(const ListNode *pHead);
void InsertNode(ListNode *dest, listData_t data);
void RemoveNode(ListNode *dest);
ListNode *AccessNode(const ListNode *start, int index);
int FindNode(const ListNode *pHead, listData_t target);
void DestoryList(ListNode **ppHead);