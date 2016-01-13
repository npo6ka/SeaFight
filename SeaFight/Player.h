#pragma once

#include "GameBoard.h"
#include <string>

class Player {
    GameBoard _myBoard;
    GameBoard _opBoard;
    string    _nick;
    int       _counter;   
public:
    GameBoard*  getMyBoard(void);
    GameBoard*  getOpBoard(void);
    Player(void) {}
    ~Player(void) {}
    int changeNick(const string);
    void clearBoards(void);
    void resetBoards(void);
    bool autoSetShips(void);
    bool checkBoard(void);
    string getNick(void);
    int getStatShot(const int, const int);
    int setStatShot(const int, const int, const int);
    virtual bool setShips(shared_ptr<Visitor>) = 0;
    virtual pair <int, int> readMove(shared_ptr<Visitor>) = 0;
    void endGame(shared_ptr<Visitor>);
    bool checkWin(void);
};

class PlayerComp: public Player {
    static int count;
public:
    PlayerComp(void);
    bool setShips(shared_ptr<Visitor>);
    pair <int, int> readMove(shared_ptr<Visitor>);
};

class PlayerUser: public Player {
    static int count;
public:
    PlayerUser(void);
    int inputCmd(int, shared_ptr<Visitor>);
    bool setShip(const int, const int, const Direction, const int);
    bool delShip(const int, const int);
    bool setShips(shared_ptr<Visitor>);
    pair <int, int> readMove(shared_ptr<Visitor>);
};