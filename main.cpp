#include <iostream>
#include <vector>
#include "board.h"
#include "players.h"
#include "moves.h"

int main()
{
    const int ROW_SIZE = 3;
    const int COLUMN_SIZE = 3;
    const int NUM_ROUNDS = 9;

    Board game;
    Players players;
    Moves moves;
    std::vector<std::vector<Board>> board(ROW_SIZE, std::vector<Board> (COLUMN_SIZE));
    std::vector<Players> player;

    players.createPlayers(player);
    players.startTurn(player);
    game.printBoard(board);

    for (int round = 1; round <= NUM_ROUNDS; ++round){
        moves.errorCheckMove(player);
        moves.moveLogic(board, player);
        game.printBoard(board);
        for (unsigned int i = 0; i < player.size(); ++i){
            if (moves.winMove(player) == true){
                std::cout << "Congratulations " << player.at(i).name << " wins!!!" << std::endl;
                return 0;
            }
        } 
    }

    if (moves.winMove(player) == false){
        std::cout << "The game ended in a draw." << std::endl;
    }
    
    return 0;
}