#include <assert.h>  // IWYU pragma: export
#include <stdio.h>   // IWYU pragma: export
#include <stdlib.h>  // IWYU pragma: export
#include <string.h>  // IWYU pragma: export
#include <time.h>    // IWYU pragma: export

typedef union {
  char c;
  int i;
  double d;
  size_t sz;
  char *pc;
} T;
typedef struct {
  T data;
  const char *type;
} Data;
typedef struct {
  Data *data;
  size_t size;
  size_t capacity;
} List;

#define DEFAULT_CAPACITY 8

void InitList(List *plist);
void DestoryList(List *plist);
void PushBack(List *plist, T data, const char *dataType);
void PrintList(const List *plist);
int CheckCapacity(List *plist, size_t insertSize);
void RandomInsertSize_tData(List *plist,
                            size_t count,
                            size_t maxNum);
void TraverseSize_tData(const List *plist);
void RandomInsertDoubleData(List *plist, size_t count);
void TraverseDoubleData(const List *plist);
void RandomInsertCharData(List *plist, size_t count);
void TraverseCharData(const List *plist);

#define mPushBack(pLIST, DATA)                    \
  _Generic(DATA,                                  \
      char: PushBack(pLIST, (T)DATA, "char"),     \
      int: PushBack(pLIST, (T)DATA, "int"),       \
      double: PushBack(pLIST, (T)DATA, "double"), \
      size_t: PushBack(pLIST, (T)DATA, "size_t"), \
      char *: PushBack(pLIST, (T)DATA, "char*"),  \
      default: PushBack(pLIST, (T)DATA, "int"))

// // list容量充足或者扩容成功返回1,满了并且扩容失败返回0
// int CheckCapacity(List *plist, size_t insertSize);
// void PushBack(List *plist, listData_t data);
// void PopBack(List *plist);
// void PushFront(List *plist, listData_t data);
// void PopFront(List *plist);
// void SortList(List *plist);
// // 找到数据返回该数据的索引(下标),找不到返回-1
// int FindList(const List *plist, listData_t target);
// void PosInsert(List *plist, int pos, listData_t data);
// void PosErase(List *plist, int pos);
// size_t ListSize(List *plist);
// size_t ListCapacity(List *plist);
