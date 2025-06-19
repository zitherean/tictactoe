#include <iostream>
#include <vector>
#include "board.h"

void Board::printBoard(std::vector<std::vector<Board>>& board) const
{
    std::cout << "Overview of the board." << std::endl;
    std::cout << ROW_WALL << std::endl;
    for (unsigned int i = 0; i < board.size(); ++i){
        std::cout << COLUMN_WALL << SPACE;
        for (unsigned int j = 0; j < board.at(i).size(); ++j){
            std::cout << board.at(i).at(j).emptySquare << SPACE << COLUMN_WALL << SPACE;
        }
        std::cout << std::endl << ROW_WALL << std::endl;
    }
    std::cout << std::endl;
}