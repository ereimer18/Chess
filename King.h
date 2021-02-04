#ifndef KING_H
#define KING_H

#include <string>
#include <ostream>
#include "RestrictedPiece.h"

class Square;

/**
 * A King is a RestrictedPiece that can move
 * one space in any direction.
 * It can castle with a Rook on its first turn.
 * As long as the King is alive, the Game is in play.
 * Once a player captures the opponent's King,
 * the game ends.
 */
class King : public RestrictedPiece {
public:
    /**
     * Constructor for an instance of the
     * King class.
     * 
     * @param color the color of this King. 
     */
    King(std::string& color);
     
     /**
      * Destructor for an instance of the King
      * class.
      */
    virtual ~King();
    
    /**
     * Returns true if the King can
     * legally reach the specified
     * Square.
     * 
     * A King may move one space in any direction.
     * 
     * @param location the destination of the move. 
     * @return true if the King can
     * legally reach the specified Square.
     */
    bool canMoveTo(Square& location) const;
     
     /**
     * Return the value of a King.
     * 
     * A King is worth 10000 points.
     * 
     * @return the value of a King.
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

    /**
     * Checks if this King is in check.
     *
     * Checks if any of the opponent's pieces
     * can move to this King.
     *
     * @param player the player that owns this King.
     * @return true if this King is in check.
     */
    bool checkForCheck(Player &player) const;
};


#endif //KING_H
