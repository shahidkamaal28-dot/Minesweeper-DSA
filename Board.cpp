
#include <iostream>
#include "Board.h"

using namespace std;

// Constructor
Board::Board() {

    rows = 9;
    cols = 9;

    // Initialize both arrays
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            internalBoard[i][j] = 0;

            displayBoard[i][j] = '#';

        }
    }
}

// Display Board Function
void Board::display() {

    // Print column numbers
    cout << "  ";

    for (int j = 0; j < cols; j++) {

        cout << j << " ";

    }

    cout << endl;

    // Print rows and cells
    for (int i = 0; i < rows; i++) {

        cout << i << " ";

        for (int j = 0; j < cols; j++) {

            cout << displayBoard[i][j] << " ";

        }

        cout << endl;
    }
}
