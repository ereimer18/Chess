#ifndef QUEEN_H
#define QUEEN_H

#include <string>
#include <ostream>
#include "Piece.h"

class Square;

/**
 * A Queen is a Piece
 * that can move vertically,
 * horizontally and diagonally
 */
class Queen : public Piece {
public:
    /**
     * Constructor for an instance of the
     * Queen class.
     * 
     * @param color the color of this Queen. 
     */
    Queen(std::string& color);
     
    /**
     * Destructor for an instance of the Queen
     * class.
     */
    virtual ~Queen();
      
    /**
     * Returns true if the Queen can
     * legally reach the specified
     * Square.
     * 
     * A Queen may move in any direction.
     * 
     * @param location the destination of the move. 
     * @return true if the Queen can
     * legally reach the specified Square.
     */
    bool canMoveTo(Square& location) const;
       
    /**
     * Return the value of a Queen.
     * 
     * A Queen is worth 9 points.
     * 
     * @return the value of a Queen.
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


#endif //QUEEN_H
