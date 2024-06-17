#include "bubble.h"

void test_int() {
  int arr[] = {1, 3, 5, 8, 4, 36, 54, 88, 99, 11, 22, 6};
  int num = sizeof(arr) / sizeof(arr[0]);
  printf("前:");
  for (int i = 0; i < num; i++) {
    printf("%d ", arr[i]);
  }
  BubbleSort(arr, num, sizeof(arr[0]), CmpInt);
  printf("\n后:");
  for (int i = 0; i < num; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void test_float() {
  float arr[] = {1.1, 3.1, 1.2, 2.1, 6.2, 0.1, 1.3, 1.5, 6.6};
  int num = sizeof(arr) / sizeof(arr[0]);
  printf("前:");
  for (int i = 0; i < num; i++) {
    printf("%.1f ", arr[i]);
  }
  BubbleSort(arr, num, sizeof(arr[0]), CmpFloat);
  printf("\n后:");
  for (int i = 0; i < num; i++) {
    printf("%.1f ", arr[i]);
  }
  printf("\n");
}
void test_struct() {
  Stu stu[] = {{"zhangsan", 30, 170, 55.6},
               {"lisi", 40, 175, 60.5},
               {"wanger", 20, 168, 50.6}};
  int sz = sizeof(stu) / sizeof(stu[0]);
  PrintStu(stu, sz);
  BubbleSort(stu, sz, sizeof(stu[0]), CmpStuAge);
  PrintStu(stu, sz);
  BubbleSort(stu, sz, sizeof(stu[0]), CmpStuName);
  PrintStu(stu, sz);
}
int main() {
  test_int();
  test_float();
  test_struct();

  return 0;
}