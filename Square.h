#ifndef SQUARE_H
#define SQUARE_H

class Piece;

/**
 * A Square makes up a Board and can
 * give information on what piece, if
 * any, is occupying it
 */
class Square {
public:
    /**
     * Constructor for an instance of the Square class.
     *
     * @param x the horizontal x position.
     * @param y the vertical y position.
     */
    Square(int x, int y);

    /**
     * Destructor for the Square class.
     */
    virtual ~Square();

    /**
     * Returns the horizontal x position.
     *
     * @return the horizontal x position.
     */
    int getX() const;

    /**
     * Returns the vertical y position.
     *
     * @return the vertical y position.
     */
    int getY() const;

    /**
     * Returns true if this Square is occupied
     * by a Piece.
     *
     * @return true if this Square is occupied.
     */
    bool occupied() const;

    /**
     * Returns the Piece occupying this Square.
     *
     * @return the Piece occupying this Square.
     */
    Piece& occupiedBy() const;

    /**
     * Sets the Square's occupant to the specified
     * Piece.
     *
     * @param piece the Piece to occupy this Square.
     */
    void setOccupier(Piece* piece);

private:
    int _x;
    int _y;
    Piece* _piece;
};


#endif //SQUARE_H
