#include <iostream>

using namespace std;

bool areEqualLenght(char text1[], char text2[]) //so not to use strlen()
{
	int counter1 = 0;
	int counter2 = 0;

	for (int i = 0; text1[i] != '\0'; i++)
	{
		counter1++;
	}

	for (int i = 0; text2[i] != '\0'; i++)
	{
		counter2++;
	}

	if (counter1 == counter2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void toUpper(char text[])
{
	int counter = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] >= 'a' && text[i] <= 'z')
		{
			text[i] -= 32;
		}

		text[counter++] = text[i];
	}
}

bool areEqual(char* str1, char* str2)
{
	if (areEqualLenght(str1, str2) == true)
	{
		for (int i = 0; str1[i] != '\0'; i++)
		{
			if (str1[i] != str2[i])
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		return false;
	}
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
    char text1[] = "HI";
    char text2[] = "Hi";

	toUpper(text1);
	toUpper(text2);

	cout << boolalpha << areEqual(text1, text2);
}

