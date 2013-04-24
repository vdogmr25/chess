#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "Square.h"

/// class Bishop - 
class Bishop : public Piece {
public:
    //Constructors
    
    /**
     * Create a Bishop with a designated color
     *
     * @param color The color of the bishop.
     */
    Bishop(std::string color, bool white);
    
    //No special Destructor needed
    
    //Accessors and checks
    
    /**
     * Checks if the piece can move to a given square
     *
     * @param location The square to test movement to.
     */
    bool canMoveTo (Square& location) const;
    
    /**
     * Returns the score value of a Bishop;
     */
    int value () const;
    
    /**
     * Displays the piece in the passed stream.
     *
     * @param outStream The stream to display the piece into.
     */
    void display (std::ostream& outStream) const;
};

#endif