#include "list.h"

int main(void) {
  List list;
  InitList(&list);
  srand((unsigned int)time(NULL));
  mPushBack(&list, -123);
  mPushBack(&list, sizeof(int));
  mPushBack(&list, "abcdefgh");
  mPushBack(&list, (char)'k');
  mPushBack(&list, 0.666666666);
  // PushBack(&list, (T)666, "size_t");
  // PushBack(&list, (T)0.333, "double");

  // RandomInsertSize_tData(&list, 13, 13);
  // TraverseSize_tData(&list);

  // RandomInsertDoubleData(&list, 6);
  // TraverseDoubleData(&list);

  // RandomInsertCharData(&list, 13);
  // TraverseCharData(&list);

  PrintList(&list);

  DestoryList(&list);

  return 0;
}