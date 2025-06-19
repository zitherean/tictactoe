#include <iostream>
#include <algorithm>
#include "moves.h"

void Moves::nextMove(std::vector<Players>& player)
{
    for (unsigned int i = 0; i < player.size(); ++i){
        if (player.at(i).firstTurn == true){
            std::cout << player.at(i).name << " play your next move: ";
            std::cin >> move;   
        }
    }
    std::cout << std::endl;
}

void Moves::errorCheckMove(std::vector<Players>& player)
{
    while (true){        

        std::cout << "Possible moves." << std::endl;
        std::cout << "(1 2 3)" << std::endl;
        std::cout << "(4 5 6)" << std::endl;
        std::cout << "(7 8 9)" << std::endl;
        std::cout << std::endl;
        
        nextMove(player);
        
        if (move < 1 || move > 9){
            std::cout << "Invalid move. Try another move." << std::endl;
        }
        else{
            bool alreadyPlayed = false;
            for (unsigned int i = 0; i < allMoves.size(); ++i){
                if (move == allMoves.at(i)){
                    alreadyPlayed = true;
                    std::cout << "This move has already been played. Try another move." << std::endl;
                    break;
                }
            }
            if (alreadyPlayed == false){
                allMoves.push_back(move);
                for (unsigned int i = 0; i < player.size(); ++i){
                    if (player.at(i).firstTurn == true){
                        player.at(i).playerMoves.insert(move);
                        break;
                    }
                }
                break;
            }
        }
    }
}

void Moves::moveLogic(std::vector<std::vector<Board>>& board, std::vector<Players>& player)
{
    for (unsigned int i = 0; i < board.size(); ++i){
        for (unsigned int j = 0; j < board.at(i).size(); ++j){
            for (unsigned int index = 0; index < player.size(); ++index){
                if (player.at(index).firstTurn == true){
                    player.at(index).firstTurn = false;
                    switch (move){
                        case 1:
                            board.at(0).at(0).emptySquare = player.at(index).charXO;
                            break;
                        case 2:
                            board.at(0).at(1).emptySquare = player.at(index).charXO;
                            break;
                        case 3:
                            board.at(0).at(2).emptySquare = player.at(index).charXO;
                            break;
                        case 4:
                            board.at(1).at(0).emptySquare = player.at(index).charXO;
                            break;
                        case 5:
                            board.at(1).at(1).emptySquare = player.at(index).charXO;
                            break;
                        case 6:
                            board.at(1).at(2).emptySquare = player.at(index).charXO;
                            break;
                        case 7:
                            board.at(2).at(0).emptySquare = player.at(index).charXO;
                            break;
                        case 8:
                            board.at(2).at(1).emptySquare = player.at(index).charXO;
                            break;
                        case 9:
                            board.at(2).at(2).emptySquare = player.at(index).charXO;
                            break;
                        default:
                            board.at(i).at(j).emptySquare = ' ';
                    }
                }
                else{
                    player.at(index).firstTurn = true;
                }
            }        
        }
    }
}

bool operator<=(const std::set<int>& leftSide, const std::set<int>& rightSide)
{
    for (auto it = leftSide.begin(); it != leftSide.end(); ++it){
        const auto& element = *it; 
            if (rightSide.find(element) == rightSide.end()){
                return false;
            }
    }
    return true;
}

bool Moves::winMove(std::vector<Players>& player)
{
    for (unsigned int i = 0; i < player.size(); ++i){
        if (WIN_ROW_ONE <= player.at(i).playerMoves || WIN_ROW_TWO <= player.at(i).playerMoves || WIN_ROW_THREE <= player.at(i).playerMoves || WIN_COLUMN_ONE <= player.at(i).playerMoves || WIN_COLUMN_TWO <= player.at(i).playerMoves || WIN_COLUMN_THREE <= player.at(i).playerMoves || WIN_DIAGONAL_ONE <= player.at(i).playerMoves || WIN_DIAGONAL_TWO <= player.at(i).playerMoves){
            return true;
        }
    }

    return false;
}