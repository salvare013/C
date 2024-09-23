#include <crtdefs.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

const void *SendData() {
  static int data;
  printf("输入>>>");
  scanf("%d", &data);
  return &data;
}
void ModifyInt(void *data) {
  int *d = (int *)data;
  *d = 666666;
}
void ModifyDouble(void *data) {
  // printf("输入>>>");
  // scanf("%lf", (double *)data);
  *(double *)data = 0.12345;
}
void PrintInt(const void *data) {
  printf("%d ", *(int *)data);
}
void PrintDouble(const void *data) {
  printf("%.5lf ", *(double *)data);
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

  // for (int i = 0, data; i < 3; i++) {
  //   data = rand() % 10;
  //   ListPushBack(list, &data);
  // }
  // ListPrint(list, PrintInt);

  // for (int i = 0, data; i < 3; i++) {
  //   data = rand() % 10;
  //   ListPushFront(list, &data);
  // }
  // int a = 666;
  // ListPosInsert(list, 2, &a);

  // ListPrint(list, PrintInt);
  // for (int i = 0; i < 1; i++) {
  //   ListPopBack(list);
  //   ListPopFront(list);
  // }
  // ListPosErase(list, 1);
  // ListPosErase(list, 0);
  // ListPosErase(list, ListSize(list) - 1);

  ListRandomInsertIntData(list, 13, 5);

  ListPrint(list, PrintInt);
  ListSort(list, CmpInt);
  ListPrint(list, PrintInt);

  printf("list size: %zu\n", ListSize(list));
  printf("list capacity: %zu\n", ListCapacity(list));
  printf("find data index is %zu\n",
         ListFindData(list, SendData(), CmpInt));
  printf("find data index is %zu\n",
         ListFindData(list, SendData(), CmpInt));
  ListDestory(list);
}
void test_double() {
  List *list = mListCreate(double);
  ListRandomInsertDoubleData(list, 13);
  ListPrint(list, PrintDouble);
  // ListSort(list, CmpDouble);
  ListDataModify(list, 0, ModifyDouble);
  ListDataModify(list, 4, ModifyDouble);
  printf("list new size:%zu:\n", ListResize(list, 5));
  ListPrint(list, PrintDouble);
  // printf("list[last] is %lf\n",
  //        *(double *)ListDataAt(list, ListSize(list) - 1));
  printf("list head data is %lf\n",
         DRFPTR(double, ListHeadData(list)));
  printf("list tail data is %lf\n",
         DRFPTR(double, ListTailData(list)));
  ListClear(list);
  printf("list size: %zu\n", ListSize(list));
  printf("list capacity: %zu\n", ListCapacity(list));
  ListDestory(list);
}
int main(void) {
  srand((unsigned int)time(NULL));
  test_int();
  // test_double();

  return 0;
}