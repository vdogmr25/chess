#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include "Square.h"
#include "Board.h"

class Player;

/// class Piece - 
class Piece {
public:
    // Constructors
    
    /**
     * Create a Piece with the designated color
     *
     * @param color Color of the piece.
     */
    Piece(std::string& color);
    
    //No special Destructor needed
    
    // Mutators
    
    /**
     * Moves the Piece to a specific square.
     *
     * @param byPlayer The player moving the piece.
     * @param to The square to move to.
     */
    virtual bool moveTo (Player& byPlayer, Square& to);
    
    /**
     * Sets the location of a Piece.
     *
     * @param square Square to set location to.
     */
    void setLocation (Square* square);
    
    // Accessors
    
    /**
     * Returns the score value of a Piece;
     */
    virtual int value () const = 0;
    
    /**
     * Returns the color of a piece.
     */
    std::string color () const;
    
    /**
     * Displays the piece in the passed stream.
     *
     * @param outStream The stream to display the piece into.
     */
    virtual void display (std::ostream& outStream) const = 0;
    
    /**
     * Checks if the piece can move to a given square
     *
     * @param location The square to test movement to.
     */
    virtual bool canMoveTo (Square& location) const = 0;
    
    /**
     * Returns if a piece is on a square.
     */
    bool isOnSquare () const;
    
    /**
     * Returns a pointer to the square the piece is on.
     */
    Square* location () const;
protected:
    // protected attributes
    std::string _color;
private:
    // private attributes
    Square* _occupies;
};

#endif