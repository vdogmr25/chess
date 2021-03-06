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
    Piece(std::string color, bool white);
    
    //No special Destructor needed
    
    // Mutators
    
    /**
     * Moves the Piece to a specific square.
     *
     * @param byPlayer The player moving the piece.
     * @param to The square to move to.
     * @return Bool result of the move (true for legal move)
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
     * Returns the score value of a Piece
     *
     * @return the score value of a Piece as an int.
     */
    virtual int value () const = 0;
    
    /**
     * Returns the color of a piece.
     *
     * @return String color value of the piece.
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
     * @return Bool result of the check (true for legal move)
     */
    virtual bool canMoveTo (Square& location) const = 0;
    
    /**
     * Returns if a piece is on a square.
     *
     * @return Bool true if on a square
     */
    bool isOnSquare () const;
    
    /**
     * Returns if a piece is white.
     *
     * @return Bool true for white
     */
    bool isWhite () const;
    
    /**
     * Returns a pointer to the square the piece is on.
     *
     * @return a pointer to the square the piece is on
     */
    Square* location () const;
private:
    // private attributes
    Square* _occupies;
    std::string _color;
    bool _white;
};

#endif