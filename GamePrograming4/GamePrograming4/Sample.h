#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* int array[100];
* 1. vector<int> vec;
*
* 2. template을 사용한 간단한 코드 구현해보기
*/

// vetcor > 내가 직접 정의한 클래스를 저장하고, 정렬하고, 출력하는 예제 만들기
// 게임 데이터로 클래스 표현도 가능함

class PocketMonster
{
private:
	int _number;
	string _name;
public:
	PocketMonster(int number, string name)
		: _number(number), _name(name) {
	}

	int GetNumber() const
	{
		return _number;
	}

	string GetName() const
	{
		return _name;
	}

	bool operator<(const PocketMonster& other)	// 비교만 할거기 때문에 const 사용하기
	{
		// this->_number : 내가 가지고 있는 도감 번호
		// other.GetNumber() : 비교 대상의 도감 번호

		return this->_number < other.GetNumber();

	}

	bool operator>(const PocketMonster& other)
	{

		return this->_number > other.GetNumber();
	}


};

class Player
{
	vector<PocketMonster> myPocketmon;
};

void Example1()
{
	PocketMonster 피카츄(25, "피카츄");
	PocketMonster 꼬부기(7, "꼬부기");
	PocketMonster 파이리(5, "파이리");
	PocketMonster 피죤투(18, "피죤투");
	PocketMonster 아보(23, "아보");
	PocketMonster 피피(36, "피피");

	//bool result = 꼬부기 < 피카츄;

	cout << "꼬부기가 피카츄보다 번호가 큰가?" << endl;

	if (꼬부기 < 피카츄)
	{
		cout << "아니오" << endl;
	}
	else
	{
		cout << "네" << endl;
	}

	vector<PocketMonster> pocketDataBase;

	// 데이터 입력

	pocketDataBase.push_back(피카츄);		// push_back 밀어넣는다? 
	pocketDataBase.push_back(꼬부기);
	pocketDataBase.push_back(파이리);
	pocketDataBase.push_back(피죤투);
	pocketDataBase.push_back(아보);
	pocketDataBase.push_back(피피);

	// 데이터 알고리즘 (정렬)
	sort(pocketDataBase.begin(), pocketDataBase.end());

	// 데이터 출력
	for (auto& pocketMon : pocketDataBase)
	{
		cout << "No." << pocketMon.GetNumber() << " " << pocketMon.GetName() << endl;
	}

	// 데이터 찾기 (검색)
	for (auto& pocketMon : pocketDataBase)
	{
		if (pocketMon.GetNumber() == 5)
		{
			cout << pocketMon.GetNumber() << "번 몬스터를 찾았다." << endl;
			cout << "No." << pocketMon.GetNumber() << " " << pocketMon.GetName() << endl;
		}
		else
		{
			cout << "못찾았다." << endl;
			cout << "No." << pocketMon.GetNumber() << " " << pocketMon.GetName() << endl;
		}
	}

}

class Cookie
{

};