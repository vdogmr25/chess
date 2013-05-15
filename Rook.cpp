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
    //If the move is a legal horizontal move
    if (Board::isClearHorizontal(*(this->location()), location)
        //or vertical move
        || Board::isClearVertical(*(this->location()), location))
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