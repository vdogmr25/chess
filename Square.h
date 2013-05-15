#ifndef SQUARE_H
#define SQUARE_H

class Piece;

/// class Square - 
class Square {
public:
    
    // Constructors
    
    /**
     * Constructs a square with a given location
     *
     * @param x The x location of the square.
     * @param y The y location of the square.
     */
    Square(int x, int y);
    
    //No special destructor needed.
    
    // Mutators
    
    /**
     * Sets the occupant of the square
     * 
     * @param piece The new occupant.
     */
    void setOccupier (Piece* piece);
    
    // Accessors
    
    /**
     * Gets the x coordinate for the square
     *
     * @return the int value of the x location
     */
    int getX ();
    
    /**
     * Gets the y coordinate for the square
     *
     * @return the int value of the y location
     */
    int getY ();
    
    /**
     * Returns true if the square is occupied.
     *
     * @return Bool true it the square is occupied.
     */
    bool occupied ();
    
    /**
     * Returns the piece the square is occupied by.
     *
     * @return a pointer the the piece that occupies the square
     */
    Piece* occupiedBy ();
private:
    //private attributes
    int _x;
    int _y;
    Piece* _occupant;
};

#endif