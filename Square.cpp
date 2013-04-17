//
//  Square.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Square.h"
#include "Piece.h"

Square::Square(int x, int y) : _x(x), _y(y){}

int Square::getX ()
{
    // returns x coordinate
    return _x;
}

int Square::getY ()
{
    // returns y coordinate
    return _y;
}

bool Square::occupied ()
{
    // checks if square is occupied
    bool check = false;
    if (_occupant != 0)
    {
        check = true;
    }
    
    // returns the result of the check.
    return check;
}

Piece* Square::occupiedBy ()
{
    // returns the occupant
    return _occupant;
}

void Square::setOccupier (Piece* piece)
{
    // sets the occupant.
    _occupant = piece;
}

