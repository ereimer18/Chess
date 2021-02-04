#include <iostream>
#include "King.h"
#include "RestrictedPiece.h"
#include "Piece.h"
#include "Board.h"
#include "Square.h"
#include "Game.h"
#include "Player.h"

King::King(std::string &color) : RestrictedPiece(color) {}
King::~King() {}
bool King::canMoveTo(Square &location) const {
    bool legal;
    Board* board = &Board::getBoard();
    int diffX = Piece::location().getX() - location.getX();
    int diffY = Piece::location().getY() - location.getY();

    // check if target is at most one space away
    legal = diffX >= -1 && diffX <= 1;
    if (legal) {
        legal = diffY >= -1 && diffY <= 1;
    }

    return legal;
}

int King::value() const {
    return 10000;
}

void King::display(std::ostream &outStream) const {
    std::string pieceColor = "W";
    if (color() == "black") {
        pieceColor = "B";
    }
    outStream << "| " << pieceColor << "K ";
}

bool King::checkForCheck(Player &player) const {
    bool inCheck = false;
    Player& opponent = Game::opponentOf(player);

    for (Piece* piece : opponent.myPieces()) {
        if (piece->isOnBoard() && piece->canMoveTo(Piece::location())) {
            inCheck = true;
        }
    }

    return inCheck;
}