#include <iostream>
#include "ConsoleUtility.h"

// Sequence Containers : vector, list, deque
#include <vector>
#include <list>
#include <deque>

// 연관 컨테이너(associate Containers) : (multi, unordered, set, map)
#include <set>
#include <map>
#include <algorithm>	// 컨테이너에 데이터를 처리하는 기능들이 저장되어 있는 라이브러리이다. iterator를 사용한다.

/*
* 1단계. 순차 컨테이너의 데이터 입력 시간 비교허가
* 2단계. 순차 컨테이너 중간 데이터 입력 시간 비교하기
* 3단계. 개수와 중간 데이터 삭제를 비교하여 적합한 순차 컨테이너 사용하기
*
*/

using namespace std;

void Example()
{
	cout << "예시" << endl;
}

#pragma region (1단계) 순차 컨테이너의 데이터 입력 시간 비교하기

void DataPushMyVector()
{
	vector<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void DataPushMyList()
{
	list<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);	// push_back, front 2개 있음
	}
}

void DataPushMyDeque()
{
	deque<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);	// push_back, front 2개 있음
	}
}

void Test1()
{
	cout << "데이터 입력 시간 비교 " << endl;

	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(DataPushMyVector);

	cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(DataPushMyList);

	cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(DataPushMyDeque);

	cout << "결과 : 단순 데이터를 입력할 때 vector가 가장 빠르다." << endl;

	cout << endl;

}
#pragma endregion

#pragma region (2단계) 순차 컨테이너 중간 데이터 입력 시간 비교하기
void InsertDataByVector()
{
	vector<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 100000; i++)
	{
		auto it = nums.begin() + 5;
		nums.insert(it, 1);		// insert : 중간에 넣는 것

	}
}

void InsertDataByList()
{
	list<int> nums;
	for (int i = 0;i < 10;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 100000; i++)
	{
		auto it = next(nums.begin(), 5);	// list만 next 함수를 사용해야 한다. 
		nums.insert(it, 1);		// insert : 중간에 넣는 것

	}
}

void InsertDataByDeque()
{
	deque<int> nums;
	for (int i = 0;i < 10;i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 100000; i++)
	{
		auto it = nums.begin() + 5;
		nums.insert(it, 1);		// insert : 중간에 넣는 것

	}
}


void Test2()
{
	cout << "중간 데이터 입력 시간 비교 " << endl;

	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);

	cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByList);

	cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);

	cout << "결과 : 처음 데이터를 입력했을 때는 vector가 빠르다." << endl;
	cout << "결과2: 중간 삽입(삭제)하는 과정이 많으면 많을수록 list가 가장 빠르다." << endl;
	cout << endl;
}
#pragma endregion

#pragma region (2-2단계) 데이터를 맨 앞에 추가할 떄 걸리는 시간 비교하기
void FrontPushByVector()
{
	vector<int> nums;

	for (int i = 0; i < 10000; i++)
	{
		auto it = nums.begin();		// vector는 insert가 없기 때문에 begin을 사용하여 맨 앞에 넣어준다. 
		nums.insert(it, i);
	}
}

void FrontPushByList()
{
	list<int> nums;
	for (int i = 0; i < 10000; i++)
	{
		nums.push_front(i);

	}
}

void FrontPushByDeque()
{
	// 똑같은 크기의 배열을 새로 만들어서 그 공간에 넣는다라는 건가 
	// 앞 뒤로 둘다 넣을 수 있을 때 덱이 유리하다? 
	deque<int> nums;
	for (int i = 0; i < 10000; i++)
	{
		nums.push_front(i);

	}
}

void Test2_2()
{
	cout << "첫번째 위치에 데이터 입력 시간 비교 " << endl;

	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByVector);

	cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByList);

	cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByDeque);

	cout << "결과 : 첫번째 원소를 넣는 경우에는 deque가 빠를 수 있으며 vector의 장점과 단점을 해결할 수 있다." << endl;
	cout << endl;
}
#pragma endregion

#pragma region (2-3단계) 순차 컨테이너에서 랜덤 원소 접근에 걸리는 시간 비교하기
void RandomAccessByVector()
{
	vector<int> nums;
	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;	// i의 값을 0으로 바꾸라는 의미

	}
}

void RandomAccessByList()
{
	list<int> nums;
	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)		// list 코드가 어려운 이유는 성능이 떨어지고 비효율적이라는 것을 짐작할 수 있다. 
	{
		auto it = next(nums.begin(), i);
		*it = 0;

	}
}

