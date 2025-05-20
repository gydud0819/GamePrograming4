/*
* 작성일	: 2025-05-20
* 작성자	: 박효영
* 주제	: iterator를 활용한 자료구조 
*/

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>	// 90개 정도의 다양한 함수가 구현되어 있다. 
#include "Algorithm.h"
using namespace std;

/*
* int타입의 데이터를 저장하는 vector클래스를 만들어 1,2,3,4,5 저장하기
*/

/*
* iterator (반복기)
* 포인터 역할을 하는 클래스
* 자료구조::iterator
* 
* 정리
* 
* iterator를 사용하여 자료구조의 element를 출력할 수 있다.
* begin(), cbegin(), rbegin(), crbegin()
* end(), cend(), rend(), crend()
* 
* auto it = 이름; 
* 
*
* 
* 알고리즘을 구현할 때 iterator를 어...... 
* https://en.cppreference.com/w/cpp/algorithm	// 알고리즘 사이트 
*/


// iterator의 기본 사용법 
void test1()
{
	vector<int> nums = { 1,2,3,4,5 };
	list<int> intlist = { 1,2,3,4,5 };
	vector<int>::iterator it = nums.begin();

	cout << endl;
	cout << "iteratorf를 활용한 자료구조 전체 데이터 출력" << endl;
	// iteratorf를 활용한 자료구조 전체 데이터 출력
	while (it != nums.end())	// vector.end()
	{
		cout << *it << " ";	// iterator에 저장된 주소의 값을 역참조하여 출력하기 
		it++;
	}

	cout << "for 반복문을 활용한 자료구조 전체 데이터 출력" << endl;
	// for 반복문을 활용한 자료구조 전체 데이터 출력
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}

	cout << "list 자료구조를 활용한 자료구조 전체 데이터 출력" << endl;
	// vector가 아닌 다른 자료구조에서 데이터를 순회, 사용하는 법
	list<int>::iterator it2 = intlist.begin();
	while (it2 != intlist.end())
	{
		cout << *it2 << " ";
		it2++;
	}
}

// 역순으로 출력하는 방법
void test2()
{
	cout << "\n============================================" << endl;
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	//vector<int>::reverse_iterator it = vec.rbegin();
	auto it = vec.rbegin();

	while (it != vec.rend())
	{
		cout << *it << " ";
		it++;
	}

	cout << endl;
	cout << "list를 활용하여 역순으로 출력" << endl;
	list<int> lis{ 1,2,3,4,5,6,7,8,9,10 };
	//list<int>::reverse_iterator it2 = lis.rbegin();
	auto it2 = lis.rbegin();

	while (it2 != lis.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
}

// auto를 활용해서 출력하는 방법
void test3()	
{
	cout << "\n============================================" << endl;

	// 예시 1
	auto x = 5;

	// 예시 2. 언제 사용하면 좋을까?
	// 타입 이름이 매우 긴 예제들이 있다.

	vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.rbegin();

	//auto score = 2.3 * 30 + 1.5 * 30;

	// 주의할 점 : 대입 연산자 오른쪽에 오는 value가 불특정한 데이터일 때 사용을 하지 않는다. 

	// 예시 3
	for (const auto& num : nums)	// 값을 바꾸고 싶지 않을때 auto& 앞에 const를 붙여 사용한다.
	{
		cout << num << " ";	// 지역 변수로 취급 
	}

	for (auto& i : nums)			// 값을 바꾸고 싶을때 auto&만 사용한다. 
	{
		i = 0;
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}

	/*
	* auto 정리
	* 
	* auto는 num으로 즉 value로 받고 있음
	* 데이터를 복사를 해서 사용하고 싶을 땐 참조타입인 &을 사용한다. 
	* 
	* 데이터 자료형이 매우 작을 때 auto만 사용한다. 
	* 
	* auto			: int, double, primitive type을 사용할 때 편하게 사용 한다. (복사해서 만들어진다.)
	* auto&			: 메모리에 데이터를 문법적으로 변경할 수 있게 한다.  
	* cosnt auto&	: 메모리에 데이터를 문법적으로 변경하지 못하게 한다.
	*/

}

// 상수 iterator
void test4()	
{
	// cbegin를 사용하면 값 변경을 할 수 없다. 

	cout << "\n============================================" << endl;
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };

	//vector<int>const_iterator it = vec
	auto it = vec.begin();	// cbegin = const begin

	while (it != vec.cend())
	{
		*it = 0;
		cout << *it << " ";
		it++;
	}

}

// iterator 응용 (포인터처럼 사용할 수 있다)
void test5()
{
	cout << "\n============================================" << endl;
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };

	//auto it = vec.begin() + 1;	// 2를 가리킨다. 2를 더하면 3을 가리킨다. 

	auto start = vec.begin() + 2;
	auto end = vec.end() - 3;
	
	while (start != end)
	{
		cout << *start << endl;
		start++;
	}
}

int main()
{
	//test1();

	//test2();

	//test3();

	//test4();

	//test5();

	//find_test();

	//find_test2();

	all_of_test();

	for_each_test();
}