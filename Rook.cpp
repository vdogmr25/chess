//
//  Rook.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Rook.h"

//Constructs a rook by passing the color string and the white bool to parent
Rook::Rook(std::string color, bool white) : RestrictedPiece(color, white) {}

//check for legal move
bool Rook::canMoveTo(Square& location) const
{
    //start with false
    bool check = false;
    //If the end location is empty or occupied by an opponent
    if ((!location.occupied() || location.occupiedBy()->isWhite() != isWhite())
        //and either a legal horizontal move
        && ((this->location()->getY() == location.getY() && Board::isClearHorizontal(*(this->location()), location))
            //or vertical move
            || (this->location()->getX() == location.getX() && Board::isClearVertical(*(this->location()), location))))
    {
        //set to true
        check = true;
    }
    return check;
}

int Rook::value() const
{
    // Return Rook's value
    return 5;
}

void Rook::display (std::ostream& outStream) const
{
    // Sends the piece's color and symbol into the outStream.
    outStream << color()[0] << "R";
}