#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include <ostream>
#include "Piece.h"

class Square;

/**
 * A Bishop is a Piece that can move
 * diagonally.
 */
class Bishop : public Piece {
public:
    /**
     * Constructor for an instance of the
     * Bishop class.
     *
     * @param color the color of this Bishop.
     */
    Bishop(std::string& color);

    /**
     * Destructor for an instance of the Bishop
     * class.
     */
    virtual ~Bishop();

    /**
     * Returns true if the Bishop can
     * legally reach the specified
     * Square.
     *
     * A Bishop may move diagonally.
     *
     * @param location the destination of the move.
     * @return true if the Bishop can
     * legally reach the specified Square.
     */
    bool canMoveTo(Square& location) const;

    /**
     * Return the value of a Bishop.
     *
     * A Bishop is worth 3 points.
     *
     * @return the value of a Bishop.
     */
    int value() const;

    /**
     * Displays a visual representation of the Piece.
     *
     * This is a method used in displaying the entire Board.
     *
     * @param outStream the ostream to output to.
     */
    void display(std::ostream& outStream) const;
};


#endif //BISHOP_H
