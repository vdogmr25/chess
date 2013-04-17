#ifndef KING_H
#define KING_H

#include "RestrictedPiece.h"
#include "Player.h"

/// class King - 
class King : public RestrictedPiece {
public:
    // Constructors
    
    /**
     * Create a King with the designated color/
     *
     * @param color Color of the piece.
     */
    King(std::string& color);
    
    //No special Destructor needed
    
    //Accessors
    
    /**
     * Checks if the piece can move to a given square
     *
     * @param location The square to test movement to.
     */
    bool canMoveTo (Square& location) const;
    
    /**
     * Returns the score value of a King;
     */
    int value () const;
    
    /**
     * Displays the piece in the passed stream.
     *
     * @param outStream The stream to display the piece into.
     */
    void display(std::ostream& outStream) const;
};

#endif