#ifndef MOVES_H
#define MOVES_H
#include <iostream>
#include <vector>
#include <set>
#include "board.h"
#include "players.h"

    class Moves{
        public:
            void nextMove(std::vector<Players>& player);
            void errorCheckMove(std::vector<Players>& player);
            void moveLogic(std::vector<std::vector<Board>>& board, std::vector<Players>& player);
            bool winMove(std::vector<Players>& player);
            int move;
            std::vector<int> allMoves;

        private:
            const std::set<int> WIN_ROW_ONE = {1, 2, 3}; 
            const std::set<int> WIN_ROW_TWO = {4, 5, 6};
            const std::set<int> WIN_ROW_THREE = {7, 8, 9};  
            const std::set<int> WIN_COLUMN_ONE = {1, 4, 7};
            const std::set<int> WIN_COLUMN_TWO = {2, 5, 8};
            const std::set<int> WIN_COLUMN_THREE = {3, 6, 9};
            const std::set<int> WIN_DIAGONAL_ONE = {1, 5, 9};
            const std::set<int> WIN_DIAGONAL_TWO = {3, 5, 7};
    };

#endif