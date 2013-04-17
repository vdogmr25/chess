//
//  King.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/17/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "King.h"

King::King(std::string& color) : RestrictedPiece(color) {}

bool King::canMoveTo(Square& location) const
{
    bool check = false;
    if ((!location.occupied() || location.occupiedBy()->color().compare(this->color()) !=0 ) && (abs(this->location()->getX() - location.getX()) <= 1 && abs(this->location()->getY() - location.getY()) <= 1)) {
        check= true;
    }
    return check;
}

int King::value() const
{
    // Return King's value
    return 0;
}

void King::display (std::ostream& outStream) const
{
    // Sends the piece's color and symbol into the outStream.
    outStream << _color + "K";
}