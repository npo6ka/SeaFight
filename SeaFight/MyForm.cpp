#include "MyForm.h"
#include "iostream"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::IO;

namespace SeaFight {
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
    bool MyForm::CheckNick(String^ str) 
    {
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


}