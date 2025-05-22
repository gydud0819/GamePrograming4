#pragma once
#include "GameModel.h"
#include "ConsoleUtility.h"

/*
* 1. DropItem ������ �����
* 2. Monster�� �����͸� �޾ƿ� �� �ְ� private�ʵ� �����ϱ�
* 3. public ���̺� ������, vector�� DropItem �߰��ϱ�
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
		// �ڷᱸ�� �����Ͽ� �����
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
		cout << "���� ��" << currentDropItem.money << endl;
		cout << "���� ����ġ" << currentDropItem.exp << endl;

	}
};