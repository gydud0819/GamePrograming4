#pragma once
#include <iostream>
using namespace std;

/*
* virtual Ű���带 ����ϸ� �ش� Ŭ������ ����ϴ� �ڽ� Ŭ������ �ʿ��ϴ�.
* Combat - Player, Monster
* override ����� ����Ͽ� CombatŸ���ӿ��� Player�� Combat�� Monster�� Combat�� ����� �� �ִ�.
* 
* virtual �Լ�()  = 0; ���� �����Լ�
* �ڽĿ��� �ش� �Լ��� override ���Ѷ�.
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
		cout << "Player��" << damage << "�� ���ظ� �Ծ���." << endl;
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
		cout << "Monster��" << damage << "�� ���ظ� �Ծ���." << endl;
	}

	int getHP() override
	{
		return hp;
	}

};