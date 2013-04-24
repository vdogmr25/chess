//
//  Queen.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Queen.h"

//Constructs a queen by passing the color string and the white bool to parent
Queen::Queen(std::string color, bool white) : Piece(color, white) {}

//Checks for legal move
bool Queen::canMoveTo(Square& location) const
{
    //start with false
    bool check = false;
    //If the end location is empty or controlled by an opponent
    if ((!location.occupied() || location.occupiedBy()->isWhite() != isWhite())
        //And is either a legal horizontal move
        && (((this->location()->getY() == location.getY() && Board::isClearHorizontal(*(this->location()), location))
        //a legal verical move
        || (this->location()->getX() == location.getX()&& Board::isClearVertical(*(this->location()), location)))
        //or a legal diagonal move
        || (abs(this->location()->getX() - location.getX()) == abs(this->location()->getY() - location.getY()) && Board::isClearDiagonal(*(this->location()), location))))
    {
        //return true
        check= true;
    }
    return check;
}

int Queen::value() const
{
    // Return Queen's Value
    return 9;
}

void Queen::display (std::ostream& outStream) const
{
    // Sends the piece's color and symbol into the outStream.
    outStream << color()[0] << "Q";
}