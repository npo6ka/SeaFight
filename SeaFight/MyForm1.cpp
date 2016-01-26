#include "MyForm1.h"
#include "Player.h"

enum {
    G_EMPT = 0,
    G_MISS = 1,
    G_DECK = 2,
    G_SHDC = 3,
};

enum statShot{
    INCOR_CORD,
    BUSY,
    MISS,
    SHIP
};

using namespace System;
using namespace System::IO;


namespace SeaFight 
{
    void MyForm1::redrawLBoard(Player* pl, bool fl) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int st;
                if (fl) st = pl->getStatOpCell(i, j);
                else st = pl->getStatMyCell(i, j);
                if (st == G_EMPT) {
                    this->buttonMas[i][j]->BackColor = Drawing::Color::Yellow;
                } else if (st == G_MISS) {
                    this->buttonMas[i][j]->BackColor = Drawing::Color::Aqua;
                } else if (st == G_DECK) {
                    this->buttonMas[i][j]->BackColor = Drawing::Color::Black;
                } else if (st == G_SHDC) {
                    this->buttonMas[i][j]->BackColor = Drawing::Color::Red;
                }
            }
        }
    }

    void MyForm1::redrawRBoard(Player* pl, bool fl) {
       for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int st;
                if (fl) st = pl->getStatOpCell(i, j);
                else st = pl->getStatMyCell(i, j);
                if (st == G_EMPT) {
                    this->buttonMas2[i][j]->BackColor = Drawing::Color::Yellow;
                } else if (st == G_MISS) {
                    this->buttonMas2[i][j]->BackColor = Drawing::Color::Aqua;
                } else if (st == G_DECK) {
                    this->buttonMas2[i][j]->BackColor = Drawing::Color::Black;
                } else if (st == G_SHDC) {
                    this->buttonMas2[i][j]->BackColor = Drawing::Color::Red;
                }
            }
        }
    }

    int MyForm1::HandlerCmd(PlayerUser* pl) {
        switch(this->bufCmd->com) {
        case 'n':
            return pl->setShip(this->bufCmd->x, this->bufCmd->y, this->bufCmd->dir, 1);
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
        }
        return 0;
    }
     
    void MyForm1::Player1Win() {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {

                this->buttonMas[i][j]->Enabled = false;
                this->buttonMas[i][j]->Hide();
                this->buttonMas2[i][j]->Enabled = false;
                this->buttonMas2[i][j]->Hide();

                this->label1->Text = L"Player1 WINS!!!";
                this->label1->Show();
		    }
		}
    }

    void MyForm1::Player2Win() {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {

                this->buttonMas[i][j]->Enabled = false;
                this->buttonMas[i][j]->Hide();
                this->buttonMas2[i][j]->Enabled = false;
                this->buttonMas2[i][j]->Hide();

                this->label1->Text = L"Player2 WINS!!!";
                this->label1->Show();
		    }
		}
    }
    void MyForm1::ComputerWin() {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {

                this->buttonMas[i][j]->Enabled = false;
                this->buttonMas[i][j]->Hide();
                this->buttonMas2[i][j]->Enabled = false;
                this->buttonMas2[i][j]->Hide();
                
                this->label1->Text = L"Computer WINS!!!";
                this->label1->Show();
		    }
		}
    }

    System::Void MyForm1::ThreadServer(System::Object^ obj) {
        outlog("th: server: start\n");
        PlayerUser* user = new PlayerUser();
        PlayerComp* comp = new PlayerComp();

        //установка кораблей компьютером
        comp->resetBoards();
        if (!comp->autoSetShips()) {
            outlog("th: server: Error auto set ship. Stop thread");
            return;
        }
        //установка кораблей игроком
        user->resetBoards();
        if (!user->autoSetShips()) {
            outlog("th: server: Error auto set ship. Stop thread");
            return;
        }
        user->clearBoards();
        comp->clearBoards();
        this->redrawLBoard(user, false);
        this->bar->SignalAndWait();
        if (!this->bufCmd->dir) {
            outlog("th: server: user left the game\n");
            this->bar->SignalAndWait();
            return;
        }
        this->bar->SignalAndWait();
        this->redrawRBoard(user, true);
        this->redrawRBoard(comp, true);
        bool fl = !rand()%2;
        int st = 0, x = 0, y = 0;
        this->bufCmd->dir = 1;
        //DisableAll();
        //this->Invoke(gcnew Action(this, &MyForm1::DisableAll));
        while (this->bufCmd->dir) {
            if (fl) {
                this->bar->SignalAndWait();
                x = this->bufCmd->x;
                y = this->bufCmd->y;
                this->bar->SignalAndWait();
                st = comp->getStatShot(x, y);
                Console::WriteLine("USer Shot to {0} {1} have stat: {2}", x, y, st);
                if (st == MISS) { 
                    user->setStatShot(x, y, st);
                    fl = !fl;
                } else if (st >= SHIP) {
                    st = user->setStatShot(x, y, st);
                    if (st == -1) {
                        outlog("fack the program\n");
                        return;
                    }
                    if (user->checkWin()) {
                        outlog("Player win\n");
                        this->Invoke(gcnew Action(this, &MyForm1::Player1Win));
                        this->bar->SignalAndWait();
                        this->bar->SignalAndWait();
                        break;
                    }
                }
                redrawRBoard(user, true);
            } else {
                x = rand()%10;
                y = rand()%10;
                st = user->getStatShot(x, y);
                Console::WriteLine("Comp Shot to {0} {1} have stat: {2}", x, y, st);
                if (st == MISS) { 
                    comp->setStatShot(x, y, st);
                    fl = !fl;
                } else if (st >= SHIP) {
                    st = comp->setStatShot(x, y, st);
                    if (st == -1) {
                        outlog("fack the program\n");
                        return;
                    }
                    if (comp->checkWin()) {
                        outlog("Computer win\n");
                        this->Invoke(gcnew Action(this, &MyForm1::ComputerWin));
                        this->bar->SignalAndWait();
                        this->bar->SignalAndWait();
                        break;
                    }
                }
                redrawLBoard(comp, true);
            }
        }
        outlog("Th: server: stop\n");
    }

    System::Void MyForm1::ThreadServerPvP(System::Object^ obj) {
        outlog("th: server: start\n");
        PlayerUser* user = new PlayerUser();
        PlayerUser* user2 = new PlayerUser();

        //установка кораблей компьютером
        user2->resetBoards();
        if (!user2->autoSetShips()) {
            outlog("th: server: Error auto set ship. Stop thread");
            return;
        }
        //установка кораблей игроком
        user->resetBoards();
        if (!user->autoSetShips()) {
            outlog("th: server: Error auto set ship. Stop thread");
            return;
        }
        user->clearBoards();
        user2->clearBoards();
        this->redrawRBoard(user, true);
        this->redrawLBoard(user2, true);
        bool fl = !rand()%2;
        int st = 0, x = 0, y = 0;
        this->bufCmd->dir = 1;
        //DisableAll();
        //this->Invoke(gcnew Action(this, &MyForm1::DisableAll));
        while (this->bufCmd->dir) {
            if (fl) {
                this->bar->SignalAndWait();
                if (!bufCmd->com) {
                    this->bar->SignalAndWait();
                    continue;
                }
                x = this->bufCmd->x;
                y = this->bufCmd->y;
                this->bar->SignalAndWait();
                st = user2->getStatShot(x, y);
                Console::WriteLine("USer Shot to {0} {1} have stat: {2}", x, y, st);
                if (st == MISS) { 
                    user->setStatShot(x, y, st);
                    fl = !fl;
                } else if (st >= SHIP) {
                    st = user->setStatShot(x, y, st);
                    if (st == -1) {
                        outlog("fack the program\n");
                        return;
                    }
                    if (user->checkWin()) {
                        outlog("Player1 win\n");
                        this->Invoke(gcnew Action(this, &MyForm1::Player1Win));
                        this->bar->SignalAndWait();
                        this->bar->SignalAndWait();
                        break;
                    }
                }
                redrawRBoard(user, true);
            } else {
                this->bar->SignalAndWait();
                if (bufCmd->com) {
                    this->bar->SignalAndWait();
                    continue;
                }
                x = this->bufCmd->x;
                y = this->bufCmd->y;
                this->bar->SignalAndWait();
                st = user->getStatShot(x, y);
                Console::WriteLine("Comp Shot to {0} {1} have stat: {2}", x, y, st);
                if (st == MISS) { 
                    user2->setStatShot(x, y, st);
                    fl = !fl;
                } else if (st >= SHIP) {
                    st = user2->setStatShot(x, y, st);
                    if (st == -1) {
                        outlog("fack the program\n");
                        return;
                    }
                    if (user2->checkWin()) {
                        outlog("Player2 win\n");
                        this->Invoke(gcnew Action(this, &MyForm1::Player2Win));
                        this->bar->SignalAndWait();
                        this->bar->SignalAndWait();
                        break;
                    }
                }
                redrawLBoard(user2, true);
            }
        }
        outlog("Th: server: stop\n");
    }

    void MyForm1::Replace() {
        this->button8->Enabled = false;
        this->button9->Enabled = false;
        this->button8->Hide();
        this->button9->Hide();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                this->buttonMas[i][j]->Size = Drawing::Size(36, 36);
                this->buttonMas[i][j]->Location = System::Drawing::Point(40 + 36 * j, 80 + 36 * i); //+80 -30
                this->buttonMas[i][j]->Click -= gcnew System::EventHandler(this, &MyForm1::buttonMas_Click);
                this->buttonMas[i][j]->MouseHover -= gcnew System::EventHandler(this, &MyForm1::buttonMas_Hover);

                this->buttonMas2[i][j]->Enabled = true;
                this->buttonMas2[i][j]->Show();
		    }
		}
    }

    void MyForm1::InitializePlacementMenu() {
        outlog("th: MyForm: start initialialize Component Placement mod\n");
        this->buttonMas = gcnew array<array<Button^>^>(10);
        this->buttonMas2 = gcnew array<array<Button^>^>(10);
		for (int i = 0; i < 10; ++i) {
            this->buttonMas[i] = gcnew array<Button^>(10);
            this->buttonMas2[i] = gcnew array<Button^>(10);
            for (int j = 0; j < 10; ++j) {
                this->buttonMas[i][j] = gcnew Button();
                this->buttonMas[i][j]->Size = Drawing::Size(48, 48);
                this->buttonMas[i][j]->Text = i.ToString() + j.ToString();
                this->buttonMas[i][j]->Location = System::Drawing::Point(230 + 48 * j, 10 + 48 * i); //+80 -30
                Controls->Add(this->buttonMas[i][j]);
                this->buttonMas[i][j]->Tag = Point(i, j);
                this->buttonMas[i][j]->Click += gcnew System::EventHandler(this, &MyForm1::buttonMas_Click);
                this->buttonMas[i][j]->MouseHover += gcnew System::EventHandler(this, &MyForm1::buttonMas_Hover);
                this->buttonMas[i][j]->Enabled = true;
                this->buttonMas[i][j]->Show();

                this->buttonMas2[i][j] = gcnew Button();
                this->buttonMas2[i][j]->Size = Drawing::Size(36, 36);
                this->buttonMas2[i][j]->Text = i.ToString() + j.ToString();
                this->buttonMas2[i][j]->Location = System::Drawing::Point(580 + 36 * j, 80 + 36 * i);
                Controls->Add(this->buttonMas2[i][j]);
                this->buttonMas2[i][j]->Tag = Point(i, j);
                this->buttonMas2[i][j]->Click += gcnew System::EventHandler(this, &MyForm1::button_ShotClick2);
                this->buttonMas2[i][j]->Enabled = false;
                this->buttonMas2[i][j]->Hide();

		    }
		}

        this->button8 = (gcnew System::Windows::Forms::Button());
        this->button9 = (gcnew System::Windows::Forms::Button());
        this->label1 = (gcnew System::Windows::Forms::Label());
        // 
        // button8
        // 
        this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(204)));
        this->button8->Location = System::Drawing::Point(105, 450);
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
        this->button9->Location = System::Drawing::Point(730, 450);
        this->button9->Name = L"button9";
        this->button9->Size = System::Drawing::Size(106, 39);
        this->button9->TabIndex = 15;
        this->button9->Text = L"В бой >>";
        this->button9->UseVisualStyleBackColor = true;
        this->button9->Click += gcnew System::EventHandler(this, &MyForm1::button_NextClick);


        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 40.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(300, 200);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(187, 36);
        this->label1->TabIndex = 6;
        this->label1->Click += gcnew System::EventHandler(this, &MyForm1::label_click);
        //this->label1->Hide();

        this->Controls->Add(this->button8);
        this->Controls->Add(this->button9);
        this->Controls->Add(this->label1);
        this->bufCmd = new Cmd;
        this->bar = gcnew Barrier(2);

        this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm1::CloseForm);
        this->Load += gcnew System::EventHandler(this, &MyForm1::OpenForm);
        
        
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
    void MyForm1::PvP() {
        statGame = false;
    }
    void MyForm1::PvC() {
        statGame = true;
    }
}