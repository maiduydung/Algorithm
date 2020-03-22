// https://www.spoj.com/PTIT/problems/BCKNIGHT/

#include<stdio.h>
#include <stdlib.h>

#define SIZE 8

int board[SIZE][SIZE] = { 0 };
int x_moves[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
int y_moves[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
int count = 0;

void print_board(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}


void move(int n, int x, int y){
    ++count;
    board[x][y] = count;
    if (count == n * n){
        print_board(n);
        exit(0);
    }

    for (int i = 0; i < 8; i++)
    {
        int u = x + x_moves[i];
        int v = y + y_moves[i];
        if ( (u >= 0) && (u < n) && (v >= 0) && (v < n) && (board[u][v]==0))
        {
            move(n, u , v);
        }
    }
    --count;
    board[x][y] = 0;
    
}

void wrapper(int n, int x, int y){
    x = x - 1;
    y = y - 1;
    move(n, x, y);
}

int main(){
    wrapper(8,4,3);
    return -1;
}
