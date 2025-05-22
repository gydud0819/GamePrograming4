/*
* 작성일	: 2025-05-22
* 작성자	: 박효영
* 주제	: 경험치 레벨업 시스템 만들기
*/

#include "GameModel.h"
#include "DataHandler.h"
#include <conio.h>

int main()
{
	Player player(0, 100, 1);	// exp = 0, Lv= 1, maxExp = 100
	//Monster monster(0, 0);

	Data data;
	//data.SaveData("data.txt");
	data.LoadData("data.txt");
	
	cout << "data의 레벨 : " << data.Lv << " exp : " << data.exp << endl;
	_getch();

	int count = 0;

	Player player;
	player.SaveData("player.txt");


	while (true)
	{
		player.GetExp(50);
		player.Show();
		_getch();

		count++;
		if (count >= 4)
		{

		}
	}
}