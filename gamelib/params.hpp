#pragma once
#include <string>

struct GameParams {
    int size;
    std::string player1;
    std::string player2;
};

GameParams loadParams();
void saveParams(const GameParams& params);
void setParameters();
