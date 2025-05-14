#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* int array[100];
* 1. vector<int> vec;
*
* 2. template�� ����� ������ �ڵ� �����غ���
*/

// vetcor > ���� ���� ������ Ŭ������ �����ϰ�, �����ϰ�, ����ϴ� ���� �����
// ���� �����ͷ� Ŭ���� ǥ���� ������

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

	bool operator<(const PocketMonster& other)	// �񱳸� �Ұű� ������ const ����ϱ�
	{
		// this->_number : ���� ������ �ִ� ���� ��ȣ
		// other.GetNumber() : �� ����� ���� ��ȣ

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
	PocketMonster ��ī��(25, "��ī��");
	PocketMonster ���α�(7, "���α�");
	PocketMonster ���̸�(5, "���̸�");
	PocketMonster ������(18, "������");
	PocketMonster �ƺ�(23, "�ƺ�");
	PocketMonster ����(36, "����");

	//bool result = ���α� < ��ī��;

	cout << "���αⰡ ��ī�򺸴� ��ȣ�� ū��?" << endl;

	if (���α� < ��ī��)
	{
		cout << "�ƴϿ�" << endl;
	}
	else
	{
		cout << "��" << endl;
	}

	vector<PocketMonster> pocketDataBase;

	// ������ �Է�

	pocketDataBase.push_back(��ī��);		// push_back �о�ִ´�? 
	pocketDataBase.push_back(���α�);
	pocketDataBase.push_back(���̸�);
	pocketDataBase.push_back(������);
	pocketDataBase.push_back(�ƺ�);
	pocketDataBase.push_back(����);

	// ������ �˰��� (����)
	sort(pocketDataBase.begin(), pocketDataBase.end());

	// ������ ���
	for (auto& pocketMon : pocketDataBase)
	{
		cout << "No." << pocketMon.GetNumber() << " " << pocketMon.GetName() << endl;
	}

	// ������ ã�� (�˻�)
	for (auto& pocketMon : pocketDataBase)
	{
		if (pocketMon.GetNumber() == 5)
		{
			cout << pocketMon.GetNumber() << "�� ���͸� ã�Ҵ�." << endl;
			cout << "No." << pocketMon.GetNumber() << " " << pocketMon.GetName() << endl;
		}
		else
		{
			cout << "��ã�Ҵ�." << endl;
			cout << "No." << pocketMon.GetNumber() << " " << pocketMon.GetName() << endl;
		}
	}

}

class Cookie
{

};