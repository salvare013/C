#pragma once

#include <crtdefs.h>
#include <stdbool.h>
#include <stdio.h>  // IWYU pragma: export

typedef struct {
  void *data;
  size_t dataSize;
  size_t size;
  size_t capacity;
} List;
#define DEFAULT_CAPACITY 4

List *ListCreate(size_t dataSize);
#define mListCreate(TYPE) ListCreate(sizeof(TYPE))
void ListDestory(List *pList);
bool CheckCapacity(List *pList, size_t insertSize);
void ListPushBack(List *pList, const void *data);
void ListPopBack(List *pList);
void ListPrint(const List *pList, void (*pfPrint)(const void *));
size_t ListSize(List *pList);
size_t ListCapacity(List *pList);
void ListPushFront(List *pList, const void *data);
void ListPopFront(List *pList);
void ListPosInsert(List *pList, size_t pos, const void *data);
void ListPosErase(List *pList, size_t pos);
void ListRandomInsertIntData(List *pList,
                             size_t count,
                             size_t maxNum);
void ListSort(List *pList, int (*pfCmp)(const void *, const void *));
void ListRandomInsertDoubleData(List *pList, size_t count);