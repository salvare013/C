// 模拟实现strstr

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char* StrStr(const char* supStr,
                   const char* subStr) {
  assert(supStr && subStr);
  assert(strlen(supStr) > strlen(subStr));
  const char* sup = supStr;
  const char* sub = subStr;
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
int main(void) {
  char str1[] = "aadaaddabcabca";
  char str2[] = "abcabc";
  const char* ret = StrStr(str1, str2);
  printf("%s", ret);

  return 0;
}