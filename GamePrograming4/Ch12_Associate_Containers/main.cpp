#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <utility>

using namespace std;

#pragma region 연관 컨테이너
/*
* 연관 컨테이너 : (multi, unordered) set, map
*
* set으로 데이터를 정렬 했을 때의 불편한 점, 그것을 개선한 map
* pair를 정의를 해야한다.
*/

#pragma endregion

#pragma region 연관 컨테이너 사용하기

void Test1()
{
	set<int> nums;
	// 데이터를 어떻게 저장할 수 있을까? 
	// 연관 컨테이너 : 데이터를 저장할 때 insert 함수를 사용한다.
	// 연관 컨테이너에 데이터를 입력하면 자동으로 정렬된다. 
	// 탐색을 할 때 정렬된 결과로 사용하면 효과적이다. 
	nums.insert(3);
	nums.insert(2);
	nums.insert(8);
	nums.insert(5);
	nums.insert(1);

	for (const auto& num : nums)
	{
		cout << num << endl;	// 1,2,3,5,8 오름차순으로 출력된다. 
	}

	//cout << "특징1. set의 데이터가 자동으로 정렬된다." << endl;
	//// set 특징
	//// 중복이 되지 않는다. (집합)
	//// 데이터가 자동으로 정렬된다.
	//nums.insert(3);
	//nums.insert(2);
	//nums.insert(8);
	//nums.insert(5);
	//nums.insert(1);

	//cout << "특징2. set의 데이터는 중복이 되지 않는다." << endl;
	//for (const auto& num : nums)
	//{
	//	cout << num << " ";
	//}
	//cout << endl;

}

void Test2()
{
	set<int> nums;
	// 데이터를 어떻게 저장할 수 있을까? 
	// 연관 컨테이너 : 데이터를 저장할 때 insert 함수를 사용한다.
	// 연관 컨테이너에 데이터를 입력하면 자동으로 정렬된다. 
	// 탐색을 할 때 정렬된 결과로 사용하면 효과적이다. 
	nums.insert(3);
	nums.insert(2);
	nums.insert(8);
	nums.insert(5);
	nums.insert(1);

	cout << "특징1. set의 데이터가 자동으로 정렬된다." << endl;
	for (const auto& num : nums)
	{
		cout << num << endl;	// 1,2,3,5,8 오름차순으로 출력된다. 
	}

	// set 특징
	// 중복이 되지 않는다. (집합)
	// 데이터가 자동으로 정렬된다.
	nums.insert(3);
	nums.insert(2);
	nums.insert(8);
	nums.insert(5);
	nums.insert(1);

	cout << "특징2. set의 데이터는 중복이 되지 않는다." << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
	cout << "연관 컨테이너 앞에 특정 키워드를 붙이면 성질이 변한다." << endl;

}
#pragma endregion

#pragma region 커스텀 클래스를 set에 넣는 방법
struct Item
{
	int id;
	string name;

	Item() = default;

	Item(int id, string name) : id(id), name(name) {}

	bool operator<(const Item& other) const		// 첫번째 const는 other의 값을 바꾸지말라는 것이고 2번째는 자체의 값을 바꾸지 말라는 의미이다.
	{
		return id < other.id;
	};


};
void Test3()
{
	set<Item> items;

	Item item1(1, "모래");
	Item item2(2, "흙");
	Item item3(3, "자갈");
	Item item4(100, "부싯돌");
	Item item5(50, "조약돌");

	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);


	cout << "중복을 허용하지 않는다." << endl;
	items.insert(Item(3, "돼지고기"));

	for (const auto& item : items)
	{
		cout << item.id << " " << item.name << endl;
	}

	cout << "set을 사용하면 데이터의 크기에 따라 자동으로 정렬한 결과를 얻을 수 있다." << endl;
	cout << "find함수를 사용해서 데이터를 빠르게 찾을 수 있다." << endl;

	// item 전체를 items안에서 찾아야 한다.
	// item의 id가 n번을 데이터를 찾고 싶을 때
	// find함수를 사용해도 되지만 map을 사용하면 해결할 수 있다.
}
#pragma endregion

