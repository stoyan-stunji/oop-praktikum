#include <iostream>

using namespace std;

struct Car
{
    int mileage;
    int averageFuel;
    char* brand;
    char* description;
};

void initializeCar(Car &c, int mileage, int averageFuel, const char brand[], const char description[])
{
    c.mileage = mileage;
    c.averageFuel = averageFuel;
    c.brand = new char[strlen(brand)];
    strcpy_s(c.brand, strlen(brand) + 1, brand);
    c.description = new char[strlen(description)];
    strcpy_s(c.description, strlen(description) + 1, description);
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

