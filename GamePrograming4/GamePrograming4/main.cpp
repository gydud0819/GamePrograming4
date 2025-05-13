/*
* �ۼ���	: 2025-05-13
* �ۼ���	: ��ȿ��
* ����	: �ڷᱸ�� vector
*/
/*
* 	�ڷ� ���� (Data Structure)
*
*   Data	  : ���ӿ� �����ϴ� ���� ��ǻ�Ͱ� �ؼ��� �� �ֵ��� �ۼ��� ��
*   Structure :	����, ���� -  ���꼺, ������
*
*   �����͸� ���� �ؾ��ϴ� ����
*   STL ( Standard Template Library)
*   ǥ�� : �ſ��� �� �ִ�. ���������� ���� ����Ѵ�.
*   ���ø� : �Ϲ�ȭ ���α׷����� �����ϱ� ���� ����
*   ���̺귯�� :	������� �Լ�, Ŭ����
*
*   �����̳� : Ư���� ������ ���� ��Ƴ��� ��ü
*   �˰��� : �����̳� �ȿ� �ִ� �����͸� ����ϴ� �Լ� ���̺귯��
*   �ݺ��� : �˰��� �ڵ带 �����ϰ� ����ϱ� ���� ����
*/

/*
*  array, vector, list, stack, queue, priority queue, hash-set, map
*  � ��쿡 ������ ����ؾ� �ϴ����� ���� �ַ� ��� ��
*  ȸ�� ������ - �� �� �ڵ忡�� �� �ڷᱸ���� ����߳���? ��� ������ ���� ���� �޴´�.
*/

#include <iostream>
#include <vector>   
#include <algorithm>
using namespace std;


#include "Template.h"
#include "Sample.h"

int main()
{
	cout << "�ڷ� ���� ����" << endl;

	vector<int> nums = { 23, 54, 5, 2, 7, 37, 31, 44 }; // ������ ������ 3�� �����ϰ� �ִ� 'nums' vector

	// ������ ���1. 23, 54, 5, 2, 7, 37, 31, 44
	cout << "������ ���1 : ";

	for (auto& num : nums)  // 'nums'�ȿ� �ִ� ������ Ÿ�� ������ҵ� ��ΰ� �����϶�
	{
		cout << num << " ";
	}

	cout << endl;

	std::sort(nums.begin(), nums.end()); // �����͸� �����Ѵ�. 

	// ������ ���2. 2, 5, 7, 23, 31, 37, 44, 54
	cout << "������ ���2 : ";
	for (auto& num : nums)  // 'nums'�ȿ� �ִ� ������ Ÿ�� ������ҵ� ��ΰ� �����϶�
	{
		cout << num << " ";
	}

	cout << endl;

	cout << "���ø� ����" << endl;

	// Ÿ�� ����

	int num = Add<int>(2, 5);
	cout << num << endl;

	int num1 = Add(1, 4);
	double num2 = Add(1.5, 4.2);
	int num3 = Add('b', 'a');
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	Example1();
}