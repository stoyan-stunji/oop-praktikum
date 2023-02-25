#include <iostream>

using namespace std;

struct Computer 
{
    int batteryCap;
    double screenSize;
    char* brand;
    char* description;
};

void initializeComputer(Computer &x, int batteryCap, double screenSize, const char brand[], const char description[])
{
    x.batteryCap = batteryCap;
    x.screenSize = screenSize;
    x.brand = new char[strlen(brand)];
    strcpy_s(x.brand, strlen(brand) + sizeof(char), brand);
    x.description = new char[strlen(description)];
    strcpy_s(x.description, strlen(description) + sizeof(char), description);
}

void printComputer(Computer& x)
{
    cout << x.batteryCap << endl;
    cout << x.screenSize << endl;
    cout << x.brand << endl;
    cout << x.description << endl;
}

int main()
{
    Computer x[2];

    initializeComputer(x[0], 70, 12.5, "Acer", "Very cool!");
    printComputer(x[0]);
}
