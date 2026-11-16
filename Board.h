
#ifndef BOARD_H
#define BOARD_H

class Board {

private:
    int rows;
    int cols;
    int internalBoard[9][9];
    char displayBoard[9][9];

public:
    Board();
    void display();
};

#endif
