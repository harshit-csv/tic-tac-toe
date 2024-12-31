#include <iostream>
using namespace std;

void display(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isFull(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
                return false;
        }
    }
    return true;
}

bool isWinner(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    if((board[0][0] == player && board[1][1] == player && board[2][2] == player)||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    ){
        return true;
    }

    return false;
}

int main()
{
    char player = 'X';
    char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    while (true)
    {
        system("cls");
        display(board);
        int row, col;
        cout << "This is turn of " << player << endl;

        cout << "Enter row(0|1|2): ";
        cin >> row;
        cout << "Enter col(0|1|2): ";
        cin >> col;

        if (0 <= row && row <= 2 && col >= 0 && col <= 2 && board[row][col] == '-')
        {
            board[row][col] = player;
        }
        else
        {
            cout << "Invalid Move, Try Again" << endl;
            continue;
        }

        if (isWinner(board, player))
        {
            system("cls");
            display(board);
            cout << "Player " << player << " wins !!!";
            break;
        }

        if (isFull(board))
        {
            system("cls");
            display(board);
            cout << "It's a draw";
            break;
        }
        player = (player == 'X') ? '0' : 'X';
    }

    int x;
    cout << "Enter any number to exit: ";
    cin >> x;
    return 0;
}