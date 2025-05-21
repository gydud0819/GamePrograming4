#pragma once
#include "GameModel.h"
using namespace std;

class BattleManager
{
private:
	Player& player;
	Monster& monster;

public:
	void Battle()
	{
		while (player.getHP() > 0 && monster.getHP() > 0)
		{
			player.attack(monster);
			if (monster.getHP() > 0)
			{
				monster.attack(player);
			}
		}

	cout << "������ ����Ǿ����ϴ�." << endl;
	}

};