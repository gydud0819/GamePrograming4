/*
* 작성일	: 2025-05-19
* 작성자	: 박효영
* 주제	: 벡터 직접 구현하기
*/

/*
* 데이터를 저장하는 클래스
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
		cout << "키를 입력하면 다음 전투가 진행된다." << endl;
		_getch();
	}
}