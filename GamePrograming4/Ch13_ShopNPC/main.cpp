/*
* 주제	: 콘솔창에서 플레이어 움직이기, 특정 위치에 NPC와 만날 때 상점 항목 보여주기
* Game Object : Player, NPC, Shop
* 자료구조, item, 어떤 컨테이너에 보관하여 사용할 것인지
* File Input & Output 메모장에있는 데이터를 NPC에 전달하는 기능 만들기
*
*
*/
#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"
#include <fstream>		// ifstream, ofstrem 인아웃 함수 사용 가능하다.
#include <iomanip>		// 입출력 조작 헤더
#include <utility>		// pair 클래스가 정의되어 있는 헤더파일 
#include <unordered_map>	// 인벤토리를 위한 자료구조

#include <string>

const int total_width = 60;			// 전체
const int field1_width = 30;		// 이름 길이
const int field2_width = 15;		// 가격
const int field3_width = 15;		// 타입

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Item
{
public:
	string name;
	int price;
	string type;
public:
	Item() = default;
	Item(string name, int price, string type) : name(name), price(price), type(type) {}
	virtual void Use() = 0;		// 순수 가상 함수 : Item을 상속하는 클래스가 이 함수를 구현하기 ? 
};

class Weapon : public Item
{
public:
	Weapon(string name, int price, string type) : Item(name, price, type) {}

	void Use() override
	{
		cout << "무기를 사용한다." << endl;
	}
};

/// <summary>
/// 아이템을 사용했을 때 사라지는 종류의 아이템
/// Player클래스의 RemoveItem을 사용해라.
/// </summary>
class UsableItem : public Item
{
public:
	UsableItem(string name, int price, string type) : Item(name, price, type) {}

	void Use() override
	{
		cout << "소비성 아이템을 사용한다." << endl;
		// 사용한 아이템 호출하기 RemoveItem을 사용해서
	}
};

#pragma region Player 코드
class Player
{
private:
	unordered_map<string, Item*> inventory;	// Item을 아이템을 이름으로 찾는 컨테이너
public:
	int posX;
	int posY;
	int money;

#pragma region 인벤토리 코드
	// 플레이어가 소유한 인벤토리를 자료구조를 하나 선택하여 자료구조에 구매한 아이템을 저장하기
	// 저장한 자료구조를 사용하는 함수 만들기 (2025-06-03) 추가

	void GetItem(Item* item)
	{
		inventory.insert({ item->name, item });
	}

	void RemoveItem(string name)
	{
		// 제거할 수 없을 때는 find를 사용하여 

		if (inventory.find(name) != inventory.end())	// 컨테이너 데이터가 존재할 때만 실행하기
		{
			inventory.erase(name);
		}
		else
		{
			cout << "인벤토리에 해당하는 아이템이 없다." << endl;
		}

	}

	void RemoveItem(Item* item)
	{
		inventory.erase(item->name);
	}

	// 특정 키를 눌렀을 때(게임 입력 Player Input)

	void Use(Item* item)
	{
		// 소비 아이템 -> 적용
		// 장비 아이템 -> 장비 장착해야함

		item->Use();
	}

#pragma endregion
	/*
	* 상점은 전부다 아이템을 팔아야한다.
	* 해당 아이템을 같은함수 Use() 같고 있지만 다른 기능으로 사용하고 싶을 때(클래스의 다형성 적용하기)
	* item을 주소로 받아오면 다형성을 사용할 수 있다.
	*/


	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	// 왼쪽 상단에 플레이어 UI 띄우기 

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(80, 0);
		cout << "플레이어의 정보";
		ConsoleUtil::GotoXY(80, 1);
		cout << "플레이어의 현재 보유중인 머니 : " << money;
		ConsoleUtil::GotoXY(80, 2);
		cout << "소유한 아이템 목록 : ,";
		ConsoleUtil::GotoXY(80, 3);
		for (const auto& item : inventory)
		{
			cout << item.first << " ";
		}

