/*
* �ۼ���	: 2025-05-14
* �ۼ���	: ��ȿ��
* ����	: �Ϲ�ȭ ���α׷��� (Generic Programing)
*/

/*
* �Ϲ�ȭ ���α׷��� (Generic Programing)
* �Ϲ����̴� : � Ÿ���̵� ��� ����� �� �ִ� �������� �ڵ�
*
* �������� (T,N,Q) ������ ���ε�, ��ǻ�Ͱ� � �������� �� �� �ֵ��� Ű���带 ����ؾ� �Ѵ�.
*
* ���ſ��� ��� �Ϲ�ȭ ���α׷����� ������?
* - macro(��ũ��)�� �Ϲ�ȭ ���α׷����� �ۼ��ϴ� ���� �����Ѵ�.
* - ������ üũ�� ���������� �ʴ´�.
*/

/*
* Legacy �ڵ带 �а�, ���� �ڵ����� ������ �� �ִ�.
* ���� : �ǵ����� ���� ����� �߻��� �� �ִ�, ������ üũ�� ���������� �ʴ´�.
*/

/*
* ������ Ÿ��(compile time)	: �������ϴ� ���� -> ��ǻ�Ͱ� �� �����ؼ� �����ϴ� �����̴�. ������ �����ϴ� �ܰ踦 ��ģ��.
* ��Ÿ�� (run time)	: ���α׷��� �����ϴ� ����
*/

/*
* template Ű����
* <type���� ������ �̸�>
* Ÿ�� ��ü�� �޾ƿ��� Ű���� : typename, class
*
* template<typename T1>
* template<class T1>
*/

/*
* Ÿ�� �߷� : �����Ϸ� �� �� �ڵ带 ���� ��õ��� ���� Ÿ���� �����ϴ� ���̴�. ?
*
* auto �̸� = 10;	// auto�� ����ϸ� ���Ե� ���� ���� int���� double���� ������ �� �ִ�.
*
* �Ϻ��ϰ� �۵������� �ʴ´�.
*/

/*
* ����
* 
* ������ �Լ� ���� template Ű���带 ����Ͽ� �Ϲ�ȭ �Լ��� ����Ѵ�?
* 
* �Լ� template
* 
* Ŭ����  ���� template< >�� ����Ͽ� �Ϲ�ȭ Ŭ������ ����� �� �ִ�(?)
* template Ŭ����
* 
* �ڷᱸ�� (STL)
* ���ø� Ŭ������ �����Ǿ� �ִ�. 
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
void Func3()	// T Ÿ���� ������ �Լ� ����
{
	for (int i = 0; i < N; i++)
	{
		std::cout << typeid(T).name << std::endl;
	}

}

/*
* Min �Լ�
*
* Mulitply �Լ� �����
*/

template<typename T>
T Min(T a, T b)		// �� ���� ���Ͽ� ���� ���� ��ȯ�ϴ� �Լ�
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


// �츮�� ���� ���� Person Ŭ������ �����ϴ� ��ü�� �������.
// Person�� �����ϴ� �Լ����� �����ϴ� �ڵ��̴�. 
// ���������� ����ϴ� �����͸� �ٷ�� Ŭ�����̴�. 
// STL

/*
* Ŭ������ �⺻������ private�� �ʵ忡 ����Ǿ� �ִ�
* 
*/

/*
* �ڷᱸ������ �����ؾ��� �͵� (�ڵ带 �ۼ��� �� ���� ȿ������ �ڷᱸ���� ���������� ���������� �ٽ� �����̴�)
* ������ ����
* ������ ���� '�迭' -> ũ�Ⱑ �����Ǿ��ִ� �����̳�
* �����̳ʸ��� ������� �����Ѵ�.
* 
* �迭�� ������ ����
* Ư¡ : ũ�Ⱑ �����Ǿ� �ִ�.
* ���� : ������ �ִ� ��Ģ�� ���������� ������ �� �ִ�. ó�� �ӵ��� ������?
* ���� : 
* 
* �׷� �׷��� ���� 12�ø� �Ǹ� 5�з��̶�� �ִµ� �̰͵� �ڷᱸ���� �����ֳ�? �װ� �ƴѰ� ������ ������ �� ���� �����ε� 
* 
* 
* ���Ǻη� �Ѱ踦 �մ´ٸ� 
* ũ�⸦ ������ų �� �ִ�? ������ �ϴ�
* 
* 1000���� �迭�� �ִ�
* 
* 1200���� �迭�� ����� -> 1000���� �迭�� 1200���� �迭�� �ű�� -> 1000���� �迭�� ���� �Ѵ� (�ð��� ����� ���� ��)
*/

