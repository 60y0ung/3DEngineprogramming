#include <windows.h>
#include <iostream>

using namespace std;

#pragma comment (lib, "winmm.lib")

double GetSeconds1()
{
	return timeGetTime()*0.001f;
}

double GetSeconds2(){
	static DWORD init_time = timeGetTime();
	static double time_counter = 0.0f;
	DWORD new_time = timeGetTime();
	time_counter += (new_time - init_time)*0.001f;
	init_time = new_time;
	return time_counter;
}

void main(void)
{
	while (1)
	{
		if (GetSeconds2() > 2)
		{
			cout << "2초가 흘렀습니다" << endl;
			break;
		}
	}
}
