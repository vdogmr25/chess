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
    Pawn(std::string color, bool white);
    
    /**
     * Destruct a Pawn
     */
    ~Pawn();
    
    //Accessors
    
    /**
     * Returns the score value of a Pawn
     *
     * @return the score value of a Pawn as an int.
     */
    int value () const;
    
    /**
     * Checks if the piece can move to a given square
     *
     * @param location The square to test movement to.
     * @return Bool result of the check (true for legal move)
     */
    bool canMoveTo (Square& location) const;
    
    /**
     * Moves the Piece to a specific square.
     *
     * @param byPlayer The player moving the piece.
     * @param to The square to move to.
     */
    virtual bool moveTo (Player& byPlayer, Square& to);
    
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