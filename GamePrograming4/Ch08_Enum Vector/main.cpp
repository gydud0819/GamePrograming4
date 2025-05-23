#include <iostream>
#include <vector>
using namespace std;

/*
* 작성일	: 2025-05-23
* 작성자	: 박효영
* 주제	:
*/

/*
* enum : 열거형
* enum으로 상수를 저장할 수 있다.
*/

/*
* vector타입의 한계점 (비효율적인 코드)
* Trait - 변하지 않음
* Stat - 추가될 수 있음
* Dex를올리면 Speed가 증가하는 시스템을 만들어야 할때
* Speed = 100 해버리면 많은 메모리를 건너뛰고 100째 칸에있는 Speed로 가기 때문에 낭비가 심하다.
*
* 배열 형태로 저장되어 있는 자료구조이기 때문에 자료의 삭제 및 추가를 할 때 문제점이 발생할 수 있다.
* 순서대로 정리되어 있지 않은 데이터의 변경이 발생했을 때 문제가 예상된다.
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
* Trait - Stat의 관계를 정의해야 한다.
* STR 1 올렸을 때 ? : Damage(기존 수치) + ( );	// 합 연산
*/

class TraitBonus
{
private:
	void IncreaseStat(Stat stat, int amount)
	{
		Stats[static_cast<int>(stat)] += amount;
	}

public:
	//Trait trait;				// 속성을 하나만 소유한다. 
	//Stat stat;					// 스탯을 1개만 소유한다. 
	//int addtiveBonusPoint;	// trait이 1 증가 할때 포인트를 추가로 더 얻는 것
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

	//Player() : stats(4, 0)		// stat의 다음 숫자가 추가 되어야 한다.
	//{
	//	stats[static_cast<int>(Stat::Damage)] = 5;		// Stat:: 없이 Damage혼자 못쓰는건가 
	//	stats[static_cast<int>(Stat::Health)] = 100;		
	//	stats[static_cast<int>(Stat::Mana)] = 30;		

	//}

	//void IncreaseStat(Stat stat, int amount)	// 스텟을 얼마나 증가시킬건지 
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
* C 형태의 Casting 문제점
* - 여러가직 형변환을 동시에 할 수 있다.
*
* C++ 형태의 Casting
* - static_cast, const_cast, reinterpret_cast
*
*
* - 의도치 않은 형변환이 발생할 수 있다.
*	이를 개선하기 위해 C++ 형태로 형변환을 사용한다.
*
* Tip) int, double, std::string Primitive Type 타입을 변환하고 싶으면 static_cast를 사용하면 된다.
*
* const_cast : 상수를 없애주는 형변환이다.
* reinterpret_cast : 메모리에 접근하여 int* -> double* 재해석하여 변환하는 형변환이다.
* dynamic_cast : 클래스의 상속관계를 형변환하여 실제 데이터가 존재하지 않으면 null을 반환한다.
*
* ex) if(dynamic_cast<Monster> d) {}
*
*
*
*/

// enum을 정수로, 정수를 enum으로 변환하는 함수
void EnumTest1()
{
	int num = Stat::Damage;

	Stat someType = (Stat)num;		// C형태의 형변환 문법이다. 
	Stat someType2 = static_cast<Stat>(num);	// C++ 형태의 형변환 문법이다.

	if (someType == Stat::Damage)
	{
		cout << "스텟 데미지가 출력되었다." << endl;	// someType이 제대로 형변환이 되었다면 코드가 실행될 것이다. 

	}

}

// Enum을 vector타입으로 형변환하여 사용하는 예제 함수 
//void EnumTest2()
//{
//	Player player;
//	player.IncreaseStat(Stat::Damage, 5);		// 플레이어의 공격력 스텟을 5만큼 증가시켜라. 
//	player.ShowPlayerStat();
//}

void EnumTest3()
{
	// 플레이어의 특성을 증가시켰을 때, 특정 스탯을 증가하게 하려면 어떤 코드를 써야할지 고민해보기

	// enum Trait, enum Stat, int amount 함수가 필요하다.
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
	cout << "============레벨업===========" << endl;

	int input;
	cout << "숫자를 몇번을 입력했을 때 특성 A를 올린다." << endl;
	cin >> input;

	if (input > Trait::None)
	{
		cout << "잘못된 숫자를 입력했다." << endl;
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

// 플레이어 레벨업 시스템 + 스텟 상승 시스템
// 레벨업을 했을 때 스텟을 상승할 수 있게 만들기
// Player TraitBonus, LevelUp