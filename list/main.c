#include "list.h"

int main(void) {
  List list;

  InitList(&list);
  printf("list size:%zu\n", ListSize(&list));
  printf("list capacity:%zu\n", ListCapacity(&list));
  PrintList(&list);

  RandomInsert(&list, 13, 9);

  printf("bf:\n");
  PrintList(&list);

  SortList(&list);
  printf("af:\n");
  PrintList(&list);

  PopBack(&list);
  PopFront(&list);
  PrintList(&list);

  PushBack(&list, 1314);
  PushFront(&list, 520);
  PrintList(&list);

  int index = FindList(&list, 6);
  printf("index:%d\n", index);
  if (-1 == index) {
    printf("没有找到目标数据!\n");
  } else {
    PosInsert(&list, index, 888);
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