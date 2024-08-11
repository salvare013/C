#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
  char c;
  int i;
  double d;
  size_t sz;
  char *pc;
} T;
typedef struct SLNode {
  T data;
  const char *dataType;
  struct SLNode *next;
} SLNode;

SLNode *GetSLNode(T data, const char *dataType);
void TraverseSL(const SLNode *pHead);

#define INIT_SL_NODE(DATA) \
  _Generic(DATA,\
  char:GetSLNode((T)DATA, "char"),\
  int:GetSLNode((T)DATA, "int"),\
  double:GetSLNode((T)DATA, "double"),\
  size_t:GetSLNode((T)DATA, "size_t"),\
  char*:GetSLNode((T)DATA, "char*"),\
  default:GetSLNode((T)DATA, "int"))

void LinkSLNode(SLNode *front, SLNode *back);
void DestorySL(SLNode **ppHead);
void RemoveSLNode(SLNode *dest);