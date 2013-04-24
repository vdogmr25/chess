#ifndef RESTRICTEDPIECE_H
#define RESTRICTEDPIECE_H

#include "Piece.h"
#include "Player.h"

/// class RestrictedPiece - 
class RestrictedPiece : public Piece{
public:
    
    //Constructors
    
    /**
     * Constructs a restricted pieces with a designated color 
     *
     * @param color The color of the piece.
     */
    RestrictedPiece(std::string color, bool white);
    
    //No special Destructor needed
    
    //Mutators
    
    /**
     * Moves the Piece to a specific square.
     *
     * @param byPlayer The player moving the piece.
     * @param to The square to move to.
     */
    virtual bool moveTo (Player& byPlayer, Square& to);
protected:
    //Protected attributes
    bool hasMoved() const;
private:
    //Private attributes
    bool _moved;
};

#endif