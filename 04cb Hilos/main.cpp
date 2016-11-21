
//#include "stdafx.h"
#include <iostream>
#include "Windows.h"
#include <conio.h>

using namespace std;

class IRunable {
public:
	virtual unsigned long __fastcall Run(void) = 0;
};

template<class IRunable>
class Thread {

	enum { TIME_OUT = 200 };

	static unsigned long __stdcall threadProc(void* action) {
		return ((IRunable*)action)->Run();
	}

private:
	IRunable* object;

	HANDLE thread;
	DWORD threadId;
	DWORD timeOut;
	DWORD flags;
	bool terminated;
	bool running;

	Thread(const Thread&) {}
	void operator = (const Thread&) {}

public:
	__fastcall Thread(DWORD flagas = CREATE_SUSPENDED, DWORD timeOut = TIME_OUT) {
		this->object = new IRunable;
		this->timeOut = timeOut;
		thread = ::CreateThread(0, 0, threadProc, object, flags, &threadId);
		running = (flags != CREATE_SUSPENDED);
		terminated = false;
	}

	__fastcall ~Thread(void) {
		if (object) delete object;
	}

	void __fastcall Start(void) {
		if (!running) {
			::ResumeThread(thread);
			running = true;
		}
	}

	void __fastcall Stop(void) {
		if (running) {
			::SuspendThread(thread);
			running = false;
		}
	}

	void __fastcall Exit(void) {
		if (!terminated) {
			::TerminateThread(thread, 0);
			::WaitForSingleObject(thread, TIME_OUT);
			running = false;
			terminated = true;
		}
	}
};

class Writer : IRunable {
public:
	virtual unsigned long __fastcall Run(void) {
		int i = 0;
		while (i < 100000) {
			cout << ++i << " Writer writing ...\n";
			//i++;
		}
		return 0L;
	}
};



int main()
{
	Thread<Writer> writer;
	Thread<Writer> writer2;
	cout << "iniciado el hilo writer 1\n";
	writer.Start();
	//cout << "iniciado el hilo writer 2\n";
	//writer2.Start();
	system("pause");
	writer.Stop();
	//writer2.Stop();
	//cout << "pausar los hilos\n";
	//system("pause");
	writer.Exit();
	writer2.Exit();
	cout << "detener los hilos\n";
	system("pause");
	cout << "ingrese q para salir" << endl;
	char a; cin >> a;
    return 0;
}
