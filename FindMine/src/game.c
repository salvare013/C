#include "game.h"

void InitBoard(char board[ROWS][COLS],
               int rows,
               int cols,
               char set) {
  int i = 0;
  int j = 0;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      board[i][j] = set;
    }
  }
}
void DisplayBoard(char board[ROWS][COLS],
                  int row,
                  int col) {
  int i = 0;
  int j = 0;
  // 打印列号
  for (i = 0; i <= col; i++) {
    printf("%d ", i);
    if (i == 0) {
      printf(" ");
    }
  }
  printf("\n\n");
  for (i = 1; i <= row; i++) {
    // 打印行号
    printf("%d  ", i);
    for (j = 1; j <= col; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
void SetMine(char mine[ROWS][COLS],
             int row,
             int col) {
  int count = EASY_COUNT;
  while (count) {
    int x = rand() % col + 1;
    int y = rand() % row + 1;
    if (mine[y][x] == '0') {
      mine[y][x] = '1';
      count--;
    }
  }
}
int GetMineCount(char mine[ROWS][COLS],
                 int x,
                 int y) {
  return mine[y + 1][x - 1] + mine[y + 1][x] +
         mine[y + 1][x + 1] + mine[y][x - 1] +
         mine[y][x + 1] + mine[y - 1][x - 1] +
         mine[y - 1][x] + mine[y - 1][x + 1] -
         8 * '0';
}
char FindMine(char mine[ROWS][COLS],
              char show[ROWS][COLS],
              int row,
              int col) {
  int x = 0;
  int y = 0;
  int count = 0;
  int flag = 0;
  while (1) {
    printf("请输入要排查雷的横,纵坐标:>");
    scanf("%d%d", &x, &y);
    // 判断坐标合法性
    if (x >= 1 && x <= col && y >= 1 &&
        y <= row) {
      // 踩雷
      if (mine[y][x] == '1') {
        return mine[y][x];
      }
      // 不踩雷
      else {
        count = GetMineCount(mine, x, y);
        show[y][x] = count + '0';
        DisplayBoard(show, row, col);
        flag++;
      }
    } else {
      printf("坐标非法,请重新输入!\n");
    }
    if (flag == row * col - EASY_COUNT) {
      return 'W';
    }
  }
}