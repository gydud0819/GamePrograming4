/*
* 주제	: unordered_map에 대해 이해하기
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsoleUtility.h"

using namespace std;

/*
* unordered : 정렬되지 않은
*/

#pragma region Hash 함수
/*
* Hash Function : Hashing하다.
* - 전달하는 타입을 특정한 규칙으로 다른 타입으로 변환하는 작업이다.
* Hashing 결과로 데이터를 재정렬해서 사용할 수 있다.
* 
*/

/*
* Hash로 만든 자료구조의 장점
* - map보다 데이터 접근이 빠르고, 데이터 탐색이 빠르다.
* 
*/
#pragma endregion

int HashFunction(int input)
{
	return input % 10;	// 0 ~ 9 까지만 나온다. 
	
}

void Test1()
{
	HashFunction(250925);	// 250925 -> 5로 저장한다.

	// unordered_map : [key - value]		:: 5에 250925라는 숫자가 들어있다. 

	unordered_map<string, int> umap;

	umap.insert({ "용과", 4 });
	umap.insert({ "복숭아", 2 });

	cout << "예제 1" << endl;
	cout << "용과 개수 : " << umap["용과"] << endl;

	cout << endl;

	cout << "예제 2" << endl;
	cout << "파인애플이 존재하는가?" << endl;

	auto it = umap.find("파인애플");
	if (it != umap.end())
	{
		cout << "파인애플을 찾았습니다." << endl;
	}
	else
	{
		cout << "찾지 못했습니다." << endl;
	}
}


//int HashFunction(string)
//{
//	return input % 10;	// 0 ~ 9 까지만 나온다. 
//}
#pragma region map과 unordered_map 비교
/*
* 탐색은 unordered_map이 map보다 압도적으로 빠르다.
* 단, 데이터의 수가 많을수록 unordered_map가 더 좋다. 
* 
* unordered_map이 유리하다. 머할때 유리하지 
* 유리한 이유
* 데이터를 초기화 하는데 걸리는 시간
* 순차 컨테이너 > 연관 컨테이너
* map > unordered_map (해시함수가 구현되어있고 해시 함수로 저장하는 내부 데이터가 ?)
* 
* 해시 함수의 단점
* - 해싱충돌이 일어날 때 성능저하가 발생할 수 있다. 
*/
void MapTimeTest()
{
	map<string, int> map;
	map.insert({ "바닐라",1 });
	map.insert({ "치즈",2 });
	map.insert({ "베리",3 });
	map.insert({ "카카오",4 });
	map.insert({ "백합",5 });

	for (int i = 0; i < 100000; i++)
	{
		map.find("바닐라");
	}
}

void UMapTimeTest()
{
	map<string, int> umap;
	umap.insert({ "바닐라",1 });
	umap.insert({ "치즈",2 });
	umap.insert({ "베리",3 });
	umap.insert({ "카카오",4 });
	umap.insert({ "백합",5 });

	for (int i = 0; i < 100000; i++)
	{
		umap.find("바닐라");
	}
}

void Test2()
{
	cout << "1번째 비교 : 데이터 입력시간 비교" << endl;
	
	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);

	/*
	* 1번째 비교 결과
	* Umap이 아주 조금 빠르다.
	* map 장점 : 데이터의 자동 정렬이 발생한다.
	* 정렬이 된 데이터가 필요할 때 map이 유리하다.
	*/

	cout << "map 장점 : 데이터의 자동 정렬이 발생한다." << endl;
	cout << "정렬이 된 데이터가 필요할 때 map이 유리하다." << endl;
	cout << "Umap이 아주 조금 빠르다." << endl;

	cout << "그 외에 컨테이너 안에 빠르게 데이터를 찾고 변경하고 싶을 때" << endl;

	cout << "2번째 비교 : 데이터 입력시간 비교" << endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);

	/*
	* 2번째 비교 결과
	* 데이터 수가 많을수록 map이 더 빠르다.

	*/

}
#pragma endregion


int main()
{
	//Test1();

	Test2();
}