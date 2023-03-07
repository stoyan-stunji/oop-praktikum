#include <iostream>

enum Flavour
{
    CHOCOLATE,
    VANILLA,
    CREAM,
    STRAWBERRY,
};

struct IceCream
{
    Flavour flavour;
    double weight;
    double price;
};

struct IceCreamFactory
{
    IceCream icecream;
};

void printIceCream(IceCreamFactory& ic)
{
    if (ic.icecream.flavour == Flavour::CHOCOLATE)
    {
        std::cout << "Chocolate" << " - " 
            << ic.icecream.price << " - " << ic.icecream.weight << " g." << std::endl;
    }
    else if (ic.icecream.flavour == Flavour::VANILLA)
    {
        std::cout << "Vanilla" << " - "
            << ic.icecream.price << " - " << ic.icecream.weight << " g." << std::endl;
    }
    else if (ic.icecream.flavour == Flavour::CREAM)
    {
        std::cout << "Cream" << " - "
            << ic.icecream.price << " - " << ic.icecream.weight << " g." << std::endl;
    }
    else if (ic.icecream.flavour == Flavour::STRAWBERRY)
    {
        std::cout << "Strawberry" << " - "
            << ic.icecream.price << " - " << ic.icecream.weight << " g." << std::endl;
    }
}

void findMostExpensiveIc(IceCreamFactory ic[], unsigned numberOfIc)
{
    unsigned max = ic[0].icecream.price;
    unsigned index = 0;
    for (unsigned i = 0; i < numberOfIc; i++)
    {
        if (ic[i].icecream.price > max)
        {
            max = ic[i].icecream.price;
            index = i;
        }
    }
    printIceCream(ic[index]);
}

int main()
{
    IceCreamFactory ic[4];
    unsigned numberOfIc = 4;
    ic[0] = {CHOCOLATE, 50, 7.56};
    ic[1] = {VANILLA, 60, 8.78};
    ic[2] = {CREAM, 30, 9.00};
    ic[3] = {STRAWBERRY, 40, 6.78};

    findMostExpensiveIc(ic, numberOfIc);
}
