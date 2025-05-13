#pragma once

// int array[100];
// 1. vector<int> vec;

// 2. template ������ �ڵ�� �����غ� ��


// vector< > �����е��� ���� ������ Ŭ������ �ѹ� �����ϰ�, �����ϰ�, ����ϴ� ������ �ѹ� ��������.
// ���� ���� 
// ���ӿ� �����͸� Ŭ������ ǥ��.
// vector<<< >>>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PocketMonster
{
private:
	int _number;
	string _name;

public:
	PocketMonster(int number, string name)
		: _number(number), _name(name) {
	}

	int Get_Number() const
	{
		return _number;
	}

	string Get_Name() const
	{
		return _name;
	}

	bool operator<(const PocketMonster& other)
	{
		// this->_number : �ڽ��� ���� ��ȣ
		// other.Get_Number() : �� ����� ���� ��ȣ

		return this->_number < other.Get_Number();

		//return this->_name.length() < other.Get_Name().length();
	}

	bool operator>(const PocketMonster& other)
	{
		return this->_number > other.Get_Number();
	}

};

// 15��.  

class Player
{
	vector<PocketMonster> myPocketmon;
};



void Example1()
{
	PocketMonster ��ī��(25, "��ī��");
	PocketMonster �ƺ�(23, "�ƺ�");
	PocketMonster ���̸�(4, "���̸�");
	PocketMonster ���α�(7, "���α�");
	PocketMonster ������(18, "������");
	PocketMonster ����(150, "����");

	//cout << "No." << pica.Get_Number() << " " << pica.Get_Name() << endl;


	cout << "���αⰡ ��ī�� ���� ���� ��ȣ�� ū��?" << endl;
	if (���α� < ��ī��)
	{
		cout << "�ƴϿ�" << endl;
	}
	else
	{
		cout << "��" << endl;
	}


	vector<PocketMonster> pocketDatabase;

	// ������ �Է�

	pocketDatabase.push_back(��ī��);
	pocketDatabase.push_back(�ƺ�);
	pocketDatabase.push_back(���̸�);
	pocketDatabase.push_back(���α�);
	pocketDatabase.push_back(������);
	pocketDatabase.push_back(����);

	// ������ �˰��� (����)
	sort(pocketDatabase.begin(), pocketDatabase.end());

	// ������ ���
	for (auto& pocketmon : pocketDatabase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	// ������ ã��(�˻�)
	for (auto& pocketmon : pocketDatabase)
	{
		if (pocketmon.Get_Number() == 25)
		{
			cout << pocketmon.Get_Number() << "�� ���͸� ã�Ҵ�.";
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
		else
		{
			cout << "��ã�Ҵ�";
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}

	}

}
