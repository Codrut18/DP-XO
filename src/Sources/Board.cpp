#include "../Headers/Board.h"

Board::Board()
{
    rlSize=0;
}
bool Board::isFull()
{
    return rlSize == bMaxSize;
}

void Board::initTable()
{
    for(size_t i=0;i<bwidth;i++)
    {
        for(size_t j=0;j<bheight;i++)
        {
            table[i][j]=-1;
        }
    }
}

