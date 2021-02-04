#include <iostream>
#include "Piece.h"
#include "Square.h"
#include "Player.h"
#include "Board.h"
#include "King.h"
#include "Game.h"

Piece::Piece(std::string &color) : _color(color), _square(nullptr) {}
Piece::~Piece() {}

bool Piece::moveTo(Player &byPlayer, Square &to) {
    Square& from = location();
    bool legal = canMoveTo(to) && !(to.getY() == location().getY()
            && to.getX() == location().getX());
    // if the move satisfies the piece's move pattern
    if (legal) {
        //check if the destination is occupied, and if so by which player's piece
        if (to.occupied()) {
            std::set<Piece*>& pieces = byPlayer.myPieces();
            legal = pieces.find(&to.occupiedBy()) == pieces.end();
            // if the piece occupying destination is an enemy, capture it
            if (legal) {
                byPlayer.capture(to.occupiedBy());
            }
        }
        // if all move criteria have been met, perform the move
        if (legal) {
            setLocation(&to);
            // if this move puts my King in check, reset; illegal move
            if (byPlayer.myKing().checkForCheck(byPlayer)) {
                setLocation(&from);
                legal = false;
            }
            else {
                // if my pieces can move to opponent's King, announce check
                Player& opponent = Game::opponentOf(byPlayer);
                if (opponent.myKing().checkForCheck(opponent)) {
                    std::cout << "Check" << std::endl;
                }
            }
        }
    }

    return legal;
}


std::string Piece::color() const {
    return _color;
}


void Piece::setLocation(Square *square) {
    /*
     * if piece is on the board,
     * make current square empty,
     * and move to new square
     */
    if (isOnBoard()) {
        Square& current = location();
        current.setOccupier(nullptr);
    }
    square->setOccupier(this);
    _square = square;
}


bool Piece::isOnBoard() const {
    return _square != nullptr;
}


Square& Piece::location() const {
    return *_square;
}

