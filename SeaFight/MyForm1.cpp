#include "MyForm1.h"
#include "Player.h"


using namespace System;
using namespace System::IO;

namespace SeaFight 
{
    /*void redrawLBoard() {
        
    }

    int MyForm1::HandlerCmd(PlayerUser* pl) {
        switch(this->bufCmd->com) {
        case 'n':
            return pl->setShip(this->bufCmd->x, this->bufCmd->y, (Direction)this->bufCmd->dir, 1);
            break;
        case 'd':
            return pl->delShip(this->bufCmd->x, this->bufCmd->y);
            break;
        case 'c':
            //----
            break;
        case 'a':
            return pl->autoSetShips();
            break;
        case 'r':
            return pl->checkBoard();
            break;
        case 'e':
            return -1;
            break;
        case 'n':

            break;
        case 'n':

            break;

        }
        return 0;
    }*/

    System::Void MyForm1::ThreadServer(System::Object^ obj) {
        outlog("th: server: start\n");
        PlayerUser* user = new PlayerUser();
        PlayerComp* comp = new PlayerComp();

        //установка кораблей компьютером
        //user->getMyBoard()->reset();
        //comp->getOpBoard()->reset();
        if (!comp->autoSetShips()) {
            outlog("th: server: Error auto set ship");
            return;
        }

        //установка кораблей игроком
        //user->getMyBoard()->reset();
        //user->getOpBoard()->reset();
        bool i = user->setShip(5,5,0, 1);
        /*while (this->bufCmd->com != 'r' || this->bufCmd->com != 'e') {
            this->bar->SignalAndWait();
            HandlerCmd(user);
            this->bar->SignalAndWait();
        }*/

        /*while (1) {
            str = msgReceive("Server", 1, obj);
        }*/
        
            //vis->clear();
            //vis->PrintFrame("", players[i-1]->getNick());

            /*if (!players[i-1]->setShips(vis)) return false;
            players[i-1]->clearBoards();*/

        /*int move = 0, size = players.size(), stat = 0;
        pair<int, int> buf;
        while (1) {
            vis->clear();
            vis->PrintFrame(players[getNextId(move, size)]->getNick(), players[move]->getNick());
            players[getPrevId(move, size)]->getOpBoard()->drawRightBoard(vis);
            players[move]->getOpBoard()->drawLeftBoard(vis);
            buf = players[move]->readMove(vis);
            if (buf.first == -2) return 0;
            stat = players[getNextId(move, size)]->getStatShot(buf.first, buf.second);
            if (stat == MISS) { 
                players[move]->setStatShot(buf.first, buf.second, stat);
                players[move]->getOpBoard()->drawLeftBoard(vis);
                move = getNextId(move, size);
                Sleep(1000);
            } else if (stat >= SHIP) {
                stat = players[move]->setStatShot(buf.first, buf.second, stat);
                if (players[move]->checkWin()) {
                    vis->PrintWin(players[move]->getNick());
                    return 1;
                }
                players[move]->getOpBoard()->drawLeftBoard(vis);
                Sleep(1000);
            } else vis->PrintMsg("incorrect shot");
        }*/
        outlog("Th: server: stop\n");
    }
    //Button System::Array<Button^>^ buf;
    void MyForm1::InitializePlacementMenu() {
        outlog("th: MyForm: start initialialize Component Placement mod\n");
        this->buttonMas = gcnew array<array<Button^>^>(10);
		for (int i = 0; i < 10; ++i) {
            this->buttonMas[i] = gcnew array<Button^>(10);
            for (int j = 0; j < 10; ++j) {
                this->buttonMas[i][j] = gcnew Button();
                this->buttonMas[i][j]->Size = Drawing::Size(48, 48);
                this->buttonMas[i][j]->Text = i.ToString() + j.ToString();
                this->buttonMas[i][j]->Location = System::Drawing::Point(150 + 48 * j, 40 + 48 * i);
                Controls->Add(this->buttonMas[i][j]);
                this->buttonMas[i][j]->Tag = Point(i, j);
                this->buttonMas[i][j]->Click += gcnew System::EventHandler(this, &MyForm1::buttonMas_Click);
                this->buttonMas[i][j]->MouseHover += gcnew System::EventHandler(this, &MyForm1::buttonMas_Hover);
                this->buttonMas[i][j]->Enabled = true;
		    }
		}
        this->button8 = (gcnew System::Windows::Forms::Button());
        this->button9 = (gcnew System::Windows::Forms::Button());
        // 
        // button8
        // 
        this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(204)));
        this->button8->Location = System::Drawing::Point(25, 480);
        this->button8->Name = L"button8";
        this->button8->Size = System::Drawing::Size(106, 39);
        this->button8->TabIndex = 8;
        this->button8->Text = L"<< назад";
        this->button8->UseVisualStyleBackColor = true;
        this->button8->Click += gcnew System::EventHandler(this, &MyForm1::button_CanselPlac);
        // 
        // button9
        // 
        this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(204)));
        this->button9->Location = System::Drawing::Point(650, 480);
        this->button9->Name = L"button9";
        this->button9->Size = System::Drawing::Size(106, 39);
        this->button9->TabIndex = 15;
        this->button9->Text = L"В бой >>";
        this->button9->UseVisualStyleBackColor = true;
        //this->button9->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);

        this->Controls->Add(this->button8);
        this->Controls->Add(this->button9);
        this->bufCmd = new Cmd;
        this->bar = gcnew Barrier(2);

        Thread^ trd1 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm1::ThreadServer));
        trd1->Start(this);

        /*this->barr = gcnew array<Barrier^>(3);
        barr[0] = gcnew Barrier(2);
        barr[1] = gcnew Barrier(2);
        barr[2] = gcnew Barrier(2);
        this->str = gcnew array<String^>(3);
        str[0] = gcnew String("");
        str[1] = gcnew String("");
        str[2] = gcnew String("");*/
        
        /*this->ex = gcnew array<Exch*>(3);
        this->ex[0] = new Exch();*/
        outlog("th: MyForm: initialialize Component Placement mod completed\n");
    }

    void MyForm1::EnabledPlacMod(bool fl) {
        for (int i=0; i<10; i++)
            for (int j=0; j<10; j++) 
                this->buttonMas[i][j]->Enabled = fl;
        this->button8->Enabled = fl;
        this->button9->Enabled = fl;
        if (fl) {
            for (int i=0; i<10; i++)
                for (int j=0; j<10; j++) 
                    this->buttonMas[i][j]->Show();
            this->button8->Show();
            this->button9->Show();
        } else {
            for (int i=0; i<10; i++)
                for (int j=0; j<10; j++) 
                    this->buttonMas[i][j]->Hide();
            this->button8->Hide();
            this->button9->Hide();
        }
    }
}