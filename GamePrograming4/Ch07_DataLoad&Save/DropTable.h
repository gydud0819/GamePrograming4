#pragma once
#include "GameModel.h"
#include "ConsoleUtility.h"

/*
* 1. DropItem 생성자 만들기
* 2. Monster가 데이터를 받아올 수 있게 private필드 선언하기
* 3. public 레이블에 생성자, vector의 DropItem 추가하기
*/

struct DropItem
{
	int index;
	int exp;
	int money;
	DropItem() = default;
	DropItem(int index, int exp, int money) : index(index), exp(exp), money(money) {}
};

class Monster
{
private:
	int exp;
	int money;
	vector<DropItem> DropTable;
	DropItem currentDropItem;

public:
	Monster(int exp, int money) : exp(exp), money(money) 
	{
		// 자료구조 생성하여 만들기
		DropTable.emplace_back(1, 10, 100);
		DropTable.emplace_back(2, 20, 100);
		DropTable.emplace_back(3, 30, 100);
		DropTable.emplace_back(4, 40, 100);
		DropTable.emplace_back(5, 50, 100);
		DropTable.emplace_back(6, 60, 100);
		DropTable.emplace_back(7, 70, 100);
		DropTable.emplace_back(8, 80, 100);
		DropTable.emplace_back(9, 90, 100);

	}	

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(- 1);
	}

	void GetDropPoint()
	{
		cout << "얻은 돈" << currentDropItem.money << endl;
		cout << "얻은 경험치" << currentDropItem.exp << endl;

	}
};