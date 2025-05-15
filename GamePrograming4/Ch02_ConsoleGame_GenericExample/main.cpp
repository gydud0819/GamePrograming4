#include "ConsoleUtility.h"
#include <iostream>
#include <conio.h>		// _getch();
#include "Poketball.h"
#include <array>		// array<Typename T, int N>
using namespace std;

void Ex1()
{
	int x = ConsoleUtil::GetRandomInt(10);
	int y = ConsoleUtil::GetRandomInt(10);

	while (true)
	{
		int random = ConsoleUtil::GetRandomInt(100);
		cout << random << endl;
		Sleep(100);
		break;
	}
}

#define LEFT 75		// ��
#define RIGHT 77	// ��
#define UP 72	// ��
#define DOWN 80	// ��
#define ENTER 13

template<int N>
void DisPlay(int index)
{
	for (int i = 0; i < N; i++)
	{
		if (i == index)
		{
			cout << "�� ";
		}
		else
		{
			cout << "�� ";

		}


	}
}

template<int N>
void DisPlay2D(int index)
{
	int height = index / N;		// ����, ��
	int width = index % N;		// ����, ������

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && j == height)
			{
				cout << "�� ";
			}
			else
			{
				cout << "�� ";
			}

		}
		cout << endl;
	}
}

int main()
{
	int selectedIndex = 0;
	char input;
	// Ű������ ����Ű �Է��� �޾Ƽ� �������� ����ϴ� �� �����ϱ�

	// ���ϸ����� �����͸� �迭�Ѵ�

	// Poketmon (�� Ÿ��)		: ������ ����, ũ�Ⱑ ���� ���, �� ��ü�� ���¸� ǥ���� �� ����� �� �ִ�.
	// Poketmon* (����Ÿ��, �ּҰ�)	: ���縦 �����ʰ� �����͸� �����´�.

	// ���� ������ ���� ũ�Ⱑ ũ�� Poketmon*���� ǥ���Ѵ�.
	// ���ͺ� ������ ���� ���°� �����ϱ� ������ Poketmon���� ǥ���Ѵ�.

	array<PoketMon*, 100> poketballs;

	PoketMon defaultMonster(0, "");
	poketballs.fill(&defaultMonster);

	poketballs[0] = new PoketMon{ 1, "�̻��ؾ�" };
	poketballs[1] = new PoketMon{ 25, "��ī��" };
	poketballs[2] = new PoketMon{ 18, "���α�" };
	poketballs[3] = new PoketMon{ 17, "���̸�" };

	while (true)
	{
		system("cls");
		//PoketMon* mon1 = new PoketMon{ 1, "�̻��ؾ�" };
		//delete mon1;
		const int size = 10;	// const�� ������� ������ �Լ� ���ø��� ������ �ٸ��⶧���� ���������Ѵ�.
		int sizePower = size * size;

		ConsoleUtil::GotoXY(0, 0);
		DisPlay2D<size>(selectedIndex);	// ���� ������ �������� �����ִ� DisPlay�Լ� �����

		if (_kbhit())
		{
			input = _getch();

			if (input == LEFT)
			{
				//cout << "���� ȭ��Ű �Է�" << endl; �۵��� �Ǵ��� Ȯ���ϱ����� ���
				selectedIndex = (selectedIndex - 1 + sizePower) % sizePower;	// 0~���� 4���� �ݿ�, -1�� �� �� ���⶧���� ����ŭ ���������

			}
			else if (input == RIGHT)
			{
				selectedIndex = (selectedIndex + 1) % sizePower;
			}
			else if (input == UP)
			{
				selectedIndex = (selectedIndex - size + sizePower) % sizePower;
			}
			else if (input == DOWN)
			{
				selectedIndex = (selectedIndex + size) % sizePower;		// size�� �Ǵ°� �ƴϿ��İ�~
			}
			else if (input == ENTER)
			{
				break;
			}

			system("cls");

		}
		ConsoleUtil::GotoXY(30, 0);
		cout << "���� UI";
		ConsoleUtil::GotoXY(30, 1);
		cout << "No. " << poketballs[selectedIndex]->get_number()
			<< poketballs[selectedIndex]->get_name();
	}
	
	cout << "No. " << poketballs[selectedIndex]->get_number()
		<< poketballs[selectedIndex]->get_name() << endl;
}