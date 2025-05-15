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

#define LEFT 75		// 좌
#define RIGHT 77	// 우
#define UP 72	// 상
#define DOWN 80	// 하
#define ENTER 13

template<int N>
void DisPlay(int index)
{
	for (int i = 0; i < N; i++)
	{
		if (i == index)
		{
			cout << "■ ";
		}
		else
		{
			cout << "□ ";

		}


	}
}

template<int N>
void DisPlay2D(int index)
{
	int height = index / N;		// 세로, 몫
	int width = index % N;		// 가로, 나머지

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && j == height)
			{
				cout << "■ ";
			}
			else
			{
				cout << "□ ";
			}

		}
		cout << endl;
	}
}

int main()
{
	int selectedIndex = 0;
	char input;
	// 키보드의 방향키 입력을 받아서 아이템을 출력하는 것 구현하기

	// 포켓몬스터의 데이터를 배열한다

	// Poketmon (값 타입)		: 데이터 복사, 크기가 작은 경우, 값 자체가 상태를 표현할 때 사용할 수 있다.
	// Poketmon* (참조타입, 주소값)	: 복사를 하지않고 데이터를 가져온다.

	// 몬스터 종류가 많고 크기가 크면 Poketmon*으로 표현한다.
	// 몬스터볼 개수가 적고 상태가 존재하기 때문에 Poketmon으로 표현한다.

	array<PoketMon*, 100> poketballs;

	PoketMon defaultMonster(0, "");
	poketballs.fill(&defaultMonster);

	poketballs[0] = new PoketMon{ 1, "이상해씨" };
	poketballs[1] = new PoketMon{ 25, "피카츄" };
	poketballs[2] = new PoketMon{ 18, "꼬부기" };
	poketballs[3] = new PoketMon{ 17, "파이리" };

	while (true)
	{
		system("cls");
		//PoketMon* mon1 = new PoketMon{ 1, "이상해씨" };
		//delete mon1;
		const int size = 10;	// const를 사용하지 않으면 함수 템플릿의 변수와 다르기때문에 사용해줘야한다.
		int sizePower = size * size;

		ConsoleUtil::GotoXY(0, 0);
		DisPlay2D<size>(selectedIndex);	// 현재 선택한 아이템을 보여주는 DisPlay함수 만들기

		if (_kbhit())
		{
			input = _getch();

			if (input == LEFT)
			{
				//cout << "왼쪽 화살키 입력" << endl; 작동이 되는지 확인하기위한 출력
				selectedIndex = (selectedIndex - 1 + sizePower) % sizePower;	// 0~부터 4까지 반영, -1이 될 수 없기때문에 수만큼 더해줘야함

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
				selectedIndex = (selectedIndex + size) % sizePower;		// size도 되는거 아니엿냐고~
			}
			else if (input == ENTER)
			{
				break;
			}

			system("cls");

		}
		ConsoleUtil::GotoXY(30, 0);
		cout << "몬스터 UI";
		ConsoleUtil::GotoXY(30, 1);
		cout << "No. " << poketballs[selectedIndex]->get_number()
			<< poketballs[selectedIndex]->get_name();
	}
	
	cout << "No. " << poketballs[selectedIndex]->get_number()
		<< poketballs[selectedIndex]->get_name() << endl;
}