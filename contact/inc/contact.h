#pragma once

// 包含库函数
#include <errno.h>   // IWYU pragma: export
#include <stdio.h>   // IWYU pragma: export
#include <stdlib.h>  // IWYU pragma: export
#include <string.h>  // IWYU pragma: export

// 宏
#define MALLOC(TYPE, SIZE) ((TYPE *)malloc(SIZE * sizeof(TYPE)))
#define REALLOC(TYPE, PTR, NEW_SIZE) \
  ((TYPE *)realloc(PTR, (NEW_SIZE) * sizeof(TYPE)))

// 定义常量
#define DEFAULT_SZ 2
#define MAX_NAME 20
#define MAX_SEX 13
#define MAX_TELE 12
#define MAX_ADDR 50
#define MAX_QQ 11

// 定义类型
enum Option { EXIT, ADD, DEL, SEARCH, MODIFY, SHOW, SORT, SAVE };
enum ModifyOption { EXIT_M, NAME, AGE, SEX, TELE, QQ, ADDR };
typedef struct Information {
  char name[MAX_NAME];
  int age;
  char sex[MAX_SEX];
  char tele[MAX_TELE];
  char qq[MAX_QQ];
  char addr[MAX_ADDR];
} Information;
typedef struct Contact {
  struct Information *data;
  int size;
  int capacity;
} Contact;

// 声明函数
void InitContact(struct Contact *ps);
void AddCon(struct Contact *ps);
void ShowCon(const struct Contact *ps);
void DelCon(struct Contact *ps);
void SearchCon(const struct Contact *ps);
void ModifyCon(struct Contact *ps);
void SortCon(struct Contact *ps);
void DestroyCon(Contact *ps);
void SaveCon(Contact *ps);
int CheckCapacity(Contact *ps);