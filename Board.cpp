//
//  Board.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Board.h"
#include "Piece.h"

// Sets initial value of board pointer.
Board* Board::_theBoard = NULL;
Square* Board::_squares[_DIMENSION][_DIMENSION];

Board::Board()
{
    // loops over x dimension.
    for (int i = 0; i < _DIMENSION; i++)
    {
        // loops over y dimension.
        for (int j = 0; j < _DIMENSION; j++)
        {
            // Places a new square with that location value in the board.
            _squares[i][j] = new Square(i + 1, j + 1);
        }
    }
}

Board::~Board()
{
    // loops over x dimension.
    for (int i = 0; i < _DIMENSION; i++)
    {
        // loops over y dimension.
        for (int j = 0; j < _DIMENSION; j++)
        {
            // Deletes the squares in the board.
            delete _squares[i][j];
        }
    }
}

Board* Board::getBoard ()
{
    // If the pointer to the board is NULL.
    if (!_theBoard)
    {
        // Create a new board and set the pointer to it.
        _theBoard = new Board();
    }
    
    //return the pointer to the board
    return _theBoard;
}

Square* Board::squareAt (int x, int y)
{
    // return a pointer to the square at a location.
    return _squares[x-1][y-1];
}

bool Board::isClearVertical (Square& from, Square& to)
{
    //start with true
    bool check = true;
    Square start = from;
    Square stop = to;
    
    //If going from a large Y value to a smaller one
    if (from.getY() > to.getY())
    {
        //swap the start and end
        start = to;
        stop = from;
    }
    for (int i = start.getY() + 1; i < stop.getY(); i++)
    {
        //If a square is occupied
        if (squareAt(from.getX(), i)->occupied())
        {
            //The check is false.
            check = false;
        }
    }
    return check;
}

bool Board::isClearHorizontal (Square& from, Square& to)
{
    //start with true
    bool check = true;
    Square start = from;
    Square stop = to;
    
    //If going from a large X value to a smaller one
    if (from.getX() > to.getX())
    {
        //swap the start and end
        start = to;
        stop = from;
    }
    for (int i = start.getX() + 1; i < stop.getX(); i++)
    {
        //If a square is occupied
        if (squareAt(i, from.getY())->occupied())
        {
            //The check is false.
            check = false;
        }
    }
    return check;
}

bool Board::isClearDiagonal (Square& from, Square& to)
{
    //start with true
    bool check = true;
    Square start = from;
    Square stop = to;
    
    //If going from a large Y value to a smaller one
    if (from.getY() > to.getY())
    {
        //swap the start and end
        start = to;
        stop = from;
    }
    if (start.getX() > stop.getX())
    {
        //Iterate from bottom left to top right.
        for (int i = start.getY() - stop.getY() + 1; i > 0; i++)
        {
            //If a square is occupied
            if (squareAt(start.getX() - i, start.getY() - i)->occupied())
            {
                //The check is false
                check = false;
            }
        }
    }
    else
    {
        //Iterate from bottom right to top left.
        for (int i = start.getY() - stop.getY() + 1; i > 0; i--)
        {
            //If a square is occupied
            if (squareAt(start.getX() + i, start.getY() - i)->occupied())
            {
                //The check is false
                check = false;
            }
        }
    }
    return check;
}

bool Board::isEnd(Square& location)
{
    return (location.getY() == 1 || location.getY() == _DIMENSION);
}

void Board::display (std::ostream& outStream)
{
    //print the letters and the top border.
    outStream << "   a  b  c  d  e  f  g  h" << std::endl << " -------------------------" << std::endl;
    
    //iterate over the board by row from bottom to top
    for (int i = _DIMENSION - 1; i >= 0 ; i--)
    {
        //print a number value for the row
        outStream << (i + 1);
        
        //iterate over the row left to right.
        for (int j = 0; j < _DIMENSION; j++)
        {
            //print a side edge to a square.
            outStream << "|";
            
            // If there's a piece in the square...
            if(_squares[j][i]->occupied())
            {
                // ...Display it
                _squares[j][i]->occupiedBy()->display(outStream);
            }
            else
            {
                //  If not, print empty space.
                outStream << "  ";
            }
        }
        // print the edge of the row and the next border.
        outStream << "|" << std::endl << " -------------------------" << std::endl;
    }
}