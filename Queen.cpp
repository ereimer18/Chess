#include <ostream>
#include "Queen.h"
#include "Piece.h"
#include "Board.h"
#include "Square.h"

Queen::Queen(std::string &color) : Piece(color) {}
Queen::~Queen() {}
bool Queen::canMoveTo(Square &location) const {
    bool legal;
    int x = Piece::location().getX();
    int y = Piece::location().getY();
    Board* board = &Board::getBoard();

    if (location.getX() == x) {
        legal = board->isClearVertical(Piece::location(), location);
    }
    else if (location.getY() == y) {
        legal = board->isClearHorizontal(Piece::location(), location);
    }
    else {
        legal = board->isClearDiagonal(Piece::location(), location);
    }

    return legal;
}
int Queen::value() const {
    return 9;
}
void Queen::display(std::ostream &outStream) const {
    std::string pieceColor = "W";
    if (color() == "black") {
        pieceColor = "B";
    }
    outStream << "| " << pieceColor << "Q ";
}