#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <ostream>
#include <map>

class Square;

/**
 * A singleton Board that is composed of Squares
 * that Pieces move to and from.
 */
class Board {
public:
    /**
     * A destructor for the Board.
     */
    virtual ~Board();

    /**
     * Returns the Board.
     *
     * Returns the single instance
     * of the Board class. This
     * method is the only way to
     * access the Board.
     * @return the Board.
     */
    static Board& getBoard();

    /**
     * Returns the Square at the given
     * coordinates on the Board.
     *
     * An exception is thrown if the
     * x or y are out of bounds.
     *
     * @param x the horizontal x position.
     * @param y the vertical y position.
     * @return the Square at the given
     * coordinates on the Board.
     */
    Square& squareAt(int x, int y) const;

    /**
     * Returns the Square at the given
     * coordinates on the Board.
     *
     * Accepts a string of the notation [a-h][1-8]
     * (ex. a5) and parses it to find the x and y
     * coordinates.
     *
     * @param location the coordinates given in algebraic
     * notation.
     * @return the Square at the given coordinates on the
     * Board.
     */
    Square& squareAt(std::string location) const;

    /**
     * Returns the distance between the specified squares.
     *
     * The distance is the number of squares needed to travel
     * between the two squares.
     *
     * @param from the origin square.
     * @param to the destination square.
     * @return the distance between the specified squares.
     */
    int distanceBetween(Square& from, Square& to) const;

    /**
     * Returns true if the vertical path between the two
     * squares is clear.
     *
     * @param from the origin square.
     * @param to the destination square.
     * @return true if the vertical path between the two
     * squares is clear.
     */
    bool isClearVertical(Square& from, Square& to) const;

    /**
     * Returns true if the horizontal path between the two
     * squares is clear.
     *
     * @param from the origin square.
     * @param to the destination square.
     * @return true if the horizontal path between the two
     * squares is clear.
     */
    bool isClearHorizontal(Square& from, Square& to) const;

    /**
     * Returns true if the diagonal path between the two squares
     * is clear.
     *
     * @param from the origin square.
     * @param to the destination square.
     * @return true if the diagonal path between the two squares
     * is clear.
     */
    bool isClearDiagonal(Square& from, Square& to) const;

    /**
     * Displays a visual Board with the Pieces in their respective
     * locations.
     *
     * @param outStream the ostream to output to.
     */
    void display(std::ostream &outStream) const;

private:
    /**
     * Private constructor for an instance
     * of the Board class.
     */
    Board();
    static Board* _theBoard;
    static const int _DIMENSION = 8;
    Square* _squares[_DIMENSION][_DIMENSION];
};


#endif //BOARD_H
