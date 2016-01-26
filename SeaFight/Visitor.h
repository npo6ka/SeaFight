#pragma once

#include <iostream>
#include <memory>
//
//using namespace std;
//
//class GameBoardCell;
//class Ship;
//class Player;
//
//
//class Visitor {
//public:
//    virtual void PrintCell(shared_ptr<GameBoardCell>, int) = 0;
//    virtual void PrintShip1(shared_ptr<Ship>, bool) = 0;
//    virtual void PrintShip2(shared_ptr<Ship>, bool) = 0;
//    virtual void PrintShip3(shared_ptr<Ship>, bool) = 0;
//    virtual void PrintShip4(shared_ptr<Ship>, bool) = 0;
//    virtual void PrintFrameForCmd(Player*) = 0;
//    virtual void PrintMsg(string) = 0;
//    virtual void PrintFrame(string, string) = 0;
//    virtual void clear(void) = 0;
//    virtual void PrintWin(string) = 0;
//};
//
//class Print: public Visitor {
//    void PrintCell(shared_ptr<GameBoardCell>, int);
//    void PrintShip1(shared_ptr<Ship>, bool);
//    void PrintShip2(shared_ptr<Ship>, bool);
//    void PrintShip3(shared_ptr<Ship>, bool);
//    void PrintShip4(shared_ptr<Ship>, bool);
//    void PrintFrameForCmd(Player*);
//    void PrintMsg(string);
//    void PrintFrame(string, string);
//    void clear(void);
//    void PrintWin(string);
//};
///*
//class MyGUI: public Visitor {
//    void PrintCell(shared_ptr<GameBoardCell>, int);
//    void PrintShip1(shared_ptr<Ship>, bool);
//    void PrintShip2(shared_ptr<Ship>, bool);
//    void PrintShip3(shared_ptr<Ship>, bool);
//    void PrintShip4(shared_ptr<Ship>, bool);
//    void PrintFrameForCmd(Player*) {}
//    // ----------
//    void PrintMsg(string) {};
//    void PrintFrame(string, string) {};
//    void clear(void) {};
//    // ----------
//    void PrintWin(string) {};
//};*/