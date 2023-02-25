#include <iostream>

using namespace std;

void clearSpaces(char text[])
{
	int counter = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if ((text[i] != ' ' || text[i + 1] != ' ') && i != 0) 
		{
			text[counter++] = text[i];
		}
	}
	text[counter] = '\0';
}

void printText(char text[])
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		cout << text[i];
	}
}

int main()
{
    char text[] = " Open        beer";
	clearSpaces(text);
	printText(text);
}

