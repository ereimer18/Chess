#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>

class Piece;
class King;

/**
 * A Player has a set of
 * pieces.
 * In a Game, there are
 * 2 players.
 */
class Player {
public:
    /**
     * Constructor for a Player instance.
     *
     * @param name the name of the player.
     */
    Player(std::string& name);

    /**
     * Destructor for a Player instance.
     */
    virtual ~Player();

    /**
     * Sets this Player's set of Pieces
     * to the specified set.
     *
     * @param pieces the set of Pieces belonging
     * to the Player.
     */
    void setPieces(std::set<Piece*>& pieces);

    /**
     * Sets this Player's King to the specified King.
     *
     * Allows the Player to have a notion of its King
     * in order to check if it is in check.
     *
     * @param king the Player's King.
     */
    void setKing(King& king);

    /**
     * Performs the specified move.
     *
     * Prompts the user to enter a move following
     * algebraic notation (ex. a2 a3).
     * If the user enters bad input or an illegal move,
     * user is prompted to try again.
     * If the user enters 'q', the game ends.
     *
     * @return true if the user enters a valid move
     * that is not 'q'.
     */
    bool makeMove();

    /**
     * Returns the Player's name.
     *
     * A Player's name is either
     * White or Black.
     *
     * @return the Player's name.
     */
    std::string& getName() const;

    /**
     * Returns the Player's score.
     *
     * The Player's score is based
     * upon the Pieces it has successfully
     * captured.
     *
     * @return the Player's score.
     */
    int score() const;

    /**
     * Captures the specified Piece
     * if it is legal to do so.
     *
     * Adds the Piece to the Player's
     * list of captured Pieces and
     * updates the Player's score.
     *
     * @param aPiece the Piece to be captured.
     */
    void capture(Piece& aPiece);

    /**
     * Returns the Player's set of Pieces.
     *
     * @return the Player's set of Pieces.
     */
    std::set<Piece*>& myPieces() const;

    /**
     * Returns the Player's King.
     *
     * @return the Player's King.
     */
    King& myKing() const;

private:
    std::string& _name;
    std::set<Piece*>* _myPieces;
    std::set<Piece*>* _captured;
    int _score;
    King* _myKing;
};


#endif //PLAYER_H
