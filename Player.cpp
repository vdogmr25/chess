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
#include "Game.h"

#define LETTER_MAX 'h'
#define LETTER_MIN 'a'
#define NUM_MAX '8'
#define NUM_MIN '1'

Player::Player (std::string name, bool white, Piece& myKing, std::set<Piece*>& myPieces) : _name(name), _white(white), _myKing(myKing), _myPieces(myPieces) {}

bool Player::makeMove()
{
    //Local variables
    std::string from;
    std::string to;
    bool play;
    
    //Check if the player is in check and prompt accordingly.
    if (checkForCheck())
    {
        std::cout << "You are in check." << std::endl;
    }
    
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
                   || from[0] < LETTER_MIN || from [0] > LETTER_MAX || to[0] < LETTER_MIN || to[0] > LETTER_MAX
                   //or improper number values based on ASCII
                   || from[1] < NUM_MIN || from [1] > NUM_MAX || to[1] < NUM_MIN || to[1] > NUM_MAX
                   //or if the starting square is empty
                   || !Board::getBoard()->squareAt((int)from[0] - LETTER_MIN + 1, (int)from[1] - NUM_MIN + 1)->occupied()
                   //or if the move failed
                   || !Board::getBoard()->squareAt((int)from[0] - LETTER_MIN + 1, (int)from[1] - NUM_MIN + 1)->occupiedBy()->moveTo(*this, *(Board::getBoard()->squareAt((int)to[0] - LETTER_MIN + 1, (int)to[1] - NUM_MIN + 1)))))
        {
            //Check if the player is in check and prompt accordingly.
            if (checkForCheck())
            {
                std::cout << "You are in check." << std::endl;
            }
            
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

bool Player::isWhite() const
{
    return _white;
}

int Player::score() const
{
    //start with 0
    int score = 0;
    
    //variables for iteration
    Piece* piece = NULL;
    std::set<Piece*>::iterator it;
    
    //For each of the player's caputred pieces
    for (it = _captured.begin(); it != _captured.end(); it++)
    {
        //add the value to the score.
        piece = *it;
        score += piece->value();
    }
    
    return score;
}

void Player::capture(Piece& aPiece)
{
    _captured.insert(&aPiece);
}

bool Player::checkForCheck()
{
    //Start with clear value
    bool check = false;
    
    //variables for iteration
    Piece* piece = NULL;
    std::set<Piece*>::iterator it;
    
    //For each of the opponent's pieces
    for (it = Game::opponentOf(*this)->myPieces()->begin(); it != Game::opponentOf(*this)->myPieces()->end(); it++)
    {
        //check if it can capture player's king
        piece = *it;
        if (piece->isOnSquare() && piece->canMoveTo(*(myKing()->location())))
        {
            //set false if capture is possible.
            check = true;
        }
    }
    return check;
}

std::set<Piece*>* Player::myPieces()
{
    return &_myPieces;
}

Piece* Player::myKing() const
{
    return &_myKing;
}
