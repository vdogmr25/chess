#include <iostream>
#include "Game.h"

int main (int argc, const char * argv[])
{
    //Player variable
    Player* currentPlayer;
    
    // intitialize the game.
    Game::initialize();
    
    //Welcome player and list input commands
    std::cout << "Welcome to Chess!" << std::endl
    << "Moves are entered in algebraic notation (eg. a2 a4)." << std::endl
    << "Type 'quit' to quit." << std::endl;
    
    //Get the first player
    currentPlayer = Game::getNextPlayer();
    
    //print the board
    Board::getBoard()->display(std::cout);
    
    //While moves are being made
    while (currentPlayer->makeMove())
    {
        //Print the board
        Board::getBoard()->display(std::cout);
        
        //Grab the other player
        currentPlayer = Game::getNextPlayer();
    }
    return 0;
}