// Person�� ���� �迭�� ����ϰ� �����س� Ŭ����
template<int N>
class People
{
private:
	int size = N;		// N�� ũ�⸦ �Ϲ�ȭ �ϰ���� �� 
	Person HumanInCity[N];

public:
	Person& operator[](int index)	// People ���� ���ȣ�� ������ �� �ִ�. 
	{
		return HumanInCity[index];
	}

public:
	void At(int index)
	{
		// Person�� �迭�� n��°�� �����ϴ� ���
		cout << "���� : " << HumanInCity[index].age << " " // ������ �����ε��� ���� �迭 ����� ����ϰ� �����غ��� 
			<< "�̸� : " << HumanInCity[index].name << endl;
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
	Person& operator[](int index)	// People ���� ���ȣ�� ������ �� �ִ�. 
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
	// Legacy �ڵ� ����
	int result = Max(5, 1);	// ( (5 > 1) ? 5 : 1)
	int result2 = Max(1.1, 2.1);	// ( (1.1 > 2.2) ? 1.1 : 2.2)
	int result3 = 100 / Square(5);	// 100 / 5 * 5 

	std::cout << result << std::endl;
	std::cout << result2 << std::endl;
	std::cout << result3 << std::endl;

	// template Ű���� ����
	std::cout << MaxFunc<int>(1.2, 2.3) << std::endl;
	std::cout << MaxFunc<double>(1.2, 2.3) << std::endl;

	// Ÿ�� �߷� ����
	std::cout << MaxFunc(1.2, 2.4) << std::endl;

	std::cout << MaxFunc(0.1, 0.2) << std::endl;



	Func(1, "��ī��");	// Ÿ���� �߷��� �Լ� 
	Func<int, std::string>(1, "��ī��");		// ���ø��� ����Ͽ� ���� ������ �Լ�?  

	Func2<155>();


	// Min ����
	std::cout << "Min ����" << std::endl;
	std::cout << Min(5, 3) << std::endl;
	std::cout << Min(5.2, 3.9) << std::endl;
	std::cout << Min('a', 'h') << std::endl;

	// Mulitply ����
	std::cout << "Mulitply ����" << std::endl;
	std::cout << Mulitply(23, 4) << std::endl;
	std::cout << Mulitply(2.2, 4.1) << std::endl;

	//Func3<5, int>();
#pragma endregion
}

int main()
{
	FuncTemplate();		// �Լ� ���ø� ���� 

	// ���� ����
	Person p1{ 10, "N" };
	Person p2{ 4, "D" };

	Person p3 = Min<Person>(p1, p2);

	cout << p3.name << " ���̰� �� ���." << endl;

	People<5> busan;
	busan[0] = { 15, "S" };
	busan.At(0);

	cout << "�������� �迭 Ŭ���� ����" << endl;

	Array<10, Person> seoul;
	seoul[0] = { 20, "d" };
	seoul.At(1) = { 21, "r" };

	cout << seoul[0].name << endl;
	cout << seoul[1].name << endl;

	cout << seoul.At(0).name << endl;
	cout << seoul.At(1).name << endl;

	//Array<10, PoketMon> poketmon;

	// STL�� ��ϵǾ��ִ� �迭 Ŭ������ ����ϴ� ���� �����Ѵ�. 
	// �����
	std::array<PoketMon, 10> myPoketmon;
	//myPoketmon[0] = { 1, "�̻��ؾ�" };
};
	
