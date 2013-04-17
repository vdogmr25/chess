#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#include "Square.h"

/// class Board - 
class Board {
public:
    // Constructors
    
    /**
     * Destructs the squares the board contains as well as itself.
     */
    ~Board();
    
    /**
     * Factory method so the board my be called Board::getBoard() instead of
     * making a new board object and risking multiple boards.
     */
    static Board* getBoard ();
    
    // Accessors
    
    /**
     * Returns the square at a given coordinate.
     *
     * @param x The x coordinate.
     * @param y The y coordinate.
     */
    static Square* squareAt (int x, int y);
    
    /**
     * Checks if a vertical path is clear.
     *
     * @param from The start location.
     * @param to The end location.
     */
    static bool isClearVertical (Square& from, Square& to);
    
    /**
     * Checks if a horizontal path is clear.
     *
     * @param from The start location.
     * @param to The end location.
     */
    static bool isClearHorizontal (Square& from, Square& to);
    
    /**
     * Checks if a diagonal path is clear.
     *
     * @param from The start location.
     * @param to The end location.
     */
    static bool isClearDiagonal (Square& from, Square& to);
    
    /**
     * Prints the board.
     *
     * @param outStream The stream to send display values to.
     */
    void display (std::ostream& outStream);
private:
    /**
     * Called by factory method.  Constructs the board.
     */
    Board ();
    
    //Private attributes
    static const int _DIMENSION = 8;
    static Board* _theBoard;
    static Square* _squares[_DIMENSION][_DIMENSION];
};

#endif