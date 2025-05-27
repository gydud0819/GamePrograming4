#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <chrono>	// clock 기능을 하는 함수들이 포함되어 있다.
using namespace std;

/*
* 목표 : vector와 list 차이점 직접 비교하기
*
* 1. 임의의 데이터에 접근하는 시간을 비교한다.
* 결과 : vector는 바로 임의의 데이터에 접근할 수 있다. 속도가 빠르다.
*		 list는 n번째 데이터에 접근하는 데 기링에 비해서 시간이 걸린다. 속도가 느리다.
*
* 2. 첫번째와 끝의 데이터가 아닌 데이터를 삭제 또는 수정하는 데 걸리는 시간 비교하기
* - 많은 데이터를 자주 삭제 또는 수정하는 경우에는 vector의 시간이 비효율적이다 (시간이 오래걸린다?)
* - 1~N 데이터 -> 1~N -1개의 데이터 옮기는 작업을 매번 해줘야 한다.
* 
* 데이터를 지우거나 변경하는 작업이 많으면 많을수록 vector가 시간이 비효율적이다. (vector의 최대 단점)
*/

/*
* 어떤 자료구조를 써야할지 잘 모를땐 vector로 만들어본다. (처리 속도가 제일 빠르다.) 시간복잡도가 빠르다고 보면되는건가?
*/

void TimeCheckList_Vector()
{
	cout << "STL Vector 기능이 시간이 얼마나 걸리는지 측정하는 코드" << endl;

	auto Start = chrono::high_resolution_clock::now();
	vector<int> vNum;

	for (int i = 0; i < 1000000;i++)
	{
		vNum.push_back(i);
	}

	for (int i = 0; i < 5000; i++)		// 이 코드를 사용하게 되면 vector의 처리속도가 더 느리다.
	{
		auto it = vNum.begin() + 5;

		vNum.erase(it);		// erase를 써도 vector가 빠르다.

	}

	auto End = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = End - Start;

	cout << duration.count() << "ms" << endl;
}

void TimeCheckList_List()
{
	cout << "STL List 기능이 시간이 얼마나 걸리는지 측정하는 코드" << endl;

	auto Start = chrono::high_resolution_clock::now();

	list<int> lNum;

	for (int i = 0; i < 50000;i++)
	{
		lNum.push_back(i);
	}

	for (int i = 0; i < 5000; i++)
	{
		auto it = next(lNum.begin(), 5);
		lNum.erase(it);

	}

	auto End = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = End - Start;

	cout << duration.count() << "ms" << endl;
}


