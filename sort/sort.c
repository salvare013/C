#include "sort.h"
#include <assert.h>
#include <crtdefs.h>
#include <stdbool.h>
#include <stdint.h>

// qsort(void *Base, size_t NumOfElements, size_t SizeOfElements,
//  int (*PtFuncCompare)(const void *, const void *)
// __attribute__((cdecl)))

void SortSwap(void *e1, void *e2, const size_t width) {
  assert(e1 && e2 && width);
  for (size_t i = 0; i < width; i++) {
    char tmp;
    tmp = DRFPTR(char, C_PTR(e1) + i);
    DRFPTR(char, C_PTR(e1) + i) = DRFPTR(char, C_PTR(e2) + i);
    DRFPTR(char, C_PTR(e2) + i) = tmp;
  }
}
void BubbleSort(void *base,
                size_t numOfElements,
                size_t sizeOfElements,
                int (*pfCmp)(const void *, const void *)) {
  assert(base && numOfElements && sizeOfElements && pfCmp);
  for (int i = 0; i < numOfElements - 1; i++) {
    bool flag = true;
    for (int j = 0; j < numOfElements - 1 - i; j++) {
      if (pfCmp(C_PTR(base) + j * sizeOfElements,
                C_PTR(base) + (j + 1) * sizeOfElements) > 0) {
        SortSwap(C_PTR(base) + j * sizeOfElements,
                 C_PTR(base) + (j + 1) * sizeOfElements,
                 sizeOfElements);
        flag = false;
      }
    }
    if (flag) {
      break;
    }
  }
}
int SortCmpInt(const void *e1, const void *e2) {
  return DRFPTR(int, e1) - DRFPTR(int, e2);
}
int SortCmpFloat(const void *e1, const void *e2) {
  return SortCmpNum(DRFPTR(float, e1), DRFPTR(float, e2));
}
int SortCmpDouble(const void *e1, const void *e2) {
  return SortCmpNum(DRFPTR(double, e1), DRFPTR(double, e2));
}
void *GetPivot(void *a,
               void *b,
               void *c,
               int (*pfCmp)(const void *, const void *)) {
  assert(a && b && c && pfCmp);
  if (pfCmp(a, b) * pfCmp(c, a) >= 0) {
    return a;
  } else if (pfCmp(b, a) * pfCmp(c, b) >= 0) {
    return b;
  } else {
    return c;
  }
}
static size_t Partition(void *base,
                        size_t num,
                        size_t size,
                        int (*pfCmp)(const void *, const void *)) {
  assert(base && num && size && pfCmp);
  char *end = C_PTR(base) + (num - 1) * size;
  SortSwap(
      end,
      GetPivot(base, end, C_PTR(base) + (num / 2) * size, pfCmp),
      size);
  char *pivot = C_PTR(base);
  for (int i = 0; i < num - 1; i++) {
    char *cur = C_PTR(base) + i * size;
    if (pfCmp(cur, end) <= 0) {
      SortSwap(cur, pivot, size);
      pivot += size;
    }
  }
  SortSwap(pivot, end, size);
  return (pivot - C_PTR(base)) / size;
}
void QuickSort(void *base,
               size_t numOfElements,
               size_t sizeOfElements,
               int (*pfCmp)(const void *, const void *)) {
  assert(base && numOfElements && sizeOfElements && pfCmp);
  if (numOfElements < 2) {
    return;
  }
  if (numOfElements < 10) {
    BubbleSort(base, numOfElements, sizeOfElements, pfCmp);
  } else {
    size_t pivot =
        Partition(base, numOfElements, sizeOfElements, pfCmp);
    QuickSort(base, pivot, sizeOfElements, pfCmp);
    QuickSort(C_PTR(base) + (pivot + 1) * sizeOfElements,
              numOfElements - pivot - 1, sizeOfElements, pfCmp);
  }
}