		// 보유한 아이템 띄우기
	}

	void BuyItem(Item& item)
	{
		money -= item.price;

		// map.insert({ 숫자, item});		// 아이템 이름으로 검색할 수 있게 map(string, item)
	}

	// Shop코드와 연동해서 Shop.items[i].price 비교하기 money == price
	// 인벤토리 (어떤 컨테이너를 사용하면 좋을지 고민하기== 최종적인 목표 vector 사용 추천) shop->player.inventory로 옮기기

	// 현재 플레이어가 가지고 있는 아이템 정보를 저장하기
	// 게임종료 
public:

};
#pragma endregion

#pragma region 상점 코드


class Shop
{
private:
	/*
	* Item 추상 클래스를 만들면 item 자체를 클래스로 생성할 수 없다. (인스턴스)
	* 주소로 받아와야 하는ㄷ , enum 타입에 따라 클래스를 다르게 사용할 수 있도록 코드를 작성해야한다.
	* "팩토리 패턴" 팩토리 클래스를 만들어서
	*/
	// vector, list, deque, set, map 
	map<int, Item*> items;			// 자료구조 클래스를 보관한다. 
public:
	Shop()	// 데이터를 초기화 한다. 
	{
		items.insert({ 0, new Weapon("다이아몬드", 10000, "보석함") });	// 동적할당 주소로 받아옴
		items.insert(make_pair(1, new Weapon("루비", 5000, "보석함")));
		pair<int, Item*> p1(2, new Weapon("사파이어", 5500, "보석함"));
		items.insert(p1);
		items.insert({ 3, new Weapon("금", 1000, "보석함") });
		items.insert({ 4, new Weapon("은", 500, "보석함") });
	}

	Shop(string filename)
	{
		LoadShopData(filename);
	}

	void LoadShopData(string filename)
	{
		ifstream in_file;
		in_file.open(filename);

		string name;
		int price;
		string type;

		if (!in_file)	// 예외를 확인하는 코드
		{
			cerr << "파일을 여는 데 실패했습니다." << endl;
			//return;
			exit(1);
		}

		int index = 0;

		while (!in_file.eof())	// end of file(파일의 끝에 도달했을 때 true를 반환한다.)
		{
			in_file >> name >> price >> type;		//	 메모장으로부터 읽어온다. 파일에서 name, price, type 순으로 읽는다.

			if (type == "보석함")
			{
				items.insert({ index, new Weapon(name, price, type) });	// map 자료구조에 저장한다.
				index++;										// 다음 index로 넘어간다. 

			}
			//else if (type == "악세사리")
			//{
			//	items.insert({ index, new Weapon(name, price, type) });	// map 자료구조에 저장한다.
			//	index++;
			//}
			else
			{
				items.insert({ index, new Weapon(name, price, type) });	// map 자료구조에 저장한다.
				index++;
			}


		}

		in_file.close();
	}

	void SaveShopData(string filename)
	{
		ofstream out_file;
		out_file.open(filename);

		string name;
		int price;
		string type;

		if (!out_file)	// 예외를 확인하는 코드
		{
			cerr << "파일을 여는 데 실패했습니다." << endl;
			//return;
			exit(1);
		}

		for (int i = 0; i < items.size(); i++)	// 인덱스 기반 접근이 가능한 자료구조여야 사용할 수 있다. (vector, map 등)
		{
			out_file << setw(field1_width) << left << items[i]->name	// 연산자 오버로딩을 사용한 것 
				<< setw(field2_width) << right << items[i]->price
				<< setw(field3_width) << right << items[i]->type
				<< endl;

		}

		out_file.close();
	}

	// 데이터를 사용하여 기능을 구현한다.
	void ShowItems(int x, int y)
	{
		//string headersize = "012345678901234567890123456789012345678901234567890123456789";
		//// 아이템의 머릿말(판매정보)
		//std::cout << headersize << endl;

		ConsoleUtil::GotoXY(x, y);

		cout << setw(field1_width) << left << "이름"	// 연산자 오버로딩을 사용한 것 
			<< setw(field2_width) << right << "가격"
			<< setw(field3_width) << right << "타입"
			<< endl;

		// 라인을 긋는 코드
		ConsoleUtil::GotoXY(x, y + 1);
		cout << setw(total_width)						// 길이 설정	
			<< setfill('-')								// 공백을 '-'로 설정한다. setfill : 공백문자를.......
			<< "" << endl;

		cout << setfill(' ');

		// 아이템 출력하기 
		for (int i = 0; i < items.size(); i++)	// 인덱스 기반 접근이 가능한 자료구조여야 사용할 수 있다. (vector, map 등)
		{
			ConsoleUtil::GotoXY(x, y + 2 + i);
			cout << setw(field1_width) << left << items[i]->name	// 연산자 오버로딩을 사용한 것 
				<< setw(field2_width) << right << items[i]->price
				<< setw(field3_width) << right << items[i]->type
				<< endl;

		}

		//cout << setfill('-');
	}

