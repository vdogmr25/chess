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
    Piece& _myKing;
    std::set<Piece*> _myPieces;
    std::set<Piece*> _captured;
  // Operations
public:
    Player (std::string name, Piece& myKing, std::set<Piece*>& myPieces);
    ~Player();
    bool makeMove ();
    std::string getName () const;
    int score () const;
    void capture (Piece& aPiece);
    std::set<Piece*>* myPieces () const;
    Piece* myKing () const;
};

#endif