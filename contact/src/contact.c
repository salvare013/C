#include "contact.h"

static void LoadCon(Contact *ps) {
  Information tmp = {0};
  FILE *pfRead = fopen("contact.txt", "rb");
  if (pfRead == NULL) {
    printf("LoadCon::%s\n", strerror(errno));
    return;
  }
  while (fread(&tmp, sizeof(Information), 1, pfRead)) {
    if (1 == CheckCapacity(ps)) {
      ps->data[ps->size] = tmp;
      ps->size++;
    }
  }
  fclose(pfRead);
  pfRead = NULL;
  printf("加载成功!\n");
}
void InitContact(struct Contact *ps) {
  // ps->data = (Information *)malloc(DEFAULT_SZ
  // * sizeof(Information));
  ps->data = MALLOC(Information, DEFAULT_SZ);
  if (ps->data == NULL) {
    exit(-1);
  }
  ps->size = 0;
  ps->capacity = DEFAULT_SZ;
  LoadCon(ps);
}
int CheckCapacity(Contact *ps) {
  if (ps->size == ps->capacity) {
    // Information *ptr = (Information
    // *)realloc(ps->data, (ps->capacity + 2) *
    // sizeof(Information));
    Information *ptr = REALLOC(Information, ps->data, 2 * ps->capacity);
    if (ptr == NULL) {
      printf("扩容失败!\n");
      return 0;
    }
    ps->data = ptr;
    ps->capacity += 2;
    return 1;
  }
  return 1;
}
void AddCon(struct Contact *ps) {
  if (1 == CheckCapacity(ps)) {
    printf("请输入姓名:>");
    scanf("%s", ps->data[ps->size].name);
    printf("请输入年龄:>");
    scanf("%d", &ps->data[ps->size].age);
    printf("请输入性别:>");
    scanf("%s", ps->data[ps->size].sex);
    printf("请输入电话:>");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入QQ号:>");
    scanf("%s", ps->data[ps->size].qq);
    printf("请输入住址:>");
    scanf("%s", ps->data[ps->size].addr);
    ps->size++;
    printf("添加成功!\n");
    return;
  }
  printf("添加失败!\n");
}
void ShowCon(const struct Contact *ps) {
  if (ps->size == 0) {
    printf("通讯录中没有联系人!\n");
    return;
  }
  int i = 0;
  printf("%-20s\t%-4s\t%-8s\t%-12s\t%-11s\t%-30s\n", "姓名", "年龄", "性别",
         "电话", "QQ号", "住址");
  for (i = 0; i < ps->size; i++) {
    printf("%-20s\t%-4d\t%-8s\t%-12s\t%-11s\t%-30s\n", ps->data[i].name,
           ps->data[i].age, ps->data[i].sex, ps->data[i].tele, ps->data[i].qq,
           ps->data[i].addr);
  }
}
static int FindByName(const struct Contact *ps, const char name[MAX_NAME]) {
  int i = 0;
  for (i = 0; i < ps->size; i++) {
    if (0 == strcmp(ps->data[i].name, name)) {
      return i;
    }
  }
  return -1;
}
void DelCon(struct Contact *ps) {
  char name[MAX_NAME];
  printf("请输入要删除的联系人姓名:>");
  scanf("%s", name);
  int pos = FindByName(ps, name);
  if (pos == -1) {
    printf("通讯录中没有该联系人!\n");
    return;
  }
  int i = 0;
  for (i = pos; i < ps->size - 1; i++) {
    ps->data[i] = ps->data[i + 1];
  }
  ps->size--;
  printf("删除成功!\n");
}
void SearchCon(const struct Contact *ps) {
  char name[MAX_NAME];
  printf("请输入要查找的联系人姓名:>");
  scanf("%s", name);
  int pos = FindByName(ps, name);
  if (pos == -1) {
    printf("通讯录中没有该联系人!\n");
    return;
  }
  printf("%-10s\t%-4s\t%-4s\t%-12s\t%-11s\t%-30s\n", "姓名", "年龄", "性别",
         "电话", "QQ号", "住址");
  printf("%-10s\t%-4d\t%-4s\t%-12s\t%-11s\t%-30s\n", ps->data[pos].name,
         ps->data[pos].age, ps->data[pos].sex, ps->data[pos].tele,
         ps->data[pos].qq, ps->data[pos].addr);
}
static void ModifyMenu() {
  printf("***************************************"
         "\n");
  printf("***  1.name     2.age     3.sex     "
         "***\n");
  printf("***  4.tale     5.qq      6.addr    "
         "***\n");
  printf("***---------    0.exit    "
         "----------***\n");
  printf("***************************************"
         "\n");
}
void ModifyCon(struct Contact *ps) {
  char name[MAX_NAME];
  printf("请输入要修改的联系人姓名:>");
  scanf("%s", name);
  int pos = FindByName(ps, name);
  if (pos == -1) {
    printf("通讯录中没有该联系人!\n");
    return;
  }
  int modify_option = 0;
  do {
    ModifyMenu();
    printf("请选择修改项:>");
    scanf("%d", &modify_option);
    switch (modify_option) {
    case EXIT_M:
      printf("退出修改!\n");
      break;
    case NAME:
      printf("请重新输入姓名:>");
      scanf("%s", ps->data[pos].name);
      printf("修改成功!\n");
      break;
    case AGE:
      printf("请重新输入年龄:>");
      scanf("%d", &ps->data[pos].age);
      printf("修改成功!\n");
      break;
    case SEX:
      printf("请重新输入性别:>");
      scanf("%s", ps->data[pos].sex);
      printf("修改成功!\n");
      break;
    case TELE:
      printf("请重新输入电话:>");
      scanf("%s", ps->data[pos].tele);
      printf("修改成功!\n");
      break;
    case QQ:
      printf("请重新输入QQ号:>");
      scanf("%s", ps->data[pos].qq);
      printf("修改成功!\n");
      break;
    case ADDR:
      printf("请重新输入住址:>");
      scanf("%s", ps->data[pos].addr);
      printf("修改成功!\n");
      break;
    default:
      printf("选择错误,请重新选择!\n");
      break;
    }
  } while (modify_option);
}
void SortCon(struct Contact *ps) {
  if (ps->size == 0) {
    printf("通讯录中没有联系人!\n");
    return;
  }
  int i = 0;
  int j = 0;
  for (i = 0; i < ps->size - 1; i++) {
    int flag = 1;
    for (j = 0; j < ps->size - 1 - i; j++) {
      if (strcmp(ps->data[j].name, ps->data[j + 1].name) > 0) {
        struct Information tmp = ps->data[j];
        ps->data[j] = ps->data[j + 1];
        ps->data[j + 1] = tmp;
        flag = 0;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  printf("排序成功!\n");
}
void DestroyCon(Contact *ps) {
  if (ps->data == NULL) {
    return;
  }
  free(ps->data);
  ps->data = NULL;
}
void SaveCon(Contact *ps) {
  FILE *pfWrite = fopen("contact.txt", "wb");
  if (pfWrite == NULL) {
    printf("SaveCon::%s\n", strerror(errno));
    return;
  }
  int i = 0;
  for (i = 0; i < ps->size; i++) {
    fwrite(&ps->data[i], sizeof(Information), 1, pfWrite);
  }
  fclose(pfWrite);
  pfWrite = NULL;
  printf("保存成功!\n");
}