	// 아이템을 판매한다. (유저가 돈이없으면 아이템을 못사게)


	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end())	// 아이템을 찾으면
		{
			Item* itemInstance = items[index];
			if (player.money >= itemInstance->price)	// 유저 돈이 충분할 때
			{
				player.BuyItem(*itemInstance);
				return true;

			}
			else
			{
				cout << "재화가 부족하다." << endl;
			}
		}
		else
		{
			cout << "아이템을 찾지 못했다." << endl;
		}
	}

	void Interact(Player& player)
	{
		int select;
		cout << "번호를 입력하여 아이템을 구매할 수 있다." << endl;

		cin >> select;

		BuyItem(select, player);
	}
};
#pragma endregion

#pragma region NPC 코드
// 상인이 존재하는 위치에 플레이어가 도달했을 때 아이템 목록을 보여주도록 하기

class NPC
{
private:
	Shop shop;
public:

	int posX;	// NPC 좌표
	int posY;
	bool isActivate;

	NPC() = default;
	NPC(string filename, int posX, int posY) : posX(posX), posY(posY), isActivate(true)
	{
		shop = Shop(filename);
	}

	void changeItemList(string filename)
	{
		shop = Shop(filename);
	}

	void ShowItems(int x, int y)
	{
		shop.ShowItems(x, y);

	}

	void Interact(Player& player)
	{
		shop.Interact(player);
		isActivate = false;
	}

	void ShowNPC()
	{
		if (isActivate == false) { return; }
		ConsoleUtil::GotoXY(posX, posY);
		cout << "#";
	}


};


//void ShowPhase(Shop& shop)
//{
//	shop.ShowItems();
//}
#pragma endregion

void Interact(Player& player, NPC& npc, int UI_x, int UI_y)	// Player와 NPC 클래스를 만들어서 넣을수도 있다.
{
	if (player.posX == npc.posX && player.posY == npc.posY)
	{
		if (npc.isActivate == false) { return; }	// 상점이 비활성화 되면 사
		npc.ShowItems(UI_x, UI_y);
		npc.Interact(player);
	}
}



int main()
{
	Player player(10, 10, 10000);	// 플레이어의 시작 설정

	//int playerX = 10;
	//int playerY = 10;

	NPC npc1("shop1.txt", 41, 5);
	NPC npc2("shop2.txt", 30, 9);
	NPC npc3("shop3.txt", 21, 1);

	Shop shop;

	//shop.SaveShopData("shop1.txt");
	//shop.SaveShopData("shop2.txt");
	//shop.SaveShopData("shop3.txt");

	while (true)
	{
		// 입력을 받았을 때 좌표가 변하는 코드 만들기 
		if (_kbhit())
		{
			system("cls");

			if (GetAsyncKeyState(VK_UP))
			{
				player.posY--;
				if (player.posY <= 0) { player.posY = 0; }
			}

			if (GetAsyncKeyState(VK_DOWN))
			{
				player.posY++;
			}

			if (GetAsyncKeyState(VK_LEFT))
			{
				player.posX--;
				if (player.posX <= 0) { player.posX = 0; }
			}

			if (GetAsyncKeyState(VK_RIGHT))
			{
				player.posX++;
			}
		}
		player.ShowPlayerUI();

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(player, npc1, 0, 10);
		Interact(player, npc2, 0, 10);
		Interact(player, npc3, 0, 10);

		//shop.ShowItems();
		ConsoleUtil::GotoXY(player.posX, player.posY);
		cout << "a";

		_getch();
	}

}