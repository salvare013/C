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
void PrintList(const List *plist);
// // list容量充足或者扩容成功返回1,满了并且扩容失败返回0
int CheckCapacity(List *plist, size_t insertSize);
void RandomInsertIntData(List *plist, size_t count, size_t maxNum);
void TraverseIntData(const List *plist);
void RandomInsertDoubleData(List *plist, size_t count);
void TraverseDoubleData(const List *plist);
void RandomInsertCharData(List *plist, size_t count);
void TraverseCharData(const List *plist);
void PushBack(List *plist, T data, const char *dataType);
#define mPushBack(pLIST, DATA)                    \
  _Generic(DATA,                                  \
      char: PushBack(pLIST, (T)DATA, "char"),     \
      int: PushBack(pLIST, (T)DATA, "int"),       \
      double: PushBack(pLIST, (T)DATA, "double"), \
      size_t: PushBack(pLIST, (T)DATA, "size_t"), \
      char *: PushBack(pLIST, (T)DATA, "char*"),  \
      default: PushBack(pLIST, (T)DATA, "int"))
void PopBack(List *plist);
void PushFront(List *plist, T data, const char *dataType);
#define mPushFront(pLIST, DATA)                    \
  _Generic(DATA,                                   \
      char: PushFront(pLIST, (T)DATA, "char"),     \
      int: PushFront(pLIST, (T)DATA, "int"),       \
      double: PushFront(pLIST, (T)DATA, "double"), \
      size_t: PushFront(pLIST, (T)DATA, "size_t"), \
      char *: PushFront(pLIST, (T)DATA, "char*"),  \
      default: PushFront(pLIST, (T)DATA, "int"))
void PopFront(List *plist);
// 找到数据返回该数据的索引(下标),找不到返回-1
int FindListData(const List *plist, T target, const char *dataType);
#define mFindListData(pLIST, DATA)                    \
  _Generic(DATA,                                      \
      char: FindListData(pLIST, (T)DATA, "char"),     \
      int: FindListData(pLIST, (T)DATA, "int"),       \
      double: FindListData(pLIST, (T)DATA, "double"), \
      size_t: FindListData(pLIST, (T)DATA, "size_t"), \
      char *: FindListData(pLIST, (T)DATA, "char*"),  \
      default: FindListData(pLIST, (T)DATA, "int"))
void PosInsert(List *plist, int pos, T data, const char *dataType);
#define mPosInsert(pLIST, POS, DATA)                    \
  _Generic(DATA,                                        \
      char: PosInsert(pLIST, POS, (T)DATA, "char"),     \
      int: PosInsert(pLIST, POS, (T)DATA, "int"),       \
      double: PosInsert(pLIST, POS, (T)DATA, "double"), \
      size_t: PosInsert(pLIST, POS, (T)DATA, "size_t"), \
      char *: PosInsert(pLIST, POS, (T)DATA, "char*"),  \
      default: PosInsert(pLIST, POS, (T)DATA, "int"))
void PosErase(List *plist, int pos);
size_t ListSize(List *plist);
size_t ListCapacity(List *plist);

// void SortList(List *plist);
