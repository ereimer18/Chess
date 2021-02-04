#ifndef ROOK_H
#define ROOK_H

#include <string>
#include <ostream>
#include "RestrictedPiece.h"

class Square;

/**
 * Rook is a RestrictedPiece that can
 * move vertically or horizontally,
 * and on its first move can castle with
 * a King.
 */
class Rook : public RestrictedPiece {
public:
    /**
     * Constructor for an instance of the
     * Rook class.
     * 
     * @param color the color of this Rook. 
     */
    Rook(std::string& color);
     
    /**
     * Destructor for an instance of the Rook
     * class.
     */
    virtual ~Rook();
      
    /**
     * Returns true if the Rook can
     * legally reach the specified
     * Square.
     * 
     * A Rook may move vertically and horizontally.
     * 
     * @param location the destination of the move. 
     * @return true if the Rook can
     * legally reach the specified Square.
     */
    bool canMoveTo(Square& location) const;
       
    /**
     * Return the value of a Rook.
     * 
     * A Rook is worth 5 points.
     * 
     * @return the value of a Rook.
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


#endif //ROOK_H
