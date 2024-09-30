#include "contact.h"

void Menu() {
  printf("****************************\n");
  printf("****  1.add   2.del     ****\n");
  printf("****  3.find  4.modify  ****\n");
  printf("****  5.show  6.sort    ****\n");
  printf("****  7.save  0.exit    ****\n");
  printf("****************************\n");
}
void ModifyOptionMenu() {
  printf("****************************\n");
  printf("****  1.name  2.age     ****\n");
  printf("****  3.sex   4.tele    ****\n");
  printf("****  5.qq    6.addr    ****\n");
  printf("****     0.exit         ****\n");
  printf("****************************\n");
}
void PrintContact(const void *data) {
  printf(
      "姓名:%-10s\t年龄:%-3d\t性别:%-8s\t电话:%-12s\tQQ:%-11s\t住址:"
      "%-10s\n",
      DRFPTR(Contact, data).name, DRFPTR(Contact, data).age,
      DRFPTR(Contact, data).sex, DRFPTR(Contact, data).tele,
      DRFPTR(Contact, data).qq, DRFPTR(Contact, data).addr);
}
const void *SendData() {
  static Contact data;
  printf("输入姓名>>>");
  scanf("%s", data.name);
  printf("输入年龄>>>");
  scanf("%d", &data.age);
  printf("输入性别>>>");
  scanf("%s", data.sex);
  printf("输入电话>>>");
  scanf("%s", data.tele);
  printf("输入QQ>>>");
  scanf("%s", data.qq);
  printf("输入住址>>>");
  scanf("%s", data.addr);
  return &data;
}
void ContactFind(List *pC) {
  Contact *data = ListFindData(pC, SendFindData(), CmpName);
  if (NULL == data) {
    printf("找不到该联系人!\n");
  } else {
    ListPrintData(data, PrintContact);
  }
}
void ContactModify(List *pC) {
  Contact *data = ListFindData(pC, SendFindData(), CmpName);
  if (NULL == data) {
    printf("找不到该联系人!\n");
  } else {
    int option;
    do {
      ModifyOptionMenu();
      printf("请选择修改项>>>");
      scanf("%d", &option);
      switch (option) {
        case EXIT_M:
          printf("退出修改!\n");
          break;
        case NAME:
          printf("重新输入姓名>>>");
          scanf("%s", data->name);
          break;
        case AGE:
          printf("重新输入年龄>>>");
          scanf("%d", &data->age);
          break;
        case SEX:
          printf("重新输入性别>>>");
          scanf("%s", data->sex);
          break;
        case TELE:
          printf("重新输入电话>>>");
          scanf("%s", data->tele);
          break;
        case QQ:
          printf("重新输入QQ>>>");
          scanf("%s", data->qq);
          break;
        case ADDR:
          printf("重新输入住址>>>");
          scanf("%s", data->addr);
          break;
        default:
          printf("请重新选择!\n");
          break;
      }
    } while (option);
    ListPrintData(data, PrintContact);
  }
}

int CmpName(const void *e1, const void *e2) {
  return strcmp(DRFPTR(Contact, e1).name, DRFPTR(Contact, e2).name);
}
int CmpTele(const void *e1, const void *e2) {
  return strcmp(DRFPTR(Contact, e1).tele, DRFPTR(Contact, e2).tele);
}
int CmpQQ(const void *e1, const void *e2) {
  return strcmp(DRFPTR(Contact, e1).qq, DRFPTR(Contact, e2).qq);
}
const void *SendFindData() {
  static Contact data;
  printf("输入姓名>>>");
  scanf("%s", data.name);
  //   printf("输入电话>>>");
  //   scanf("%s", data.tele);
  //   printf("输入QQ>>>");
  //   scanf("%s", data.qq);
  return &data;
}
void ContactDel(List *pC) {
  size_t index = ListFindDataAt(pC, SendFindData(), CmpName);
  if (ListSize(pC) == index) {
    printf("没有该联系人!\n");
  } else {
    ListPosErase(pC, index);
  }
}
void ContactSave(List *pC, const char *fileName) {
  FILE *pfWrite = fopen(fileName, "wb");
  if (pfWrite == NULL) {
    printf("%s\n", strerror(errno));
    return;
  }
  for (size_t i = 0; i < pC->size; i++) {
    fwrite(ListDataAt(pC, i), sizeof(Contact), 1, pfWrite);
  }
  fclose(pfWrite);
}
void ContactLoad(List *pC, const char *fileName) {
  Contact buf;
  FILE *pfRead = fopen(fileName, "rb");
  if (pfRead == NULL) {
    printf("%s\n", strerror(errno));
    return;
  }
  while (fread(&buf, sizeof(Contact), 1, pfRead)) {
    ListPushBack(pC, &buf);
  }
  fclose(pfRead);
}