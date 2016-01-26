#pragma once
//#include "threads.h"
#include "MyForm1.h"
/*
#define HEIGHT 600
#define WIDTH 800
#define HEBUT 64
#define WIBUT 192*/


namespace SeaFight {
  
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{   
			InitializeComponent();
            
            this->label2->Text = getNickFromConf();
            this->textBox2->Text = this->label2->Text;

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: String^ getNickFromConf();
    private: bool CheckNick(String^);
    private: bool WriteInConf(String^, String^);
    Void threadSenderClient(System::Object^);

    private: void InitializeChangeManu(void);
    private: void EnabledMainManu(bool);
    private: void HideMainManu(void);
    private: void ShowMainManu(void);

    private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::Button^  button3;
    private: System::Windows::Forms::Button^  button4;
    private: System::Windows::Forms::Button^  button5;
    private: System::Windows::Forms::Button^  button6;
    private: System::Windows::Forms::Button^  button7;

    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::Label^  label4;
    private: System::Windows::Forms::Panel^  panel1;
    private: System::Windows::Forms::TextBox^  textBox2;
    private: System::Windows::Forms::TextBox^  textBox1;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
            outlog("th: MyForm: start initialialize Component maim menu\n");
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(139, 161);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(192, 64);
            this->button1->TabIndex = 0;
            this->button1->Text = L"PvC";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button_PvC);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(139, 231);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(192, 64);
            this->button2->TabIndex = 1;
            this->button2->Text = L"PvP";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button_PvP);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(139, 301);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(192, 64);
            this->button3->TabIndex = 2;
            this->button3->Text = L"Net PvP";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button_NET_PvP);
            this->button3->Enabled = false;
            // 
            // button4
            // 
            this->button4->Location = System::Drawing::Point(436, 161);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(192, 64);
            this->button4->TabIndex = 3;
            this->button4->Text = L"change nick";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button_changeNick);
            // 
            // button5
            // 
            this->button5->Location = System::Drawing::Point(436, 301);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(192, 64);
            this->button5->TabIndex = 4;
            this->button5->Text = L"Exit";
            this->button5->UseVisualStyleBackColor = true;
            this->button5->Click += gcnew System::EventHandler(this, &MyForm::button_Exit);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(176, 516);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(187, 36);
            this->label1->TabIndex = 6;
            this->label1->Text = L"your nickname: ";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Ravie", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(369, 518);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(58, 30);
            this->label2->TabIndex = 7;
            this->label2->Text = L"123";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(336, 84);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(100, 20);
            this->textBox1->TabIndex = 5;
            this->textBox1->Text = L"что то";
            this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(0, 0);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(100, 20);
            this->textBox2->TabIndex = 0;
            // 
            // MyForm
            // 
            InitializeChangeManu();

            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 561);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->ForeColor = System::Drawing::Color::Black;
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"SeaFight";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
            outlog("th: MyForm: initialialize Component maim menu completed\n");
        }
#pragma endregion
        private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}
        private: System::Void button_PvC(System::Object^  sender, System::EventArgs^  e) {
                outlog("th: MyForm: User click on button PvC\n");
                /*HideMainManu();
                EnabledPlacMod(true);
                Thread^ trd1 = gcnew Thread(gcnew ParameterizedThreadStart(&threadServer));
                trd1->Start(this);
                Thread^ trd2 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm::threadSenderClient));
                trd2->Start(this);*/
                MyForm1^ form1 = gcnew MyForm1;
                this->Hide();
                form1->ShowDialog();
                this->Show();
                /*Thread^ thr = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm::ThreadFunc));
                thr->Start(true);*/
            }
        System::Void button_PvP(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button PvP\n");
            this->textBox1->Text = L"button_PvP";
        }
        System::Void button_Exit(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button Exit\n");
            this->textBox1->Text = L"button_Exit";
            Application::Exit();
        }
        System::Void button_NET_PvP(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button network PvP\n");
            this->textBox1->Text = L"button_NET_PvC";
        }
        System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
        }
        System::Void button_changeNick(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button chenge nickname\n");
            this->textBox1->Text = L"changeNick";
            panel1->Enabled = true;
            panel1->Show();
            EnabledMainManu(false);
        }
        System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button cancel in a state of chenge nickname\n");
            this->textBox1->Text = L"Menu";
            EnabledMainManu(true);
            this->panel1->Enabled = false;
            this->panel1->Hide();
        }
        System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
            outlog("th: MyForm: User click on button apply in a state of chenge nickname\n");
            this->textBox1->Text = L"change";
            if (CheckNick(this->textBox2->Text)) {
                this->label2->Text = gcnew String(this->textBox2->Text);
                WriteInConf("name: ", this->textBox2->Text);
                this->label3->Hide();
                this->panel1->Enabled = false;
                this->panel1->Hide();
                EnabledMainManu(true);
                outlog("th: MyForm: successful change nickname\n");
            } else {
                outlog("th: MyForm: failed change nickname\n");
                this->label3->Show();
            }    
        }
    };
}
