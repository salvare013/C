#include "list.h"
#include <assert.h>
#include <crtdefs.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

List *ListCreate(size_t dataSize) {
  List *list = (List *)malloc(sizeof(List));
  if (NULL == list) {
    printf("malloc fail!\n");
    exit(-1);
  }
  void *ptr = malloc(DEFAULT_CAPACITY * dataSize);
  if (NULL == ptr) {
    printf("malloc fail!\n");
    exit(-1);
  }
  list->data = ptr;
  list->dataSize = dataSize;
  list->capacity = DEFAULT_CAPACITY;
  list->size = 0;

  return list;
}
void ListDestory(List *pList) {
  assert(pList);
  free(pList->data);
  pList->data = NULL;
  free(pList);
  pList = NULL;
}
bool CheckCapacity(List *pList, size_t insertSize) {
  assert(pList && insertSize);
  if (insertSize <= pList->capacity - pList->size) {
    return true;
  }
  if (insertSize > 1) {
    void *ptr = realloc(pList->data, (pList->capacity + insertSize) *
                                         pList->dataSize);
    if (NULL == ptr) {
      printf("realloc fail!\n");
      return false;
    }
    pList->data = ptr;
    pList->capacity = pList->capacity + insertSize;
    return true;
  } else {
    void *ptr =
        realloc(pList->data, 2 * pList->capacity * pList->dataSize);
    if (NULL == ptr) {
      printf("realloc fail!\n");
      return false;
    }
    pList->data = ptr;
    pList->capacity = 2 * pList->capacity;
    return true;
  }
}
void ListPushBack(List *pList, const void *data) {
  assert(pList && data);
  if (CheckCapacity(pList, 1)) {
    memcpy(pList->data + pList->dataSize * pList->size, data,
           pList->dataSize);
    pList->size++;
  }
}
void ListPopBack(List *pList) {
  assert(pList);
  if (pList->size) {
    pList->size--;
  }
}
void ListPrint(const List *pList, void (*pfPrint)(const void *)) {
  assert(pList);
  for (int i = 0; i < pList->size; i++) {
    pfPrint(pList->data + pList->dataSize * i);
  }
  printf("\n");
}
size_t ListSize(List *pList) {
  assert(pList);
  return pList->size;
}
size_t ListCapacity(List *pList) {
  assert(pList);
  return pList->capacity;
}
void ListPushFront(List *pList, const void *data) {
  assert(pList && data);
  if (CheckCapacity(pList, 1)) {
    for (int i = pList->size; i > 0; i--) {
      memcpy(pList->data + i * pList->dataSize,
             pList->data + (i - 1) * pList->dataSize,
             pList->dataSize);
    }
    memcpy(pList->data, data, pList->dataSize);
    pList->size++;
  }
}
void ListPopFront(List *pList) {
  assert(pList);
  if (pList->size) {
    for (int i = 0; i < pList->size; i++) {
      memcpy(pList->data + i * pList->dataSize,
             pList->data + (i + 1) * pList->dataSize,
             pList->dataSize);
    }
    pList->size--;
  }
}
void ListPosInsert(List *pList, size_t pos, const void *data) {
  assert(pList && data);
  assert(pos < pList->size);
  if (CheckCapacity(pList, 1)) {
    for (int i = pList->size; i > pos; i--) {
      memcpy(pList->data + i * pList->dataSize,
             pList->data + (i - 1) * pList->dataSize,
             pList->dataSize);
    }
    memcpy(pList->data + pos * pList->dataSize, data,
           pList->dataSize);
    pList->size++;
  }
}
void ListPosErase(List *pList, size_t pos) {
  assert(pList);
  assert(pos < pList->size);
  if (pList->size) {
    for (int i = pos; i < pList->size; i++) {
      memcpy(pList->data + i * pList->dataSize,
             pList->data + (i + 1) * pList->dataSize,
             pList->dataSize);
    }
    pList->size--;
  }
}
void ListRandomInsertIntData(List *pList,
                             size_t count,
                             size_t maxNum) {
  assert(pList);
  assert(maxNum + 1 < RAND_MAX);
  if (CheckCapacity(pList, count)) {
    int data = 0;
    for (int i = 0; i < count; i++) {
      data = rand() % (maxNum + 1);
      memcpy(pList->data + pList->dataSize * pList->size, &data,
             sizeof(int));
      pList->size++;
    }
  }
}
void ListSort(List *pList,
              int (*pfCmp)(const void *, const void *)) {
  assert(pList && pfCmp);
  if (pList->size > 1) {
    // qsort(void *Base, size_t NumOfElements, size_t SizeOfElements,
    // int (*PtFuncCompare)(const void *, const void *)
    // __attribute__((cdecl)))
    qsort(pList->data, pList->size, pList->dataSize, pfCmp);
  }
}
void ListRandomInsertDoubleData(List *pList, size_t count) {
  assert(pList);
  if (CheckCapacity(pList, count)) {
    double data = 0;
    for (int i = 0; i < count; i++) {
      data = (double)rand() / RAND_MAX;
      memcpy(pList->data + pList->dataSize * pList->size, &data,
             sizeof(double));
      pList->size++;
    }
  }
}
void ListDataModify(List *pList,
                    size_t pos,
                    void (*pfModify)(void *)) {
  assert(pList && pfModify);
  assert(pos < pList->size);
  pfModify(pList->data + pList->dataSize * pos);
}
bool ListIsEmpty(List *pList) {
  assert(pList);
  if (0 == pList->size) {
    return true;
  } else {
    return false;
  }
}
bool ListReserve(List *pList, size_t size) {
  assert(pList);
  return CheckCapacity(pList, size);
}
size_t ListResize(List *pList, size_t size) {
  assert(pList);
  if (size <= pList->size) {
    pList->size = size;
  } else {
    if (CheckCapacity(pList, size - pList->size)) {
      memset(pList->data + pList->dataSize * pList->size, 0,
             (size - pList->size) * pList->dataSize);
      pList->size = size;
    }
  }
  return pList->size;
}
void *ListDataAt(List *pList, size_t index) {
  assert(pList);
  assert(index < pList->size);
  return pList->data + pList->dataSize * index;
}
void *ListHeadData(List *pList) {
  assert(pList);
  if (pList->size) {
    return pList->data;
  } else {
    return NULL;
  }
}
void *ListTailData(List *pList) {
  assert(pList);
  if (pList->size) {
    return pList->data + pList->dataSize * (pList->size - 1);
  } else {
    return NULL;
  }
}
void ListClear(List *pList) {
  assert(pList);
  pList->size = 0;
}
size_t ListFindData(List *pList,
                    const void *findData,
                    int (*pfCmp)(const void *, const void *)) {
  assert(pList && findData && pfCmp);
  for (int i = 0; i < pList->size; i++) {
    if (0 == pfCmp(findData, pList->data + pList->dataSize * i)) {
      return i;
    }
  }
  return pList->size;
}