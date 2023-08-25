#include <iostream>
#include <vector>
// using namespace std;

class TicTacToe
{
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void play()
    {
        while (!isGameOver())
        {
            printBoard();
            getPlayerMove();
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        printBoard();
        printResult();
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void printBoard()
    {
        std::cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i)
        {
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 3; ++j)
            {
                std::cout << board[i][j];
                if (j < 2)
                    std::cout << '|';
            }
            std::cout << '\n';
            if (i < 2)
                std::cout << "  -----\n";
        }
        std::cout << '\n';
    }

    void getPlayerMove()
    {
        int row, col;
        while (true)
        {
            std::cout << "Player " << currentPlayer << ", enter your move (row col): ";
            std::cin >> row >> col;
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ')
            {
                board[row - 1][col - 1] = currentPlayer;
                break;
            }
            else
            {
                std::cout << "Invalid move. Try again.\n";
            }
        }
    }

    bool isGameOver()
    {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;

        // Check for a draw
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void printResult()
    {
        if (isGameOver())
        {
            if (currentPlayer == 'X')
            {
                std::cout << "Player O wins!\n";
            }
            else
            {
                std::cout << "Player X wins!\n";
            }
        }
        else
        {
            std::cout << "It's a draw!\n";
        }
    }
};

int main()
{
    TicTacToe game;
    game.play();
    return 0;
}
