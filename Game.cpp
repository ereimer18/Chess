#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include "Game.h"
#include "Board.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Player.h"
#include "Square.h"

Player& Game::getNextPlayer() {
    Player& nextPlayer = *_nextPlayer;
    // update the next player
    _nextPlayer = &opponentOf(nextPlayer);
    return nextPlayer;
}

void Game::initialize() {
    Board* board = &Board::getBoard();
    
    std::string white = "white";
    std::string black = "black";
    std::string p2 = "Black";
    Player* player1 = _nextPlayer;
    Player* player2 = _opponent;

    _players->insert(player1);
    _players->insert(player2);

    // instantiate all pieces
    Rook* BRa = new Rook(black);
    Knight* BNa = new Knight(black);
    Bishop* BBa = new Bishop(black);
    Queen* BQ = new Queen(black);
    King* BK = new King(black);
    Bishop* BBb = new Bishop(black);
    Knight* BNb = new Knight(black);
    Rook* BRb = new Rook(black);
    Pawn* BPa = new Pawn(black);
    Pawn* BPb = new Pawn(black);
    Pawn* BPc = new Pawn(black);
    Pawn* BPd = new Pawn(black);
    Pawn* BPe = new Pawn(black);
    Pawn* BPf = new Pawn(black);
    Pawn* BPg = new Pawn(black);
    Pawn* BPh = new Pawn(black);

    Rook* WRa = new Rook(white);
    Knight* WNa = new Knight(white);
    Bishop* WBa = new Bishop(white);
    Queen* WQ = new Queen(white);
    King* WK = new King(white);
    Bishop* WBb = new Bishop(white);
    Knight* WNb = new Knight(white);
    Rook* WRb = new Rook(white);
    Pawn* WPa = new Pawn(white);
    Pawn* WPb = new Pawn(white);
    Pawn* WPc = new Pawn(white);
    Pawn* WPd = new Pawn(white);
    Pawn* WPe = new Pawn(white);
    Pawn* WPf = new Pawn(white);
    Pawn* WPg = new Pawn(white);
    Pawn* WPh = new Pawn(white);

    // set locations
    Square* sB1 = &board->squareAt(0,0);
    sB1->setOccupier(BRa);
    Square* sB2 = &board->squareAt(1,0);
    sB2->setOccupier(BNa);
    Square* sB3 = &board->squareAt(2,0);
    sB3->setOccupier(BBa);
    Square* sB4 = &board->squareAt(3,0);
    sB4->setOccupier(BQ);
    Square* sB5 = &board->squareAt(4,0);
    sB5->setOccupier(BK);
    Square* sB6 = &board->squareAt(5,0);
    sB6->setOccupier(BBb);
    Square* sB7 = &board->squareAt(6,0);
    sB7->setOccupier(BNb);
    Square* sB8 = &board->squareAt(7,0);
    sB8->setOccupier(BRb);
    Square* sB9 = &board->squareAt(0,1);
    sB9->setOccupier(BPa);
    Square* sB10 = &board->squareAt(1,1);
    sB10->setOccupier(BPb);
    Square* sB11 = &board->squareAt(2,1);
    sB11->setOccupier(BPc);
    Square* sB12 = &board->squareAt(3,1);
    sB12->setOccupier(BPd);
    Square* sB13 = &board->squareAt(4,1);
    sB13->setOccupier(BPe);
    Square* sB14 = &board->squareAt(5,1);
    sB14->setOccupier(BPf);
    Square* sB15 = &board->squareAt(6,1);
    sB15->setOccupier(BPg);
    Square* sB16 = &board->squareAt(7,1);
    sB16->setOccupier(BPh);

    Square* sW1 = &board->squareAt(0,6);
    sW1->setOccupier(WPa);
    Square* sW2 = &board->squareAt(1,6);
    sW2->setOccupier(WPb);
    Square* sW3 = &board->squareAt(2,6);
    sW3->setOccupier(WPc);
    Square* sW4 = &board->squareAt(3,6);
    sW4->setOccupier(WPd);
    Square* sW5 = &board->squareAt(4,6);
    sW5->setOccupier(WPe);
    Square* sW6 = &board->squareAt(5,6);
    sW6->setOccupier(WPf);
    Square* sW7 = &board->squareAt(6,6);
    sW7->setOccupier(WPg);
    Square* sW8 = &board->squareAt(7,6);
    sW8->setOccupier(WPh);
    Square* sW9 = &board->squareAt(0,7);
    sW9->setOccupier(WRa);
    Square* sW10 = &board->squareAt(1,7);
    sW10->setOccupier(WNa);
    Square* sW11 = &board->squareAt(2,7);
    sW11->setOccupier(WBa);
    Square* sW12 = &board->squareAt(3,7);
    sW12->setOccupier(WQ);
    Square* sW13 = &board->squareAt(4,7);
    sW13->setOccupier(WK);
    Square* sW14 = &board->squareAt(5,7);
    sW14->setOccupier(WBb);
    Square* sW15 = &board->squareAt(6,7);
    sW15->setOccupier(WNb);
    Square* sW16 = &board->squareAt(7,7);
    sW16->setOccupier(WRb);

    // set square locations
    BRa->setLocation(&board->squareAt(0,0));
    BNa->setLocation(&board->squareAt(1,0));
    BBa->setLocation(&board->squareAt(2,0));
    BQ->setLocation(&board->squareAt(3,0));
    BK->setLocation(&board->squareAt(4,0));
    BBb->setLocation(&board->squareAt(5,0));
    BNb->setLocation(&board->squareAt(6,0));
    BRb->setLocation(&board->squareAt(7,0));
    BPa->setLocation(&board->squareAt(0,1));
    BPb->setLocation(&board->squareAt(1,1));
    BPc->setLocation(&board->squareAt(2,1));
    BPd->setLocation(&board->squareAt(3,1));
    BPe->setLocation(&board->squareAt(4,1));
    BPf->setLocation(&board->squareAt(5,1));
    BPg->setLocation(&board->squareAt(6,1));
    BPh->setLocation(&board->squareAt(7,1));

    WPa->setLocation(&board->squareAt(0,6));
    WPb->setLocation(&board->squareAt(1,6));
    WPc->setLocation(&board->squareAt(2,6));
    WPd->setLocation(&board->squareAt(3,6));
    WPe->setLocation(&board->squareAt(4,6));
    WPf->setLocation(&board->squareAt(5,6));
    WPg->setLocation(&board->squareAt(6,6));
    WPh->setLocation(&board->squareAt(7,6));
    WRa->setLocation(&board->squareAt(0,7));
    WNa->setLocation(&board->squareAt(1,7));
    WBa->setLocation(&board->squareAt(2,7));
    WQ->setLocation(&board->squareAt(3,7));
    WK->setLocation(&board->squareAt(4,7));
    WBb->setLocation(&board->squareAt(5,7));
    WNb->setLocation(&board->squareAt(6,7));
    WRb->setLocation(&board->squareAt(7,7));

    // fill _whitePieces & _blackPieces
    _whitePieces->insert(WPa);
    _whitePieces->insert(WPb);
    _whitePieces->insert(WPc);
    _whitePieces->insert(WPd);
    _whitePieces->insert(WPe);
    _whitePieces->insert(WPf);
    _whitePieces->insert(WPg);
    _whitePieces->insert(WPh);
    _whitePieces->insert(WRa);
    _whitePieces->insert(WNa);
    _whitePieces->insert(WBa);
    _whitePieces->insert(WQ);
    _whitePieces->insert(WK);
    _whitePieces->insert(WBb);
    _whitePieces->insert(WNb);
    _whitePieces->insert(WRb);

    _blackPieces->insert(BRa);
    _blackPieces->insert(BNa);
    _blackPieces->insert(BBa);
    _blackPieces->insert(BQ);
    _blackPieces->insert(BK);
    _blackPieces->insert(BBb);
    _blackPieces->insert(BNb);
    _blackPieces->insert(BRb);
    _blackPieces->insert(BPa);
    _blackPieces->insert(BPb);
    _blackPieces->insert(BPc);
    _blackPieces->insert(BPd);
    _blackPieces->insert(BPe);
    _blackPieces->insert(BPf);
    _blackPieces->insert(BPg);
    _blackPieces->insert(BPh);

    player1->setPieces(*_whitePieces);
    player2->setPieces(*_blackPieces);
    player1->setKing(*WK);
    player2->setKing(*BK);

}

Player& Game::opponentOf(Player &player) {
    Player* opponent = &player;

    for (Player* p : *_players) {
        if (p->getName() != player.getName()) {
            opponent = p;
        }
    }
    return *opponent;
}

std::set<Piece*>* Game::_whitePieces = new std::set<Piece*>;
std::set<Piece*>* Game::_blackPieces = new std::set<Piece*>;
std::set<Player*>* Game::_players = new std::set<Player*>;
std::string p1 = "White";
std::string p2 = "Black";
Player* Game::_nextPlayer = new Player(p1);
Player* Game::_opponent = new Player(p2);