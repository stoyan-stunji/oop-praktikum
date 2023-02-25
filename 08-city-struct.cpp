#include <iostream>

using namespace std;

struct Destination 
{
    char city[32];
    int kilometers;
};

void initializeDestination(Destination& d, const char city[], int kilometers)
{
    strcpy_s(d.city, strlen(city) + sizeof(char), city);
    d.kilometers = kilometers;
}

void printDestination(Destination& d)
{
    cout << d.city << " - " << d.kilometers << " km to Sofia" << endl;
}

void findClosestCity(Destination* d, int count)
{
    int min = d[0].kilometers;
    int index = 0;
    for (int i = 0; i < count; i++)
    {
        if (d[i].kilometers < min) 
        {
            min = d[i].kilometers;
            index = i;
        }
    }
    printDestination(d[index]);
}

void findFurthestCity(Destination* d, int count)
{
    int max = d[0].kilometers;
    int index = 0;
    for (int i = 0; i < count; i++)
    {
        if (d[i].kilometers > max)
        {
            max = d[i].kilometers;
            index = i;
        }
    }
    printDestination(d[index]);
}

int main()
{
    Destination d[30];

    // а)
    initializeDestination(d[0], "Sliven", 350);
    initializeDestination(d[1], "Plovdiv", 120);

    // б)
    printDestination(d[0]);
    printDestination(d[1]);

    // в) и г)
    for (int i = 0; i < 30; i++)
    {
        //initializeDestination(d[i], "City", 0);
    }

    // д)
    cout << "Closest city: " << endl;
    findClosestCity(d, 2);

    // е)
    cout << "Furthest city: " << endl;
    findFurthestCity(d, 2);
}
