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

#include <string>

const int total_width = 60;			// 전체
const int field1_width = 30;		// 이름 길이
const int fieldl2_width = 15;		// 가격
const int fieldl3_width = 15;		// 타입

using std::cout;
using std::cin;
using std::endl;
using std::string;

#pragma region 상점 코드
class Item
{
public:
	string name;
	int price;
	string type;
public:
	Item() = default;
	Item(string name, int price, string type) : name(name), price(price), type(type) {}
};

class Shop
{
private:
	// vector, list, deque, set, map 
	map<int, Item> items;			// 자료구조 클래스를 보관한다. 
public:
	Shop()	// 데이터를 초기화 한다. 
	{
		items.insert({ 0, Item("다이아몬드", 10000, "보석함") });
		items.insert(make_pair(1, Item("루비", 5000, "보석함")));
		pair<int, Item> p1(2, Item("사파이어", 5500, "보석함"));
		items.insert(p1);
		items.insert({ 3, Item("금", 1000, "보석함") });
		items.insert({ 4, Item("은", 500, "보석함") });
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
			items.insert({ index, Item(name, price, type) });	// map 자료구조에 저장한다.
			index++;										// 다음 index로 넘어간다. 
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
			out_file << setw(field1_width) << left  << items[i].name	// 연산자 오버로딩을 사용한 것 
				<< setw(fieldl2_width) << right  << items[i].price
				<< setw(fieldl3_width) << right  << items[i].type
				<< endl;

		}

		out_file.close();
	}

	// 데이터를 사용하여 기능을 구현한다.
	void ShowItems()
	{
		//string headersize = "012345678901234567890123456789012345678901234567890123456789";
		//// 아이템의 머릿말(판매정보)
		//std::cout << headersize << endl;

		
		cout << setw(field1_width) << left << "이름"	// 연산자 오버로딩을 사용한 것 
			<< setw(fieldl2_width) << right << "가격"
			<< setw(fieldl3_width) << right << "타입"
			<< endl;

		// 라인을 긋는 코드
		cout << setw(total_width)						// 길이 설정	
			<< setfill('-')								// 공백을 '-'로 설정한다. setfill : 공백문자를.......
			<< "" << endl;

		cout << setfill(' ');

		// 아이템 출력하기 
		for (int i = 0; i < items.size(); i++)	// 인덱스 기반 접근이 가능한 자료구조여야 사용할 수 있다. (vector, map 등)
		{
			cout << setw(field1_width) << left << items[i].name	// 연산자 오버로딩을 사용한 것 
				<< setw(fieldl2_width) << right << items[i].price
				<< setw(fieldl3_width) << right << items[i].type
				<< endl;

		}

		//cout << setfill('-');
	}

	// 아이템을 판매한다. 

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

	NPC() = default;
	NPC(string filename, int posX, int posY) : posX(posX), posY(posY)
	{
		shop = Shop(filename);
	}

	void changeItemList(string filename)
	{
		shop = Shop(filename);
	}

	void ShowItems()
	{
		shop.ShowItems();
	}

	void ShowNPC()
	{
		ConsoleUtil::GotoXY(posX, posY);
		cout << "#";
	}
};

void Interact(int x1, int y1, NPC& npc)	// Player와 NPC 클래스를 만들어서 넣을수도 있다.
{
	if (x1 == npc.posX && y1 == npc.posY)
	{
		npc.ShowItems();
	}
}

//void ShowPhase(Shop& shop)
//{
//	shop.ShowItems();
//}
#pragma endregion

#pragma region Player 코드
class Player
{
private:
	int posX;
	int posY;
	int money;

	// Shop코드와 연동해서 Shop.items[i].price 비교하기 money == price
	// 인벤토리 (어떤 컨테이너를 사용하면 좋을지 고민하기== 최종적인 목표 vector 사용 추천) shop->player.inventory로 옮기기

	// 현재 플레이어가 가지고 있는 아이템 정보를 저장하기
	// 게임종료 
public:

};
#pragma endregion



int main()
{
	int playerX = 10;
	int playerY = 10;

	NPC npc1("shop1.txt", 3,5);
	NPC npc2("shop2.txt", 10,9);
	NPC npc3("shop3.txt", 7,1);

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
				playerY--;
				if (playerY <= 0) { playerY = 0; }
			}

			if (GetAsyncKeyState(VK_DOWN))
			{
				playerY++;
			}

			if (GetAsyncKeyState(VK_LEFT))
			{
				playerX--;
				if (playerX <= 0) { playerX = 0; }
			}

			if (GetAsyncKeyState(VK_RIGHT))
			{
				playerX++;
			}
		}
		
		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(playerX, playerY, npc1);
		Interact(playerX, playerY, npc2);
		Interact(playerX, playerY, npc3);

		//shop.ShowItems();
		ConsoleUtil::GotoXY(playerX, playerY);
		cout << "a";

		_getch();
	}

}