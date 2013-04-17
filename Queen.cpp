//
//  Queen.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Queen.h"

Queen::Queen(std::string& color) : Piece(color) {}

bool Queen::canMoveTo(Square& location) const
{
    bool check = false;
    if ( (!location.occupied() || location.occupiedBy()->color().compare(this->color()) !=0 )
        && (((this->location()->getY() == location.getY() && Board::isClearHorizontal(*(this->location()), location)) || (this->location()->getX() == location.getX()&& Board::isClearVertical(*(this->location()), location)))
        || (abs(this->location()->getX() - location.getX()) == abs(this->location()->getY() - location.getY()) && Board::isClearDiagonal(*(this->location()), location)))) {
        check= true;
    }
    return check;
}

int Queen::value() const
{
    // Return Queen's Value
    return 9;
}

void Queen::display (std::ostream& outStream) const
{
    // Sends the piece's color and symbol into the outStream.
    outStream << _color + "Q";
}