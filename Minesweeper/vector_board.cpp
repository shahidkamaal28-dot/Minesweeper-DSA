
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

const int SIZE = 9;
const int TOTAL_MINES = 10;

// Place 10 random mines
void placeMines(vector<vector<int>>& board)
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(0, SIZE - 1);

    int placed = 0;

    while (placed < TOTAL_MINES)
    {
        int row = dist(gen);
        int col = dist(gen);

        if (board[row][col] != -1)
        {
            board[row][col] = -1;
            placed++;
        }
    }
}

// Calculate neighbouring mines
void calculateNumbers(vector<vector<int>>& board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == -1)
                continue;

            int count = 0;

            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int newRow = i + r;
                    int newCol = j + c;

                    if (newRow >= 0 && newRow < SIZE &&
                        newCol >= 0 && newCol < SIZE)
                    {
                        if (board[newRow][newCol] == -1)
                            count++;
                    }
                }
            }

            board[i][j] = count;
        }
    }
}

// Display internal board for testing
void showInternalBoard(const vector<vector<int>>& board)
{
    cout << "\nINTERNAL BOARD (Testing Only)\n\n";

    cout << "    ";
    for (int j = 0; j < SIZE; j++)
        cout << setw(3) << j;

    cout << "\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(3) << i << " ";

        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == -1)
                cout << setw(3) << "*";
            else
                cout << setw(3) << board[i][j];
        }

        cout << "\n";
    }
}

// Display player's covered board
void showDisplayBoard(const vector<vector<char>>& displayBoard)
{
    cout << "\nPLAYER BOARD\n\n";

    cout << "    ";
    for (int j = 0; j < SIZE; j++)
        cout << setw(3) << j;

    cout << "\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(3) << i << " ";

        for (int j = 0; j < SIZE; j++)
            cout << setw(3) << displayBoard[i][j];

        cout << "\n";
    }
}

int main()
{
    // Create internal vector board
    vector<vector<int>> board(
        SIZE, vector<int>(SIZE, 0)
    );

    // Create player's display board
    vector<vector<char>> displayBoard(
        SIZE, vector<char>(SIZE, '#')
    );

    placeMines(board);
    calculateNumbers(board);

    cout << "============================\n";
    cout << "    MINESWEEPER VECTOR      \n";
    cout << "============================\n";

    showInternalBoard(board);
    showDisplayBoard(displayBoard);

    cout << "\nTotal Mines: " << TOTAL_MINES << endl;

    return 0;
}
