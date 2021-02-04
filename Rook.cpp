#include <ostream>
#include "Rook.h"
#include "RestrictedPiece.h"
#include "Piece.h"
#include "Board.h"
#include "Square.h"

Rook::Rook(std::string &color) : RestrictedPiece(color) {}
Rook::~Rook() {}
bool Rook::canMoveTo(Square &location) const {
    bool legal;
    int x = Piece::location().getX();
    int y = Piece::location().getY();
    Board* board = &Board::getBoard();

    if (location.getX() == x) {
        legal = board->isClearVertical(Piece::location(), location);
    }
    else {
        legal = board->isClearHorizontal(Piece::location(), location);
    }

    return legal;
}
int Rook::value() const {
    return 5;
}
void Rook::display(std::ostream &outStream) const {
    std::string pieceColor = "W";
    if (color() == "black") {
        pieceColor = "B";
    }
    outStream << "| " << pieceColor << "R ";
}