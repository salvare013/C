#include <stdio.h>
#include <time.h>
#include "list.h"

typedef struct {
  char name[20];
  int age;
} People;

int CmpPeopleAge(const void *e1, const void *e2) {
  return DRFPTR(People, e1).age - DRFPTR(People, e2).age;
}
int CmpPeopleName(const void *e1, const void *e2) {
  return strcmp(DRFPTR(People, e1).name, DRFPTR(People, e2).name);
}
void PrintPeople(const void *data) {
  printf("name:%-10s\tage:%2d\n", DRFPTR(People, data).name,
         DRFPTR(People, data).age);
}
void ModifyInt(void *data) {
  int *d = (int *)data;
  *d = 666666;
}
void ModifyDouble(void *data) {
  // printf("输入>>>");
  // scanf("%lf", (double *)data);
  *(double *)data = 0.123456;
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

  ListRandomInsertIntData(list, 6666, 1314);

  // ListPrint(list, PrintInt);
  ListSort(list, CmpInt);
  // ListPrint(list, PrintInt);

  printf("list size: %zu\n", ListSize(list));
  printf("list capacity: %zu\n", ListCapacity(list));
  while (1) {
    int find;
    printf(">>>");
    scanf("%d", &find);
    int *data = ListFindData(list, &find, CmpInt);
    if (NULL == data) {
      printf("找不到该数据,请重新输入!\n");
    } else {
      ListPrintData(data, PrintInt);
      break;
    }
  }
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
  // ListClear(list);
  printf("list size: %zu\n", ListSize(list));
  printf("list capacity: %zu\n", ListCapacity(list));
  size_t index;
  while (1) {
    double data;
    printf("输入>>>");
    scanf("%lf", &data);
    index = ListFindDataAt(list, &data, CmpInt);
    if (index == ListSize(list)) {
      printf("找不到该数据,请重新输入!\n");
    } else {
      break;
    }
  }
  printf("find data index is %zu\n", index);
  ListIndexAccess(list, index, PrintDouble);
  ListDestory(list);
}
void test_struct() {
  List *list = mListCreate(People);
  People p;
  for (int i = 0; i < 3; i++) {
    printf("输入姓名>>>");
    scanf("%s", p.name);
    printf("输入年龄>>>");
    scanf("%d", &p.age);
    ListPushBack(list, &p);
  }
  ListPrint(list, PrintPeople);
  // ListSort(list, CmpPeopleAge);
  ListSort(list, CmpPeopleName);
  ListPrint(list, PrintPeople);
  while (1) {
    People p;
    printf(">>>");
    scanf("%d", &p.age);
    People *data = ListFindData(list, &p, CmpPeopleAge);
    if (NULL == data) {
      printf("找不到该数据,请重新输入!\n");
    } else {
      ListPrintData(data, PrintPeople);
      break;
    }
  }
  ListDestory(list);
}
int main(void) {
  srand((unsigned int)time(NULL));
  // test_int();
  // test_double();
  test_struct();

  return 0;
}