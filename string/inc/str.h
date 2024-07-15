#pragma once
#include <assert.h>
#include <stdio.h>

int StrLen(const char *str);
char *StrCat(char *dest, const char *src, size_t destSize);
int StrCmp(const char *str1, const char *str2);
char *StrCpy(char *dest, const char *src, size_t destSize);
char *StrNCat(char *front,
              const char *back,
              unsigned int count,
              size_t frontSize);
int StrNCmp(const char *str1, const char *str2, unsigned int count);
char *StrNCpy(char *dest,
              const char *src,
              unsigned int count,
              size_t destSize);
const char *StrStr(const char *supStr, const char *subStr);
int StrNStr(const char *supStr, const char *subStr);