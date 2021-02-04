#ifndef PAWN_H
#define PAWN_H

#include <string>
#include <ostream>
#include "RestrictedPiece.h"

class Piece;
class Square;

/**
 * Pawn is a RestrictedPiece
 * that can move two spaces forward on
 * its first turn.
 * Else, it can move one space forward.
 * If a Pawn reaches the end of the Board,
 * it is promoted to a Queen.
 */
class Pawn : public RestrictedPiece {
public:
    /**
     * Constructor for an instance of the
     * Pawn class.
     * 
     * @param color the color of this Pawn. 
     */
    Pawn(std::string& color);
     
    /**
     * Destructor for an instance of the Pawn
     * class.
     */
    virtual ~Pawn();
      
    /**
     * Returns true if the Pawn can
     * legally reach the specified
     * Square.
     * 
     * A Pawn may move one space forwards, or two spaces
     * forward on the first move.
     * 
     * @param location the destination of the move. 
     * @return true if the Pawn can
     * legally reach the specified Square.
     */
    bool canMoveTo(Square& location) const;
       
    /**
     * Sets the location of the delegate Queen
     * to the specified square.
     * 
     * @param square the location of the delegate
     * Queen.
     */
    void setLocation(Square* square);
    
    /**
     * Return the value of a Pawn.
     * 
     * A Pawn is worth 1 point.
     * 
     * @return the value of a Pawn.
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

private:
    Piece* _delegate;
    int _direction;
    void setDirection();
};


#endif //PAWN_H
