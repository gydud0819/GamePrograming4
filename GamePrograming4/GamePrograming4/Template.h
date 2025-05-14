#pragma once
#include <iostream>

// 더하기 함수 
// 함수 오버로딩, 실수
// 현재 갖고 있는 코인 + 추가된 코인 (1/2 코인이 생겼을때)
// 일반화된 코드로 만들면 유지 보수, 가독성에 좋지 않을까?

// T가 int면 자료형의 형식으로 만들어주라는 의미?
// T가 int, double, char

template<typename T>	// 사용하면 코드의 가독성이 늘어난다.

T Add(T a, T b)
{
	return a + b;
}