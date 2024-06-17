// 可以比较任意数据类型的冒泡排序

#include <stdio.h>

int CmpInt(const void *e1, const void *e2) {
  return *((int *)e1) - *((int *)e2);
}
int CmpFloat(const void *e1, const void *e2) {
  if (*((float *)e1) > *((float *)e2)) {
    return 1;
  } else if (*((float *)e1) < *((float *)e2)) {
    return -1;
  } else {
    return 0;
  }
}
void Swap(void *p1, void *p2, int size) {
  for (int i = 0; i < size; i++) {
    char tmp = *((char *)p1 + i);
    *((char *)p1 + i) = *((char *)p2 + i);
    *((char *)p2 + i) = tmp;
  }
}
void BubbleSort(void *pArr, int num, int size,
                int (*pCmpF)(const void *, const void *)) {
  int flag = 1;
  for (int i = 0; i < num - 1; i++) {
    for (int j = 0; j < num - 1 - i; j++) {
      if (pCmpF((char *)pArr + j * size, (char *)pArr + (j + 1) * size) > 0) {
        Swap((char *)pArr + j * size, (char *)pArr + (j + 1) * size, size);
        flag = 0;
      }
    }
    if (flag == 1) {
      break;
    }
  }
}
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
}
int main() {
  test_int();
  test_float();

  return 0;
}