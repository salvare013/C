#include <stdio.h>
#include "str.h"

#define SZ(X) sizeof((X))

int main(void) {
  char s1[] = "adgahgabcaabcaaaaabcyyhjabchcabc";
  char s2[33] = "abc";
  // StrCat(arr1, arr2, sizeof(arr1));
  StrCpy(s2, s1, SZ(s2));
  // StrNCat(arr1, arr2, 6, SZ(arr1));
  // int ret = StrNCmp(s1, s2, 4);
  // if (ret > 0) {
  //   printf("s1>s2");
  // } else if (ret < 0) {
  //   printf("s1<s2");
  // } else {
  //   printf("s1===s2");
  // }
  // StrNCpy(s1, s2, 5, SZ(s1));
  // printf("%s", StrStr(s1, s2));
  // printf("%d", StrNStr(s1, s2));
  printf("%s", s1);
  printf("%d", StrLen(s1));

  return 0;
}
