#ifndef PAWN_H
#define PAWN_H

#include "RestrictedPiece.h"
#include "Piece.h"

/// class Pawn - 
class Pawn : public RestrictedPiece {
public:
    // Constructors
    
    /**
     * Create a Pawn with the designated color
     *
     * @param color Color of the piece.
     */
    Pawn(std::string& color);
    
    //No special Destructor needed
    
    //Accessors
    
    /**
     * Returns the score value of a Pawn;
     */
    int value () const;
    
    /**
     * Checks if the piece can move to a given square
     *
     * @param location The square to test movement to.
     */
    bool canMoveTo (Square& location) const;
    
    /**
     * Displays the piece in the passed stream.
     *
     * @param outStream The stream to display the piece into.
     */
    void display (std::ostream& outStream) const;
private:
    // private attributes
    Piece* _delegate;
};

#endif