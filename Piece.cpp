//
//  Piece.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Piece.h"
#include "Player.h"

Piece::Piece(std::string& color) : _color(color) {}

bool Piece::moveTo (Player& byPlayer, Square& to)
{
    //Start with false
    bool attempt = false;
    //If the end location is unoccupied or occupied by a different colored piece
    if ((!to.occupied() || to.occupiedBy()->color() != _color)
        //And the player moving the piece owns the piece and the piece can move to the
        //square
        && (this->color()[0] == byPlayer.getName()[0] && canMoveTo(to)))
    {
        //If the square is occupied..
        if (to.occupied())
        {
            //..capture the piece
            byPlayer.capture(*(to.occupiedBy()));
        }
        //Set the old location's occupant to NULL
        location()->setOccupier(NULL);
        //Set the new square's occupant to this piece
        to.setOccupier(this);
        //set the current location to the new square.
        setLocation(&to);
        //set to true for successful move.
        attempt = true;
    }
    //return the result.
    return attempt;
}

std::string Piece::color () const
{
    // reuturns the piece's color
    return _color;
}

void Piece::setLocation (Square* square)
{
    // sets the square the piece occupies
    _occupies = square;
}

bool Piece::isOnSquare () const
{
    // Not developed yet.
    return true;
}

Square* Piece::location () const
{
    //returns the piece's location.
    return _occupies;
}