#include "threads.h"
#include "Myform.h"
#include "Player.h"

//#include "iostream"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::IO;
/*
bool strToInt(string str) {
    if (str.find_first_not_of
        ("0123456789") 
        != string::npos || str.size() > 1000) {
            return 0; // неккоректное чмсло
    } else  return 1; // всё хорошо
}

bool handlerCmd(String^ strin) {
    string str = msclr::interop::marshal_as<std::string>(strin);
    if ((string("ns")).find(str) != string::npos) {        //set new ship
        string st0 = "", st1 = "", st2 = "", st3 = "";
        st0 = str[3]; st1 = str[5]; st2 = str[7]; st3 = str[9];
        int x = -1, y = -1, size = 0;
        Direction dir = UNK;
        if ( !strToInt(st0) || !strToInt(st1) || !strToInt(st2) ||  !strToInt(st3)
            || (x = stoi(st0)) >= BOARD_SIZE || x < 0 || (y = stoi (st1)) >= BOARD_SIZE || y <0 || 
            (size = stoi(st3)) > MAX_SIZE_SHIP || size <= 0) {
                //error
        } else {

        }
    } else if ((string("ds")).find(str) != string::npos) { //del ship

    } else if ((string("cs")).find(str) != string::npos) { //check set ship

    } else if ((string("as")).find(str) != string::npos) { //autoset ship

    } else if ((string("rd")).find(str) != string::npos) { //ready

    } else if ((string("en")).find(str) != string::npos) { //end

    } else return false;
}

Void threadSenderServer(Object^ obj) {
    outlog("**** Start thread: Sender Server ****\n");
    SeaFight::MyForm^ form = safe_cast<SeaFight::MyForm^>(obj);
    String^ str = "";
    while (str != "ex") {
        str = msgReceive("SendServ", 0, obj);
        msgSend(str, "SenderServer", 1, obj);
    }
    //msgSend("ex", "SenderServer", 1, obj);

    outlog("**** End thread: Sender Server ****\n");
}

Void threadServer(Object^ obj) {
    outlog("**** Start thread: Server ****\n");
    Threading::Thread^ trd = gcnew Threading::Thread(gcnew Threading::ParameterizedThreadStart(&threadSenderServer));
    trd->Start(obj);
    SeaFight::MyForm^ form = safe_cast<SeaFight::MyForm^>(obj);
    String^ str = "";
    //Player* user = new PlayerUser();
    //Player* comp = new PlayerUser();
    
    while (1) {
        str = msgReceive("Server", 1, obj);
    }


    while (str != "ex") {
        str = msgReceive("Server", 1, obj);
    }
    msgSend("ex", "Server", 2, obj);
    
    outlog("**** End thread: Server ****\n");
}

Void msgSend(String^ str, String^ threadName, int numThre, Object^ obj) {
    SeaFight::MyForm^ form = safe_cast<SeaFight::MyForm^>(obj);

    form->str[numThre] = str;
    form->barr[numThre]->SignalAndWait();
    std::string strin = "th: "; strin += msclr::interop::marshal_as<std::string>(threadName);
    strin += ": send msg \"";
    outlog(strin, msclr::interop::marshal_as<std::string>(str),"\"\n");
}

String^ msgReceive(String^ threadName, int numThre, Object^ obj) {
    SeaFight::MyForm^ form = safe_cast<SeaFight::MyForm^>(obj);

    form->barr[numThre]->SignalAndWait();
    String^ str = form->str[numThre];
    std::string strin = "th: "; strin += msclr::interop::marshal_as<std::string>(threadName);
    strin += ": receive msg \"";
    outlog(strin, msclr::interop::marshal_as<std::string>(str) ,"\"\n");
    return str;
}
*/
