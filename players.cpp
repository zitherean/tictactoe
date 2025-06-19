#include <iostream>
#include <vector>
#include "players.h"


void Players::createPlayers(std::vector<Players>& player)
{
    std::cout << "Enter the names of " << MAX_PLAYERS << " players." << std::endl;

    player.resize(MAX_PLAYERS);

    for (int i = 0; i < MAX_PLAYERS; ++i){
        std::cout << "Enter Player " << i + 1 << " name: ";
        std::cin >> player.at(i).name;
        player.at(i).playerNum = i + 1;
    }
    std::cout << std::endl;
}

void Players::startTurn(std::vector<Players>& player)
{
    for (unsigned int i = 0; i < player.size(); ++i){
        if (player.at(i).playerNum == 1){
            player.at(i).firstTurn = true;
            player.at(i).charXO = 'x';
        }
        else if (player.at(i).playerNum == 2){
            player.at(i).firstTurn = false;
            player.at(i).charXO = 'o';
        }
        else{
            player.at(i).firstTurn = false;
            player.at(i).charXO = ' ';
        }
    }
}