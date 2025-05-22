#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*
* 목표 : 레벨업 시스템을 구현하고 싶을 때 
*
* int exp;
* int maxExp;	현재 경험치 > maxExp 일때 레벨을 1 증가한다.
*/

/*
* 목표2 : 레벨에 따른 경험치 요구량을 자료구조로 표현하기
* 사용할 자료구조 : vector
*/

/*
* 1. 데이터를 표현하기 위한 클래스 생성하기
* 2. 특정 클래스 안에 표현하기 위한 자료구조로 선언하기		Player -> vector<LvExp> LvTable;
*/

/*
* 생성자에 데이터를 직접 작성한다. 
* vector.push(); 이나 vector.emplace_back(); 을 사용한다. 
*/

struct LvExp
{
	int Lv;
	int maxExp;
	
	LvExp(int Lv, int maxExp) : Lv(Lv), maxExp(maxExp){}
};

class Player
{
private:
	int exp;
	int maxExp;
	int Lv;
	vector<LvExp> LvTable;	// 데이터를 직접 만들어줘야한다. 

public:
	Player() : exp(0), Lv(1), maxExp(100) {}
	Player(int exp, int maxExp, int Lv) : exp(exp), maxExp(maxExp), Lv(Lv) 
	{
		LvTable.emplace_back(1, 100);
		LvTable.emplace_back(2, 120);
		LvTable.emplace_back(3, 140);
		LvTable.emplace_back(4, 160);
		LvTable.emplace_back(5, 180);
		LvTable.emplace_back(6, 200);
		LvTable.emplace_back(7, 220);
		LvTable.emplace_back(8, 240);
		LvTable.emplace_back(9, 260);
		
	}

	//void LoadExpInTable(int i)
	//{
	//	// 1레벨의 데이터를 가져와서 사용한다.
	//	
	//	maxExp = LvTable[i].maxExp;
	//}

	int GetMaxExpForLv(int Lv)
	{
		for (const auto& data : LvTable)
		{
			// 레벨과 table 레벨을 비교한다.
			if (Lv == data.Lv)
			{
				return data.maxExp;
			}
		}

		return -1;	// 0을 반환하면 에러로 인식하라는 의미이다. 
	}

	void GetExp(int amount)		// 경험치를 획득하면
	{
		exp += amount;	// 경험치 수치만큼 더해준다.  

		maxExp = GetMaxExpForLv(Lv);

		if (maxExp == -1)
		{
			cout << "최대 레벨에 도달했습니다. 실행을 취소합니다." << endl;
			return;		// 예외처리 코드 알림 후 함수를 종료한다. 
		}
		
		if (exp >= maxExp)	// 레벨의 최대 경험치에 도달했을 때 
		{
			Lv++;
			exp -= maxExp;		

		}
	}

	void Show()
	{
		cout << "Lv : " << Lv << endl;
		cout << "Exp : " << exp << endl;
		cout << "maxExp : " << maxExp << endl;
	}

	void SaveData(const string& filename)
	{
		ofstream file(filename);

		if (file.is_open())
		{
			file << Lv << " ";
			file << exp << endl;
			file.close();
		}
			
	}

	void LoadData(const string& filename)
	{
		ifstream file(filename);

		int _Lv, _exp;

		file >> _Lv >> _exp;
		Lv = _Lv;
		exp = _exp;

	}
};

class Monster
{

};