//
//  Bishop.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/17/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Bishop.h"

Bishop::Bishop(std::string& color) : Piece(color){}

bool Bishop::canMoveTo(Square& location) const
{
    bool check = false;
    if (abs(this->location()->getX() - location.getX()) == abs(this->location()->getY() - location.getY()) && (!location.occupied() || location.occupiedBy()->color().compare(this->color()) !=0 ) && Board::isClearDiagonal(*(this->location()), location)) {
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
    outStream << _color + "B";
}