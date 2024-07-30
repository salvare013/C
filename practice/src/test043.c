// 统计母字符串中子串的个数

#include <assert.h>
#include <stdio.h>
#include <string.h>

int StrNStr(const char* supStr,
            const char* subStr) {
  assert(supStr && subStr);
  assert(strlen(supStr) > strlen(subStr));
  int count = 0;
  const char* sup = supStr;
  const char* sub = subStr;
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
int main(void) {
  char str1[] = "aabababaab";
  char str2[] = "ab";
  printf("count = %d\n", StrNStr(str1, str2));

  return 0;
}