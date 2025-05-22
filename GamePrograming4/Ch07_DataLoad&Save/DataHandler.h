#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/*
* ������ ����
* 1. �÷��̾��� ����, ����ġ
* 
* 2. ������ �ڷᱸ�� ���·� ����.
* 1 100
* 2 150
*/

class Data
{
public:
	int exp;
	int Lv;

	Data() : exp(100), Lv(1) {}

public:
	void SaveData(const string& filename)
	{
		ofstream file(filename);

		// 1. file�� �����
		// 2. �޸��忡 exp�� level�� �����ض�.
		// 3. close
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

		int _exp, _Lv;

		file >> _Lv >> _exp;

		Lv = _Lv;
		exp = _exp;
	}
};