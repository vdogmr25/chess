#ifndef ROOK_H
#define ROOK_H

#include "RestrictedPiece.h"

/// class Rook - 
class Rook : public RestrictedPiece {
public:
    // Constructors
    
    /**
     * Create a Rook with the designated color/
     *
     * @param color Color of the piece.
     */
    Rook(std::string& color);
    
    //No special Destructor needed
    
    //Accessors
    
    /**
     * Checks if the piece can move to a given square
     *
     * @param location The square to test movement to.
     */
    bool canMoveTo (Square& location) const;
    
    /**
     * Returns the score value of a Rook;
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