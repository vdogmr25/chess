//
//  Rook.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Rook.h"

Rook::Rook(std::string& color) : RestrictedPiece(color) {}

bool Rook::canMoveTo(Square& location) const
{
    bool check = false;
    if ((!location.occupied() || location.occupiedBy()->color().compare(this->color()) !=0 ) && ((this->location()->getY() == location.getY() && Board::isClearHorizontal(*(this->location()), location)) || (this->location()->getX() == location.getX() && Board::isClearVertical(*(this->location()), location))))
    {
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
    outStream << _color + "R";
}