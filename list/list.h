#pragma once
#include <assert.h>
#include <crtdefs.h>
#include <stdbool.h>
#include <stdio.h>   // IWYU pragma: export
#include <stdlib.h>  // IWYU pragma: export
#include <string.h>  // IWYU pragma: export
#include <time.h>    // IWYU pragma: export

typedef struct {
  void *data;
  size_t dataSize;
  size_t size;
  size_t capacity;
} List;

#define DEFAULT_CAPACITY 4
#define DRFPTR(type, ptr) (*(type *)ptr)

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
void ListPosInsert(List *pList, const size_t pos, const void *data);
void ListPosErase(List *pList, const size_t pos);
void ListRandomInsertIntData(List *pList,
                             size_t count,
                             size_t maxNum);
void ListSort(List *pList, int (*pfCmp)(const void *, const void *));
void ListRandomInsertDoubleData(List *pList, size_t count);
void ListDataModify(List *pList,
                    size_t pos,
                    void (*pfModify)(void *));
bool ListIsEmpty(List *pList);
bool ListReserve(List *pList, size_t size);
size_t ListResize(List *pList, size_t size);
const void *ListDataAt(List *pList, const size_t index);
const void *ListHeadData(List *pList);
const void *ListTailData(List *pList);
void ListClear(List *pList);
size_t ListFindData(List *pList,
                    const void *findData,
                    int (*pfCmp)(const void *, const void *));
void ListIndexAccess(const List *pList,
                     const size_t index,
                     void (*pfPrint)(const void *));