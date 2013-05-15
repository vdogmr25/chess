#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include <set>

/// class Game - 
class Game {  
public:
    
    // Constructors
    
    /**
     * Destructs the Pieces and the players the game contains.
     */
    ~Game();
    
    /**
     * Singleton initialize call.
     */
    static void initialize ();
    
    //Accessors
    
    /**
     * Returns a pointer to the next player.
     *
     * @return a Player pointer to the next player.
     */
    static Player* getNextPlayer ();
    
    /**
     * Returns the opponent of a given player.
     *
     * @param player Player to pull opponent for.
     * @return a Player pointer to the oppenent of the given player.
     */
    static Player* opponentOf (Player& player);
    
private:
    // Private Attributes
    static Game* _theGame;
    static Board* _theBoard;
    static Player* nextTurn;
    static Player* _whitePlayer;
    static Player* _blackPlayer;
    static Player* _nextPlayer;
    static std::set<Piece*> _whitePieces;
    static std::set<Piece*> _blackPieces;
};

#endif