#include <iostream>
#include "Pawn.h"
#include "RestrictedPiece.h"
#include "Queen.h"
#include "Square.h"
#include "Board.h"
#include "Piece.h"

Pawn::Pawn(std::string &color) : RestrictedPiece(color), _delegate((Queen*)0)
{Pawn::setDirection();}
Pawn::~Pawn() {delete _delegate;}

bool Pawn::canMoveTo(Square &location) const {
    bool legal = false;
    Board* board = &Board::getBoard();
    if (_delegate != (Queen*)0) {
        legal = _delegate->canMoveTo(location);
    }
    else {
        int x = Piece::location().getX();
        int y = Piece::location().getY();

        legal = (y - (_direction)) == location.getY() && x == location.getX()
                && !location.occupied();
        if (!hasMoved()) {
            // on the first move, the pawn may move forward two spaces
            legal = ((y - (_direction * 2)) == location.getY()
                    || (y - (_direction)) == location.getY())
                    && x == location.getX() && !location.occupied()
                    && board->isClearVertical(Piece::location(), location);
        }
        // a pawn may capture diagonally forward
        if (!legal) {
            legal = ((y - (_direction)) == location.getY())
                    && (x == location.getX() + 1 || x == location.getX() - 1)
                    && location.occupied();
        }
    }

    return legal;
}

void Pawn::setLocation(Square *square) {
    std::string color = Piece::color();

    /*
     * if the pawn reaches the end of the board,
     * promote it to a Queen.
     */

    if (square->getY() == 0 || square->getY() == 8) {
        _delegate = new Queen(color);
    }
    // if the pawn is promoted, set delegate to this square
    if (_delegate != (Queen*)0) {
        _delegate->setLocation(square);
    }
    Piece::setLocation(square);
}

int Pawn::value() const {
    return 1;
}

void Pawn::display(std::ostream &outStream) const {
    std::string pieceColor = "W";
    if (_delegate != (Queen*)0) {
        _delegate->display(outStream);
    }
    else {
        if (color() == "black") {
            pieceColor = "B";
        }
        outStream << "| " << pieceColor << "P ";
    }
}

void Pawn::setDirection() {
    if (color() == "black") {
        _direction = -1;
    }
    else {
        _direction = 1;
    }
}