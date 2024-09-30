#pragma once
#include "list.h"  // IWYU pragma: export

#define MAX_NAME 20
#define MAX_SEX 13
#define MAX_TELE 12
#define MAX_ADDR 50
#define MAX_QQ 11

typedef struct {
  char name[MAX_NAME];
  int age;
  char sex[MAX_SEX];
  char tele[MAX_TELE];
  char qq[MAX_QQ];
  char addr[MAX_ADDR];
} Contact;

enum Option { EXIT, ADD, DEL, FIND, MODIFY, SHOW, SORT, SAVE };
enum ModifyOption { EXIT_M, NAME, AGE, SEX, TELE, QQ, ADDR };

void Menu();
void ModifyOptionMenu();
const void *SendData();
void PrintContact(const void *data);
int CmpName(const void *e1, const void *e2);
int CmpTele(const void *e1, const void *e2);
int CmpQQ(const void *e1, const void *e2);
const void *SendFindData();
void ContactFind(List *pC);
void ContactDel(List *pC);
void ContactModify(List *pC);
void ContactSave(List *pC, const char *fileName);
void ContactLoad(List *pC, const char *fileName);