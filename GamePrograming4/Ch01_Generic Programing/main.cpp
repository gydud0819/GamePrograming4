/*
* 작성일	: 2025-05-14
* 작성자	: 박효영
* 주제	: 일반화 프로그래밍 (Generic Programing)
*/

/*
* 일반화 프로그래밍 (Generic Programing)
* 일반적이다 : 어떤 타입이든 모두 사용할 수 있는 범용적인 코드
*
* 변수들을 (T,N,Q) 선언할 것인데, 컴퓨터가 어떤 형태인지 알 수 있도록 키워드를 사용해야 한다.
*
* 과거에는 어떻게 일반화 프로그래밍을 했을까?
* - macro(매크로)로 일반화 프로그래밍을 작성하는 것을 지양한다.
* - 컴파일 체크를 지원해주지 않는다.
*/

/*
* Legacy 코드를 읽고, 옛날 코드임을 인지할 수 있다.
* 단점 : 의도하지 않은 결과가 발생할 수 있다, 컴파일 체크를 지원해주지 않는다.
*/

/*
* 컴파일 타임(compile time)	: 컴파일하는 시점 -> 컴퓨터가 언어를 번역해서 전달하는 시점이다. 오류를 검증하는 단계를 거친다.
* 런타임 (run time)	: 프로그램이 시작하는 시점
*/

/*
* template 키워드
* <type지정 변수의 이름>
* 타입 자체를 받아오는 키워드 : typename, class
*
* template<typename T1>
* template<class T1>
*/

/*
* 타입 추론 : 컴파일러 앞 뒤 코드를 보고 명시되지 않은 타입을 유추하는 것이다. ?
*
* auto 이름 = 10;	// auto를 사용하면 대입된 값을 보고 int인지 double인지 유추할 수 있다.
*
* 완벽하게 작동하지는 않는다.
*/

/*
* 정리
* 
* 선언한 함수 위에 template 키워드를 사용하여 일반화 함수로 사용한다?
* 
* 함수 template
* 
* 클래스  위에 template< >을 사용하여 일반화 클래스로 사용할 수 있다(?)
* template 클래스
* 
* 자료구조 (STL)
* 템플릿 클래스로 구현되어 있다. 
*/

#include <iostream>
#include <array>
#include <vector>
#define Max(a,b) ( (a > b) ? a : b)
#define Square(a) a * a
using namespace std;

template<typename T1>
T1 MaxFunc(T1 a, T1 b)
{
	return (a > b) ? a : b;
}

template<typename T1, typename T2>
void Func(T1 a, T2 b)
{
	std::cout << "No." << a << " " << b << std::endl;
}

template<int N>
void Func2()
{
	std::cout << N << std::endl;
}

template<int N, typename T>
void Func3()	// T 타입을 리턴한 함수 예시
{
	for (int i = 0; i < N; i++)
	{
		std::cout << typeid(T).name << std::endl;
	}

}

/*
* Min 함수
*
* Mulitply 함수 만들기
*/

template<typename T>
T Min(T a, T b)		// 두 수를 비교하여 작은 수를 반환하는 함수
{
	return (a < b) ? a : b;
}

template<typename T>
T Mulitply(T a, T b)
{
	return a * b;
}

struct Person
{
	int age;
	std::string name;

	bool operator<(const Person& other)
	{
		return this->age < other.age;
	}
};


// 우리가 직접 만든 Person 클래스에 접근하는 객체를 만들었다.
// Person을 조작하는 함수들을 정의하는 코드이다. 
// 보편적으로 사용하는 데이터를 다루는 클래스이다. 
// STL

/*
* 클래스는 기본적으로 private로 필드에 선언되어 있다
* 
*/

