#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOAT_LIST_DATA_TYPE

#ifndef INT_LIST_DATA_TYPE
#define FLOAT_LIST_DATA_TYPE
#define listData_t float
#endif

#ifndef FLOAT_LIST_DATA_TYPE
#define INT_LIST_DATA_TYPE
#define listData_t int
#endif

#define DEFAULT_CAPACITY 4

typedef struct {
  listData_t *data;
  size_t size;
  size_t capacity;
} List;

#ifdef FLOAT_LIST_DATA_TYPE
void RandomInsert(List *plist, size_t count);
#endif
#ifdef INT_LIST_DATA_TYPE
void RandomInsert(List *plist, size_t count, size_t maxNum);
#endif

void InitList(List *plist);
void DestoryList(List *plist);
void PrintList(const List *plist);
// list容量充足或者扩容成功返回1,满了并且扩容失败返回0
int CheckCapacity(List *plist, size_t insertSize);
void PushBack(List *plist, listData_t data);
void PopBack(List *plist);
void PushFront(List *plist, listData_t data);
void PopFront(List *plist);
void SortList(List *plist);
// 找到数据返回该数据的索引(下标),找不到返回-1
int FindList(const List *plist, listData_t target);
void PosInsert(List *plist, int pos, listData_t data);
void PosErase(List *plist, int pos);
size_t ListSize(List *plist);
size_t ListCapacity(List *plist);
