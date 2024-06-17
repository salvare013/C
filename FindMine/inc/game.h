#pragma once

//定义常量
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 13

//包含库函数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//函数声明

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);

//返回两种游戏状态
//失败	'1'
//成功	'W'
char FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);