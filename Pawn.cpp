//
//  Pawn.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/17/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Pawn.h"
#include "Queen.h"

//Constructs a pawn by passing the color string and the white bool to parent
Pawn::Pawn(std::string color, bool white) : RestrictedPiece(color, white) {}

//Desturctor
Pawn::~Pawn()
{
    //If there's a delegate
    if (_delegate)
    {
        //delete the delegate
        delete _delegate;
    }
}

int Pawn::value() const
{
    // return Pawn's value
    return 1;
}

bool Pawn::canMoveTo(Square& location) const
{
    //Start with false
    bool canMove = false;
    
    //If there's a delegate
    if (_delegate)
    {
        canMove = _delegate->canMoveTo(location);
    }
    //Otherwise, if the white player is trying to move up the board
    else if ((isWhite() && location.getY() > this->location()->getY()) || 
        //or the black player is moving down the board
        ((!isWhite() && location.getY() < this->location()->getY())))
    {
        //If the player has moved and the move is a legal vertical move
        if (hasMoved() && Board::isClearVertical(*(this->location()), location)
            //and the piece is only moving one space
            && abs(this->location()->getY() - location.getY()) == 1
            //and the stop location is unoccupied.
            && !location.occupied())
        {
            //check is true
            canMove = true;
        }
        //If the player hasn't moved and the piece is moving 2 squares at most
        else if (!hasMoved() && abs(this->location()->getY() - location.getY()) <= 2
                 // and the board is clear for a vertical move
                 && Board::isClearVertical(*(this->location()), location)
                 //and the stop location is unoccupied.
                 && !location.occupied())
        {
            //check is true
            canMove = true;
        }
        //If the piece is moving the same number of spaces along the x and y axes
        else if (abs(this->location()->getY() - location.getY())
                 == abs(this->location()->getX() - location.getX())
                 //and the piece is only moving one square in a direction.
                 && abs(this->location()->getY() - location.getY()) == 1
                 //and the end location is occupied..
                 && location.occupied()
                 //..by an opponent's piece
                 && location.occupiedBy()->isWhite() != isWhite())
        {
            //check is true
            canMove = true;
        }
    }
    //return check.
    return canMove;
}

bool Pawn::moveTo(Player& byPlayer, Square& to)
{
    bool attempt = RestrictedPiece::moveTo(byPlayer, to);
    if (attempt && Board::isEnd(to) && !_delegate)
    {
        _delegate = new Queen(color(), isWhite());
    }
    if (attempt && _delegate)
    {
        _delegate->setLocation(&to);
    }
    return attempt;
}

void Pawn::display (std::ostream& outStream) const
{
    //If there's a delegate
    if (_delegate)
    {
        //Call the delegate's display
        _delegate->display(outStream);
    }
    //Otherwise
    else
    {
        // Sends the piece's color and symbol into the outStream.
        outStream << color()[0] << "P";
    }
}