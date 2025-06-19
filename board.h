#ifndef BOARD_H
#define BOARD_H
#include <string>

    class Board{
        public:
            void printBoard(std::vector<std::vector<Board>>& board) const;
            char emptySquare = ' ';

        private:
            const std::string ROW_WALL = "-------------";
            const std::string COLUMN_WALL = "|";
            const std::string SPACE = " ";
    
    };

#endif