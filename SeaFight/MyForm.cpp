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
            this->button6->TabIndex = 8;
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
            this->button7->TabIndex = 9;
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
            this->label3->TabIndex = 10;
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
            this->label4->TabIndex = 11;
            this->label4->Text = L"Смена никнейма";
            // 
            // textBox2
            // 
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(204)));
            this->textBox2->Location = System::Drawing::Point(16, 56);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(238, 29);
            this->textBox2->TabIndex = 12;
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
            this->panel1->TabIndex = 8;
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            
            this->panel1->Enabled = false;
            this->panel1->Hide();
    }

    void MyForm::DisableMainManu() {
        button1->Enabled = false;
        button2->Enabled = false;
        button3->Enabled = false;
        button4->Enabled = false;
        button5->Enabled = false;
        textBox1->Enabled = false;
    }
    void MyForm::EnableMainManu() {
        button1->Enabled = true;
        button2->Enabled = true;
        button3->Enabled = true;
        button4->Enabled = true;
        button5->Enabled = true;
        textBox1->Enabled = true;
    }
    void MyForm::HideMainManu() {
        panel1->Enabled = false;
        panel1->Hide();
        DisableMainManu();
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
        EnableMainManu();
        label1->Show();
        label2->Show();
        button1->Show();
        button2->Show();
        button3->Show();
        button4->Show();
        button5->Show();
        textBox1->Show();
    }
}