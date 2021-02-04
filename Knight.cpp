#include <ostream>
#include "Knight.h"
#include "Piece.h"
#include "Board.h"
#include "Square.h"

Knight::Knight(std::string &color) : Piece(color) {}
Knight::~Knight() {}
bool Knight::canMoveTo(Square &location) const {
    bool legal;
    Board* board = &Board::getBoard();
    int diffX = abs(Piece::location().getX() - location.getX());
    int diffY = abs(Piece::location().getY() - location.getY());
    int diff = abs(diffX - diffY);

    // check for L-shape
    legal = diff == 1;
    if (legal) {
        legal = diffX <= 2 && diffY <= 2;
    }

    return legal;
}

int Knight::value() const {
    return 3;
}
void Knight::display(std::ostream &outStream) const {
    std::string pieceColor = "W";
    if (color() == "black") {
        pieceColor = "B";
    }
    outStream << "| " << pieceColor << "N ";
}