#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;


// ã���� true ��, iterator�� ��ȯ�ϰ� ��ã���� false, end()�� ��ȯ�Ѵ�.
// �����͵� �ȿ� ã�� �����Ͱ� �ִ��� Ȯ���ϴ� �ڵ�
void find_test()
{
	cout << "\n=======================================" << endl;
	vector<int> nums = { 1,2,3,4,5 };

	auto it = find(nums.begin(), nums.end(), 23);
	//cout << *it << endl;	// 4�� ���´�. 

	if (it != nums.end())
	{
		cout << *it << endl;
	}
	else
	{
		cout << "�����͸� ã�� ���߽��ϴ�." << endl;
	}
}

struct Monster
{
	int id;
	string name;

	Monster(int id, string name) : id(id), name(name) {}	// ������ �Լ� 
};

// �˰����� ����� ��ȭ �ڵ�

/*
* �˰��� ����
* 
* std::�Լ��̸�(vec.begin(), vec.end(), ���ǵ� �Լ�, ���ٽ�, ����)
* 
* �Լ��ȿ� �Լ� ��� ����(?)
* 
* 1. bool (*�Լ��̸�) (int x);	
* 
* 2. functor : struct �Ǵ� class Ÿ���� ���� ��������� �� �����̱⿡ ������ ���� ������� �ʴ´�.
* 
* 3. lamda�� : �Լ��� �������� �ʾƵ� �Լ��� ȣ���� ��ó�� ����� �� �ִ�. (���� �Լ� - �̸��� ���� �Լ�)
* 
* []() {} 
*/

// Ȧ�� (Even)
bool IsEven(int x)
{
	return x % 2 != 0;
}

// ¦�� (Odd)
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
	monsters.emplace_back(1, "�밨�� ��Ű");
	monsters.emplace_back(2, "������� ��Ű");
	monsters.emplace_back(3, "������ũ�� ��Ű");
	monsters.emplace_back(4, "Ŀ���͵�3���� ��Ű");

	// find_if() : 3��° ���ڿ� � �����͸� ã������ ������ �־��ش�. 
	// �Լ�, functor, ���ٽ�

	auto it = find_if(monsters.begin(), monsters.end(),
		[](const Monster& findMon) {return findMon.id == 3; });
	cout << it->name << endl;

	cout << "�Լ� �����ͷ� ������ ����" << endl;

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
		cout << "nums�� ��� �����Ͱ� Ȧ���̴�." << endl;
	}
	else
	{
		cout << "nums�� �����Ϳ� ¦���� �����Ѵ�." << endl;
	}
}