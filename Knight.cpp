//
//  Knight.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/17/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Knight.h"

//Constructs the Knight by passing the color string and the white bool to parent
Knight::Knight(std::string color, bool white) : Piece(color, white) {}

//checks for legal move
bool Knight::canMoveTo(Square& location) const
{
    //start with false
    bool check = false;
    //If the end location is empty or occupied by an opponent
    if ((!location.occupied() || location.occupiedBy()->isWhite() != isWhite())
        //And the knight is only moving in an "L" shape
        && ((abs(this->location()->getX() - location.getX()) == 1 && abs(this->location()->getY() - location.getY()) == 2) || (abs(this->location()->getX() - location.getX()) == 2 && abs(this->location()->getY() - location.getY()) == 1)))
    {
        //set to true
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
    outStream << color()[0] << "N";
}
