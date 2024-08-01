#include "list.h"

int main(void) {
  srand((unsigned int)time(NULL));

  List list;
  InitList(&list);

  printf("list size:%zu\n", ListSize(&list));
  printf("list capacity:%zu\n", ListCapacity(&list));

  // RandomInsert(&list, 10, 10);
  RandomInsert(&list, 10);

  PrintList(&list);
  printf("bf:\n");
  PrintList(&list);

  SortList(&list);
  printf("af:\n");
  PrintList(&list);

  PopBack(&list);
  PopFront(&list);
  PrintList(&list);

  PushBack(&list, 1);
  PushFront(&list, 0);
  PrintList(&list);

  int index = FindList(&list, 0);
  printf("index:%d\n", index);
  if (-1 == index) {
    printf("没有找到目标数据!\n");
  } else {
    // PosInsert(&list, index, 666);
    PosInsert(&list, index, 0.123);

    PrintList(&list);

    PosErase(&list, index);
    PrintList(&list);
  }
  printf("list size:%zu\n", ListSize(&list));
  printf("list capacity:%zu\n", ListCapacity(&list));

  PosErase(&list, ListSize(&list) - 1);
  PosErase(&list, 0);
  PrintList(&list);

  printf("list size:%zu\n", ListSize(&list));
  printf("list capacity:%zu\n", ListCapacity(&list));

  DestoryList(&list);

  return 0;
}