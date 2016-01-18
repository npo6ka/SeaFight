#include "MyForm.h"
#include "iostream"
#include <msclr\marshal_cppstd.h>


using namespace System;
using namespace System::IO;

#define SETFILE "setting.txt"

namespace SeaFight 
{
    String^ MyForm::getNickFromConf() 
    {
        String^ path = "setting.cfg";
        if (  !File::Exists( path ) ) {
            FileStream^ fs = File::Create( path );
            if ( fs ) delete (IDisposable^)fs;
        }
        StreamReader^ sr = File::OpenText( path );
        try
        {
            path = "";
            String^ s = "";
            while ( s = sr->ReadLine() )
            {
                int count = s->LastIndexOf("name: ");
                if (count != -1) {
                    path = s->Substring(count + 6);
                    break;
                }
            }
        }
        finally
        {
            if ( sr )
                delete (IDisposable^)(sr);
        }
        if (CheckNick(path)) {
            return path;
        } else {
            WriteInConf("name: ", "Player");
            return "Player";
        }
    }
    bool MyForm::CheckNick(String^ str) {
        std::string nick = msclr::interop::marshal_as<std::string>(str);
        if (nick.find_first_not_of
        ("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ_") 
        != std::string::npos || str->Length > 20 || !str->Length) {
            return false; // неккоректный никнейм
        } else {
            return true; // всё хорошо
        }
    }

    bool MyForm::WriteInConf(String^ find, String^ insert) {
        String^ path = "setting.cfg";
        if (  !File::Exists( path ) ) {
            FileStream^ fs = File::Create( path );
            if ( fs ) delete (IDisposable^)fs;
        }
        String^ buf;
        StreamReader^ sr = File::OpenText( path );
        try {
            buf = sr->ReadToEnd();
        }
        finally {
            if ( sr )
                delete (IDisposable^)(sr);
        }
        int EndPos = 0;
        int FirPos = buf->LastIndexOf(find);
        if (FirPos != -1) {
            int i = FirPos;
            while(i < buf->Length && buf[i] != 13 && buf[i] != 10) i++;
            EndPos = i;
            i = FirPos;
            while(i >= 0 && buf[i] != 13 && buf[i] != 10) i--;
            FirPos = i+1;
        } else FirPos = 0;
        buf = buf->Substring(0, FirPos) + find + insert + buf->Substring(EndPos, buf->Length - EndPos);

        File::Delete( path );
        StreamWriter^ sw = File::CreateText( path );
        try {
            sw->Write(buf);
        }
        finally {
            if ( sr )
                delete (IDisposable^)(sw);
        }
        return true;
    }

    void MyForm::InitializeChangeManu() {
        outlog("th: MyForm: start initialialize Component chenge menu\n");
        this->button6  = (gcnew System::Windows::Forms::Button());
        this->button7  = (gcnew System::Windows::Forms::Button());
        this->panel1   = (gcnew System::Windows::Forms::Panel());
        this->label3   = (gcnew System::Windows::Forms::Label());
        this->label4   = (gcnew System::Windows::Forms::Label());

        this->panel1->SuspendLayout();
        this->SuspendLayout();
        // 
        // button6
        // 
        this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(204)));
        this->button6->Location = System::Drawing::Point(148, 131);
        this->button6->Name = L"button6";
        this->button6->Size = System::Drawing::Size(106, 39);
        this->button6->TabIndex = 10;
        this->button6->Text = L"отмена";
        this->button6->UseVisualStyleBackColor = true;
        this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
        // 
        // button7
        // 
        this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(204)));
        this->button7->Location = System::Drawing::Point(16, 131);
        this->button7->Name = L"button7";
        this->button7->Size = System::Drawing::Size(106, 39);
        this->button7->TabIndex = 11;
        this->button7->Text = L"изменить";
        this->button7->UseVisualStyleBackColor = true;
        this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
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
        this->label3->TabIndex = 12;
        this->label3->Text = L"Некорректные данные!";
        this->label3->Hide();
        // 
        // label4
        // 
        this->label4->AutoSize = true;
        this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(204)));
        this->label4->Location = System::Drawing::Point(27, 14);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(213, 29);
        this->label4->TabIndex = 13;
        this->label4->Text = L"Смена никнейма";
        // 
        // textBox2
        // 
        this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
            static_cast<System::Byte>(204)));
        this->textBox2->Location = System::Drawing::Point(16, 56);
        this->textBox2->Name = L"textBox2";
        this->textBox2->Size = System::Drawing::Size(238, 29);
        this->textBox2->TabIndex = 14;
        // 
        // panel1
        // 
        this->panel1->AutoSize = true;
        this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel1->Controls->Add(this->label4);
        this->panel1->Controls->Add(this->label3);
        this->panel1->Controls->Add(this->textBox2);
        this->panel1->Controls->Add(this->button6);
        this->panel1->Controls->Add(this->button7);
        this->panel1->Location = System::Drawing::Point(255, 200);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(271, 185);
        this->panel1->TabIndex = 9;
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        
        this->panel1->Enabled = false;
        this->panel1->Hide();

        this->barr = gcnew array<Barrier^>(3);
        barr[0] = gcnew Barrier(2);
        barr[1] = gcnew Barrier(2);
        barr[2] = gcnew Barrier(2);
        this->str = gcnew array<String^>(3);
        str[0] = gcnew String("");
        str[1] = gcnew String("");
        str[2] = gcnew String("");
        
        this->ex = gcnew array<Exch*>(3);
        this->ex[0] = new Exch();
        outlog("th: MyForm: initialialize Component chenge menu completed\n");
    }
    void MyForm::InitializePlacementMenu() {
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
                this->buttonMas[i][j]->Click += gcnew System::EventHandler(this, &MyForm::buttonMas_Click);
                this->buttonMas[i][j]->MouseHover += gcnew System::EventHandler(this, &MyForm::buttonMas_Hover);
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
        this->button8->Click += gcnew System::EventHandler(this, &MyForm::button_CanselPlac);
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
        EnabledPlacMod(false);
        outlog("th: MyForm: initialialize Component Placement mod completed\n");
    }
    void MyForm::EnabledPlacMod(bool fl) {
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


    void MyForm::EnabledMainManu(bool fl) {
        button1->Enabled = fl;
        button2->Enabled = fl;
        button3->Enabled = fl;
        button4->Enabled = fl;
        button5->Enabled = fl;
        textBox1->Enabled = fl;
    }

    void MyForm::HideMainManu() {
        panel1->Enabled = false;
        panel1->Hide();
        EnabledMainManu(false);
        label1->Hide();
        label2->Hide();
        button1->Hide();
        button2->Hide();
        button3->Hide();
        button4->Hide();
        button5->Hide();
        textBox1->Hide();
    }
    void MyForm::ShowMainManu() {
        EnabledMainManu(true);
        label1->Show();
        label2->Show();
        button1->Show();
        button2->Show();
        button3->Show();
        button4->Show();
        button5->Show();
        textBox1->Show();
    }
    System::Void MyForm::threadSenderClient(System::Object^ obj) {
        outlog("**** Start thread: Sender Client ****\n");
        SeaFight::MyForm^ form = safe_cast<SeaFight::MyForm^>(obj);
        String^ str = "SenderClient";
        while (str != "ex") {
            str = msgReceive("", 2, obj);
        }
        outlog("**** End thread: Sender Client ****\n");
    }
}