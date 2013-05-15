//
//  King.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/17/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "King.h"

//Constructs a king by passing the color string and the white bool to parent
King::King(std::string color, bool white) : RestrictedPiece(color, white) {}

//check for legal move
bool King::canMoveTo(Square& location) const
{
    //start with false
    bool canMove = false;
    //If the piece is only moving one square.
    if (abs(this->location()->getX() - location.getX()) <= 1 && abs(this->location()->getY() - location.getY()) <= 1)
    {
        //set to true
        canMove = true;
    }
    return canMove;
}

int King::value() const
{
    // Return King's value
    return 0;
}

void King::display (std::ostream& outStream) const
{
    // Sends the piece's color and symbol into the outStream.
    outStream << color()[0] << "K";
}