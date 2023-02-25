#include <iostream>

using namespace std;

const int MAX_SIZE = 50;

void enterArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

void copyArray(int array[], int size)
{
	enterArray(array, size);

    int* copy = new int[size];
	
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		copy[counter++] = array[i];
	}
	
	printArray(copy, size);

	delete[] copy;
}

int main()
{
    int array[MAX_SIZE];
	int size = 0;
	cin >> size;

	copyArray(array, size);
}