/*
* 자료구조에서 공부해야할 것들 (코드를 작성할 때 가장 효율적인 자료구조가 무엇인지가 수업에서의 핵심 내용이다)
* 데이터 선언
* 데이터 저장 '배열' -> 크기가 고정되어있는 컨테이너
* 컨테이너마다 장단점이 존재한다.
* 
* 배열의 장점과 단점
* 특징 : 크기가 고정되어 있다.
* 장점 : 정해져 있는 규칙을 문법적으로 제한할 수 있다. 처리 속도가 빠르다?
* 단점 : 
* 
* 그럼 테런에 자정 12시만 되면 5분렉이라고 있는데 이것도 자료구조랑 관련있나? 그건 아닌거 같은데 ㅇㅅㅇ 얜 서버 문제인듯 
* 
* 
* 조건부로 한계를 뚫는다면 
* 크기를 증가시킬 수 있다? 가능은 하다
* 
* 1000개의 배열이 있다
* 
* 1200개의 배열을 만든다 -> 1000개의 배열을 1200개의 배열로 옮긴다 -> 1000개의 배열을 삭제 한다 (시간과 비용이 많이 듦)
*/

// Person을 위한 배열을 비슷하게 구현해낸 클래스
template<int N>
class People
{
private:
	int size = N;		// N의 크기를 일반화 하고싶을 때 
	Person HumanInCity[N];

public:
	Person& operator[](int index)	// People 안을 대괄호로 접근할 수 있다. 
	{
		return HumanInCity[index];
	}

public:
	void At(int index)
	{
		// Person의 배열에 n번째에 접근하는 기능
		cout << "나이 : " << HumanInCity[index].age << " " // 연산자 오버로딩을 통해 배열 기능을 비슷하게 구현해보기 
			<< "이름 : " << HumanInCity[index].name << endl;
	}
};

class PoketMon
{

};

template<int N, typename T>
class Array
{
private:
	int size = N;
	int value[N];
public:
	Person& operator[](int index)	// People 안을 대괄호로 접근할 수 있다. 
	{
		return value[index];
	}

public:
	T& At(int index)
	{
		return value[index];
	}
};

void FuncTemplate()
{
#pragma region 
	// Legacy 코드 예시
	int result = Max(5, 1);	// ( (5 > 1) ? 5 : 1)
	int result2 = Max(1.1, 2.1);	// ( (1.1 > 2.2) ? 1.1 : 2.2)
	int result3 = 100 / Square(5);	// 100 / 5 * 5 

	std::cout << result << std::endl;
	std::cout << result2 << std::endl;
	std::cout << result3 << std::endl;

	// template 키워드 예시
	std::cout << MaxFunc<int>(1.2, 2.3) << std::endl;
	std::cout << MaxFunc<double>(1.2, 2.3) << std::endl;

	// 타입 추론 예시
	std::cout << MaxFunc(1.2, 2.4) << std::endl;

	std::cout << MaxFunc(0.1, 0.2) << std::endl;



	Func(1, "피카츄");	// 타입을 추론한 함수 
	Func<int, std::string>(1, "피카츄");		// 템플릿을 사용하여 직접 지정한 함수?  

	Func2<155>();


	// Min 예제
	std::cout << "Min 예제" << std::endl;
	std::cout << Min(5, 3) << std::endl;
	std::cout << Min(5.2, 3.9) << std::endl;
	std::cout << Min('a', 'h') << std::endl;

	// Mulitply 예제
	std::cout << "Mulitply 예제" << std::endl;
	std::cout << Mulitply(23, 4) << std::endl;
	std::cout << Mulitply(2.2, 4.1) << std::endl;

	//Func3<5, int>();
#pragma endregion
}

int main()
{
	FuncTemplate();		// 함수 템플릿 예제 

	// 보충 예제
	Person p1{ 10, "N" };
	Person p2{ 4, "D" };

	Person p3 = Min<Person>(p1, p2);

	cout << p3.name << " 나이가 더 어리다." << endl;

	People<5> busan;
	busan[0] = { 15, "S" };
	busan.At(0);

	cout << "직접만든 배열 클래스 예제" << endl;

	Array<10, Person> seoul;
	seoul[0] = { 20, "d" };
	seoul.At(1) = { 21, "r" };

	cout << seoul[0].name << endl;
	cout << seoul[1].name << endl;

	cout << seoul.At(0).name << endl;
	cout << seoul.At(1).name << endl;

	//Array<10, PoketMon> poketmon;

	// STL에 등록되어있는 배열 클래스를 사용하는 것을 권장한다. 
	// 사용방법
	std::array<PoketMon, 10> myPoketmon;
	//myPoketmon[0] = { 1, "이상해씨" };
};
	
