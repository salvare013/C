#include "str.h"
int StrLen(const char *str) {
  assert(str);
  int len = 0;
  while (*str++) {
    len++;
  }
  return len;
}
char *StrCat(char *front,
             const char *back,
             size_t frontSize) {
  assert(front && back);
  assert(frontSize >
         (StrLen(front) + StrLen(back)));
  char *start = front;
  while (*front) {
    front++;
  }
  while ((*front++ = *back++)) {
    ;
  }
  return start;
}
int StrCmp(const char *_str1,
           const char *_str2) {
  assert(_str1 && _str2);
  while (*_str1 == *_str2) {
    if (*_str1 == '\0') {
      return 0;
    }
    _str1++;
    _str2++;
  }
  return (*_str1 - *_str2);
}
char *StrCpy(char *dest,
             const char *src,
             size_t destSize) {
  assert(dest && src);
  assert(destSize > StrLen(src));
  char *start = dest;
  while ((*dest++ = *src++)) {
    ;
  }
  return start;
}
char *StrNCat(char *front,
              const char *back,
              unsigned int count,
              size_t frontSize) {
  assert(front && back);
  assert(frontSize > StrLen(front) + count);
  char *start = front;
  while (*front) {
    front++;
  }
  while (count--) {
    *front = *back;
    if ('\0' == *front) {
      return start;
    }
    front++;
    back++;
  }
  *front = '\0';
  return start;
}
int StrNCmp(const char *_str1,
            const char *_str2,
            unsigned int count) {
  assert(_str1 && _str2);
  while (--count > 0) {
    if (*_str1 == *_str2) {
      if (*_str1 == '\0') {
        return 0;
      }
      _str1++;
      _str2++;
    }
  }
  return (*_str1 - *_str2);
}
char *StrNCpy(char *dest,
              const char *src,
              unsigned int count,
              size_t destSize) {
  assert(dest && src);
  assert(destSize > count);
  char *start = dest;
  while (count && (*dest++ = *src++)) {
    count--;
  }
  while (count--) {
    *dest++ = '\0';
  }
  return start;
}
const char *StrStr(const char *supStr,
                   const char *subStr) {
  assert(supStr && subStr);
  assert(StrLen(supStr) > StrLen(subStr));
  const char *sup = supStr;
  const char *sub = subStr;
  while (*sup) {
    while (*supStr == *subStr && *subStr) {
      supStr++;
      subStr++;
    }
    if (*subStr == '\0') {
      return sup;
    } else {
      supStr = ++sup;
      subStr = sub;
    }
  }
  return NULL;
}
int StrNStr(const char *supStr,
            const char *subStr) {
  assert(supStr && subStr);
  assert(StrLen(supStr) > StrLen(subStr));
  int count = 0;
  const char *sup = supStr;
  const char *sub = subStr;
  while (*sup) {
    while (*supStr == *subStr && *subStr) {
      supStr++;
      subStr++;
    }
    if (*subStr == '\0') {
      count++;
      sup = supStr;
    } else {
      supStr = ++sup;
    }
    subStr = sub;
  }
  return count;
}