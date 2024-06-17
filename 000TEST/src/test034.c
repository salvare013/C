// 题目：有一个已经排好序的数组。
// 现输入一个数，要求按原来的规律将它插入数组中。

#include <stdio.h>

void OrderInsert(int arr[], int size, int num) {
  if (arr[0] < arr[size - 2]) {
    // 由小到大
    if (num >= arr[size - 2]) {
      arr[size - 1] = num;
      return;
    }
    for (int i = 0; i < size - 1; i++) {
      if (arr[i] > num) {
        // 往后挪
        int end = size - 2;
        while (end >= i) {
          arr[end + 1] = arr[end];
          end--;
        }
        arr[i] = num;
        break;
      }
    }
  } else {
    // 由大到小
    if (num <= arr[size - 2]) {
      arr[size - 1] = num;
      return;
    }
    for (int i = 0; i < size - 1; i++) {
      if (arr[i] < num) {
        // 往后挪
        int end = size - 2;
        while (end >= i) {
          arr[end + 1] = arr[end];
          end--;
        }
        arr[i] = num;
        break;
      }
    }
  }
}
int main() {
  int arr1[11] = {99, 88, 77, 66, 55, 44, 33, 22, 11, 10};
  int arr2[11] = {10, 11, 22, 33, 44, 55, 66, 77, 88, 99};
  int num;
  printf("输入:>");
  scanf("%d", &num);
  OrderInsert(arr1, 11, num);
  OrderInsert(arr2, 11, num);
  for (int i = 0; i < 11; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  for (int i = 0; i < 11; i++) {
    printf("%d ", arr2[i]);
  }

  return 0;
}