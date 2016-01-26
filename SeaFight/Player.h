#pragma once

//#include "GameBoard.h"
#include <string>

class GameBoard;

class Player {
    GameBoard* _myBoard;
    GameBoard* _opBoard;
    std::string    _nick;
    int       _counter;   
public:
    GameBoard*  getMyBoard(void);
    GameBoard*  getOpBoard(void);
    Player(void) {}
    ~Player(void) {}
    int changeNick(const std::string);
    void clearBoards(void);
    void resetBoards(void);
    bool autoSetShips(void);
    bool checkBoard(void);
    std::string getNick(void);
    int getStatShot(const int, const int);
    int setStatShot(const int, const int, const int);
    virtual bool setShips(void) = 0;
    //virtual pair <int, int> readMove(void) = 0;
    void endGame(void);
    bool checkWin(void);
};

class PlayerComp: public Player {
    static int count;
public:
    PlayerComp(void);
    bool setShips(void);
    //pair <int, int> readMove(void);
};

class PlayerUser: public Player {
    static int count;
public:
    PlayerUser(void);
    int inputCmd(int);
    bool setShip(const int, const int, const int, const int);
    bool delShip(const int, const int);
    bool setShips(void);
    //pair <int, int> readMove(void);
};