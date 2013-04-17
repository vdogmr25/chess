//
//  Player.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include <algorithm>
#include "Player.h"
#include "Board.h"

Player::Player (std::string name, Piece& myKing, std::set<Piece*>& myPieces) : _name(name), _myKing(myKing), _myPieces(myPieces) {}

Player::~Player()
{
    
}

bool Player::makeMove()
{
    //Local variables
    std::string from;
    std::string to;
    bool play;
    
    //prompt player for input.
    std::cout << _name << ", make your move: ";
    
    //get input
    std::cin >> from;
    
    //set "from" to lowercase
    std::transform(from.begin(), from.end(), from.begin(), ::tolower);
    
    //If player doesn't want to quit
    if (from.compare("quit"))
    {
        //get the "to" square value
        std::cin >> to;
        
        //set "to" to lowercase
        std::transform(to.begin(), to.end(), to.begin(), ::tolower);
        
        //Keep trying to move
        play = true;
    
        //error trap if keep playing
        while (play
               //improper input based on size of input
               && (from.length() != 2 || to.length() != 2
               //or improper letter values based on ASCII
               || from[0] < 97 || from [0] > 104 || to[0] < 97 || to[0] > 104
               //or improper number values based on ASCII
               || from[1] < 49 || from [1] > 56 || to[1] < 49 || to[1] > 56
               //or if the starting square is empty
               || !Board::getBoard()->squareAt((int)from[0]-96, (int)from[1]-48)->occupied()
               //or if the move failed
               || !Board::getBoard()->squareAt((int)from[0]-96, (int)from[1]-48)->occupiedBy()->moveTo(*this, *(Board::getBoard()->squareAt((int)to[0]-96, (int)to[1]-48)))))
        {
            //inform user of bad input and prompt again.
            std::cout << "Invalid move." << std::endl << _name << ", make your move: ";
        
            //get input
            std::cin >> from;
            
            //set "from" to lowercase
            std::transform(from.begin(), from.end(), from.begin(), ::tolower);
            
            //Keep going if not quitting
            if (from.compare("quit"))
            {
                //get the "to" square value
                std::cin >> to;
            }
            //If player wants to quit
            else
            {
                //quit the game
                play = false;
            }
        
            //set to to lowercase
            std::transform(to.begin(), to.end(), to.begin(), ::tolower);
        }
    }
    //If player wants to quit
    else
    {
        //quit the game
        play = false;
    }
    
    //return the result.
    return play;
}

std::string Player::getName() const
{
    return _name;
}

int Player::score() const
{
    return 0;
}

void Player::capture(Piece& aPiece)
{
    aPiece.setLocation(NULL);
    _captured.insert(&aPiece);
}

std::set<Piece*>* Player::myPieces() const
{
    return NULL;
}

Piece* Player::myKing() const
{
    return &_myKing;
}
