#include <ostream>
#include "Bishop.h"
#include "Piece.h"
#include "Board.h"
#include "Square.h"

Bishop::Bishop(std::string &color) : Piece(color) {}
Bishop::~Bishop() {}
bool Bishop::canMoveTo(Square &location) const {
    bool legal;
    int x = Piece::location().getX();
    int y = Piece::location().getY();
    Board* board = &Board::getBoard();

    legal = board->isClearDiagonal(Piece::location(), location);

    return legal;
}
int Bishop::value() const {
    return 3;
}
void Bishop::display(std::ostream &outStream) const {
    std::string pieceColor = "W";
    if (color() == "black") {
        pieceColor = "B";
    }
    outStream << "| " << pieceColor << "B ";
}