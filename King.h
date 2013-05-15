#ifndef KING_H
#define KING_H

#include "RestrictedPiece.h"
#include "Player.h"

/// class King - 
class King : public RestrictedPiece {
public:
    // Constructors
    
    /**
     * Create a King with the designated color.
     *
     * @param color Color of the piece.
     */
    King(std::string color, bool white);
    
    //No special Destructor needed
    
    //Accessors
    
    /**
     * Checks if the piece can move to a given square
     *
     * @param location The square to test movement to.
     * @return Bool result of the check (true for legal move)
     */
    bool canMoveTo (Square& location) const;
    
    /**
     * Returns the score value of a King.
     *
     * @return the score value of a King as an int.
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