#pragma once
#include <iostream>

using namespace std;

/*
* 1. 함수선언하기 ((반환 값) (*호출할 함수 이름) () )
* 2. 호출할 함수의 인자가 있을 때 
*	함수 선언 ((반환 값) (*호출할 함수 이름) (타입 이름, 타입 이름) 타입 이름, 타입 이름 )
*/

void Add(int a, int b)
{
	cout << "덧셈" << endl;
	cout << a + b << endl;
}

void Minus(int a, int b)
{
	cout << "뺄셈" << endl;
	cout << a - b << endl;
}

void Times(int a, int b)
{
	cout << "곱셈" << endl;
	cout << a * b << endl;
}

void Divided(int a, int b)
{
	cout << "나눗셈1" << endl;
	cout << a / b << endl;
}

void Divided2(int a, int b)
{
	cout << "나눗셈2" << endl;
	cout << a % b << endl;
}

void Calculate(void (*Func) (int a, int b), int a, int b )	// 기억해두면 함수 포인터를 쓸때 유용하다. 
{
	Func(a, b);		// 인자를 함수로 받아온다. 
}

void Test()
{
	Calculate(Add, 37, 31);	// 덧셈

	Calculate(Minus, 44, 23);	// 뺄셈

	Calculate(Times, 54, 22);	// 곱셈

	Calculate(Divided, 45, 32);	// 나눗셈(몫)

	Calculate(Divided2, 45, 3);	// 나눗셈(나머지)

}