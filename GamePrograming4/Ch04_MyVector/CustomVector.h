#pragma once
/*
* 벡터(가변 배열)의 특징
* - 길이가 변할 수 있다. (동적 크기 변환이 가능하다)
* - 자동으로 크기가 변경된다. 
*/

/*
* int size(크기);
* int capacity(수용량);
* 
* int arr = new int[5]; size = 0, capacity = 5
* 
* resize(); 크기를 조절해주는 함수
* int size, capacity
*/

/*
* auto& R = vector<int>
* auto타입은 내일 추가로 할 예정
*/

// value에 해당하는 타입을 T로 변환하기
template<typename T>	// 타입을 바꿔야함 파란글자인 int, double, string 같은 것만 보면된다.
class MyVector
{
private:
	int size;		// 개수 지정
	int capacity;	// 최대 크기
	T* vec;			// 
public:
	// 생성자
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];	// 벡터 공간에 int 크기만큼의 startSize 만들어라
		size = 0;
		capacity = startSize;
	}

	// 소멸자
	~MyVector()
	{
		delete[] vec;
	}

	T& operator[](int idx) // vec[1]	
	{
		return vec[idx];
	}
	void resize(int newSize)
	{
		// size : 현재 배열에 들어있는 원소의 숫자
		// newSize : 변경하려는 사이즈의 크기

		// 원소의 개수를 재정의해준다.
		if (size < newSize)
		{
			size = size;
		}
		else
		{
			size = newSize;
		}
		// capacity로 어떻게 변경하는가?
		capacity = newSize;

		T* arr = new T[newSize];
		// vec[0], vec[1] ... size
		for (int i = 0; i < size; i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec;	// 기존의 vector가 가리키고 있는 공간(메모리)을 해제한다.
		vec = arr;		// vec가 새로운 공간을 다시 가리키라는 의미이다?		 둘다 주소?
		//delete[] arr; <= 쓰면 안됨. 댕글링 레퍼런스로 인해 터질 수(?) 있음.

		
	}
	void push_back (const T& element)
	{
		if (capacity <= size)
		{
			capacity = capacity * 2;
			resize(capacity);
		}

		vec[size] = element;	// 0에 데이터를 넣음?
		size++;	
	}
	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;
	}

	int Size() { return size; }


};

void Test1()
{
	while (true)
	{
		MyVector<int>* myVec = new MyVector<int>(10);	// myVec는 주소공간을 가리킨다. 
		delete myVec;
	}
}

void Test2()
{
	MyVector<int> vec(5);
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i + 1);

		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	vec.push_back(6);
	for (int i = 0; i < vec.Size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;

	MyVector<double> vec2(4);
	for (int i = 0; i < 4; i++)
	{
		vec2.push_back(i + 0.5);

		std::cout << vec2[i] << " ";
	}

	
}

/*
* ai가 알려준 코드와 비교해보기 
* 
* #include <iostream>
#include <stdexcept>

class IntVector {
private:
    int* data;  // 동적 할당된 배열
    size_t size; // 현재 배열의 크기
    size_t capacity; // 할당된 공간의 크기

    void expandCapacity() {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        int* newData = new int[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    IntVector() : data(nullptr), size(0), capacity(0) {}

    ~IntVector() {
        delete[] data;
    }

    void resize(size_t newSize) {
        if (newSize > capacity) {
            int* newData = new int[newSize];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newSize;
        }
        size = newSize;
    }

    void push_back(int value) {
        if (size == capacity) {
            expandCapacity();
        }
        data[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            --size;
        } else {
            throw std::out_of_range("Vector is empty!");
        }
    }

    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds!");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    IntVector vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    vec.pop_back();
    std::cout << "After pop_back, last element: " << vec[vec.getSize() - 1] << "\n";

    return 0;
}

*/