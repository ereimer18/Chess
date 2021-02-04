#include <iostream>
#include <stdexcept>
#include "Board.h"
#include "Square.h"
#include "Piece.h"

Board::Board() {
    for (int i = 0; i < _DIMENSION; i++) {
        for (int j = 0; j < _DIMENSION; j++) {
            _squares[j][i] = new Square(i,j);
        }
    }
}

Board::~Board() {
    for (int i = 0; i < _DIMENSION; i++) {
        for (int j = 0; j < _DIMENSION; j++) {
            delete _squares[j][i];
        }
    }
}

Board& Board::getBoard() {
    return *_theBoard;
}

Square& Board::squareAt(int x, int y) const {
    if (x >= _DIMENSION || y >= _DIMENSION || x < 0 || y < 0) {
        throw std::out_of_range("No such Square");
    }
    return *_squares[y][x];
}

Square& Board::squareAt(std::string location) const {
    char xChar = location.at(0);
    std::string yChar = location.substr(1,1);
    int x = xChar - 'a';
    int y = _DIMENSION - std::stoi (yChar, nullptr);
    return squareAt(x,y);
}

int Board::distanceBetween(Square &from, Square &to) const {
    return 0;
}

bool Board::isClearVertical(Square &from, Square &to) const {
    // return false if horizontal x positions are not the same
    bool isClear = from.getX() == to.getX();

    if (isClear) {
        int dif;
        int x = from.getX();
        int y = from.getY();
        int yMax = to.getY();
        int yMin = from.getY();
        if (from.getY() > to.getY()) {
            yMax = from.getY();
            yMin = to.getY();
        }
        dif = yMax - yMin;

        for (int i = 0; i < dif - 1; i++) {
            if (to.getY() < from.getY()) {
                y--;
            }
            else {
                y++;
            }
            if (squareAt(x, y).occupied()) {
                isClear = false;
            }
        }
    }
    return isClear;
}

bool Board::isClearHorizontal(Square &from, Square &to) const {
    // return false if vertical y positions are not the same
    bool isClear = from.getY() == to.getY();
    if (isClear) {
        int dif;
        int x = from.getX();
        int y = from.getY();
        int xMax = to.getX();
        int xMin = from.getX();
        if (from.getX() > to.getX()) {
            xMax = from.getX();
            xMin = to.getX();
        }
        dif = xMax - xMin;

        for (int i = 0; i < dif - 1; i++) {
            if (to.getX() < from.getX()) {
                x--;
            }
            else {
                x++;
            }
            if (squareAt(x, y).occupied()) {
                isClear = false;
            }
        }
    }

    return isClear;
}

bool Board::isClearDiagonal(Square &from, Square &to) const {
    bool isClear;
    int x;
    int y;
    int diff;
    int xMax = to.getX();
    int xMin = from.getX();
    int yMax = to.getY();
    int yMin = from.getY();

    if (from.getX() > to.getX()) {
        xMax = from.getX();
        xMin = to.getX();
    }
    if (from.getY() > to.getY()) {
        yMax = from.getY();
        yMin = to.getY();
    }
    // check if the suggested path is a perfect diagonal
    isClear = (xMax - xMin) == (yMax - yMin);
    if (isClear) {
        diff = xMax - xMin;
        // determine orientation of path & get starting x and y
        if (from.getX() < to.getX()) {
            x = from.getX();
            y = from.getY();
        }
        else {
            x = to.getX();
            y = to.getY();
        }
        // iterate over the diagonal
        for (int i = 0; i < diff - 1; i++) {
            if ((to.getY() < from.getY() && from.getX() < to.getX()) ||
                    (from.getY() < to.getY() && to.getX() < from.getX())) {
                y--;
            }
            else {
                y++;
            }
            x++;
            if (squareAt(x, y).occupied()) {
                isClear = false;
            }
        }
    }
    return isClear;
}

void Board::display(std::ostream &outStream) const {
    outStream << "     a    b    c    d    e    f    g    h    " << std::endl;
    outStream << "  -----------------------------------------" << std::endl;
    for (int i = 0; i < _DIMENSION; i++) {
        outStream << _DIMENSION - i << " ";
        for (int j = 0; j < _DIMENSION; j++) {
            if (squareAt(j,i).occupied()) {
                Piece* piece = &(squareAt(j,i).occupiedBy());
                piece->display(outStream);
            }
            else {
                outStream << "|    ";
            }
        }
        outStream << "| " << _DIMENSION - i << std::endl;
        outStream << "  -----------------------------------------" << std::endl;
    }
    outStream << "     a    b    c    d    e    f    g    h    " << std::endl;
}

Board* Board::_theBoard = new Board();



