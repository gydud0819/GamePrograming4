/*
* �ۼ���	: 2025-05-16
* �ۼ���	: ��ȿ��
* ����	: �迭�� ũ�⸦ �������� �����ϴ� �ڵ� �����
*/
#include <iostream>
#include <vector>
using namespace std;

/*
* '�ڵ�'���� �����ϴ� �ڵ�� veotor
* 
* int 10�� �迭�� �����Ѵ�.
* �迭�� Ư¡	: ũ�Ⱑ �����Ǿ� �ִ�. ���� �� ũ�⸦ ������� �Ѵ�. 40����Ʈ�� ������ Ȯ������� �Ѵ�.
* 41����Ʈ ������ �������� �޸𸮸� �����ϸ� ������ �߻��Ѵ�.
*/

// �迭�� ũ�⸦ N���� ���� �� �ְ� �ڵ� �߰��غ���
// string, char, double �ڵ� �߰��غ���
// template<typename>�� ������ ���� �Ǹ�...

/*
* ���� Ŭ������ ���
* push_back		: ������ ���� �����͸� �߰��Ѵ�.	(�̹� �����ϴ� �����͸�)
* size()		: ������ ���̸� ��ȯ�Ѵ�.
* emplace_back	: ������ ���� ���� �������� �����͸� �ٷ� �߰��Ѵ�.
* pop_back		: ���� �ڿ� �ִ� ������ �ϳ��� �����Ѵ�.
* empty			: ������ ũ�Ⱑ 0�̸� true, �̻��̸� false�� ��ȯ�Ѵ�.
* insert()		: �־��� ��ġ�� �����͸� �Է��Ѵ�.	vec.insert(vec.begin() +2, 10); vdc[2] = value;
* erase()		: �־��� ��ġ�� �����͸� �����Ѵ�. vec.erase(vec.begin());
*/

template<typename T, int N>
void MakeArray(T*& ptr, T value) // 2���� �����ֳ�?, T value�� ����ϸ� � ���ڵ� �޾ƿͼ� ����� �� �ִ�.
{
	// ����� �޸𸮸� �����ϴ� �ڵ�
	// �迭�� ũ�⸦ �������� ����� �����ִ� ���� �ڵ�
	delete[] ptr;
	ptr = new T[N];	// �߰� �ؼ��� �ʿ��ϴ�. 

	for (int i = 0; i < N; i++)
	{
		*(ptr + i) = value;
		cout << *(ptr + i) << " ";
	}

	cout << endl;
}

/*
* Ŭ���� �����
* Ŭ���� �̸�	: monster, ��ȣ, �̸�
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

	// friend : �ܺ� Ŭ������ private�� ������ �� �ְ� ���ִ� Ű����
	friend ostream& operator<<(ostream& os, const Monster& obj)
	{
		os << obj.num << "_" << obj.name << " ";
		return os;
	}
};

template<typename T>
void Show(vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)	// ������ ũ�⸸ŭ ��ȯ�Ѵ�?
	{
		cout << vec[i] << " ";
	}

	cout << endl;
}



/*
* ��������	: 
*/

int main()
{
	// �������� �迭�� ũ�⸦ �����ϰ� �����ϴ� �Լ� ���ø�
	// �츮�� ����� Ŭ���� ���ø�

	int* aptr = new int[10];	// intŸ���� ������ �����͸� ����� 10�� ����ڴٶ�� �ǹ�
	double* bptr = new double[10];	// intŸ���� ������ �����͸� ����� 10�� ����ڴٶ�� �ǹ�
	string* sptr = new string[10];
	Monster* dptr = new Monster[10];

	Monster mon1(1, "���ͳν���");

	MakeArray<int, 10>(aptr, 0);	// ������ �޾ƿ��� ���̱� ������ int�� ����Ѵ�.
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

	// vector�� ���� �迭�� �����ϰ� ����ϱ�

	cout << "���ͻ�� ����" << endl;

	vector<int> nums;	// vector�� �迭�� �����ϴ� Ŭ���� (int�� �����ϴ� �����迭 Ŭ����)

	// push_back : ������ ���� �����͸� �߰��Ѵ�.  �׷� �ڿ������� �ϳ��� �о�־ ä��ٴ� �ǰ�
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	// size() : ������ ���̸� ��ȯ�Ѵ�. 
	Show<int>(nums);

	vector<double> doublecontainer;
	vector<string> stringcontainer;
	
	vector<Monster> monsterDataBase;
	monsterDataBase.emplace_back(1, "���");
	monsterDataBase.emplace_back(2, "�������ũ");
	monsterDataBase.emplace_back(3, "���׽����̽�");
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
		cout << "�����Ͱ� �ֽ��ϴ�." << endl;
	}

	// pop_Back()

	// empty

	// insert()

	// erase()
}