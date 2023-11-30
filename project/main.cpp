#include "Board.h"

int main()
{
    Board board;
    for (int i = 0; i < 82; i++)
    {
        cout << "BRUH I FUCKING HATE THIS" << endl;
        board.setPlayerPosition(i, 2);
        board.displayBoard();
    }
    return 0;
}