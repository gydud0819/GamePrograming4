#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/*
* 데이터 저장
* 1. 플레이어의 레벨, 경험치
* 
* 2. 데이터 자료구조 형태로 저장.
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

		// 1. file을 열어라
		// 2. 메모장에 exp와 level을 저장해라.
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