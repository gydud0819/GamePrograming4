#pragma once
#include "ConsoleUtility.h"
#include <vector>
#include <iostream>
using namespace std;

class Monster
{
public:
	string name;
	int hp;
	int atk;
public:
	Monster() = default;
	~Monster() = default;

	Monster(string name, int hp, int atk)
		: name(name), hp(hp), atk(atk) {
	}

	void ShowInfo() const
	{
		cout << "���� �̸� : " << name << endl;
	}

	void TakeDamage(int dmg)
	{
		hp -= dmg;	// ������ ������ŭ ü�� ����
		if (hp <= 0)
		{
			cout << name << "�� ����߽��ϴ�." << endl;
		}
		else
		{
			cout << name << "�� ���� ü�� : " << hp << endl;
		}
	}

};
class Player
{
private:
	vector<Monster> huntedMonster;

	//huntedMonster.push_back();
public:
	void killMonster(const Monster& monster)
	{
		huntedMonster.push_back(monster);
	}

	void Display() const
	{
		cout << "����� ���� ���" << endl;
		int i = 1;
		for (const auto& monster : huntedMonster)
		{
			cout << i << "��° ����� ���� : " << monster.name << endl;
			i++;
		}
	}


};

void Battle(Player& player)
{
	vector<Monster> monsters =
	{
		Monster("zombie", 40, 10),
		Monster("witch", 50, 20),
		Monster("pig", 30, 3),
	};

	int randIndex = ConsoleUtil::GetRandomInt(monsters.size() - 1);
	
	Monster& selectMonster = monsters[randIndex];

	int playerAttackDamage = 10;

	// �ϵ��ڵ����� ��Ʋ �����ϱ�
	while (selectMonster.hp > 0)
	{
		//cout << "���Ϳ��� " << playerAttackDamage << "��ŭ ������ �߽��ϴ�.";
		selectMonster.TakeDamage(playerAttackDamage);
	}

	player.killMonster(selectMonster);
}