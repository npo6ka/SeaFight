#pragma once
#include "log.h"

struct Exch {
    char com;
    int x;
    int y;
    int dir;
};

System::Void threadSenderServer(System::Object^);
System::Void threadServer(System::Object^);

System::Void msgSend(System::String^, System::String^, int, System::Object^);
System::String^ msgReceive(System::String^, int, System::Object^);
