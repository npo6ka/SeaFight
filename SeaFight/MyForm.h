#pragma once


#define HEIGHT 600
#define WIDTH 800
#define HEBUT 64
#define WIBUT 192
#define SETFILE "setting.txt"

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
            statMenu = 0;
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
    private: int statMenu;
    private: bool WriteInConf(String^, String^);
    private: System::Windows::Forms::Button^  button1;
    protected: 
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::Button^  button3;
    private: System::Windows::Forms::Button^  button5;
    private: System::Windows::Forms::Button^  button6;
    private: System::Windows::Forms::TextBox^  textBox1;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Panel^  panel1;
    private: System::Windows::Forms::TextBox^  textBox2;
    private: System::Windows::Forms::Button^  button7;
    private: System::Windows::Forms::Button^  button4;
    private: System::Windows::Forms::Label^  label3;
    private: System::Windows::Forms::Label^  label4;



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->panel1->SuspendLayout();
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
            this->button3->Location = System::Drawing::Point(436, 301);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(192, 64);
            this->button3->TabIndex = 2;
            this->button3->Text = L"Exit";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button_Exit);
            // 
            // button5
            // 
            this->button5->Location = System::Drawing::Point(139, 301);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(192, 64);
            this->button5->TabIndex = 4;
            this->button5->Text = L"Net PvP";
            this->button5->UseVisualStyleBackColor = true;
            this->button5->Click += gcnew System::EventHandler(this, &MyForm::button_NET_PvC);
            // 
            // button6
            // 
            this->button6->Location = System::Drawing::Point(436, 161);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(192, 64);
            this->button6->TabIndex = 3;
            this->button6->Text = L"change nick";
            this->button6->UseVisualStyleBackColor = true;
            this->button6->Click += gcnew System::EventHandler(this, &MyForm::button_changeNick);
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
            // panel1
            // 
            this->panel1->AutoSize = true;
            this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel1->Controls->Add(this->label4);
            this->panel1->Controls->Add(this->label3);
            this->panel1->Controls->Add(this->textBox2);
            this->panel1->Controls->Add(this->button7);
            this->panel1->Controls->Add(this->button4);
            this->panel1->Location = System::Drawing::Point(255, 200);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(271, 185);
            this->panel1->TabIndex = 8;
            this->panel1->Hide();
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(204)));
            this->label4->Location = System::Drawing::Point(27, 14);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(213, 29);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Смена никнейма";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(204)));
            this->label3->ForeColor = System::Drawing::Color::Red;
            this->label3->Location = System::Drawing::Point(42, 92);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(186, 20);
            this->label3->TabIndex = 3;
            this->label3->Text = L"Некорректные данные!";
            this->label3->Hide();
            // 
            // textBox2
            // 
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(204)));
            this->textBox2->Location = System::Drawing::Point(16, 56);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(238, 29);
            this->textBox2->TabIndex = 2;
            // 
            // button7
            // 
            this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(204)));
            this->button7->Location = System::Drawing::Point(148, 131);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(106, 39);
            this->button7->TabIndex = 1;
            this->button7->Text = L"отмена";
            this->button7->UseVisualStyleBackColor = true;
            this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
            // 
            // button4
            // 
            this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(204)));
            this->button4->Location = System::Drawing::Point(16, 131);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(106, 39);
            this->button4->TabIndex = 0;
            this->button4->Text = L"изменить";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 561);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button6);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->ForeColor = System::Drawing::Color::Black;
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"SeaFight";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}
        System::Void button_PvC(System::Object^  sender, System::EventArgs^  e) {
            if (statMenu == 0) {
                this->textBox1->Text = L"button_PvC";
            }
        }
        System::Void button_PvP(System::Object^  sender, System::EventArgs^  e) {      
            if (statMenu == 0) {
                this->textBox1->Text = L"button_PvP";
            }
        }
        System::Void button_Exit(System::Object^  sender, System::EventArgs^  e) {    
            if (statMenu == 0) {
                this->textBox1->Text = L"button_Exit";
            }
        }
        System::Void button_NET_PvC(System::Object^  sender, System::EventArgs^  e) {    
            if (statMenu == 0) {
                this->textBox1->Text = L"button_NET_PvC";
            }
        }
        System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
        }
        System::Void button_changeNick(System::Object^  sender, System::EventArgs^  e) {    
            if (statMenu == 0) {
                this->textBox1->Text = L"changeNick";
                this->panel1->Show();
                statMenu = 1;
            }
        }
        System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
            if (statMenu == 1) {
                this->textBox1->Text = L"Menu";
                this->panel1->Hide();
                statMenu = 0;
            }
        }
        System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
            if (statMenu == 1) {
                this->textBox1->Text = L"change";
                if (CheckNick(this->textBox2->Text)) {
                    this->label2->Text = gcnew String(this->textBox2->Text);
                    WriteInConf("name: ", this->textBox2->Text);
                    this->label3->Hide();
                    this->panel1->Hide();
                    statMenu = 0;
                } else {
                    this->label3->Show();
                }
            }      
        }
};
}
