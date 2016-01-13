#include <Windows.h>
#include "MyForm.h"
#include "log.h"
//#include "sec.h"
using namespace SeaFight;
using namespace System::Threading;

void fun(Object^ obj) {
    MyForm^ form1 = gcnew MyForm;
    form1->ShowDialog();
    Console::WriteLine("end thread 2");
}

//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
int main()
{
    
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
    /*Thread^ thr = gcnew Thread(gcnew ParameterizedThreadStart(this, &MyForm::fun));
            thr->Start(true);*/
	return 0;
}