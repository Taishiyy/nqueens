#ifndef NQUEENS_H
#define NQUEENS_H

#include <stdio.h>
#include <unistd.h>
#define SIZE 14

typedef struct s_Puzzle
{
    int board_map[SIZE]; //出力用
    int row_bit_map;     //行確認
    int left_bit_map;    //左上から右下
    int right_bit_map;   //右上から右下
    int col_bit_map;     //縦方向
}            t_Puzzle;

static int    counter;

int            ft_ten_queens_puzzle(void);
void        solve(t_Puzzle board, int row, int col, int count);
int            check_all(t_Puzzle board, int row, int col);
void        set_queens(t_Puzzle *board, int row, int col, int count);
void        reset_queens(t_Puzzle *board, int row, int col);
void        print_queens(t_Puzzle *board);

#endif