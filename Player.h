#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>

#include "Piece.h"

/// class Player - 
class Player {
  // Attributes
private:
    std::string _name;
    bool _white;
    Piece& _myKing;
    std::set<Piece*> _myPieces;
    std::set<Piece*> _captured;
  // Operations
public:
    /**
     * Constructs a player with a name, white value, king, and set of pieces
     *
     * @param name The player's name
     * @param white True if the player is white
     * @param myKing A reference to that player's king
     * @param myPieces A reference to that player's set of pieces
     */
    Player (std::string name, bool white, Piece& myKing, std::set<Piece*>& myPieces);
    
    /**
     * Calls for a user to make a move
     *
     * @return Bool true if the game continues.
     */
    bool makeMove ();
    
    /**
     * Gets the player's name
     *
     * @return A string of the player's name
     */
    std::string getName () const;
    
    /**
     * Returns if the player is white
     *
     * @return Bool true for white
     */
    bool isWhite () const;
    
    /**
     * Returns the player's score
     *
     * @return Int the player's score
     */
    int score () const;
    
    /**
     * Captures a piece
     *
     * @param aPiece A reference to the piece to capture.
     */
    void capture (Piece& aPiece);
    
    /**
     * Returns if the player is in check
     *
     * @return Bool true for in check
     */
    bool checkForCheck ();
    
    /**
     * Returns a pointer the player's set of pieces
     *
     * @return a pointer the player's set of pieces
     */
    std::set<Piece*>* myPieces();
    
    /**
     * Returns a pointer the player's king
     *
     * @return a pointer the player's king
     */
    Piece* myKing () const;
};

#endif