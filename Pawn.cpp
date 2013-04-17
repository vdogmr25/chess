//Grading Template

/* ID         :  1300374
 Assignment :  Chess Part 2
 Class      :  CSIS 370 Object-Oriented Programming
 Date       :  4/9/12
 
 Programming Assesment Standards
 
 PROGRAM CORRECTNESS
 a) the program is complete & functions correctly       (40)________
 PROGRAM DESIGN
 b) object-oriented class design & implementation       (10)________
 c) appropriate use of language and features            (10)________
 d) subjective elegance                                 (20)________
 PROGRAM READABILITY AND DOCUMENTATION
 e) Header comments are complete & clear                 (5)________
 f) Internal comments are used when appropriate         (15)________
 
 TOTAL                                                    (100)________
 
 ******************************************************************/

//
//  Pawn.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/17/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Pawn.h"

Pawn::Pawn(std::string& color) : RestrictedPiece(color) {}

int Pawn::value() const
{
    // return Pawn's value
    return 1;
}

bool Pawn::canMoveTo(Square& location) const
{
    //Start with false
    bool check = false;
    
    //If the white player is trying to move up the board
    if ((_color.compare("W") == 0 && location.getY() > this->location()->getY()) || 
        //or the black player is moving down the board
        ((_color.compare("B") == 0 && location.getY() < this->location()->getY())))
    {
        //If the player has moved and the x locations are the same for both squares
        if (hasMoved() && this->location()->getX() == location.getX()
            //and the piece is only moving one space
            && abs(this->location()->getY() - location.getY()) == 1
            //and the stop location is unoccupied.
            && !location.occupied())
        {
            //check is true
            check = true;
        }
        //If the player hasn't moved and the x loactions are the same for both squares
        else if (!hasMoved() && this->location()->getX() == location.getX()
                 //and the piece is moving 2 squares at most
                 && abs(this->location()->getY() - location.getY()) <= 2
                 // and the board is clear for a vertical move
                 && Board::isClearVertical(*(this->location()), location)
                 //and the stop location is unoccupied.
                 && !location.occupied())
        {
            //check is true
            check = true;
        }
        //If the piece is moving the same number of spaces along the x and y axes
        else if (abs(this->location()->getY() - location.getY())
                 == abs(this->location()->getX() - location.getX())
                 //and the piece is only moving one square in a direction.
                 && abs(this->location()->getY() - location.getY()) == 1
                 //and the end location is occupied..
                 && location.occupied()
                 //..by an opponent's piece
                 && location.occupiedBy()->color().compare(this->color()) != 0)
        {
            //check is true
            check = true;
        }
    }
    //return check.
    return check;
}

void Pawn::display (std::ostream& outStream) const
{
    // Sends the piece's color and symbol into the outStream.
    outStream << _color + "P";
}