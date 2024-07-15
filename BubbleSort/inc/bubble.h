#pragma once
// 库函数
#include <stdio.h>
#include <string.h>

// 宏

#define CMP_VOID_NUM(X, Y, TYPE) \
  (*((TYPE*)(X)) > *((TYPE*)(Y)) ? 1 : (*((TYPE*)(X)) < *((TYPE*)(Y)) ? -1 : 0))
// 类

typedef struct Student {
  char name[20];
  int age;
  int height;
  float weight;
} Stu;
// 声明
void PrintStu(Stu stu[], int size);
int CmpStuAge(const void* e1, const void* e2);
int CmpStuName(const void* e1, const void* e2);
int CmpInt(const void* e1, const void* e2);
int CmpFloat(const void* e1, const void* e2);
void Swap(char* buf1, char* buf2, int width);
// 可以比较任意数据类型的冒泡排序
void BubbleSort(void* start,
                int count,
                int width,
                int (*pCmpF)(const void*, const void*));
