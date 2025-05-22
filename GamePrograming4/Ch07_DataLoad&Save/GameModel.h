#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*
* ��ǥ : ������ �ý����� �����ϰ� ���� �� 
*
* int exp;
* int maxExp;	���� ����ġ > maxExp �϶� ������ 1 �����Ѵ�.
*/

/*
* ��ǥ2 : ������ ���� ����ġ �䱸���� �ڷᱸ���� ǥ���ϱ�
* ����� �ڷᱸ�� : vector
*/

/*
* 1. �����͸� ǥ���ϱ� ���� Ŭ���� �����ϱ�
* 2. Ư�� Ŭ���� �ȿ� ǥ���ϱ� ���� �ڷᱸ���� �����ϱ�		Player -> vector<LvExp> LvTable;
*/

/*
* �����ڿ� �����͸� ���� �ۼ��Ѵ�. 
* vector.push(); �̳� vector.emplace_back(); �� ����Ѵ�. 
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
	vector<LvExp> LvTable;	// �����͸� ���� ���������Ѵ�. 

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
	//	// 1������ �����͸� �����ͼ� ����Ѵ�.
	//	
	//	maxExp = LvTable[i].maxExp;
	//}

	int GetMaxExpForLv(int Lv)
	{
		for (const auto& data : LvTable)
		{
			// ������ table ������ ���Ѵ�.
			if (Lv == data.Lv)
			{
				return data.maxExp;
			}
		}

		return -1;	// 0�� ��ȯ�ϸ� ������ �ν��϶�� �ǹ��̴�. 
	}

	void GetExp(int amount)		// ����ġ�� ȹ���ϸ�
	{
		exp += amount;	// ����ġ ��ġ��ŭ �����ش�.  

		maxExp = GetMaxExpForLv(Lv);

		if (maxExp == -1)
		{
			cout << "�ִ� ������ �����߽��ϴ�. ������ ����մϴ�." << endl;
			return;		// ����ó�� �ڵ� �˸� �� �Լ��� �����Ѵ�. 
		}
		
		if (exp >= maxExp)	// ������ �ִ� ����ġ�� �������� �� 
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