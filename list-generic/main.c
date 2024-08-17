#include <corecrt.h>
#include <stdio.h>
#include "list.h"

int main(void) {
  List list;
  InitList(&list);
  srand((unsigned int)time(NULL));
  printf("list size:%d\n", ListSize(&list));
  printf("list capacity:%d\n", ListCapacity(&list));

  mPushBack(&list, -123);
  mPushBack(&list, sizeof(List));
  mPushBack(&list, 0.666666);
  PushBack(&list, (T) "abcdefgh", "char*");
  PushBack(&list, (T)'k', "char");
  mPushFront(&list, -520);
  mPushFront(&list, "love");
  PushFront(&list, (T)0, "int");
  PushFront(&list, (T)'a', "char");

  // RandomInsertIntData(&list, 3, 3);
  // TraverseIntData(&list);

  // RandomInsertDoubleData(&list, 3);
  // TraverseDoubleData(&list);

  // RandomInsertCharData(&list, 3);
  // TraverseCharData(&list);

  PrintList(&list);

  int index = mFindListData(&list, "love");
  printf("index:%d\n", index);
  mPosInsert(&list, index, "NB!!!");

  // PopBack(&list);
  // PopBack(&list);
  // PopBack(&list);
  // PopFront(&list);
  // PopFront(&list);
  // PopFront(&list);

  // PrintList(&list);
  PrintList(&list);
  PosErase(&list, index);
  PrintList(&list);

  printf("list size:%d\n", ListSize(&list));
  printf("list capacity:%d\n", ListCapacity(&list));

  DestoryList(&list);

  return 0;
}