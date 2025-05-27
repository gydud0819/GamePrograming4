#pragma once
#include"ConsoleUtility.h"

using std::cout;
using std::cin;
using std::endl;

// 복습 : 계산기 기능을 함수 포인터로 표현하기 



#pragma region (심화1) 함수 포인터에 일반화 프로그래밍 적용
// 심화1. 함수 포인터에 일반화 프로그래밍 적용
template<typename T>
void Plus(T a, T b)
{
	cout << "덧셈 : ";
	cout << a + b << endl;
}

template<typename T>
void Minus(T a, T b)
{
	cout << "뺄셈 : ";
	cout << a - b << endl;
}

template<typename T>
void Calculate(void (*Func) (T a, T b), T outA, T outB)
{
	Func(outA, outB);

}

template<typename T>
void Times(T a, T b)
{
	cout << "곱셈 : ";
	cout << a * b << endl;
}

template<typename T>
void Divide(T a, T b)
{
	cout << "나눗셈 : ";
	cout << a / b << endl;
}
#pragma endregion

#pragma region (심화2) 열거형과 클래스로 함수 포인터 활용
// 열거형의 이름은 항상 대문자로 작성하고 이름으로 타입을 알아볼 수 있게 설정한다.
// 함수는 첫글자를 대문자로 표현한다. 
enum ActorAction	
{
	MOVE, TALK
};

class Actor	// 등장 요소
{
private:

	static void Move()	// 
	{
		cout << "움직인다." << endl;
	}

	static void Talk()
	{
		cout << "대화한다." << endl;
	}

public:
	Actor() = default;
	
	void (*Action)();

	void ActionMove()
	{
		Action = Move;
	}

	void ActionTalk()
	{
		Action = Talk;
	}

	void Think()
	{
		// 랜덤한 숫자를 받아서 0이 나오면 move, 1이 나오면 talk 등
		int select = ConsoleUtil::GetRandomInt(2);	// 0 또는 1 반환

		ActorAction action1 = static_cast<ActorAction>(select -1);	// 열거형을 정수로 반환

		switch (action1)
		{
		case MOVE:
			Action = Move;
			break;
		case TALK:
			Action = Talk;
			break;
		default:
			cout << "잘못된 입력을 받아왔다." << endl;
			return;
		}
	}
};



#pragma endregion

#pragma region 가위바위보 예제 만들기
enum RCP // 가위바위보
{
	ROCK,
	SCISSORS,
	PAPER
};

class RCPGame
{
//private:
	// 함수포인터 선언하기
	void (*RCPPlay)();

	static void Rock()
	{
		cout << "묵" << endl;
	}

	static void Scissors()
	{
		cout << "찌" << endl;
	}

	static void Paper()
	{
		cout << "빠" << endl;
	}
	// switch(RCP_TYPE) 각 타입에 맞게 함수포인터의 함수를 넣는 코드 만들기
	RCP AiRcpType;
	RCP PlayerType;

	int PlayerScore;
	int AiScore;

	void Result()
	{
		// 같을 때 : 비김      비기면 이길때까지 해야하는데 
		if (PlayerType == AiRcpType)
		{
			cout << "비겼으니까 다시 선택하세용" << endl;

			//StartGame();	// 비기면 이기거나 질때까지 재실행한다.

		}

		// 유저>AI : 이김
		else if (PlayerType == ROCK && AiRcpType == SCISSORS ||
			PlayerType == SCISSORS && AiRcpType == PAPER ||
			PlayerType == PAPER && AiRcpType == ROCK)
		{
			cout << "이겼지롱." << endl;
			PlayerScore++;
		}
		// 유저<AI : 졌음
		else
		{
			cout << "졌넹" << endl;
			AiScore++;
		}

	}
public:
	RCPGame() : PlayerScore(0), AiScore(0) {}	// 생성자 만들고 0으로 바로 초기화하기

	void StartGame()
	{
		while (true)
		{
			// 유저가 입력하는 방식 
			cout << "0 : 묵, 1 : 찌, 2 : 빠" << endl;
			cout << "선택해주세용" << endl;
			cout << "내가 고른 선택 :" << " ";
			int input = 0;
			cin >> input;
			PlayerType = static_cast<RCP>(input);

			// 컴퓨터가 선택할 번호를 랜덤으로 받는다.
			int sel = ConsoleUtil::GetRandomInt(3);
			AiRcpType = static_cast<RCP>(sel - 1);
			// switch문을 사용한다. (함수포인터를 결정한다.)
			switch (AiRcpType)
			{
			case ROCK:
				RCPPlay = Rock;
				break;
			case SCISSORS:
				RCPPlay = Scissors;
				break;
			case PAPER:
				RCPPlay = Paper;
			default:
				//cout << "다시 입력하세요." << endl;
				break;
			}

			// 함수포인터의 함수를 실행한다.
			cout << "ai가 고른 선택 :" << " ";
			RCPPlay();
			Result();

			if (PlayerScore >= 3 || AiScore >= 3)
			{
				break;
			}
		}

		if (PlayerScore >= 3)
		{
			cout << "유저가 이겼음!" << endl;
		}
		else if (AiScore >= 3)
		{
			cout << "Ai가 이겼음!" << endl;
		}
		
	}
		
};

#pragma endregion

void FPTest()
{
	Calculate(Plus, 4, 2);		// 정수
	Calculate(Plus, 2.3, 5.7);	// 실수
	Calculate(Minus, 4, 2);		// 정수
	Calculate(Minus, 4.5, 2.8);	// 실수 

	Calculate(Times, 4, 2);		// 정수 
	Calculate(Times, 4.5, 2.8);	// 실수 
	Calculate(Divide, 4, 2);	// 실수 
	Calculate(Divide, 4.5, 2.8); // 실수 

}

void FPTest2()
{
	Actor actor;
	// actor.의사결정을 한다.
	//actor.ActionMove();
	actor.Think();
	actor.Action();
	//actor.ActionTalk();
}

void FPTest3()
{
	RCPGame rcpGame;
	rcpGame.StartGame();
}