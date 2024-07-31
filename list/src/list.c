#include "list.h"

void InitList(List *plist) {
  assert(plist);
  listData_t *ptr = malloc(DEFAULT_CAPACITY * sizeof(listData_t));
  if (ptr == NULL) {
    printf("malloc fail!\n");
    exit(-1);
  }
  plist->data = ptr;
  plist->capacity = DEFAULT_CAPACITY;
  plist->size = 0;
}
void DestoryList(List *plist) {
  assert(plist);
  free(plist->data);
  plist->data = NULL;
  plist->capacity = plist->size = 0;
}
int CheckCapacity(List *plist, size_t insertSize) {
  assert(plist);
  if (insertSize <= plist->capacity - plist->size) {
    return 1;
  }
  if (insertSize > 1) {
    listData_t *ptr = (listData_t *)realloc(
        plist->data,
        (insertSize + plist->capacity) * sizeof(listData_t));
    if (ptr == NULL) {
      printf("realloc fail!");
      return 0;
    }
    plist->data = ptr;
    plist->capacity = insertSize + plist->capacity;
    return 1;
  }
  listData_t *ptr = (listData_t *)realloc(
      plist->data, 2 * plist->capacity * sizeof(listData_t));
  if (ptr == NULL) {
    printf("realloc fail!");
    return 0;
  }
  plist->data = ptr;
  plist->capacity = 2 * plist->capacity;
  return 1;
}
void PushBack(List *plist, listData_t data) {
  assert(plist);
  if (1 == CheckCapacity(plist, 1)) {
    plist->data[plist->size] = data;
    plist->size++;
  }
}
void PopBack(List *plist) {
  assert(plist);
  if (plist->size > 0) {
    plist->size--;
  }
}
void PushFront(List *plist, listData_t data) {
  assert(plist);
  if (1 == CheckCapacity(plist, 1)) {
    for (int i = plist->size - 1; i >= 0; i--) {
      plist->data[i + 1] = plist->data[i];
    }
    plist->data[0] = data;
    plist->size++;
  }
}
void PopFront(List *plist) {
  assert(plist);
  for (int i = 0; i < plist->size; i++) {
    plist->data[i] = plist->data[i + 1];
  }
  plist->size--;
}
void PrintList(const List *plist) {
  assert(plist);
  if (plist->size > 0) {
    for (int i = 0; i < plist->size; i++) {
      printf("%d ", plist->data[i]);
    }
    printf("\n");
  } else {
    printf("无数据!\n");
  }
}
void SortList(List *plist) {
  for (int i = 0; i < plist->size - 1; i++) {
    int flag = 1;
    for (int j = 0; j < plist->size - 1 - i; j++) {
      if (plist->data[j] > plist->data[j + 1]) {
        listData_t tmp = plist->data[j];
        plist->data[j] = plist->data[j + 1];
        plist->data[j + 1] = tmp;
        flag = 0;
      }
    }
    if (1 == flag) {
      break;
    }
  }
}
void RandomInsert(List *plist, size_t count, size_t maxNum) {
  assert(plist);
  srand((unsigned int)time(NULL));
  if (1 == CheckCapacity(plist, count)) {
    for (int i = 0; i < count; i++) {
      plist->data[i] = rand() % (maxNum + 1);
      plist->size++;
    }
  }
}
int FindList(const List *plist, listData_t target) {
  assert(plist);
  for (int i = 0; i < plist->size; i++) {
    if (target == plist->data[i]) {
      return i;
    }
  }
  return -1;
}
void PosInsert(List *plist, int pos, listData_t data) {
  assert(plist);
  assert(pos >= 0 && pos < plist->size);
  if (1 == CheckCapacity(plist, 1)) {
    for (int i = plist->size - 1; i >= pos; i--) {
      plist->data[i + 1] = plist->data[i];
    }
    plist->data[pos] = data;
    plist->size++;
  }
}
void PosErase(List *plist, int pos) {
  assert(plist);
  assert(pos >= 0 && pos < plist->size);
  for (int i = pos; i < plist->size; i++) {
    plist->data[i] = plist->data[i + 1];
  }
  plist->size--;
}
size_t ListSize(List *plist) {
  assert(plist);
  return plist->size;
}
size_t ListCapacity(List *plist) {
  assert(plist);
  return plist->capacity;
}