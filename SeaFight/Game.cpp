#include "Game.h"
#include "Visitor.h"
#include <windows.h>

//Game::Game(const int user, const int comp) {
//    for (int i = 0; i < user; i++) {
//        _users.push_back(shared_ptr<PlayerUser> (new PlayerUser()));
//    }
//    for (int i = 0; i < comp; i++) {
//        _comps.push_back(shared_ptr<PlayerComp> (new PlayerComp()));
//    }
//}
//
//vector<shared_ptr<Player>> randomList(list<shared_ptr<PlayerUser>> users, list<shared_ptr<PlayerComp>> comp) {
//    srand(clock()+(unsigned int)time(0));
//    vector <shared_ptr<Player>> buf;
//    while (comp.size() || users.size()) {
//        if (rand() % 2) {
//            if (!comp.empty()) {
//                buf.push_back(comp.front());
//                comp.erase(comp.begin());
//            }
//        } else if (!users.empty()) {
//            buf.push_back(users.front());
//            users.erase(users.begin());
//        }
//    }
//    return buf;
//}
//
//int getNextId(int cur, int size) {
//    if (++cur == size) return 0;
//    else return cur;
//}
//int getPrevId(int cur, int size) {
//    if (--cur < 0) return size-1;
//    else return cur;
//}
//
//bool Game::start(shared_ptr<Visitor> vis) {
//    vector <shared_ptr<Player>> players = randomList(_users, _comps);
//    /*for (int i = players.size(); i > 0; i--) {
//        vis->clear();
//        vis->PrintFrame("", players[i-1]->getNick());
//        if (!players[i-1]->setShips(vis)) return false;
//        players[i-1]->clearBoards();
//    }
//    int move = 0, size = players.size(), stat = 0;
//    pair<int, int> buf;
//    while (1) {
//        vis->clear();
//        vis->PrintFrame(players[getNextId(move, size)]->getNick(), players[move]->getNick());
//        players[getPrevId(move, size)]->getOpBoard()->drawRightBoard(vis);
//        players[move]->getOpBoard()->drawLeftBoard(vis);
//        buf = players[move]->readMove(vis);
//        if (buf.first == -2) return 0;
//        stat = players[getNextId(move, size)]->getStatShot(buf.first, buf.second);
//        if (stat == MISS) { 
//            players[move]->setStatShot(buf.first, buf.second, stat);
//            players[move]->getOpBoard()->drawLeftBoard(vis);
//            move = getNextId(move, size);
//            Sleep(1000);
//        } else if (stat >= SHIP) {
//            stat = players[move]->setStatShot(buf.first, buf.second, stat);
//            if (players[move]->checkWin()) {
//                vis->PrintWin(players[move]->getNick());
//                return 1;
//            }
//            players[move]->getOpBoard()->drawLeftBoard(vis);
//            Sleep(1000);
//        } else vis->PrintMsg("incorrect shot");
//    }*/
//    return 1;
//}

