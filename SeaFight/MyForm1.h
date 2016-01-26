#pragma once
//#include "player.h"
#include "log.h"

class Player;
class PlayerUser;

namespace SeaFight {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Threading;

    struct Cmd {
        char com;
        int x;
        int y;
        int dir;
    };
	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm1()
		{
            delete bufCmd;
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button8;
    private: System::Windows::Forms::Button^  button9;
    private: System::Windows::Forms::Label^  label1;
    private: System::Threading::Barrier^ bar;
    private: Cmd* bufCmd;
    private: array<array<Button^>^>^ buttonMas;
    private: array<array<Button^>^>^ buttonMas2;
             bool statGame;
    //public: array<String^>^ str;
    private: System::ComponentModel::Container ^components;

    private: void InitializePlacementMenu(void);
             void Replace(void);
    private: void EnabledPlacMod(bool);
    private: System::Void ThreadServer(System::Object^ MyForm1);
    private: System::Void ThreadServerPvP(System::Object^ MyForm1);
    private: int HandlerCmd(PlayerUser*);
             void redrawLBoard(Player*, bool);
             void redrawRBoard(Player*, bool);
             void MyForm1::Player2Win();
             void MyForm1::Player1Win();
             void MyForm1::ComputerWin();
    public:  void PvP();
             void PvC();

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
            InitializePlacementMenu();
            this->SuspendLayout();
            // 
            // MyForm1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(985, 512);
            this->Name = L"MyForm1";
            this->Text = L"SeaFight";
            this->ResumeLayout(false);

        }
#pragma endregion

        System::Void button_CanselPlac(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button CanselPlac\n");
            /*this->bufCmd->dir = 0;
            this->bar->SignalAndWait();
            this->bar->SignalAndWait();*/
            this->~MyForm1();
        }
        System::Void button_NextClick(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button NextClick\n");
            this->Replace();
            this->bufCmd->dir = 1;
            this->bar->SignalAndWait();
            this->bar->SignalAndWait();
        }

        System::Void button_ShotClick1(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button ShotClick\n");
            Button^ but = safe_cast<Button^>(sender);
	        but->Tag->GetType();
	        Point point = safe_cast<Point>(but->Tag);
            this->bufCmd->com = 0;
            this->bufCmd->x = point.X;
            this->bufCmd->y = point.Y;
            this->bar->SignalAndWait();
            this->bar->SignalAndWait();
        }
        System::Void button_ShotClick2(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button ShotClick\n");
            Button^ but = safe_cast<Button^>(sender);
	        but->Tag->GetType();
	        Point point = safe_cast<Point>(but->Tag);
            this->bufCmd->com = 1;
            this->bufCmd->x = point.X;
            this->bufCmd->y = point.Y;
            this->bar->SignalAndWait();
            this->bar->SignalAndWait();
        }

        System::Void label_click(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on label_click\n");
            this->~MyForm1();
        }
        

        System::Void button_VoidClick(System::Object^  sender, System::EventArgs^  e) {}
        private: System::Void buttonMas_Hover(System::Object^  sender, System::EventArgs^  e) {
                 outlog("th: MyForm: mouse hover above button when placement of ships\n");
				 Button^ b = safe_cast<Button^>(sender);
                 b->Tag->GetType();
				 Console::WriteLine(Convert::ToString(b->Tag));
                 Point p = safe_cast<Point>(b->Tag);
				 this->buttonMas[p.X][p.Y]->Text = "lalitka";
			 }
        private: System::Void buttonMas_Click(System::Object^  sender, System::EventArgs^  e) {
                 outlog("th: MyForm: User click on button when placement of ships\n");
				 Button^ b = safe_cast<Button^>(sender);
                 b->Tag->GetType();
				 Console::WriteLine(Convert::ToString(b->Tag));
                 Point p = safe_cast<Point>(b->Tag);
				 this->buttonMas[p.X][p.Y]->Text = "Click";
			}
         private: System::Void CloseForm(System::Object^  sender, FormClosingEventArgs^  e) {
                 this->bufCmd->dir = 0;
                 this->bar->SignalAndWait();
                 this->bar->SignalAndWait();                 
            }
        System::Void OpenForm(System::Object^  sender, System::EventArgs^  e) {
            if (statGame) {
                Thread^ trd1 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm1::ThreadServer));
                trd1->Start(this);
            } else {
                Thread^ trd1 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm1::ThreadServerPvP));
                trd1->Start(this);
                this->Replace();
                for (int i = 0; i <10; i++)
                    for (int j=0; j<10; j++)
                        this->buttonMas[i][j]->Click += gcnew System::EventHandler(this, &MyForm1::button_ShotClick1);
            }
        }
	};
}
