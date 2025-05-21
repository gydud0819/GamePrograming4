#pragma once
#include <iostream>
using namespace std;

/*
* virtual 키워드를 사용하면 해당 클래스를 상속하는 자식 클래스가 필요하다.
* Combat - Player, Monster
* override 기능을 사용하여 Combat타입임에도 Player의 Combat과 Monster의 Combat을 사용할 수 있다.
* 
* virtual 함수()  = 0; 순수 가상함수
* 자식에서 해당 함수를 override 시켜라.
*/

class Combat
{
public:
	virtual ~Combat() = default;

	virtual void attack(Combat& target) = 0;
	virtual void takeDamage(int damage) = 0;
	virtual int getHP() = 0;

	
};


class Player : public Combat
{
private:
	int hp;
	int atk;

public:
	Player(int hp, int atk) : hp(hp), atk(atk) {}

	void attack(Combat& target) override
	{
		target.takeDamage(atk);
	}

	void takeDamage(int damage) override
	{
		hp -= damage;
		cout << "Player가" << damage << "의 피해를 입었다." << endl;
	}

	int getHP() override
	{
		return hp;
	}
};

class Monster : public Combat
{
private:
	int hp;
	int atk;

public:
	Monster(int hp, int atk) : hp(hp), atk(atk) {}

	void attack(Combat& target) override
	{
		target.takeDamage(atk);
	}

	void takeDamage(int damage) override
	{
		hp -= damage;
		cout << "Monster가" << damage << "의 피해를 입었다." << endl;
	}

	int getHP() override
	{
		return hp;
	}

};