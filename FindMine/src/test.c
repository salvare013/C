#include "game.h"

void Menu() {
  printf(
      "************************************\n");
  printf(
      "*******      1.play       **********\n");
  printf(
      "*******      0.exit       **********\n");
  printf(
      "************************************\n");
}
void Game() {
  // 判断游戏状态
  char ret = 0;
  // 储存布置的雷信息
  char mine[ROWS][COLS] = {0};
  // 储存排除的雷信息
  char show[ROWS][COLS] = {0};
  // 初始化
  InitBoard(mine, ROWS, COLS, '0');
  InitBoard(show, ROWS, COLS, '*');
  // 布置雷
  SetMine(mine, ROW, COL);
  DisplayBoard(mine, ROW, COL);
  DisplayBoard(show, ROW, COL);
  // 扫雷
  ret = FindMine(mine, show, ROW, COL);
  if (ret == '1') {
    printf("很遗憾,你被炸死了!\n");
    DisplayBoard(mine, ROW, COL);
    printf("GAME OVER!\n");

  } else {
    printf("哇!!! 恭喜你排雷成功了!\n");
    DisplayBoard(mine, ROW, COL);
    printf("你是我的YYDS!\n");
  }
}
void test() {
  int input = 0;
  srand((unsigned int)time(NULL));
  do {
    Menu();
    printf("请选择:>");
    scanf("%d", &input);
    switch (input) {
      case 1:
        Game();
        break;
      case 0:
        printf("退出游戏!\n");
        break;
      default:
        printf("选择错误,请重新选择!\n");
        break;
    }
  } while (input);
}
int main() {
  test();

  return 0;
}