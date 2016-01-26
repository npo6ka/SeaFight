#include "GameBoard.h"

const int GameBoard::_shipCount[MAX_SIZE_SHIP] = {4,3,2,1};

void GameBoard::generate() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _board[i][j] = shared_ptr<GameBoardCell> (new GameBoardCell(i, j));
        }
    }
}
shared_ptr<GameBoardCell> GameBoard::getCell(const int x, const int y) const {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return NULL;
    } else return _board[x][y];
}
shared_ptr<Ship> GameBoard::getShip(const int x, const int y) const {
    shared_ptr<GameBoardCell> cell = getCell(x, y);
    if (cell != NULL) {
        return cell->getShip();
    } else return NULL;
}
list<shared_ptr<Ship>> GameBoard::getListShip(const int size) const {
    if (size >= 0 && size <= MAX_SIZE_SHIP) {
        return _masShip[size];
    } else {
        list<shared_ptr<Ship>> ship;
        return ship; 
    }
}
bool GameBoard::addShipAtList(const shared_ptr<Ship> &buf) {
    if (buf != NULL && buf->getSize() <= MAX_SIZE_SHIP) {
        _masShip[buf->getSize()-1].push_back(buf);
        buf->setShipInCells();
        return true;
    } else return false;
}

bool GameBoard::rankingShip(int const count) {
    reset();
    for (int i = MAX_SIZE_SHIP - 1; i >= 0; i--) {
        int x, y, BufX, BufY;
        Direction dir;
        for (int j = _shipCount[i]-1; j >= 0; j--) {
            BufX = x = rand() % BOARD_SIZE;
            BufY = y = rand() % BOARD_SIZE;
            dir = Direction(rand() % 2);
            while (!(setFullShip(x, y, dir, i+1) || setFullShip(x, y, (Direction)(!dir), i+1))) {
                if ((y += OPTIMAZE) >= BOARD_SIZE) {
                    y -= BOARD_SIZE;
                    if ((x += OPTIMAZE) >= BOARD_SIZE) x -= BOARD_SIZE;
                } 
                if (y == BufY && x == BufX) {
                    if (count > 0) {
                        return rankingShip(count - 1);
                    } else return false;
                }
            }
        }
    }
    if (!checkFullBoard()) {
        if (count > 0) {
            return rankingShip(count - 1); 
        } else return false;
    } else return true; 
}

GameBoard::GameBoard() {
    generate();
}
GameBoard::~GameBoard() {    
    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
        _masShip[i].clear();
    }
}

GameBoard::GameBoard(const GameBoard &obj) {
    generate();
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            getCell(i, j)->setStat(obj.getCell(i, j)->getStat());
        }
    }
    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
        for (auto& it: obj.getListShip(i)) {
            if (it->checkFull()) {
                setFullShip(it->getX(), it->getY(), it->getDir(), it->getSize());
            } else {
                for (auto& it2: it->getCells()) {
                    setDeckShip(it2->getPosX(), it2->getPosY(), it->getSize());
                }
            }
        }
    }
}

void GameBoard::drawBoard(shared_ptr<Visitor> vis, bool shift) const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            getCell(i, j)->drawCell(vis, shift);
        }
    }
    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
        for (auto& it: getListShip(i)) {
            it->drawShip(vis, shift);
        }
    }
}

void GameBoard::drawRightBoard(shared_ptr<Visitor> vis) const {
    drawBoard(vis, 1);
}

void GameBoard::drawLeftBoard(shared_ptr<Visitor> vis) const {
    drawBoard(vis, 0);
}

bool GameBoard::removeShipOfList(shared_ptr<Ship> const sh) {
    int size = sh->getSize()-1;
    auto it = search_n (_masShip[size].begin(), _masShip[size].end(), 1, sh,
            [](shared_ptr<Ship> i, shared_ptr<Ship> j) -> bool {
                return (i == j);
            }
        );
    if (it != _masShip[size].end()) {
        _masShip[size].erase(it);
        return true;
    } else return false;
}


