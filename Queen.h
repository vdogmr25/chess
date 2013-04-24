#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

/// class Queen - 
class Queen : public Piece {
public:
    // Constructors
    
    /**
     * Create a Queen with the designated color
     *
     * @param color Color of the piece.
     */
    Queen(std::string color, bool white);
    
    //No special Destructor needed
    
    //Acessors
    
    /**
     * Checks if the piece can move to a given square
     *
     * @param location The square to test movement to.
     */
    bool canMoveTo (Square& location) const;
    
    /**
     * Returns the score value of a Queen;
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