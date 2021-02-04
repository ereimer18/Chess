#include "RestrictedPiece.h"
#include "Piece.h"

RestrictedPiece::RestrictedPiece(std::string &color) : Piece(color), _moved(false)
{}

RestrictedPiece::~RestrictedPiece() {}

bool RestrictedPiece::hasMoved() const {
    return _moved;
}

bool RestrictedPiece::moveTo(Player &byPlayer, Square &to) {
    bool legal = Piece::moveTo(byPlayer, to);
    if (legal) {
        _moved = true;
    }

    return legal;
}