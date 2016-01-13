#include "Ship.h"
#include "Visitor.h"
#include "GameBoardCell.h"

Ship::Ship (): _status(-1), _dir(UNK) {}
Ship::~Ship() {
    for (auto& it: _bufCells) {
        it->clearCell();
    }
}

void Ship::setDir(Direction dir) {
    _dir = dir;
}
Direction Ship::resetDir() {
    if (_bufCells.size() < 2) {
        setDir(UNK);
    } else {
        if (_bufCells.front()->getPosX() == _bufCells.back()->getPosX()) {
            setDir(HORIZONTAL);
        } else setDir(VERTICAL); 
    }
    return getDir();
}
void Ship::sortCell() {
    if (_dir == HORIZONTAL) {
        _bufCells.sort([](const shared_ptr<GameBoardCell> first, const shared_ptr<GameBoardCell> second) -> bool {
                        return (first->getPosY() < second->getPosY());  });
    } else {
        _bufCells.sort([](const shared_ptr<GameBoardCell> first, const shared_ptr<GameBoardCell> second) -> bool {
                        return (first->getPosX() < second->getPosX());  });
    }
}
bool Ship::tryAddCell(list <shared_ptr<GameBoardCell>> cells) {
    _bufCells.splice(_bufCells.end(), cells); //��������� �����
    if (_bufCells.size() >= 0 && _bufCells.size() <= (unsigned int)getSize()) { //����� ����� �� ������ ��������� ������ �������
        if (_bufCells.size() == 1) return 1; //���� ������������, �� �����
        if (resetDir() == UNK) return false; //������������ ����� ����������� ������� 
        sortCell();
        return checkShip();
    } else return false;
}

void Ship::setShipInCells() {   
    for (auto& it:_bufCells) {
        it->setShip(shared_from_this());
    }
}

list<shared_ptr<GameBoardCell>> Ship::getCells() const{
    return _bufCells;
}
Direction Ship::getDir() const {
    return _dir;
}
int Ship::getX() const {
    if (_bufCells.size()) {
        return _bufCells.front()->getPosX();
    } else return -1;
}
int Ship::getY() const {
    if (_bufCells.size()) {
        return _bufCells.front()->getPosY();
    } else return -1;
}    


bool Ship::checkShip() {
    if (getDir()) {
        for (list<shared_ptr<GameBoardCell>>::iterator it = _bufCells.begin(); *it != _bufCells.back();) {
                if ((*it)->getPosY() != _bufCells.back()->getPosY()) return false; //�.�. ����������� ������������, ��� ������� ������ ����� ���������� ���������� �� �
                if ((*it)->getPosX()+1 != (*(++it))->getPosX()) return false; //� ������ ����������� ������ ����� ���������� � �� 1 ������, ��� ����������
        }
        
    } else { 
        for (list<shared_ptr<GameBoardCell>>::iterator it = _bufCells.begin(); *it != _bufCells.back();) {
                if ((*it)->getPosX() != _bufCells.back()->getPosX()) return false; //�.�. ����������� ��������������, ��� ������� ������ ����� ���������� ���������� �� �
                if ((*it)->getPosY()+1 != (*(++it))->getPosY()) return false; //� ������ ����������� ������ ����� ���������� � �� 1 ������, ��� ����������
        }
    }
    return 1;
}
bool Ship::checkFull() {
    if (_bufCells.size() == getSize() && checkShip()) {
        return 1;
    } else return false;
}
bool Ship::checkDestShip() {
    for (auto& it: getCells()) {
        if (!it->getStat()) return false;
    }
    return 1;
}
void Ship::clearShip() {
    for (auto& it: _bufCells) {
        it->clearCell();
    }
    _bufCells.clear();
    setDir(UNK);
}


Ship1::Ship1 (): Ship() {}
Ship1::Ship1 (list <shared_ptr<GameBoardCell>> bufCells): Ship() {
    addCells(bufCells);
}
bool Ship1::addCells(list <shared_ptr<GameBoardCell>> cells) {
    Ship1 SaveStat = *this;
    if (!tryAddCell(cells)) {
        *this = SaveStat;
        return false;
    } else return 1; 
}
SizeShip Ship1::getSize(void) const {
    return DECK1;
}
void Ship1::drawShip(shared_ptr<Visitor> vis, bool sh) {
    vis->PrintShip1(shared_from_this(), sh);
}

Ship2::Ship2 (): Ship() {}
Ship2::Ship2 (list <shared_ptr<GameBoardCell>> bufCells): Ship() {
    addCells(bufCells);
}
bool Ship2::addCells(list <shared_ptr<GameBoardCell>> cells) {
    Ship2 SaveStat = *this;
    if (!tryAddCell(cells)) {
        *this = SaveStat;
        return false;
    } else return 1; 
}
SizeShip Ship2::getSize(void) const{
    return DECK2;
}
void Ship2::drawShip(shared_ptr<Visitor> vis, bool sh) {
    vis->PrintShip2(shared_from_this(), sh);
}

Ship3::Ship3 (): Ship() {}
Ship3::Ship3 (list <shared_ptr<GameBoardCell>> bufCells): Ship() {
    addCells(bufCells);
}
bool Ship3::addCells(list <shared_ptr<GameBoardCell>> cells) {
    Ship3 SaveStat = *this;
    if (!tryAddCell(cells)) {
        *this = SaveStat;
        return false;
    } else return 1; 
}
SizeShip Ship3::getSize(void) const {
    return DECK3;
}
void Ship3::drawShip(shared_ptr<Visitor> vis, bool sh) {
    vis->PrintShip3(shared_from_this(), sh);
}

Ship4::Ship4 (): Ship() {}
Ship4::Ship4 (list <shared_ptr<GameBoardCell>> bufCells): Ship() {
    addCells(bufCells);
}
bool Ship4::addCells(list <shared_ptr<GameBoardCell>> cells) {
    Ship4 SaveStat = *this;
    if (!tryAddCell(cells)) {
        *this = SaveStat;
        return false;
    } else return 1; 
}
SizeShip Ship4::getSize(void) const {
    return DECK4;
}
void Ship4::drawShip(shared_ptr<Visitor> vis, bool sh) {
    vis->PrintShip4(shared_from_this(), sh);
}

