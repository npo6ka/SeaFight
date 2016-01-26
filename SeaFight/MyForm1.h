#pragma once
#include "log.h"
#include "player.h"

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
    private: System::Threading::Barrier^ bar;
    private: Cmd* bufCmd;
    private: array<array<Button^>^>^ buttonMas;
    //public: array<String^>^ str;
    private: System::ComponentModel::Container ^components;

    private: void InitializePlacementMenu(void);
    private: void EnabledPlacMod(bool);
    private: System::Void ThreadServer(System::Object^ MyForm1);
//    private: void HandlerCmd(Player*);

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
            /*EnabledPlacMod(false);
            this->str[0] = "ex";
            this->barr[0]->SignalAndWait();
            outlog("th: MyForm: send msg \"ex\"\n");
            ShowMainManu();*/
            this->~MyForm1();
        }
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
	};
}
