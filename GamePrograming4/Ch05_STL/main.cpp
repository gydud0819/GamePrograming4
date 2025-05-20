/*
* �ۼ���	: 2025-05-20
* �ۼ���	: ��ȿ��
* ����	: iterator�� Ȱ���� �ڷᱸ�� 
*/

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>	// 90�� ������ �پ��� �Լ��� �����Ǿ� �ִ�. 
#include "Algorithm.h"
using namespace std;

/*
* intŸ���� �����͸� �����ϴ� vectorŬ������ ����� 1,2,3,4,5 �����ϱ�
*/

/*
* iterator (�ݺ���)
* ������ ������ �ϴ� Ŭ����
* �ڷᱸ��::iterator
* 
* ����
* 
* iterator�� ����Ͽ� �ڷᱸ���� element�� ����� �� �ִ�.
* begin(), cbegin(), rbegin(), crbegin()
* end(), cend(), rend(), crend()
* 
* auto it = �̸�; 
* 
*
* 
* �˰����� ������ �� iterator�� ��...... 
* https://en.cppreference.com/w/cpp/algorithm	// �˰��� ����Ʈ 
*/


// iterator�� �⺻ ���� 
void test1()
{
	vector<int> nums = { 1,2,3,4,5 };
	list<int> intlist = { 1,2,3,4,5 };
	vector<int>::iterator it = nums.begin();

	cout << endl;
	cout << "iteratorf�� Ȱ���� �ڷᱸ�� ��ü ������ ���" << endl;
	// iteratorf�� Ȱ���� �ڷᱸ�� ��ü ������ ���
	while (it != nums.end())	// vector.end()
	{
		cout << *it << " ";	// iterator�� ����� �ּ��� ���� �������Ͽ� ����ϱ� 
		it++;
	}

	cout << "for �ݺ����� Ȱ���� �ڷᱸ�� ��ü ������ ���" << endl;
	// for �ݺ����� Ȱ���� �ڷᱸ�� ��ü ������ ���
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}

	cout << "list �ڷᱸ���� Ȱ���� �ڷᱸ�� ��ü ������ ���" << endl;
	// vector�� �ƴ� �ٸ� �ڷᱸ������ �����͸� ��ȸ, ����ϴ� ��
	list<int>::iterator it2 = intlist.begin();
	while (it2 != intlist.end())
	{
		cout << *it2 << " ";
		it2++;
	}
}

// �������� ����ϴ� ���
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
	cout << "list�� Ȱ���Ͽ� �������� ���" << endl;
	list<int> lis{ 1,2,3,4,5,6,7,8,9,10 };
	//list<int>::reverse_iterator it2 = lis.rbegin();
	auto it2 = lis.rbegin();

	while (it2 != lis.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
}

// auto�� Ȱ���ؼ� ����ϴ� ���
void test3()	
{
	cout << "\n============================================" << endl;

	// ���� 1
	auto x = 5;

	// ���� 2. ���� ����ϸ� ������?
	// Ÿ�� �̸��� �ſ� �� �������� �ִ�.

	vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.rbegin();

	//auto score = 2.3 * 30 + 1.5 * 30;

	// ������ �� : ���� ������ �����ʿ� ���� value�� ��Ư���� �������� �� ����� ���� �ʴ´�. 

	// ���� 3
	for (const auto& num : nums)	// ���� �ٲٰ� ���� ������ auto& �տ� const�� �ٿ� ����Ѵ�.
	{
		cout << num << " ";	// ���� ������ ��� 
	}

	for (auto& i : nums)			// ���� �ٲٰ� ������ auto&�� ����Ѵ�. 
	{
		i = 0;
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}

	/*
	* auto ����
	* 
	* auto�� num���� �� value�� �ް� ����
	* �����͸� ���縦 �ؼ� ����ϰ� ���� �� ����Ÿ���� &�� ����Ѵ�. 
	* 
	* ������ �ڷ����� �ſ� ���� �� auto�� ����Ѵ�. 
	* 
	* auto			: int, double, primitive type�� ����� �� ���ϰ� ��� �Ѵ�. (�����ؼ� ���������.)
	* auto&			: �޸𸮿� �����͸� ���������� ������ �� �ְ� �Ѵ�.  
	* cosnt auto&	: �޸𸮿� �����͸� ���������� �������� ���ϰ� �Ѵ�.
	*/

}

// ��� iterator
void test4()	
{
	// cbegin�� ����ϸ� �� ������ �� �� ����. 

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

// iterator ���� (������ó�� ����� �� �ִ�)
void test5()
{
	cout << "\n============================================" << endl;
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };

	//auto it = vec.begin() + 1;	// 2�� ����Ų��. 2�� ���ϸ� 3�� ����Ų��. 

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