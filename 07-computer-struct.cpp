#include <iostream>

using namespace std;

struct Computer 
{
    int batteryCap;
    double screenSize;
    char brand[32];
    char description[128];
};

void initializeComputer(Computer &x, int batteryCap, double screenSize, const char brand[], const char description[])
{
    x.batteryCap = batteryCap;
    x.screenSize = screenSize;
    strcpy_s(x.brand, strlen(brand) + sizeof(char), brand);
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
