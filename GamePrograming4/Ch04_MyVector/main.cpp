/*
* �ۼ���	: 2025-05-19
* �ۼ���	: ��ȿ��
* ����	: ���� ���� �����ϱ�
*/

/*
* �����͸� �����ϴ� Ŭ����
* T value, pointer
*/

#include <iostream>
#include "CustomVector.h"
#include "RandomInCount.h"
#include <conio.h>
using namespace std;

int main()
{
	//Test1();
	Test2();

	Player player;

	while (true)
	{
		system("cls");
		Battle(player);
		player.Display();
		cout << "Ű�� �Է��ϸ� ���� ������ ����ȴ�." << endl;
		_getch();
	}
}