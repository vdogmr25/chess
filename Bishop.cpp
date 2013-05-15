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
    bool canMove = false;
    //If the move is a legal diagonal move.
    if (Board::isClearDiagonal(*(this->location()), location))
    {
        //set to true.
        canMove = true;
    }
    return canMove;
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