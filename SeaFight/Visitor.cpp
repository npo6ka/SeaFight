#include "Visitor.h"
//#include "HandlerCmd.h"
#include "Player.h"
#include "MyForm1.h"
#include <windows.h>
#include <conio.h>
//
//#define WIDTH            80
//#define HEIGHT           25
//#define HEI_INDENT_BOARD HEIGHT / 5
//#define WID_INDENT_BOARD WIDTH / 5
//#define SHIFT_FOR_BOARD  WIDTH - WID_INDENT_BOARD*2 - BOARD_SIZE
//
//void gotoxy(short x, short y)
//{
//    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD  coord  = {x, y};
//    SetConsoleCursorPosition(StdOut, coord);
//}
//
//void Print::PrintCell(shared_ptr<GameBoardCell> cell, int shift) {
//    gotoxy(cell->getPosY() + shift*(SHIFT_FOR_BOARD) + (WID_INDENT_BOARD), cell->getPosX() + (HEI_INDENT_BOARD));
//    if (cell->getStat()) {
//        cout << char(178);
//    } else cout << char(176);
//}
//void Print::PrintShip1(shared_ptr<Ship> sh, bool shift) {
//    for (auto& it:sh->getCells()) {
//        gotoxy(it->getPosY() + shift*(SHIFT_FOR_BOARD) + (WID_INDENT_BOARD), it->getPosX() + (HEI_INDENT_BOARD));
//        if (it->getStat()) {
//            cout << char(219);
//        } else {
//            cout << "#";
//        }
//    }
//    gotoxy(20, 0);
//}
//void Print::PrintShip2(shared_ptr<Ship> sh, bool shift) {
//    for (auto& it:sh->getCells()) {
//        gotoxy(it->getPosY() + shift*(SHIFT_FOR_BOARD) + (WID_INDENT_BOARD), it->getPosX() + (HEI_INDENT_BOARD));
//        if (it->getStat()) {
//            cout << char(219);
//        } else {
//            cout << "#";
//        }
//    }
//    gotoxy(20, 0);
//}
//void Print::PrintShip3(shared_ptr<Ship> sh, bool shift) {
//    for (auto& it:sh->getCells()) {
//        gotoxy(it->getPosY() + shift*(SHIFT_FOR_BOARD) + (WID_INDENT_BOARD), it->getPosX() + (HEI_INDENT_BOARD));
//        if (it->getStat()) {
//            cout << char(219);
//        } else {
//            cout << "#";
//        }
//    }
//    gotoxy(20, 0);
//}
//void Print::PrintShip4(shared_ptr<Ship> sh, bool shift) {
//    for (auto& it:sh->getCells()) {
//        gotoxy(it->getPosY() + shift*(SHIFT_FOR_BOARD) + (WID_INDENT_BOARD), it->getPosX() + (HEI_INDENT_BOARD));
//        if (it->getStat()) {
//            cout << char(219);
//        } else {
//            cout << "#";
//        }
//    }
//    gotoxy(20, 0);
//}
//
//void Print::PrintFrameForCmd(Player* pl) {
//    gotoxy(0, 20);
//    cout << (string (WIDTH * 4, ' '));
//    gotoxy(0, 20);
//    cout << pl->getNick() <<" enter command: ";  
//}
//void Print::PrintMsg(string str) {
//    gotoxy(22, 19);
//    cout << str;
//    gotoxy(0, 21);
//}
//
//void Print::PrintFrame(string nick2, string nick1) {
//    gotoxy((SHIFT_FOR_BOARD) + (WID_INDENT_BOARD), (HEI_INDENT_BOARD)-4);
//    cout << "nick: " << nick1;
//    gotoxy((SHIFT_FOR_BOARD) + (WID_INDENT_BOARD), (HEI_INDENT_BOARD)-2);
//    cout << "0123456789";
//    for (int i = 0; i < 10; i++) {
//        gotoxy((SHIFT_FOR_BOARD) + (WID_INDENT_BOARD) - 2, (HEI_INDENT_BOARD) + i);
//        cout << i;
//    }
//    gotoxy((WID_INDENT_BOARD), (HEI_INDENT_BOARD)-4);
//    cout << "nick: " << nick2;
//    gotoxy((WID_INDENT_BOARD), (HEI_INDENT_BOARD)-2);
//    cout << "0123456789";
//    for (int i = 0; i < 10; i++) {
//        gotoxy((WID_INDENT_BOARD) - 2, (HEI_INDENT_BOARD) + i);
//        cout << i;
//    }
//};
//
//void Print::clear() {
//    gotoxy(0, 0);
//    cout << (string ((WIDTH) * (HEIGHT), ' '));
//    gotoxy(0, 0);
//}
//
//void Print::PrintWin(string str) {
//    clear();
//    gotoxy(30, 13);
//    cout << "Player: " << str << " WIN";
//    _getch();
//}
//
///*
//void PrintCell(shared_ptr<GameBoardCell> cell, int stat) {
//    SeaFight::MyForm1^ sdf;
//}
//
//void PrintShip1(shared_ptr<Ship> sh, bool st) {
//
//}
//
//void PrintShip2(shared_ptr<Ship> sh, bool st) {
//
//}
//
//void PrintShip3(shared_ptr<Ship> sh, bool st) {
//
//}
//
//void PrintShip4(shared_ptr<Ship> sh, bool st) {
//
//}*/
