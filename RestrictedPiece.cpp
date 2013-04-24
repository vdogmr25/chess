//
//  RestrictedPiece.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "RestrictedPiece.h"

//Constucts a rescricted piece by passing the color string and the white bool to parent
RestrictedPiece::RestrictedPiece(std::string color, bool white) : Piece(color, white)
{
    //set _moved to false.
    _moved = false;
}

bool RestrictedPiece::moveTo (Player& byPlayer, Square& to)
{
    //Attempt to move using parent class
    bool attempt = Piece::moveTo(byPlayer, to);
    
    //if move attempt was successful
    if (attempt)
    {
        //set _moved to true
        _moved = true;
    }
    
    //return result
    return attempt;
}

bool RestrictedPiece::hasMoved() const
{
    // return if the pieces has moved yet.
    return _moved;
}