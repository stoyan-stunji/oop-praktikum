#include <iostream>

using namespace std;

struct Car
{
    int mileage;
    int averageFuel;
    char brand[32];
    char description[128];
};

void initializeCar(Car &c, int mileage, int averageFuel, const char brand[], const char description[])
{
    c.mileage = mileage;
    c.averageFuel = averageFuel;
    strcpy_s(c.brand, strlen(brand) + sizeof(char), brand);
    strcpy_s(c.description, strlen(description) + sizeof(char), description);
}

void printCar(const Car& c)
{
    cout << c.mileage << endl;
    cout << c.averageFuel << endl;
    cout << c.brand << endl;
    cout << c.description << endl;
}

int main()
{
    Car c[2];

    initializeCar(c[0], 10000, 5, "Camaro '79", "Bumblebee");
    printCar(c[0]);
}
