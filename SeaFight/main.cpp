#include <Windows.h>
#include "MyForm.h"
#include "log.h"

using namespace SeaFight;
using namespace System::Threading;

void fun(Object^ obj) {
    
}

//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
    Thread^ thr = gcnew Thread(gcnew ParameterizedThreadStart(&fun));
    thr->Start(true);

	return 0;
}