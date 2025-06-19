#ifndef PLAYERS_H
#define PLAYERS_H
#include <vector>
#include <string>
#include <set>

    class Players{
        public:
            void createPlayers(std::vector<Players>& player);
            void startTurn(std::vector<Players>& player);
            std::string name;
            int playerNum;
            bool firstTurn = false;
            char charXO;
            std::set<int> playerMoves;
            
        private:
            const int MAX_PLAYERS = 2;
    };

#endif