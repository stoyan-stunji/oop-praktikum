#include <iostream>

void printArray(const int* array, unsigned size)
{
	for (unsigned i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
}

void resizeArray(int*& array, int& size, int& capacity)
{
	capacity *= 2;
	int* newArray = new int[capacity];

	for (unsigned i = 0; i < size; i++)
	{
		newArray[i] = array[i];
	}

	delete[] array;
	array = newArray;
}

void pushBack(int*& array, int& size, int& capacity, unsigned newElement)
{
	if (size == capacity)
	{
		resizeArray(array, size, capacity);
	}
	array[size++] = newElement;
}

int main()
{
	int CAPACITY = 5;
	int size = 0;
	int* array = new int[CAPACITY];

	pushBack(array, size, CAPACITY, 1);
	printArray(array, size);

	delete[] array;
	return 0;
}
