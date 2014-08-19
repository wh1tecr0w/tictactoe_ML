#include <stdio.h>
#include <stdlib.h>

typedef int bool;
enum { false, true };

// char board[3][3];

#define OTHER(player) (player == 'X'? 'O' : 'X')

int winningPatterns[] = {  0x1c0,   // 0b111 000 000 (row 2)
                           0x038,   // 0b000 111 000 (row 1)
                           0x007,   // 0b000 000 111 (row 0)
                           0x124,   // 0b100 100 100 (col 2)
                           0x092,   // 0b010 010 010 (col 1)
                           0x049,   // 0b001 001 001 (col 0)
                           0x111,   // 0b100 010 001 (diagonal)
                           0x054
                        };  // 0b001 010 100 (opposite diagonal)
// msb is (2, 2); lsb is (0, 0)

void initBoard(char board[3][3])
{
    int i, j;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}
void showBoard(char board[3][3])
{
    int t;

    for (t = 0; t < 3; t++)
    {
        printf(" %c | %c | %c ", board[t][0],
               board[t][1], board [t][2]);
        if (t != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}



void playerMove(char board[3][3])
{
    int x, y;
    printf("Enter board coordinate (x,y): ");
    scanf("%d %d", &x, &y);
    x = x - 1;
    y = y - 1;
    if (board[x][y] != '-')
    {
        printf("Invalid move\n");
        playerMove();
    }
    else
        board[x][y] = 'X';
}

void computerMove(char board[3][3])
{
    // printf("TESTSTESETSETSET\n");
    int i = 0, j = 0;
    for ( i = 0; i < 3; i++)
    {
        // printf("Outer: i= %d j= %d\n", i, j );
        for ( j = 0; j < 3; j++)
        {
            // printf("Inner: i = %d j= %d\n", i, j );
            if (board[i][j] == '-')
                break;
        }
        if (board[i][j] == '-') break;

    }
    if (i * j == 9)
    {
        printf("Draw\n");
        exit(0);
    }
    else if (board[i][j] == '-')
    {
        board[i][j] = 'O';
    }
}
/*int my_min(char board[3][3], char player)
{
    int result = boardCheck(board, OTHER(player));
    if (result != UNFINISHED)
        return result;

    int i, j, min;
    min = 10; //Only actually has to be greater than 1
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            if (board[i][j] != ' ')
                continue;
            char new_board[N][N];
            int x, y;
            for (x = 0; x < N; ++x)
            {
                for (y = 0; y < N; ++y)
                {
                    new_board[x][y] = board[x][y];
                }
            }
            if (new_board[i][j] != ' ')
            {
                printf("MY_MIN overlap\n"); //Debug
                exit(0);
            }
            new_board[i][j] = player;
            int temp = my_max(new_board, OTHER(player));
            if (temp < min)
                min = temp;
        }
    }
    return min;
}

void minmax(char board[3][3]){
    int i, j, max, max_i, max_j;
    max = -10;
      for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            if (board[i][j] != ' ')
                continue;
            char new_board[3][3];
            int x, y;
            for (x = 0; x < 3; ++x)
            {
                for (y = 0; y < 3; ++y)
                {
                    new_board[x][y] = board[x][y];
                }
            }
            new_board[i][j] = player;
            int temp = my_min(new_board, OTHER(player));
            // Max(Computer) is always the top of minimax tree
            // Finish with max result of my_min() recursive loop
            if (temp > max)
            {
                max = temp;
                max_i = i;
                max_j = j;
            }
        }
    }
    if (enter_coord_move(board, player, max_i, max_j) == TRUE)
    {
        printf("Minimax - Error entering move\n"); //Debug
        exit(0);
    }
}*/
/*void computerMove_minmax()
{
    minmax();
    boardCheck('O');
}*/
char boardCheck(char board[3][3],char player)
{

    int i;

    for (i = 0; i < 3; i++) /* check rows */
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];

    for (i = 0; i < 3; i++) /* check columns */
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];

    /* test diagonals */
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return '-';
}
char boardCheck_bin()
{
    // int playerPattern = (th)
}

int main(int argc, char const *argv[])
{
    int x = 0, y = 0;
    char done = '-';
    char mainboard[3][3];
    initBoard(mainboard);
    do
    {
        showBoard(mainboard);
        playerMove(mainboard);
        done = boardCheck(mainboard, 'X');
        if (done != '-') break;
        computerMove(mainboard);
        done = boardCheck(mainboard,'O');
        if(done!='-') break;
    }
    while (done == '-');
    if (done == 'X')
        printf("You won\n");
    else
        printf("Computer Won\n");
    showBoard(mainboard);
    return 0;
}