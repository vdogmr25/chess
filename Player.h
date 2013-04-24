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
    Player (std::string name, bool white, Piece& myKing, std::set<Piece*>& myPieces);
    ~Player();
    bool makeMove ();
    std::string getName () const;
    bool isWhite () const;
    int score () const;
    void capture (Piece& aPiece);
    bool checkForCheck ();
    std::set<Piece*>* myPieces();
    Piece* myKing () const;
};

#endif