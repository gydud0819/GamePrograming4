/*
*/

#include "ConsoleUtility.h"
#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		int random = ConsoleUtil::GetRandomInt(100);
		cout << random << endl;
		Sleep(100);
		break;
	}

	ConsoleUtil::GotoXY(0, 20);
	cout << "����" << endl;
}