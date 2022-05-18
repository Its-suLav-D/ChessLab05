#include "position.h"
#include <iostream>

using namespace std;


int Position:: getLocation()
{
    return location;
}

int Position::getRow()
{
    return isInvalid() ? 0 : (int)(location / 8);
}

int Position:: getCol()
{
    return  isInvalid() ? 0 : (int)(location % 8);
}

int Position:: getX()
{
    return  (int)((double)getCol()* getSquareWidth());
}

int Position:: getY()
{
    return (int)((double)getCol()* getSquareHeight());
}

void Position:: setRow(int row)
{
    if( row >=0 && row <8 && isValid())
    {
        location = row;
    } else
    {
        location = -1;
    }
}

void Position:: setCol(int col)
{
    if(col >=0 && col <8 && isValid())
    {
        location = getLocation() + col;
    } else
    {
        location = -1;
    }
}

void Position:: set(int row, int col)
{
    location=0;
    setRow(row);
    setCol(col);
}

