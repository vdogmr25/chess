//
//  Bishop.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/17/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Bishop.h"

//Constructs by passing the color string and the white boolean to parent
Bishop::Bishop(std::string color, bool white) : Piece(color, white){}

//Checks for legal move
bool Bishop::canMoveTo(Square& location) const
{
    //start with false
    bool check = false;
    //If the piece is moving the same distance vertically as horizontally
    if (abs(this->location()->getX() - location.getX()) == abs(this->location()->getY() - location.getY())
        //and the square to move to is empty or occupied by an opponent
        && (!location.occupied() || location.occupiedBy()->isWhite() != isWhite())
        //and the path there is clear
        && Board::isClearDiagonal(*(this->location()), location))
    {
        //set to true.
        check = true;
    }
    return check;
}

int Bishop::value() const
{
    //Return Bishop's value
    return 3;
}

void Bishop::display (std::ostream& outStream) const
{
    // Sends the piece's color and symbol into the outStream.
    outStream << color()[0] << "B";
}