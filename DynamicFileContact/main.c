#include "contact.h"

static void Menu() {
  printf(
      "*************************************\n");
  printf(
      "***      1.add      2.del         ***\n");
  printf(
      "***      3.search   4.modify      ***\n");
  printf(
      "***      5.show     6.sort        ***\n");
  printf(
      "***      7.save     0.exit        ***\n");
  printf(
      "*************************************\n");
}
void test() {
  int input = 0;
  struct Contact con;
  InitContact(&con);
  do {
    Menu();
    printf("请选择:>");
    scanf("%d", &input);
    switch (input) {
      case EXIT: {
        int choose = 0;
        printf("是否保存?\n");
        printf("请选择:\nYes(1) or No(0)\t>");
        scanf("%d", &choose);
        if (choose == 1) {
          SaveCon(&con);
        }
        DestroyCon(&con);
        printf("退出!\n");
      } break;
      case ADD:
        AddCon(&con);
        break;
      case DEL:
        DelCon(&con);
        break;
      case SEARCH:
        SearchCon(&con);
        break;
      case MODIFY:
        ModifyCon(&con);
        break;
      case SHOW:
        ShowCon(&con);
        break;
      case SORT:
        SortCon(&con);
        break;
      case SAVE:
        SaveCon(&con);
        break;
      default:
        printf("选择错误!\n");
        break;
    }
  } while (input);
}

int main() {
  test();

  return 0;
}
