#ifndef RESTRICTEDPIECE_H
#define RESTRICTEDPIECE_H

#include <string>
#include "Piece.h"

class Player;
class Square;

/**
 * A RestrictedPiece is a Piece that has different
 * movement behavior depending on whether
 * the Piece has moved or not.
 */
class RestrictedPiece : public Piece {
public:
    
    /**
     * Constructor for an instance of the
     * RestrictedPiece class.
     * 
     * @param color the color of this RestrictedPiece. 
     */
    RestrictedPiece(std::string& color);
     
    /**
     * Destructor for an instance of the RestrictedPiece
     * class.
     */
    virtual ~RestrictedPiece();

    /**
     * Moves the Piece to the specified square if it
     * is legal to do so.
     *
     * Sets the has moved attribute to true.
     *
     * @param byPlayer the player who is performing the move.
     * @param to the destination square.
     * @return true if the Piece may legally move to the
     * specified square.
     */
    bool moveTo(Player& byPlayer, Square& to);

protected:
    /**
     * Returns true if this Piece has moved yet.
     * @return true if this Piece has moved yet.
     */
    bool hasMoved() const;

private:
    bool _moved;
};


#endif //RESTRICTEDPIECE_H
