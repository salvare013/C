#include "slist.h"

SLNode *GetSLNode(T data, const char *dataType) {
  SLNode *node = (SLNode *)malloc(sizeof(SLNode));
  if (node == NULL) {
    printf("malloc fail");
    exit(-1);
  }
  node->data = data;
  node->dataType = dataType;
  node->next = NULL;
  return node;
}
void TraverseSL(const SLNode *pHead) {
  assert(pHead);
  const SLNode *cur = pHead;
  do {
    if (0 == strcmp("char", cur->dataType)) {
      printf("<%s>%c --> ", cur->dataType, cur->data.c);
      cur = cur->next;
      continue;
    }
    if (0 == strcmp("int", cur->dataType)) {
      printf("<%s>%d --> ", cur->dataType, cur->data.i);
      cur = cur->next;
      continue;
    }
    if (0 == strcmp("double", cur->dataType)) {
      printf("<%s>%lf --> ", cur->dataType, cur->data.d);
      cur = cur->next;
      continue;
    }
    if (0 == strcmp("size_t", cur->dataType)) {
      printf("<%s>%zu --> ", cur->dataType, cur->data.sz);
      cur = cur->next;
      continue;
    }
    if (0 == strcmp("char*", cur->dataType)) {
      printf("<%s>%s --> ", cur->dataType, cur->data.pc);
      cur = cur->next;
      continue;
    }
  } while (cur != NULL);
  printf("null\n");
}
void LinkSLNode(SLNode *front, SLNode *back) {
  assert(front->next == NULL);
  front->next = back;
}
void DestorySL(SLNode **ppHead) {
  assert(ppHead);
  SLNode *curNode = *ppHead;
  SLNode *nextNode = NULL;
  do {
    nextNode = curNode->next;
    free(curNode);
    curNode = nextNode;
  } while (nextNode != NULL);

  *ppHead = NULL;
}
void RemoveSLNode(SLNode *dest) {
  assert(dest);
  if (dest->next == NULL) {
    return;
  }
  SLNode *tmp = dest->next->next;
  free(dest->next);
  dest->next = tmp;
}