shared_ptr<Ship> NewShip1(list <shared_ptr<GameBoardCell>> buf) {
    return shared_ptr<Ship> (new Ship1(buf));
}
shared_ptr<Ship> NewShip2(list <shared_ptr<GameBoardCell>> buf) {
    return shared_ptr<Ship> (new Ship2(buf));
}
shared_ptr<Ship> NewShip3(list <shared_ptr<GameBoardCell>> buf) {
    return shared_ptr<Ship> (new Ship3(buf));
}
shared_ptr<Ship> NewShip4(list <shared_ptr<GameBoardCell>> buf) {
    return shared_ptr<Ship> (new Ship4(buf));
}
shared_ptr<Ship> (*NewShip[MAX_SIZE_SHIP])(list <shared_ptr<GameBoardCell>>) 
    = {NewShip1, NewShip2, NewShip3, NewShip4};

void GameBoard::drowAroundShip(shared_ptr<Ship> const sh) {
    const int x = sh->getX();
    const int y = sh->getY();
    const int size = sh->getCells().size();
    if (sh->getDir() == HORIZONTAL) {
        for (int i = y-1; i < y + size + 1; i++) {
            if (getCell(x-1, i)) getCell(x-1, i)->setStat(HIT);
            if (getCell(x+1, i)) getCell(x+1, i)->setStat(HIT);
        } 
        if (getCell(x, y-1))      getCell(x, y-1)   ->setStat(HIT);
        if (getCell(x, y + size)) getCell(x, y+size)->setStat(HIT);

    } else {
        for (int i = x-1; i < x + size + 1; i++) {
            if (getCell(i, y-1)) getCell(i, y-1)->setStat(HIT);
            if (getCell(i, y+1)) getCell(i, y+1)->setStat(HIT);
        }
        if (getCell(x-1, y))      getCell(x-1, y)->setStat(HIT);
        if (getCell(x + size, y)) getCell(x+size, y)->setStat(HIT);
    }
}

bool GameBoard::setFullShip(const int x, const int y, const Direction dir, const int size) {
    if (size > MAX_SIZE_SHIP) return false;
    list <shared_ptr<GameBoardCell>> mas;
    if (dir == HORIZONTAL) {
        if (y + size > BOARD_SIZE) return false;
        for (int i = 0; i < size; i++) {
            if (getCell(x, y+i) != NULL && getShip(x, y+i) == NULL 
                && getCell(x, y+i)->getStat() == EMPTY) {
                mas.push_back(getCell(x, y+i));
            } else return false;
        }
    } else {
        if (x + size > BOARD_SIZE) return false;
        for (int i = 0; i < size; i++) {
            if (getCell(x+i, y) != NULL && getShip(x+i, y) == NULL
                && getCell(x+i, y)->getStat() == EMPTY) {
                mas.push_back(getCell(x+i, y));
            } else return false;
        }
    }
    shared_ptr<Ship> buf = NewShip[size-1](mas);
    
    if (checkCellsAroundShip(buf)) {
        drowAroundShip(buf);
        return addShipAtList(buf);
    } else return false;
}

bool GameBoard::TrySetShip(const int x, const int y, const Direction dir, const int size) {
    if (dir == HORIZONTAL) {
        if (y + size > BOARD_SIZE) return false;
        for (int i = 0; i < size; i++) {
            if (getCell(x, y+i) == NULL || getShip(x, y+i) != NULL 
                || getCell(x, y+i)->getStat() != EMPTY) return false;
        }
    } else {
        if (x + size > BOARD_SIZE) return false;
        for (int i = 0; i < size; i++) {
            if (getCell(x+i, y) == NULL || getShip(x+i, y) != NULL
                || getCell(x+i, y)->getStat() != EMPTY) return false;
        }
    }
    return checkCellsAroundShip(x, y, dir, size);
}

bool GameBoard::mergeShip(shared_ptr<Ship> &oldSh, shared_ptr<Ship> &newSh) {
    if (oldSh) {
        if (oldSh->getSize() != newSh->getSize() || 
            oldSh->getCells().size() + newSh->getCells().size() > (unsigned int)newSh->getSize() ||
            !newSh->addCells(oldSh->getCells())) {
            cout << "ERROR marge two ships!!!" << endl;
            return false;
        }
        removeShipOfList(oldSh);
    } 
    return true;
}

