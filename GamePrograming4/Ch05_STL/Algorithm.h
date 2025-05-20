#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;


// 찾으면 true 즉, iterator를 반환하고 못찾으면 false, end()를 반환한다.
// 데이터들 안에 찾는 데이터가 있는지 확인하는 코드
void find_test()
{
	cout << "\n=======================================" << endl;
	vector<int> nums = { 1,2,3,4,5 };

	auto it = find(nums.begin(), nums.end(), 23);
	//cout << *it << endl;	// 4가 나온다. 

	if (it != nums.end())
	{
		cout << *it << endl;
	}
	else
	{
		cout << "데이터를 찾지 못했습니다." << endl;
	}
}

struct Monster
{
	int id;
	string name;

	Monster(int id, string name) : id(id), name(name) {}	// 생성자 함수 
};

// 알고리즘을 사용한 심화 코드

/*
* 알고리즘 정리
* 
* std::함수이름(vec.begin(), vec.end(), 정의된 함수, 람다식, 펑터)
* 
* 함수안에 함수 사용 가능(?)
* 
* 1. bool (*함수이름) (int x);	
* 
* 2. functor : struct 또는 class 타입을 만들어서 사용하지만 옛 문법이기에 지금은 거의 사용하지 않는다.
* 
* 3. lamda식 : 함수를 선언하지 않아도 함수를 호출한 것처럼 사용할 수 있다. (무명 함수 - 이름이 없는 함수)
* 
* []() {} 
*/

// 홀수 (Even)
bool IsEven(int x)
{
	return x % 2 != 0;
}

// 짝수 (Odd)
bool IsOdd(int x)
{
	return x % 2 == 0;
}

bool CheckMonster(const Monster& findMon)
{
	return findMon.id == 3;
}

void find_test2()
{
	vector<Monster> monsters;
	monsters.emplace_back(1, "용감한 쿠키");
	monsters.emplace_back(2, "마법사맛 쿠키");
	monsters.emplace_back(3, "팬케이크맛 쿠키");
	monsters.emplace_back(4, "커스터드3세맛 쿠키");

	// find_if() : 3번째 인자에 어떤 데이터를 찾을건지 조건을 넣어준다. 
	// 함수, functor, 람다식

	auto it = find_if(monsters.begin(), monsters.end(),
		[](const Monster& findMon) {return findMon.id == 3; });
	cout << it->name << endl;

	cout << "함수 포인터로 구현한 예시" << endl;

	auto it2 = find_if(monsters.begin(), monsters.end(), CheckMonster);
	cout << it2->name << endl;
}

// Square_Functor square();
struct Square_Functor
{
	void operator()(int x)
	{
		cout << x << " ";
	}
};

void for_each_test()
{
	vector<int> nums = { 2,4,6,8 };
	Square_Functor square;
	for_each(nums.begin(), nums.end(), square);

}

void all_of_test()
{
	vector<int> nums = { 1,2,3,4,5 };
	if (all_of(nums.begin(), nums.end(), IsEven))
	{
		cout << "nums의 모든 데이터가 홀수이다." << endl;
	}
	else
	{
		cout << "nums의 데이터에 짝수가 존재한다." << endl;
	}
}