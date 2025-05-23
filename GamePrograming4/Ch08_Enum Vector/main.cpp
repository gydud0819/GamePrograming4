#include <iostream>
#include <vector>
using namespace std;

/*
* �ۼ���	: 2025-05-23
* �ۼ���	: ��ȿ��
* ����	:
*/

/*
* enum : ������
* enum���� ����� ������ �� �ִ�.
*/

/*
* vectorŸ���� �Ѱ��� (��ȿ������ �ڵ�)
* Trait - ������ ����
* Stat - �߰��� �� ����
* Dex���ø��� Speed�� �����ϴ� �ý����� ������ �Ҷ�
* Speed = 100 �ع����� ���� �޸𸮸� �ǳʶٰ� 100° ĭ���ִ� Speed�� ���� ������ ���� ���ϴ�.
*
* �迭 ���·� ����Ǿ� �ִ� �ڷᱸ���̱� ������ �ڷ��� ���� �� �߰��� �� �� �������� �߻��� �� �ִ�.
* ������� �����Ǿ� ���� ���� �������� ������ �߻����� �� ������ ����ȴ�.
*/

enum Trait
{
	Strength,
	Dexterity,
	Inteligence,
	None
};

enum Stat
{
	Damage,
	Health,
	Mana,
	Speed
};

/*
* Trait - Stat�� ���踦 �����ؾ� �Ѵ�.
* STR 1 �÷��� �� ? : Damage(���� ��ġ) + ( );	// �� ����
*/

class TraitBonus
{
private:
	void IncreaseStat(Stat stat, int amount)
	{
		Stats[static_cast<int>(stat)] += amount;
	}

public:
	//Trait trait;				// �Ӽ��� �ϳ��� �����Ѵ�. 
	//Stat stat;					// ������ 1���� �����Ѵ�. 
	//int addtiveBonusPoint;	// trait�� 1 ���� �Ҷ� ����Ʈ�� �߰��� �� ��� ��
	vector<int> Stats;

	TraitBonus() : Stats(4, 0) {}
	//TraitBonus(Trait trait, Stat stat, float addtiveBonusPoint) 
	//	: trait(trait), stat(stat), addtiveBonusPoint(addtiveBonusPoint), Stats(4,0) {}

	void GetTrait(Trait trait)
	{
		switch (trait)
		{
		case Trait::Strength:
			IncreaseStat(Damage, 10);
			IncreaseStat(Health, 5);
			break;
		case Trait::Dexterity:
			IncreaseStat(Speed, 2);
			break;
		case Trait::Inteligence:
			IncreaseStat(Mana, 100);

			break;
		default:
			break;
		}
	}

	void ShowStats()
	{
		cout << "Damage : " << Stats[Damage] << endl;
		cout << "Health : " << Stats[Health] << endl;
		cout << "Mana : " << Stats[Mana] << endl;
	}


};

class Player
{
private:

	TraitBonus traitbonus;

public:
	Player() : traitbonus() {}

	TraitBonus GetTrait() const { return traitbonus; }


	void GetTraits(Trait trait)
	{
		traitbonus.GetTrait(trait);
	}

	//Player() : stats(4, 0)		// stat�� ���� ���ڰ� �߰� �Ǿ�� �Ѵ�.
	//{
	//	stats[static_cast<int>(Stat::Damage)] = 5;		// Stat:: ���� Damageȥ�� �����°ǰ� 
	//	stats[static_cast<int>(Stat::Health)] = 100;		
	//	stats[static_cast<int>(Stat::Mana)] = 30;		

	//}

	//void IncreaseStat(Stat stat, int amount)	// ������ �󸶳� ������ų���� 
	//{
	//	stats[static_cast<int>(stat)] += amount;
	//}

	//void ShowPlayerStat()
	//{
	//	cout << "Damage : "<< stats[Damage] << endl;
	//	cout << "Health : "<< stats[Health] << endl;
	//	cout << "Mana : "<< stats[Mana]		<< endl;
	//}

};

/*
* C ������ Casting ������
* - �������� ����ȯ�� ���ÿ� �� �� �ִ�.
*
* C++ ������ Casting
* - static_cast, const_cast, reinterpret_cast
*
*
* - �ǵ�ġ ���� ����ȯ�� �߻��� �� �ִ�.
*	�̸� �����ϱ� ���� C++ ���·� ����ȯ�� ����Ѵ�.
*
* Tip) int, double, std::string Primitive Type Ÿ���� ��ȯ�ϰ� ������ static_cast�� ����ϸ� �ȴ�.
*
* const_cast : ����� �����ִ� ����ȯ�̴�.
* reinterpret_cast : �޸𸮿� �����Ͽ� int* -> double* ���ؼ��Ͽ� ��ȯ�ϴ� ����ȯ�̴�.
* dynamic_cast : Ŭ������ ��Ӱ��踦 ����ȯ�Ͽ� ���� �����Ͱ� �������� ������ null�� ��ȯ�Ѵ�.
*
* ex) if(dynamic_cast<Monster> d) {}
*
*
*
*/

// enum�� ������, ������ enum���� ��ȯ�ϴ� �Լ�
void EnumTest1()
{
	int num = Stat::Damage;

	Stat someType = (Stat)num;		// C������ ����ȯ �����̴�. 
	Stat someType2 = static_cast<Stat>(num);	// C++ ������ ����ȯ �����̴�.

	if (someType == Stat::Damage)
	{
		cout << "���� �������� ��µǾ���." << endl;	// someType�� ����� ����ȯ�� �Ǿ��ٸ� �ڵ尡 ����� ���̴�. 

	}

}

// Enum�� vectorŸ������ ����ȯ�Ͽ� ����ϴ� ���� �Լ� 
//void EnumTest2()
//{
//	Player player;
//	player.IncreaseStat(Stat::Damage, 5);		// �÷��̾��� ���ݷ� ������ 5��ŭ �������Ѷ�. 
//	player.ShowPlayerStat();
//}

void EnumTest3()
{
	// �÷��̾��� Ư���� ���������� ��, Ư�� ������ �����ϰ� �Ϸ��� � �ڵ带 ������� ����غ���

	// enum Trait, enum Stat, int amount �Լ��� �ʿ��ϴ�.
	TraitBonus traits;
	//traits.GetTrait(Trait::Strength);

	traits.ShowStats();

}

void EnumTest4()
{
	/*Player player;
	player.GetTraits().GetTrait(Trait::Strength);
	player.GetTraits().ShowStats();*/
}

int main()
{
	//EnumTest1();

	//EnumTest2();

	//EnumTest3();
	//
	//EnumTest4();

	Player player;
	cout << "============������===========" << endl;

	int input;
	cout << "���ڸ� ����� �Է����� �� Ư�� A�� �ø���." << endl;
	cin >> input;

	if (input > Trait::None)
	{
		cout << "�߸��� ���ڸ� �Է��ߴ�." << endl;
	}
	else
	{

		player.GetTraits(static_cast<Trait>(input));
	}

	//player.

	/*switch (input)
	{
	case 0:
		player.GetTraits(Trait::Strength);
	case 1:
		player.GetTraits(Trait::Dexterity);
	default:
		break;
	}*/
}

// �÷��̾� ������ �ý��� + ���� ��� �ý���
// �������� ���� �� ������ ����� �� �ְ� �����
// Player TraitBonus, LevelUp