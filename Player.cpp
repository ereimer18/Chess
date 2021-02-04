#include <iostream>
#include <string>
#include <stdexcept>
#include "Player.h"
#include "Square.h"
#include "Board.h"
#include "Piece.h"

Player::Player(std::string &name) : _name(name), _myPieces(new std::set<Piece*>),
_captured(new std::set<Piece*>), _score(0), _myKing((King*) 0) {}
Player::~Player() {}

void Player::setPieces(std::set<Piece *> &pieces) {
    _myPieces = &pieces;
}

void Player::setKing(King &king) {
    _myKing = &king;
}

bool Player::makeMove() {
    bool legalMove = false;
    bool continueGame = true;
    Board* board = &Board::getBoard();

    while (!legalMove && continueGame) {
        std::cout << getName() << ">";
        // get input and test if its valid
        char locationChars[99999];
        std::cin.getline (locationChars, 99999);
        std::string coordinates(locationChars);
        continueGame = coordinates != "q";
        if (continueGame) {
            // filter input
            std::string coordinateFrom = coordinates.substr(0,2);
            std::string coordinateTo = coordinates.substr(3, 2);
            // check if squares are in range
            try {
                Square& from = board->squareAt(coordinateFrom);
                Square& to = board->squareAt(coordinateTo);
                if (!from.occupied()) {
                    std::cerr << "No piece at given square" << std::endl;
                }
                Piece& piece = from.occupiedBy();
                // if the piece is an opponent's piece, illegal move
                if (myPieces().find(&piece) == myPieces().end()) {
                    std::cerr << "Piece does not belong to "
                    << getName()
                    << std::endl;
                }
                else {
                    legalMove = piece.moveTo(*this, to);
                }

                if (!legalMove) {
                    std::cerr << "Illegal Move: try again" << std::endl;
                }
            }
            catch (std::out_of_range& e) {
                std::cerr << "Square out of range" << std::endl;
            }
            catch (std::invalid_argument& e) {
                std::cerr << "Bad Input" << std::endl;
                std::cout << "Usage: [a-h][1-8] [a-h][1-8]" << std::endl;
            }
        }
    }
    board->display(std::cout);

    return continueGame;
}

std::string& Player::getName() const {
    return _name;
}

int Player::score() const {
    int score = 0;

    return 0;
}

void Player::capture(Piece &aPiece) {
    _score += aPiece.value();
    _captured->insert(&aPiece);
}

std::set<Piece*>& Player::myPieces() const {
    return *_myPieces;
}

King& Player::myKing() const {
    return *_myKing;
}

