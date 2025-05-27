/*
* 작성일	: 2025-05-26
* 작성자	: ㅂㅎㅇ
* 주제	: vector와 list 차이점 직접 비교하기
*/

#include<iostream>
#include <vector>
#include <list>
#include <deque>
#include "TimeCheck.h"
#include "FunctionPointer.h"
#include "ConsoleUtility.h"

using namespace std;

/*
* Sequence Container
* Vector
* Deque
* List
*/

/*
* 목표 : vector와 list 차이점 직접 비교하기
* 1. vector push_back() 추가, list push_back() 추가한 시간 비교 하기
* vector가 더 빠르다. 
* 이유 : 
* 
* 2. 임의의 데이터에 접근하는 데 걸리는 시간
* vector가 더 빠르다.
* 이유 : list 개수가 많을수록 시간이 더 많이 걸린다. 
* 
* 3. 임의의 데이터를 지우는 데 걸리는 시간
* list가 더 빠르다.
* 이유 : 
* 
* 데이터 삭제는 적지만 접근은 많은 경우 : vector가 유리하다.
* 
* 데이터의 삭제가 잦은 경우 : list가 유리하다.
* 
* 데이터 삭제도 많고 접근도 많은 경우 : unodered_map 이 유리하다.
* 
* 게임을 만들 땐 밑의 2가지를 많이 사용한다. 
* vector
* unodered_map
*/

/*
* Vector와 List는 크게 차이가 없다.
* Vector [ ] 인덱스로 데이터를 출력할 수 있다.
* List [ ] 인덱스로 접근할 수 없다.	// 배열이 아닌 어떻게 자료를 표현할까
*
* 차이점을 눈으로 확인하기 위해 환경 설정을 한다.
*/

struct Node
{
	int value;
	Node* nextPtr;	// 다음 노드 
	Node* prevPtr;	// 이전 노드
};

void Test1_Vector()
{
	vector<int> nums;
	//nums.push_back(1);
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

	cout << nums[500] << endl;
}

void Test2_List()
{
	list<int> nums;
	nums.push_back(3);
	nums.push_front(2);
	nums.push_back(1);



	for (const auto& num : nums)
	{
		cout << num << endl;
	}

	
}

void VectorExample()
{
	vector<int> nums;

	for (int i = 0; i < 1000;i++)
	{
		nums.push_back(i);
	}
	cout << "임의의 데이터에 접근하는 데 걸리는 시간" << endl;

	cout << nums[990] << endl;

	// erase 함수 n번 사용하는 예제 만들어보기 
	// 함수 포인터 사용하기 

	for (int i = 0; i < 500; i++)
	{
		auto it = nums.begin() + 10;
		nums.erase(it);
	}
}

void ListExample()
{
	list<int> nums;

	for (int i = 0; i < 1000;i++)
	{
		nums.push_back(i);
	}

	cout << "임의의 데이터에 접근하는 데 걸리는 시간" << endl;
	
	auto it = next(nums.begin(), 990);
	cout << *it << endl;
}

template<typename T>
void VectorExample2(vector<T>& nums)
{
	auto Start = chrono::high_resolution_clock::now();
	vector<T> nums;

	for(auto& num : i)

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
	cout << "임의의 데이터에 접근하는 데 걸리는 시간" << endl;

	// erase 함수 n번 사용하는 예제 만들어보기 
	// 함수 포인터 사용하기 

	// 벡터의 중간 삭제 연산
	for (int i = 0; i < 500; i++)
	{
		auto it = nums.begin() + 10;
		nums.erase(it);
	}
	auto End = chrono::high_resolution_clock::now();

}

void ListExample2()
{
	auto Start = chrono::high_resolution_clock::now();
	list<int> nums;

	for (int i = 0; i < 1000;i++)
	{
		nums.push_back(i);
	}

	cout << "임의의 데이터에 접근하는 데 걸리는 시간" << endl;

	// 리스트의 중간 삭제 연산
	for (int i = 0; i < 1000; i++)
	{
		auto it = next(nums.begin(), 550);
		cout << *it << endl;
	}

	auto End = chrono::high_resolution_clock::now();
}

int main()
{
	//Test1_Vector();

	// Test2_List();

	// 자료구조 시간 테스트
	// TimeCheckList_Vector();
	// 
	// TimeCheckList_List();

	// 함수 포인터 예제
	// Test();

	// Console::TimeCheck(); 실행 테스트 
	// ConsoleUtil::TimeCheck(VectorExample);
	// ConsoleUtil::TimeCheck(ListExample);

	// double을 반환해서 비교도 할 수 있다. 

	//ConsoleUtil::TimeCheck(VectorExample2);
	//ConsoleUtil::TimeCheck(ListExample2);

	ConsoleUtil::VectorTimeCheck(VectorExample2);
}

/*
* // 삭제 방법을 넘기는 함수
void RepeatDelete(vector<int>& nums, void (*DelFunc)(vector<int>&)) {
    for(int i=0; i<500; ++i) DelFunc(nums);
}

// 실제 삭제 방법
void DeleteAt10(vector<int>& nums) {
    nums.erase(nums.begin() + 10);
}

// 벡터 예제
void VectorExample2() {
    vector<int> nums(1000);
    iota(nums.begin(), nums.end(), 0); // 0~999로 초기화

    RepeatDelete(nums, DeleteAt10);
}

*/
