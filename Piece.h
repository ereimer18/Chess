#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <ostream>

class Player;
class Square;

/**
 * Piece is an abstract class
 * that describes a generic chess Piece.
 * Much of the behavior is to be implemented
 * by subclasses.
 */
class Piece {
public:
    /**
     * Constructor for an instance of the
     * Piece class.
     * 
     * @param color the color of this Piece. 
     */
    Piece(std::string& color);
     
    /**
     * Destructor for an instance of the Piece
     * class.
     */
    virtual ~Piece();

    /**
     * Moves the Piece to the specified square if it
     * is legal to do so.
     *
     * @param byPlayer the player who is performing the move.
     * @param to the destination square.
     * @return true if the Piece may legally move to the
     * specified square.
     */
    virtual bool moveTo(Player& byPlayer, Square& to);
    
    /**
     * Return the value of a Piece.
     *
     * @return the value of a Piece.
     */
    virtual int value() const = 0;

    /**
     * Returns this Piece's color.
     *
     * @return this Piece's color.
     */
    std::string color() const;
    
    /**
     * Displays a visual representation of the Piece.
     * 
     * This is a method used in displaying the entire Board.
     * 
     * @param outStream the ostream to output to. 
     */
    virtual void display(std::ostream& outStream) const = 0;
    
    /**
     * Returns true if the Piece can
     * legally reach the specified
     * Square.
     *
     * @param location the destination of the move. 
     * @return true if the Piece can
     * legally reach the specified Square.
     */
    virtual bool canMoveTo(Square& location) const = 0;

    /**
     * Sets this Piece's location to the specified Square.
     *
     * @param square the destination square.
     */
    virtual void setLocation(Square* square);

    /**
     * Returns true if the Piece is on the Board.
     *
     * @return true if the Piece is on the Board.
     */
    bool isOnBoard() const;

    /**
     * Returns this Piece's current location.
     *
     * @return this Piece's current location.
     */
    Square& location() const;
    
private:
    std::string _color;
    Square* _square;
};


#endif //PIECE_H
