//
//  Knight.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/17/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Knight.h"

Knight::Knight(std::string& color) : Piece(color) {}

bool Knight::canMoveTo(Square& location) const
{
    bool check = false;
    if ((!location.occupied() || location.occupiedBy()->color().compare(this->color()) !=0 ) && ((abs(this->location()->getX() - location.getX()) == 1 && abs(this->location()->getY() - location.getY()) == 2) || (abs(this->location()->getX() - location.getX()) == 2 && abs(this->location()->getY() - location.getY()) == 1))) {
        check = true;
    }
    return check;
}

int Knight::value() const
{
    //Return Knight's value
    return 3;
}

void Knight::display (std::ostream& outStream) const
{
    // Sends the piece's color and symbol into the outStream.
    outStream << _color + "N";
}
