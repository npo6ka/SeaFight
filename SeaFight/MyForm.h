#pragma once


#define HEIGHT 600
#define WIDTH 800
#define HEBUT 64
#define WIBUT 192


namespace SeaFight {
  
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Threading;

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
    protected: array<array<Button^>^>^ buttonMas;
    public: Barrier^ barin;
    public: Barrier^ barout;
    public: String^ strin;
    public: Barrier^ strout;

    private: void InitializeChangeManu(void);
    private: void DisableMainManu(void);
    private: void EnableMainManu(void);
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
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button_NET_PvC);
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

        }
#pragma endregion
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}
        System::Void button_PvC(System::Object^  sender, System::EventArgs^  e) {
            HideMainManu();
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
					 this->buttonMas[i][j]->Click += gcnew System::EventHandler(this, &MyForm::buttonMas_Click);
                     this->buttonMas[i][j]->MouseHover += gcnew System::EventHandler(this, &MyForm::buttonMas_Hover);
                     this->buttonMas[i][j]->Enabled = true;
				 }
			 }
        }
        private: System::Void buttonMas_Hover(System::Object^  sender, System::EventArgs^  e) {
				 Button^ b = safe_cast<Button^>(sender);
                 b->Tag->GetType();
				 Console::WriteLine(Convert::ToString(b->Tag));
                 Point p = safe_cast<Point>(b->Tag);
				 this->buttonMas[p.X][p.Y]->Text = "lalitka";
			 }
       private: System::Void buttonMas_Click(System::Object^  sender, System::EventArgs^  e) {
				 Button^ b = safe_cast<Button^>(sender);
                 b->Tag->GetType();
				 Console::WriteLine(Convert::ToString(b->Tag));
                 Point p = safe_cast<Point>(b->Tag);
				 this->buttonMas[p.X][p.Y]->Text = "Click";
			 }
        System::Void button_PvP(System::Object^  sender, System::EventArgs^  e) {       
            this->textBox1->Text = L"button_PvP";
        }
        System::Void button_Exit(System::Object^  sender, System::EventArgs^  e) {    
            this->textBox1->Text = L"button_Exit";
            Application::Exit();
        }
        System::Void serverPVC(Object^ obj) {

        }
        System::Void button_NET_PvC(System::Object^  sender, System::EventArgs^  e) {    
            this->textBox1->Text = L"button_NET_PvC";
        }
        System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
        }
        System::Void button_changeNick(System::Object^  sender, System::EventArgs^  e) {    
            this->textBox1->Text = L"changeNick";
            panel1->Enabled = true;
            panel1->Show();
            DisableMainManu();
        }
        System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
            this->textBox1->Text = L"Menu";
            EnableMainManu();
            this->panel1->Enabled = false;
            this->panel1->Hide();
        }
        System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
            this->textBox1->Text = L"change";
            if (CheckNick(this->textBox2->Text)) {
                this->label2->Text = gcnew String(this->textBox2->Text);
                WriteInConf("name: ", this->textBox2->Text);
                this->label3->Hide();
                this->panel1->Enabled = false;
                this->panel1->Hide();
                EnableMainManu();
            } else {
                this->label3->Show();
            }    
        }
    };
}
