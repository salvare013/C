#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

void PrintInt(const void *data) {
  printf("%d ", *(int *)data);
}
void PrintDouble(const void *data) {
  printf("%.3lf ", *(double *)data);
}
int CmpInt(const void *e1, const void *e2) {
  return *(int *)e1 - *(int *)e2;
}
int CmpDouble(const void *e1, const void *e2) {
  return (*(double *)e1 > *(double *)e2
              ? 1
              : (*(double *)e1 < *(double *)e2 ? -1 : 0));
}
void test_int() {
  List *list = mListCreate(int);
  printf("list size: %zu\n", ListSize(list));
  printf("list capacity: %zu\n", ListCapacity(list));

  for (int i = 0, data; i < 3; i++) {
    data = rand() % 10;
    ListPushBack(list, &data);
  }
  ListPrint(list, PrintInt);

  for (int i = 0, data; i < 3; i++) {
    data = rand() % 10;
    ListPushFront(list, &data);
  }
  int a = 666;
  ListPosInsert(list, 2, &a);

  ListPrint(list, PrintInt);
  for (int i = 0; i < 1; i++) {
    ListPopBack(list);
    ListPopFront(list);
  }
  ListPosErase(list, 1);
  ListPosErase(list, 0);
  ListPosErase(list, ListSize(list) - 1);

  ListRandomInsertIntData(list, 13, 520);

  ListPrint(list, PrintInt);
  ListSort(list, CmpInt);
  ListPrint(list, PrintInt);

  printf("list size: %zu\n", ListSize(list));
  printf("list capacity: %zu\n", ListCapacity(list));

  ListDestory(list);
}
void test_double() {
  List *list = mListCreate(double);
  ListRandomInsertDoubleData(list, 13);
  ListPrint(list, PrintDouble);
  ListSort(list, CmpDouble);
  ListPrint(list, PrintDouble);

  ListDestory(list);
}
int main(void) {
  srand((unsigned int)time(NULL));
  // test_int();
  test_double();

  return 0;
}