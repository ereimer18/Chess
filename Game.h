#include <set>
#ifndef GAME_H
#define GAME_H

class Piece;
class Bishop;
class Queen;
class Knight;
class Pawn;
class Rook;
class King;
class Player;
class Board;

/**
 * Instantiates all states and objects
 * needed to play a game of chess.
 */
class Game {
public:

    /**
     * Returns the next Player.
     *
     * Returns the next Player and updates
     * the nextPlayer attribute.
     *
     * @return the next Player.
     */
    static Player& getNextPlayer();

    /**
     * Creates the Board, Players, Squares and Pieces
     * and places them in their respective start positions.
     */
    static void initialize();

    /**
     * Returns the specified Player's opponent.
     *
     * @param player the player to find the opponent of.
     * @return the specified Player's opponent.
     */
    static Player& opponentOf(Player& player);

private:
    static std::set<Piece*>* _whitePieces;
    static std::set<Piece*>* _blackPieces;
    static std::set<Player*>* _players;
    static Player* _nextPlayer;
    static Player* _opponent;
    static const int NUM_PIECES = 16;
};


#endif //GAME_H
