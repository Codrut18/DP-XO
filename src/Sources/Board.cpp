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

bool Board::placeMark(int line, int col, bool mark) {
    if(line<0 || line>this->bheight || col<0 || col>this->bwidth)
        return false;

    if(this->table[line][col]!=-1)
        return false;

    this->table[line][col] = (int)mark;
}

Board::~Board() {

}