void RandomAccessByDeque()
{
	deque<int> nums;
	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;	// i의 값을 0으로 바꾸라는 의미

	}
}

void Test2_3()
{
	cout << "랜덤 위치에 데이터를 접근하는 시간 비교 " << endl;

	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByVector);

	cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByList);

	cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccessByDeque);

	cout << "결과 : 배열 형태의 자료구조인 vector와 deque은 바로 접근할 수 있다." << endl;	// 처리 속도가 빠르다.
	cout << "list의 경우 시작과 거리가 멀면 멀수록 처리하는 속도가 오래 걸린다." << endl;
	cout << endl;
}
#pragma endregion

#pragma region 순차 컨테이너 결과 비교
/*
* 처리 속도 비교 결과
*				|	vector		|		List		|		Deque		|
*	push		|		1		|		3			|		2			|
*	insert		|		2		|		1			|		3			|
*	front		|		3		|		2			|		1			|
*	access		|		1		|		3			|		2			|
*				|				|					|					|
*				|				|					|					|
*/

/*
* Case 1. 데이터의 입력이 (많이) 발생하고, 중간 데이터 입력이 (적으며), 앞에 데이터 입력이 (적으며), 랜덤 접근이 (많은) 경우
*/
#pragma endregion

#pragma region (3단계) 순차 컨테이너와 연관 컨테이너

// 데이터를 저장하는 공간으로 컨테이너를 만들었다.
// ex) std::vector<int> nums;	int a = nums[?];
// 컨테이너 안에 해당하는 데이터가 없으면 에러가 발생한다. if(데이터가 존재하는가?) ==> 실행하라.
//bool Find(int value)
//{
//	int nums[10] = { 0,1,2,3,4,5,6,7,8,9, };
//	for (int i = 0; i < value; i++)
//	{
//		if (nums[i] == 5)
//		{
//			cout << nums[i] << "값을 찾았다." << endl;
//			return true;
//		}
//
//	}
//	cout << "값을 찾지 못했다." << endl;
//	return false;
//}

void FindByVector()
{
	vector<int> nums;

	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}

	for (int i = 0; i < 10; i++)
	{
		auto it = find(nums.begin(), nums.end(), 5);
		
	}
}

void FindByList()
{
	list<int> nums;

	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}

	for (int i = 0; i < 10; i++)
	{
		auto it = find(nums.begin(), nums.end(), 5);
		
	}
}

void FindByDeque()
{
	deque<int> nums;

	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}

	for (int i = 0; i < 10; i++)
	{
		auto it = find(nums.begin(), nums.end(), 5);
		
	}
}

void FindBySet()
{
	set<int> nums;

	for (int i = 10; i > 0; i--)
	{
		nums.insert(i);		// set도 push가 없기에 insert를 사용한다.

	}

	nums.insert(100);
	nums.insert(50);

	//nums.insert(1);

	for (auto num : nums)
	{
		cout << num << " ";
	}

	for (int i = 0; i < 10; i++)
	{

		nums.find(i);
	}
}

void Test3()
{
	cout << "데이터를 검색하는 시간 비교 " << endl;

	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(FindByVector);

	cout << "list의 시간 : ";
	ConsoleUtil::TimeCheck(FindByList);

	cout << "deque의 시간 : ";
	ConsoleUtil::TimeCheck(FindByDeque);

	cout << "set의 시간 : ";
	ConsoleUtil::TimeCheck(FindBySet);

	cout << "결과 : 순차 컨테이너는 데이터를 입력하는 데 빠르다." << endl;	// 처리 속도가 빠르다.
	cout << "연관 컨테이너는 자체적으로 데이터를 입력하는 로직이 존재하기 때문에 시간이 더 걸린다." << endl;
	cout << "데이터를 지속적으로 입력하는 경우가 아니면서, 자주 데이터를 검색해야 할 때 사용한다." << endl;	// 설명이 모호함 좀 더 찾아봐야겟음 
	cout << endl;
}
#pragma endregion



int main()
{
	Test1();	// 벡터가 빠르다
	Test2();	// 리스트가 빠르다
	Test2_2();	// 덱이 빠르다
	Test2_3();	// 벡터가 빠르다

	//cout << boolalpha;	// true, flase를 출력하고 싶을 때 사용한다?
	//cout << Find(10);

	Test3();

	FindByVector();
	cout << endl;
	FindByList();
	cout << endl;
	FindByDeque();
	cout << endl;
	FindBySet();
}