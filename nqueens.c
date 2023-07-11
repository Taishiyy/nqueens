#include "nqueens.h"

//初期化
int    ft_ten_queens_puzzle(void)
{
    t_Puzzle    board;

    int            i;

    i = 0;
    board.col_bit_map = 0;
    board.row_bit_map = 0;
    board.left_bit_map = 0;
    board.right_bit_map = 0;
    while (i < SIZE)
    {
        board.board_map[i] = 0;
        i++;
    }
    solve(board, 0, 0, 0);
    return (counter);
}

//バックトラック
void    solve(t_Puzzle board, int row, int col, int count)
{
    if (row == SIZE)
    {
        print_queens(&board);
        counter++;
        return ;
    }
    while (col < SIZE)
    {
        if (check_all(board, row, col))
        {
            solve(board, row, col + 1, count);
            return ;
        }
        set_queens(&board, row, col, count);
        solve(board, row + 1, 0, count + 1);
        reset_queens(&board, row, col);
        col++;
    }
}

//四方向のチェック関数
int    check_all(t_Puzzle board, int row, int col)
{
    if ((1 << row & board.row_bit_map) || (1 << col & board.col_bit_map)
        || (1 << (row - col + SIZE - 1) & board.left_bit_map) || (1 << (row
                + col) & board.right_bit_map))
    {
        return (1);
    }
    return (0);
}

//ビットマップに追加
void    set_queens(t_Puzzle *board, int row, int col, int count)
{
    board->board_map[col] = count;
    board->row_bit_map += (1 << (row));
    board->col_bit_map += (1 << (col));
    board->left_bit_map += (1 << (row - col + SIZE - 1)); //row - col + n - 1
    board->right_bit_map += (1 << (row + col));
}

//ビットマップから削除
void    reset_queens(t_Puzzle *board, int row, int col)
{
    board->row_bit_map -= (1 << (row));
    board->col_bit_map -= (1 << (col));
    board->left_bit_map -= (1 << (row - col + SIZE - 1)); //row - col + n - 1
    board->right_bit_map -= (1 << (row + col));
}

//出力
void    print_queens(t_Puzzle *board)
{
    int    i;
    int    ans;

    i = 0;
    while (i < SIZE)
    {
        ans = board->board_map[i];
        printf("%d ", ans);
        i++;
    }
    printf("\n");
}

int    main(void)
{
    int ans;
    ans = ft_ten_queens_puzzle();
    printf("%d", ans);
    return (0);
}