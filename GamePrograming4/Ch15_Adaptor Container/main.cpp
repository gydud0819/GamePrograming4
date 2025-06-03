/*
* 주제	: adaptor 컨테이너에 대한 이해
*
* vector, list, deque로 만들어진 특별한 컨테이너
*
* stack, queue, priority_queue
* 스택, 큐, 우선순위 큐
*/
#include <iostream>


using namespace std;

#pragma region 스택
#include <stack>
/*
* 메모리 구조 LIFO (Last In First Out) - 후입선출
* 데이터를 사용하는 규칙을 제한하는 것으로 효율을 얻는 자료구조이다.
* Iterator(반복자)를 지원해주지 않는다. (내부적으로 iterator 클래스가 없다.)
*
* ex)
* ctrl+z (특정 위치로 돌아갈 수 있다.)
* 홈페이지 뒤로가기 등
*/

void Test1()
{
	cout << "스택 사용 예시" << endl;

	stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}

	// iterator를 지원해주지 않기 때문에 범위 기반 for loop를 사용할 수 없다.
	cout << "nums 데이터 출력" << endl;
	/*for (const auto& num : nums)
	{
		cout << num << " ";
	}*/

	while (!nums.empty())	// 자료구조가 비어있지 않을 때 반복하라는 의미이다.
	{
		cout << nums.top() << " ";	// top은 가장 위에 있는 데이터를 출력하는 것
		nums.pop();					// top의 데이터를 삭제하라는 것 
	}

	// size() = nums의 최댓값을 반환한다. 

	/*for (int i = 0; i < nums.size(); i++)
	{
		cout << nums.top() << " ";
		nums.pop();
	}*/

	cout << endl;
	cout << endl;
}
#pragma endregion

#pragma region 큐
/*
* 메모리 구조 FIFO(First In First Out) - 선입선출
*/

#include <queue>

void Test2()
{
	cout << "큐 사용 예시" << endl;

	queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}

	// iterator를 지원해주지 않기 때문에 범위 기반 for loop를 사용할 수 없다.
	cout << "nums 데이터 출력" << endl;
	/*for (const auto& num : nums)
	{
		cout << num << " ";
	}*/

	while (!nums.empty())	// 자료구조가 비어있지 않을 때 반복하라는 의미이다.
	{
		cout << nums.front() << " ";	// 들어온 순서대로 나간다.
		nums.pop();					// front의 데이터를 삭제하라는 것 
	}

	// size() = nums의 최댓값을 반환한다. 

	/*for (int i = 0; i < nums.size(); i++)
	{
		cout << nums.top() << " ";
		nums.pop();
	}*/

	cout << endl;
	cout << endl;
}

#pragma endregion

#pragma region 우선순위 큐

// 큐 : 들어온 순서대로 나가는 것
// 우선순위 큐 : 먼저 나가야하는 데이터가 우선적으로 나가는 것

// ex) 놀이공원 일반 이용권, 프리패스 이용권,
// 수강신청?

//#include <queue>에 포함되어 있다.
// heap 알고리즘으로 구현되어 있다. 가장 작은(큰) 값을 트리 구조의 맨 위로 보내는 형태
void Test3()
{
	cout << "우선순위 큐 사용 예시" << endl;

	priority_queue<int> nums;

	nums.push(0);
	nums.push(3);
	nums.push(1);
	nums.push(6);
	nums.push(9);
	nums.push(4);
	nums.push(8);

	// iterator를 지원해주지 않기 때문에 범위 기반 for loop를 사용할 수 없다.
	cout << "nums 데이터 출력" << endl;
	/*for (const auto& num : nums)
	{
		cout << num << " ";
	}*/

	while (!nums.empty())	// 자료구조가 비어있지 않을 때 반복하라는 의미이다.
	{
		cout << nums.top() << " ";	// 중요하다 생각되는 것 순서로 나간다.
		nums.pop();					// top의 데이터를 삭제하라는 것 
	}

	// size() = nums의 최댓값을 반환한다. 

	/*for (int i = 0; i < nums.size(); i++)
	{
		cout << nums.top() << " ";
		nums.pop();
	}*/

	cout << endl;
	cout << endl;
}
#pragma endregion

#include <vector>
#include <deque>

template<typename T>
class MyQueue
{
private:
	int size;
	deque<T> data;
public:
	MyQueue() : size(0) 
	{
		
	}
	void push(T& e)		// 포인터 또는 참조로 받아오는 것이 좋다.
	{
		size++;
		data.push_back(e);
	}

	T front()
	{
		return data[0];		// vector는 제일 앞에 있는 데이터를 불러온다.
	}

	void pop()
	{
		size--;
		data.pop_front();
	}

	int Size()
	{
		return size;
	}

	bool empty()
	{
		return size == 0;
	}
};

void Test4()
{
	// vector를 이용해 queue 만들기
	MyQueue<int> nums;

	cout << "vector를 이용해 queue 만들기" << endl;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}

	// iterator를 지원해주지 않기 때문에 범위 기반 for loop를 사용할 수 없다.
	cout << "nums 데이터 출력" << endl;
	/*for (const auto& num : nums)
	{
		cout << num << " ";
	}*/

	while (!nums.empty())	// 자료구조가 비어있지 않을 때 반복하라는 의미이다.
	{
		cout << nums.front() << " ";	// 들어온 순서대로 나간다.
		nums.pop();					// front의 데이터를 삭제하라는 것 
	}

	// size() = nums의 최댓값을 반환한다. 

	/*for (int i = 0; i < nums.size(); i++)
	{
		cout << nums.top() << " ";
		nums.pop();
	}*/

	cout << endl;
	cout << endl;
}

template<typename T>	// 헤더에서 만드는 것을 추천한다. 
class MyStack
{
private:
	int size;
	vector<int> data;
public:
	MyStack() : size(0)
	{
		
	}

	void push(T& e)
	{
		size++;
		data.push_back(e);
	}

	T top()
	{
		return data[0];
	}

	void pop()
	{
		size--;
		data.pop_back();	// back, front 주의하기 
	}

	int Size()
	{
		return size;
	}

	bool empty()
	{
		return size == 0;
	}
};

void Test5()
{
	cout << "직접 만든 스택 예시" << endl;

	stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);

	}

	// iterator를 지원해주지 않기 때문에 범위 기반 for loop를 사용할 수 없다.
	cout << "nums 데이터 출력" << endl;

	while (!nums.empty())	// 자료구조가 비어있지 않을 때 반복하라는 의미이다.
	{
		cout << nums.top() << " ";	// top은 가장 위에 있는 데이터를 출력하는 것
		nums.pop();					// top의 데이터를 삭제하라는 것 
	}

	cout << endl;
	cout << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

}