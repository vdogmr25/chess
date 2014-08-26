//
//  Piece.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Piece.h"
#include "Player.h"

Piece::Piece(std::string color, bool white) : _color(color), _white(white) {}

bool Piece::moveTo (Player& byPlayer, Square& to)
{
    //Start with false
    bool attempt = false;
    Piece* capture = NULL;
    Square* current = location();
    //If the end location is unoccupied or occupied by a different colored piece
    if ((!to.occupied() || to.occupiedBy()->isWhite() != isWhite())
        //And the player moving the piece owns the piece and the piece can move to the
        //square
        && (isWhite() == byPlayer.isWhite() && canMoveTo(to)))
    {
        //If the square is occupied..
        if (to.occupied())
        {
            //..capture the piece
            capture = to.occupiedBy();
            capture->setLocation(NULL);
        }
        else if (Board::squareAt(to.getX(), this->location()->getY())->occupied()
                 && Board::squareAt(to.getX(), this->location()->getY())->occupiedBy()->isWhite() != isWhite()
                 && Board::squareAt(to.getX(), this->location()->getY())->occupiedBy()->value() == 1)
        {
            capture = Board::squareAt(to.getX(), this->location()->getY())->occupiedBy();
            capture->setLocation(NULL);
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
    //If the player is in check
    if (byPlayer.checkForCheck())
    {
        //Signal for bad move
        attempt = false;
        
        //Revert pieces to old locations
        setLocation(current);
        current->setOccupier(this);
        
        //revert capture.
        if (capture)
        {
            to.setOccupier(capture);
            capture->setLocation(&to);
        }
    }
    //If the player isn't in check and there's a piece to capture
    else if(capture)
    {
        //capture
        byPlayer.capture(*capture);
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
    bool onSquare = false;
    if (location())
    {
        onSquare = true;
    }
    return onSquare;
}

bool Piece::isWhite() const
{
    return _white;
}

Square* Piece::location () const
{
    //returns the piece's location.
    return _occupies;
}