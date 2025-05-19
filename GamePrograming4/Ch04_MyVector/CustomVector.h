#pragma once
/*
* ����(���� �迭)�� Ư¡
* - ���̰� ���� �� �ִ�. (���� ũ�� ��ȯ�� �����ϴ�)
* - �ڵ����� ũ�Ⱑ ����ȴ�. 
*/

/*
* int size(ũ��);
* int capacity(���뷮);
* 
* int arr = new int[5]; size = 0, capacity = 5
* 
* resize(); ũ�⸦ �������ִ� �Լ�
* int size, capacity
*/

/*
* auto& R = vector<int>
* autoŸ���� ���� �߰��� �� ����
*/

// value�� �ش��ϴ� Ÿ���� T�� ��ȯ�ϱ�
template<typename T>	// Ÿ���� �ٲ���� �Ķ������� int, double, string ���� �͸� ����ȴ�.
class MyVector
{
private:
	int size;		// ���� ����
	int capacity;	// �ִ� ũ��
	T* vec;			// 
public:
	// ������
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];	// ���� ������ int ũ�⸸ŭ�� startSize ������
		size = 0;
		capacity = startSize;
	}

	// �Ҹ���
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
		// size : ���� �迭�� ����ִ� ������ ����
		// newSize : �����Ϸ��� �������� ũ��

		// ������ ������ ���������ش�.
		if (size < newSize)
		{
			size = size;
		}
		else
		{
			size = newSize;
		}
		// capacity�� ��� �����ϴ°�?
		capacity = newSize;

		T* arr = new T[newSize];
		// vec[0], vec[1] ... size
		for (int i = 0; i < size; i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec;	// ������ vector�� ����Ű�� �ִ� ����(�޸�)�� �����Ѵ�.
		vec = arr;		// vec�� ���ο� ������ �ٽ� ����Ű��� �ǹ��̴�?		 �Ѵ� �ּ�?
		//delete[] arr; <= ���� �ȵ�. ��۸� ���۷����� ���� ���� ��(?) ����.

		
	}
	void push_back (const T& element)
	{
		if (capacity <= size)
		{
			capacity = capacity * 2;
			resize(capacity);
		}

		vec[size] = element;	// 0�� �����͸� ����?
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
		MyVector<int>* myVec = new MyVector<int>(10);	// myVec�� �ּҰ����� ����Ų��. 
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
* ai�� �˷��� �ڵ�� ���غ��� 
* 
* #include <iostream>
#include <stdexcept>

class IntVector {
private:
    int* data;  // ���� �Ҵ�� �迭
    size_t size; // ���� �迭�� ũ��
    size_t capacity; // �Ҵ�� ������ ũ��

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