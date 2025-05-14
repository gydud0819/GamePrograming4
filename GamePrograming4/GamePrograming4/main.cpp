/*
* �ۼ���	: 2025-05-13
* �ۼ���	: ��ȿ��
* ����	: �ڷ� ���� (OT)
*/

/*
* �ڷᱸ�� (Data Structure)
*
* Data		: ���ӿ� �����ϴ� ������ ��ǻ�Ͱ� �ؼ��� �� �ֵ��� �ۼ��� ��
* Structure : ����, ���� - ���꼺, ������
*
* �����͸� ���� �ؾ��ϴ� ����
* STL (Standard Template Library)
* ǥ��		: �ſ��� �� �ִ�? ���������� ���� ����Ѵ�.
* ���ø�		: �Ϲ�ȭ ���α׷����� �����ϱ� ���� ����
* ���̺귯��	: ������� �Լ�, Ŭ����
*
* �����̳�	: Ư���� ������ ���� ��Ƴ��� Ŭ����(��ü)
*
* �˰���	: �����̳� �ȿ� �ִ� �����͸� ����ϴ� �Լ� ���̺귯��
*
* �ݺ���		: �˰��� �ڵ带 �����ϰ� ����ϱ� ���� ����
*/

/*
* array, vector, list, queue, priorlity queue, hash-set, map
* � ��쿡 ������ ����ؾ� �ϴ��� ���� ���� �ٽ��̴�.
*
* �� �� �ڵ忡�� �� �ڷᱸ���� ����ߴ°�? ��� ������ ���̹���.
*/

#include <iostream>
#include <vector>		// 
#include <algorithm>	// 
using namespace std;

#include "Template.h"
#include "Sample.h"
int main()
{
	cout << "�ڷᱸ�� ����" << endl;

	vector<int> nums = { 23,33,5,7,44,37 };	// ������ ������ 3���� �����ϰ� �ִ� 'nums' vector
	// <>�� ����ǹ�

	// ������ ���1. 23, 33, 11
	cout << "������ ���1 : ";

	for (auto& num : nums)		// 'nums'�ȿ� �ִ� ������ Ÿ�� ������ҵ� ��θ� �����϶�� ��
	{
		cout << num << " ";
	}
	cout << endl;

	sort(nums.begin(), nums.end());	// �����͸� �����Ѵ�.

	cout << "������ ���2 : ";

	// ������ ���2. 1, 23, 33

	for (auto& num : nums)		// 'nums'�ȿ� �ִ� ������ Ÿ�� ������ҵ� ��θ� �����϶�� ��
	{
		cout << num << " ";
	}

	cout << endl;

	cout << "���ø� ����" << endl;

	// Ÿ���� �����ϴ� 

	int num = Add<int>(2, 5);
	cout << num << endl;

	int num1 = Add(1, 5);
	double num2 = Add(1.3, 5.3);
	int num3 = Add('c', 'a');
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	Example1();
}