#include <iostream>

using namespace std;

struct Prisoner 
{
    char name[32];
    char id[32];
    int timeLeft;
};

struct Prison
{
    char nameBuilding[32];
    Prisoner x;
};

void initializePrison(Prison& p, const char nameBuilding[], const char name[], const char id[], int timeLeft)
{
    strcpy_s(p.nameBuilding, strlen(nameBuilding) + sizeof(char), nameBuilding);

    strcpy_s(p.x.name, strlen(name) + sizeof(char), name);
    strcpy_s(p.x.id, strlen(id) + sizeof(char), id);
    p.x.timeLeft = timeLeft;
}

void sortArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

void printPrison(Prison& p)
{
    cout << p.nameBuilding << " - " << p.x.name << " : " << p.x.id << " : " << p.x.timeLeft << endl;
}

int main()
{
    Prison p[6];
    Prisoner x[6];

    initializePrison(p[0], "FMI", "Stoyan Ivanov", "0MI1", 1);
    initializePrison(p[1], "FMI", "Petar Balulov", "0MI2", 3);
    initializePrison(p[2], "FMI", "Daria Lazarova", "0MI3", 2);
    initializePrison(p[3], "FHF", "Dimitar Gagashev", "1MI1", 4);
    initializePrison(p[4], "FHF", "Pavel Nikolov", "1MI2", 1);
    initializePrison(p[5], "FHF", "Sofia Stefanova", "1MI3", 4);

    int input = 0;
    cin >> input;

    while (input != 1 && input != 2)
    {
        cout << "Please enter the correct number!";
        cout << endl;
        cin >> input;
    }

    if (input == 1)
    {
        for (int i = 0; i <= 2; i++)
        {
            printPrison(p[i]);
        }
    }
    else if (input == 2)
    {
        for (int i = 3; i <= 5; i++)
        {
            printPrison(p[i]);
        }
    }

    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == p[j].x.timeLeft)
            {
                printPrison(p[j]);
            }
        }
    }
}