bool GameBoard::setDeckShip(const int x, const int y, const int size) {
    if (getShip(x, y) || getCell(x, y)->getStat() != EMPTY) return false;
    shared_ptr<Ship> bufSh = NewShip[size-1](list<shared_ptr<GameBoardCell>> (1, getCell(x, y)));
    if (mergeShip(getShip(x-1, y), bufSh) & mergeShip(getShip(x, y-1), bufSh) &
        mergeShip(getShip(x+1, y), bufSh) & mergeShip(getShip(x, y+1), bufSh)) {
            if (checkCellsAroundShip(bufSh)) {
                if (bufSh->checkFull()) drowAroundShip(bufSh);
                return addShipAtList(bufSh);    
            } else return false;
    } else return false;
}

bool GameBoard::delShip (const int x, const int y) {
    if (getShip(x, y)) {
        if(!removeShipOfList(getShip(x, y))) return false;
        clear(); //�.�. ������� �������, �� � ����������� ������ ������� ���� ���� ���� ��������
        for (int i = 0; i < MAX_SIZE_SHIP; i++) { 
            for (auto& it: getListShip(i)) {
                drowAroundShip(it);
            }
        }
        return 1;
    } else return false;
}

bool GameBoard::checkCellsAroundShip(shared_ptr<Ship> const sh) const{
    return checkCellsAroundShip(sh->getX(), sh->getY(), sh->getDir(), sh->getCells().size());
}

bool GameBoard::checkCellsAroundShip(const int x, const int y, const Direction dir, const int size) const{
    if (dir == HORIZONTAL) {
        for (int i = y-1; i < y + size + 1; i++) {
            if (getShip(x-1, i) || getShip(x+1, i)) return false;
        }
        if (getShip(x, y-1) || getShip(x, y + size)) return false;
    } else {
        for (int i = x-1; i < x + size + 1; i++) {
            if (getShip(i, y-1) || getShip(i, y+1)) return false;
        }
        if(getShip(x-1, y) || getShip(x + size, y)) return false;
    }
    return 1;
}

void GameBoard::clear() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            getCell(i, j)->setStat(EMPTY);
        }
    }
}

void GameBoard::reset() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            getCell(i, j)->clearCell();
            getCell(i, j)->setStat(EMPTY);
        }
    }
    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
        _masShip[i].clear();
    }
}

bool GameBoard::checkFullBoard() const {
    list<shared_ptr<Ship>> BufShip;
    for (int i = 0; i < MAX_SIZE_SHIP; i++) {
        BufShip = getListShip(i);
        if (BufShip.size() != _shipCount[i]) return false; 
        for (auto& it: BufShip) {
            if (!it->checkFull()) return false;
        }
    }
    return true;
}

bool GameBoard::empty() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (getCell(i, j)->getStat() != EMPTY || getCell(i, j)->getShip() != nullptr) return false;
        }
    }
    return true;
}

bool GameBoard::generateShips() {
    srand(clock()+(unsigned int)time(0));
    return rankingShip(AMOUNT_GENERATION);
}

int GameBoard::getStatShot(const int x, const int y) {
    shared_ptr<GameBoardCell> buf = getCell(x, y); 
    if (!buf) return INCOR_CORD; // �������� ����������
    if (buf->getStat()) return BUSY; //���� ��� ������� 
    buf->setStat(HIT);
    if (!buf->getShip()) return MISS; //������� ���
    if (buf->getShip()->checkDestShip()) drowAroundShip(buf->getShip()); //���� ��� ������ ������� �����������, �� ���������� ���
    return SHIP + buf->getShip()->getSize(); //���������� ������ �������
}

int GameBoard::setStatShot(const int x, const int y, const int stat) {
    shared_ptr<GameBoardCell> buf = getCell(x, y);
    if (!buf) return 0; //������������ ����������
    if (buf->getStat()) {
        if (stat == -1) {
            return 1;
        } else return -1; //��������� �����
    }
    if (stat == MISS) {
        buf->setStat(HIT);
        return 1;
    } else {
        if (!setDeckShip(x, y, stat-SHIP)) return -1; ////��������� �����
        buf->setStat(HIT);
        return 1;
    }
}

int GameBoard::getStatCell(int x, int y) {
    return getCell(x, y)->getStat() + 2 * (int)!!(getCell(x, y)->getShip()); 
}