/*
* 작성일	: 2025-05-16
* 작성자	: 박효영
* 주제	: 배열의 크기를 수동으로 변경하는 코드 만들기
*/
#include <iostream>
#include <vector>
using namespace std;

/*
* '자동'으로 변경하는 코드는 veotor
* 
* int 10개 배열로 저장한다.
* 배열의 특징	: 크기가 고정되어 있다. 만들 때 크기를 정해줘야 한다. 40바이트의 공간을 확보해줘야 한다.
* 41바이트 떨어진 공간에서 메모리를 접근하면 문제가 발생한다.
*/

// 배열의 크기를 N으로 받을 수 있게 코드 추가해보기
// string, char, double 코드 추가해보기
// template<typename>를 여러개 쓰게 되면...

/*
* 벡터 클래스의 기능
* push_back		: 벡터의 끝에 데이터를 추가한다.	(이미 존재하는 데이터를)
* size()		: 벡터의 길이를 반환한다.
* emplace_back	: 벡터의 끝에 직접 생성ㅎ나 데이터를 바로 추가한다.
* pop_back		: 가장 뒤에 있는 데이터 하나를 제거한다.
* empty			: 벡터의 크기가 0이면 true, 이상이면 false를 반환한다.
* insert()		: 주어진 위치에 데이터를 입력한다.	vec.insert(vec.begin() +2, 10); vdc[2] = value;
* erase()		: 주어진 위치의 데이터를 제거한다. vec.erase(vec.begin());
*/

template<typename T, int N>
void MakeArray(T*& ptr, T value) // 2개다 쓸수있나?, T value를 사용하면 어떤 인자든 받아와서 출력할 수 있다.
{
	// 연결된 메모리를 해제하는 코드
	// 배열의 크기를 수동으로 만들고 보여주는 예제 코드
	delete[] ptr;
	ptr = new T[N];	// 추가 해석이 필요하다. 

	for (int i = 0; i < N; i++)
	{
		*(ptr + i) = value;
		cout << *(ptr + i) << " ";
	}

	cout << endl;
}

/*
* 클래스 만들기
* 클래스 이름	: monster, 번호, 이름
*/

class Monster
{
private:
	int num;
	string name;
public:
	Monster() = default;
	~Monster() = default;
	Monster(int num, string name)
		: num(num), name(name) { }

	int get_num() const { return num; }
	string get_name() const { return name; }

	// friend : 외부 클래스의 private에 접근할 수 있게 해주는 키워드
	friend ostream& operator<<(ostream& os, const Monster& obj)
	{
		os << obj.num << "_" << obj.name << " ";
		return os;
	}
};

template<typename T>
void Show(vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)	// 사이즈 크기만큼 반환한다?
	{
		cout << vec[i] << " ";
	}

	cout << endl;
}



/*
* 도전과제	: 
*/

int main()
{
	// 수동으로 배열의 크기를 변경하고 생성하는 함수 템플릿
	// 우리가 만들건 클래스 템플릿

	int* aptr = new int[10];	// int타입의 공간을 포인터를 사용해 10개 만들겠다라는 의미
	double* bptr = new double[10];	// int타입의 공간을 포인터를 사용해 10개 만들겠다라는 의미
	string* sptr = new string[10];
	Monster* dptr = new Monster[10];

	Monster mon1(1, "이터널슈가");

	MakeArray<int, 10>(aptr, 0);	// 정수를 받아오는 것이기 때문에 int를 써야한다.
	MakeArray<double, 10>(bptr, 0.1);	// 
	MakeArray<string, 10>(sptr, "nc dinos");	// 
	MakeArray<Monster, 10>(dptr, mon1);	// 
	
	/*delete[] aptr;

	aptr = new int[20];

	for (int i = 0; i < 20; i++)
	{
		*(aptr + i) = 0;
		cout << *(aptr + i) << " ";
	}*/

	// vector로 쉽게 배열을 생성하고 출력하기

	cout << "벡터사용 예제" << endl;

	vector<int> nums;	// vector는 배열을 저장하는 클래스 (int를 저장하는 가변배열 클래스)

	// push_back : 벡터의 끝에 데이터를 추가한다.  그럼 뒤에서부터 하나씩 밀어넣어서 채운다는 건가
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	// size() : 벡터의 길이를 반환한다. 
	Show<int>(nums);

	vector<double> doublecontainer;
	vector<string> stringcontainer;
	
	vector<Monster> monsterDataBase;
	monsterDataBase.emplace_back(1, "고블린");
	monsterDataBase.emplace_back(2, "쉐도우밀크");
	monsterDataBase.emplace_back(3, "버닝스파이스");
	monsterDataBase.clear();

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(0);

		doublecontainer.push_back(0.1);
		stringcontainer.push_back("bb");
		monsterDataBase.push_back(mon1);

	}
	
	Show<int>(nums);
	Show<double>(doublecontainer);
	Show<string>(stringcontainer);
	Show<Monster>(monsterDataBase);

	if (!monsterDataBase.empty())
	{
		cout << "데이터가 있습니다." << endl;
	}

	// pop_Back()

	// empty

	// insert()

	// erase()
}