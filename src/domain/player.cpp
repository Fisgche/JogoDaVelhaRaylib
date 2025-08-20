#include "player.h"

using namespace tictactoe;

int player::getType() {
    return type;
}
void player::setType(int type) {
    if (type == 1 || type == 2) {
        this->type = type;
    }
    else {
        std::cerr << "Invalid player type. Use 1 for X or 2 for O." << std::endl;
    }
}