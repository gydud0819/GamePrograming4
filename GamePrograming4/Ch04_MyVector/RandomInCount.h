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
		cout << "몬스터 이름 : " << name << endl;
	}

	void TakeDamage(int dmg)
	{
		hp -= dmg;	// 데미지 입은만큼 체력 감소
		if (hp <= 0)
		{
			cout << name << "이 사망했습니다." << endl;
		}
		else
		{
			cout << name << "의 남은 체력 : " << hp << endl;
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
		cout << "사냥한 몬스터 목록" << endl;
		int i = 1;
		for (const auto& monster : huntedMonster)
		{
			cout << i << "번째 사냥한 몬스터 : " << monster.name << endl;
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

	// 하드코딩으로 배틀 구현하기
	while (selectMonster.hp > 0)
	{
		//cout << "몬스터에게 " << playerAttackDamage << "만큼 공격을 했습니다.";
		selectMonster.TakeDamage(playerAttackDamage);
	}

	player.killMonster(selectMonster);
}