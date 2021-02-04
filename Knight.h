#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include <ostream>
#include "Piece.h"

class Square;

/**
 * A Knight is a Piece
 * that can move one space vertically and
 * two spaces horizontally,
 * or two spaces vertically and one space
 * horizontally.
 * A Knight can also jump over Pieces.
 */
class Knight : public Piece {
public:
    /**
     * Constructor for an instance of the
     * Knight class.
     * 
     * @param color the color of this Knight. 
     */
    Knight(std::string& color);
     
    /**
     * Destructor for an instance of the Knight
     * class.
     */
    virtual ~Knight();
      
    /**
     * Returns true if the Knight can
     * legally reach the specified
     * Square.
     * 
     * A Knight may move in an L shape
     * (2 spaces vertically + 1 space horizontally
     * or 2 spaces horizontally + 1 space vertically).
     * 
     * @param location the destination of the move. 
     * @return true if the Knight can
     * legally reach the specified Square.
     */
    bool canMoveTo(Square& location) const;
       
    /**
     * Return the value of a Knight.
     * 
     * A Knight is worth 3 points.
     * 
     * @return the value of a Knight.
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


#endif //KNIGHT_H