#pragma region map 사용하기
void Test4()
{
	cout << "map 구조 사용하기" << endl;
	map<int, Item> items;		// 왜 int를 써야하는걸까
	// map에 데이터를 넣는 방법
	// (1) 중괄호로 사용한다.
	items.insert({ 0, Item(100, "당근") });

	// (2) make_pair 함수 사용하기
	items.insert(make_pair(10, Item(1000, "에메랄드")));

	// (3) pair 클래스를 직접 선언하기. (utilty 헤더파일이 필요하다.)
	pair<int, Item> p1(5, Item(101, "황금당근"));
	items.insert(p1);

	cout << "특징1. map은 pair로 이루어진 데이터를 저장하는 컨테이너이다." << endl;
	cout << "특징2. map의 key값으로 자동 정렬이 이루어진다." << endl;

	for (const auto& item : items)
	{
		cout << item.first << " " << "ID : " << item.second.id << "이름 : " << item.second.name << endl;		// first가 정렬해준다? 
	}

	cout << "특징3. 사전형(Dictionary) 자료구조이다." << endl;

	cout << items[0].id << items[0].name << endl;		// 인덱스로 번호에 접근할 수 있다. 
}
#pragma endregion

#pragma region 연관 컨테이너 실습
struct NewItem
{
	string name;
	int ATK;
	int price;

	NewItem() = default;
	NewItem(string name, int ATK, int price) : name(name), ATK(ATK), price(price){}
};
void Test5()
{
	map<string, int> map1;
	map1.insert({"밀", 1});
	map1.insert({"케이크", 2});
		for (const auto& e : map1)
		{
			cout << "[";
			cout << e.first << " " << e.second;
			cout << "]" << endl;
		}

		cout << "밀에 어떤 숫자가 들어가 있는가?" << endl;
		cout << map1["밀"] << endl;

	map<int, int> map2;		// 플레이어 고유 번호(id), 레벨로 표현할 수도 있다. 

	map2.insert({ 1, 1 });
	map2.insert({ 4, 8 });
	map2.insert({ 2, 3 });


	for (const auto& e : map2)
	{
		cout << "[";
		cout << e.first << " " << e.second;
		cout << "]" << endl;
	}

	cout << "map2 컨테이너 속 1 키워드에 어떤 값이 들어가 있는가?" << endl;
	cout << map2[1] << endl;
	
	map<string, NewItem> map3;
	map3.insert({"활", NewItem("활", 50, 100)});
	map3.insert({"석궁", NewItem("석궁", 30, 120)});
	map3.insert({"검", NewItem("검", 40, 90)});

	cout << "map3 컨테이너중에 이름이 석궁인 데이터를 불러와라." << endl;
	NewItem itemInstance = map3["석궁"];
	cout << "이름 : " << itemInstance.name << endl;
	cout << "공격력 : " << itemInstance.ATK << endl;
	cout << "가격 : " << itemInstance.price << endl;
	
}
#pragma endregion

#pragma region 상점 UI 및 기능 구현하기
// iomanip : 문자열의 규격을 맞추는 기능이 포함되어 있다. 
class Player
{
private:
	int money;
public:
	Player(int money) : money(money){}
	// 상점의 아이템을 획득했다라는 함수 만들기
	void BuyItems()
	{

	}
};

// 상점에 많은 아이템을 팔고 싶을 때 아이템을 컨테이너 형태로 저장해야 한다.
class Shop
{
	map<int, NewItem> items;
	// 1. 타입<int, NewItem, items> 컨테이너 선언하기
	Shop()
	{
		// 2. 5개의 상점 
		//NewItem("팬던트", 20, 30);
		items.insert({ 1, NewItem("팬던트", 20, 300) });
		items.insert({ 2, NewItem("크라운", 10, 500) });
		items.insert({ 3, NewItem("팔찌", 20, 430) });
		items.insert({ 4, NewItem("부츠", 20, 530) });
		items.insert({ 5 , NewItem("반지", 5, 250) });
	}

	void ShopItem()
	{
		for (const auto& item : items)
		{

		}

		cout << left;
		cout << setw(10) << "ID" << setw(20) << "이름" << endl;
			// 1. Item 데이터 만들기
			// 2. 정의한 데이터를 사용할 클래스 만들기
			// 3. Shop 클래스 안에 map 자료구조 추가하기
			// 4. items 데이터 초기화 하기

	}

	void SellItem(Player& player)
	{
		// 
	}
};

#pragma endregion


int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}