#pragma once

#include <stdbool.h>
#include <stdio.h>   // IWYU pragma: export
#include <stdlib.h>  // IWYU pragma: export

#ifndef __C_PTR__
#define __C_PTR__
#define C_PTR(ptr) ((char *)(ptr))
#endif

#ifndef __DRFPTR__
#define __DRFPTR__
#define DRFPTR(type, ptr) (*(type *)(ptr))
#endif

#ifndef __SortCmpNum__
#define __SortCmpNum__
#define SortCmpNum(e1, e2) ((e1) > (e2) ? 1 : ((e1) < (e2) ? -1 : 0))
#endif

void SortSwap(void *e1, void *e2, const size_t width);
void BubbleSort(void *base,
                size_t numOfElements,
                size_t sizeOfElements,
                int (*pfCmp)(const void *, const void *));
int SortCmpInt(const void *e1, const void *e2);
int SortCmpFloat(const void *e1, const void *e2);
int SortCmpDouble(const void *e1, const void *e2);
void QuickSort(void *base,
               size_t numOfElements,
               size_t sizeOfElements,
               int (*pfCmp)(const void *, const void *));