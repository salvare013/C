#include <stdio.h>
#include "str.h"

#define SZ(X) sizeof((X))

int main(void) {
  char s1[] = "************";
  char s2[] = "abc";
  printf("%d\n", StrLen(s1));
  printf("%d\n", StrLen(s2));
  char *ret1, *ret2, *ret3;
  ret1 = StrCpy(s1, s2, sizeof(s1));
  printf("%s\n", ret1);
  ret2 = StrCat(s1, s2, sizeof(s1));
  printf("%s\n", ret2);
  ret3 = StrStr(s1, s2);
  printf("%s\n", ret3);
  printf("%d\n", StrNStr(s1, s2));

  return 0;
}
