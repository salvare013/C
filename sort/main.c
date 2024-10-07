#include <crtdefs.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"
#define N 999

void PrintArr(void *base,
              const size_t numOfElements,
              size_t sizeOfElements,
              void(pfPrint)(const void *)) {
  for (size_t i = 0; i < numOfElements; i++) {
    pfPrint(base + i * sizeOfElements);
  }
  printf("\n");
}
void PrintInt(const void *data) {
  printf("%d ", DRFPTR(int, data));
}
void PrintFloat(const void *data) {
  printf("%f ", DRFPTR(float, data));
}
void test_float() {
  float arr1[N];
  for (int i = 0; i < N; i++) {
    arr1[i] = (float)rand() / RAND_MAX;
  }
  // PrintArr(arr1, N, sizeof(int), PrintFloat);
  clock_t start, end;
  double sortTime;
  start = clock();
  // BubbleSort(arr1, N, sizeof(float), SortCmpFloat);
  // qsort(arr1, N, sizeof(float), SortCmpFloat);
  QuickSort(arr1, N, sizeof(float), SortCmpFloat);
  end = clock();
  sortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("排序时间%f 秒\n", sortTime);
  // PrintArr(arr1, N, sizeof(int), PrintFloat);
}
void test_int() {
  int arr1[N];
  for (int i = 0; i < N; i++) {
    arr1[i] = rand();
  }
  PrintArr(arr1, N, sizeof(int), PrintInt);
  clock_t start, end;
  double sortTime;
  start = clock();
  // BubbleSort(arr1, N, sizeof(int), SortCmpInt);
  // qsort(arr1, N, sizeof(int), SortCmpInt);
  QuickSort(arr1, N, sizeof(int), SortCmpInt);
  end = clock();
  sortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("排序时间%f 秒\n", sortTime);
  PrintArr(arr1, N, sizeof(int), PrintInt);
}
int main(void) {
  srand(time(NULL));

  // test_int();
  test_float();

  return 0;
}