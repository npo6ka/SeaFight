#include "Player.h"
//#include "HandlerCmd.h"
#include "Visitor.h"

int PlayerComp::count = 0;
int PlayerUser::count = 0;

GameBoard* Player::getMyBoard() {
    return &_myBoard;
}
GameBoard* Player::getOpBoard() {
    return &_opBoard;
}

int Player::changeNick(const string str) {
    if (str.find_first_not_of
        ("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ_ ") 
        != string::npos) {
            return 0; // неккоректный никнейм
    } else {
        _nick = str;
        return 1; // всё хорошо
    }
}
void Player::clearBoards() {
    getMyBoard()->clear();
    getOpBoard()->clear();
}
void Player::resetBoards() {
    getMyBoard()->reset();
    getOpBoard()->reset();
}
bool Player::autoSetShips() {
    return getMyBoard()->generateShips();
}
bool Player::checkBoard() {
    return getMyBoard()->checkFullBoard() & getOpBoard()->empty();
}
string Player::getNick() {
    return _nick;
}
int Player::getStatShot(const int x, const int y) {
    return getMyBoard()->getStatShot(x, y);
}
int Player::setStatShot(const int x, const int y, const int size) {
    return getOpBoard()->setStatShot(x, y, size);
}
bool Player::checkWin() {
    return getOpBoard()->checkFullBoard();
}

PlayerComp::PlayerComp(): Player() {
    changeNick(string ("Computer_" + to_string(++count)));
}
bool PlayerComp::setShips(shared_ptr<Visitor>) {
    getMyBoard()->reset();
    getOpBoard()->reset();
    return autoSetShips();
}
pair <int, int> PlayerComp::readMove(shared_ptr<Visitor>) {
    srand(clock()+(unsigned int)time(0));
    return pair <int, int> (rand() % BOARD_SIZE, rand() % BOARD_SIZE);
}

PlayerUser::PlayerUser(): Player() {
    changeNick(string ("User_" + to_string(++count)));
}
bool PlayerUser::setShip(const int x, const int y, const Direction dir, const int size) {
    return getMyBoard()->setFullShip(x, y, dir, size);
}
bool PlayerUser::delShip(const int x, const int y) {
    return getMyBoard()->delShip(x, y);
}
bool PlayerUser::setShips(shared_ptr<Visitor> vis) {
    //static HandlerCmd hnd(vis);
    int stat = 0;
    while (stat != -1) {
        getMyBoard()->drawRightBoard(vis);
        getOpBoard()->drawLeftBoard(vis);
        //stat = hnd.handlerCmdPrep(this);
        if (stat == 1) {
            if (checkBoard()) return true;
            else vis->PrintMsg("Board is'n valid!!!");
        }
    }
    return false;
}
pair <int, int> PlayerUser::readMove(shared_ptr<Visitor> vis) {
    //static HandlerCmd hnd(vis);
    pair <int, int> buf;
    do {
    //    buf = hnd.handlerCmdGame(this);
    } while (buf.first == -1);
    return buf;
}