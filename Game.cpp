//
//  Game.cpp
//  Chess
//
//  Created by Christian Bodnar on 3/18/13.
//  Copyright (c) 2013 George Fox University. All rights reserved.
//

#include "Game.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

#define WHITE "White"
#define BLACK "Black"

std::set<Piece*> Game::_whitePieces;
std::set<Piece*> Game::_blackPieces;
Player* Game::_whitePlayer;
Player* Game::_blackPlayer;
Player* Game::_nextPlayer;

Game::~Game()
{    
    //Delete the white pieces.
    std::set<Piece*>::iterator it;
    for (it = _whitePieces.begin(); it != _whitePieces.end(); it++)
    {
        delete *(it);
    }
    _whitePieces.clear();
    
    //Delete the black pieces
    for (it = _blackPieces.begin(); it != _blackPieces.end(); it++)
    {
        delete *(it);
    }
    _blackPieces.clear();
    
    delete _whitePlayer;
    delete _blackPlayer;
}

Player* Game::getNextPlayer()
{
    _nextPlayer = opponentOf(*_nextPlayer);
    return _nextPlayer;
}

void Game::initialize()
{
    //variables to help with set up.
    Piece* newPiece = NULL;
    
    //start with white pieces
    bool isWhite = true;
    
    //Build 8 white pawns
    for (int i = 1; i <= 8; i++)
    {
        // Build a new Pawn.
        newPiece = new Pawn(WHITE, isWhite);
        
        // Set it on the board.
        newPiece->setLocation(Board::getBoard()->squareAt(i,2));
        Board::getBoard()->squareAt(i, 2)->setOccupier(newPiece);
        
        //  Add it to white pieces.
        _whitePieces.insert(newPiece);
    }
    
    // Build a new Rook
    newPiece = new Rook(WHITE, isWhite);
    
    // Set it on the board.
    newPiece->setLocation(Board::getBoard()->squareAt(1,1));
    Board::getBoard()->squareAt(1, 1)->setOccupier(newPiece);
    
    // Add it to white pieces
    _whitePieces.insert(newPiece);
    
    // Build a new Rook
    newPiece = new Rook(WHITE, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(8,1));
    Board::getBoard()->squareAt(8, 1)->setOccupier(newPiece);
    
    // Add it to white pieces
    _whitePieces.insert(newPiece);
    
    // Builld a new knight
    newPiece = new Knight(WHITE, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(2,1));
    Board::getBoard()->squareAt(2, 1)->setOccupier(newPiece);
    
    // Add it to white pieces
    _whitePieces.insert(newPiece);
    
    // Builld a new knight
    newPiece = new Knight(WHITE, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(7,1));
    Board::getBoard()->squareAt(7, 1)->setOccupier(newPiece);
    
    // Add it to white pieces
    _whitePieces.insert(newPiece);
    
    // Build a new bishop
    newPiece = new Bishop(WHITE, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(3,1));
    Board::getBoard()->squareAt(3, 1)->setOccupier(newPiece);
    
    // Add it to white pieces
    _whitePieces.insert(newPiece);
    
    // Build a new bishop
    newPiece = new Bishop(WHITE, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(6,1));
    Board::getBoard()->squareAt(6, 1)->setOccupier(newPiece);
    
    // Add it to white pieces
    _whitePieces.insert(newPiece);
    
    // Build a new queen
    newPiece = new Queen(WHITE, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(4,1));
    Board::getBoard()->squareAt(4, 1)->setOccupier(newPiece);
    
    // Add it to white pieces
    _whitePieces.insert(newPiece);
    
    // Build a new king
    newPiece = new King(WHITE, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(5,1));
    Board::getBoard()->squareAt(5, 1)->setOccupier(newPiece);
    
    // Add it to white pieces
    _whitePieces.insert(newPiece);
    
    //create the white player
    _whitePlayer = new Player(WHITE, isWhite, *newPiece, _whitePieces);
    
    //set to black pieces
    isWhite = false;
    
    //Build 8 black pawns
    for (int i = 1; i <= 8; i++)
    {
        // Build a new Pawn.
        newPiece = new Pawn(BLACK, isWhite);
        
        // Set it on the Board
        newPiece->setLocation(Board::getBoard()->squareAt(i,7));
        Board::getBoard()->squareAt(i, 7)->setOccupier(newPiece);
        
        // Add it to black pieces.
        _blackPieces.insert(newPiece);
    }
    
    // Build a new Rook
    newPiece = new Rook(BLACK, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(1,8));
    Board::getBoard()->squareAt(1, 8)->setOccupier(newPiece);
    
    // Add it to black pieces.
    _blackPieces.insert(newPiece);
    
    // Build a new Rook
    newPiece = new Rook(BLACK, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(8,8));
    Board::getBoard()->squareAt(8, 8)->setOccupier(newPiece);
    
    // Add it to black pieces.
    _blackPieces.insert(newPiece);
    
    //Build a new Knight
    newPiece = new Knight(BLACK, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(2,8));
    Board::getBoard()->squareAt(2, 8)->setOccupier(newPiece);
    
    // Add it to black pieces.
    _blackPieces.insert(newPiece);
    
    //Build a new Knight
    newPiece = new Knight(BLACK, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(7,8));
    Board::getBoard()->squareAt(7, 8)->setOccupier(newPiece);
    
    // Add it to black pieces.
    _blackPieces.insert(newPiece);
    
    // Build a new Bishop
    newPiece = new Bishop(BLACK, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(3,8));
    Board::getBoard()->squareAt(3, 8)->setOccupier(newPiece);
    
    // Add it to black pieces.
    _blackPieces.insert(newPiece);
    
    // Build a new Bishop
    newPiece = new Bishop(BLACK, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(6,8));
    Board::getBoard()->squareAt(6, 8)->setOccupier(newPiece);
    
    // Add it to black pieces.
    _blackPieces.insert(newPiece);
    
    // Build a new Queen
    newPiece = new Queen(BLACK, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(4,8));
    Board::getBoard()->squareAt(4, 8)->setOccupier(newPiece);
    
    // Add it to black pieces.
    _blackPieces.insert(newPiece);
    
    // Build a new King
    newPiece = new King(BLACK, isWhite);
    
    // Set it on the Board
    newPiece->setLocation(Board::getBoard()->squareAt(5,8));
    Board::getBoard()->squareAt(5, 8)->setOccupier(newPiece);
    
    // Add it to black pieces.
    _blackPieces.insert(newPiece);
    
    //create the black player
    _blackPlayer = new Player(BLACK, isWhite, *newPiece, _blackPieces);
    
    //set the _next player to black so main will call white first
    _nextPlayer = _blackPlayer;
}

Player* Game::opponentOf(Player& player)
{
    //A player to return
    Player* toReturn;
    
    //If current player is the white player
    if (player.getName().compare(_whitePlayer->getName()) == 0)
    {
        //set the player to return to the black player
        toReturn = _blackPlayer;
    }
    //If the current player is the black player
    else
    {
        //set the player to return to the white player
        toReturn = _whitePlayer;
    }
    //return the opponent.
    return toReturn;
}