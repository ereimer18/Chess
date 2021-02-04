#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Player.h"

/**
 * Main class to run the game logic.
 *
 * Starts by initializing a board,
 * setting up the board via Game,
 * and displaying the board.
 *
 * @param argc the number of command-line
 * given arguments.
 * @param argv the command-line given arguments.
 * @return 0 if successful.
 */
int main(int argc, char *argv[]) {

    Game::initialize();
    Board* board = &Board::getBoard();
    board->display(std::cout);
    std::cout << "Quit: q" << std::endl;
    bool continueGame = true;

    // play game until a player wins or chooses to quit.
    while (continueGame) {
        continueGame = Game::getNextPlayer().makeMove();
    }

    return 0;
}
