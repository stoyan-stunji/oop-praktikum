#include <iostream>

struct Date 
{
    unsigned day;
    unsigned month;
    unsigned year;
};

struct Hour
{
    unsigned hour;
    unsigned minutes;
};

enum TempType
{
    CELSIUS,   //0
    KELVIN,    //1
    FAHRENHEIT,//2
};

enum MoonPhase
{
    FULL_MOON,    //0
    FIRST_QUARTER,//1
    NEW_MOON,     //2
    THIRD_QUARTER,//3
};

struct Clock 
{
    Date date;
    Hour hour;
    double temperature;
    TempType tempType;
    MoonPhase moonPhase;
};

bool areAllFullMoon(Clock c[], unsigned numberOfClocks)
{
    for (unsigned i = 0; i < numberOfClocks; i++)
    {
        if(c[i].moonPhase != MoonPhase::FULL_MOON)
        {
            return false;
        }

        return true;
    }
}

void printClocks(Clock c[], unsigned numberOfClocks)
{
    std::cout << "Date: " << std::endl;
    for (unsigned i = 0; i < numberOfClocks; i++)
    {
        std::cout << c[i].date.day << "." << c[i].date.month << "." << c[i].date.year << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Hour: " << std::endl;
    for (unsigned i = 0; i < numberOfClocks; i++)
    {
        std::cout << c[i].hour.hour << ":" << c[i].hour.minutes << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Temperature: " << std::endl;
    for (unsigned i = 0; i < numberOfClocks; i++)
    {
        std::cout << c[i].temperature << " ";
        switch (c[i].tempType)
        {
            case CELSIUS:
                std::cout << "Celsius" << std::endl;
                break;
            case KELVIN:
                std::cout << "Kelvin" << std::endl;
                break;
            case FAHRENHEIT:
                std::cout << "Fahrenheit" << std::endl;
                break;
        }
    }    
    std::cout << std::endl;

    std::cout << "Moon Phase: " << std::endl;
    for (unsigned i = 0; i < numberOfClocks; i++)
    {
        switch (c[i].moonPhase)
        {
        case FULL_MOON:
            std::cout << "Full Moon" << std::endl;
            break;
        case FIRST_QUARTER:
            std::cout << "First Quarter" << std::endl;
            break;
        case NEW_MOON:
            std::cout << "New Moon" << std::endl;
            break;
        case THIRD_QUARTER:
            std::cout << "Third Quarter" << std::endl;
            break;
        }
    }
    std::cout << std::endl;

    if (areAllFullMoon(c, numberOfClocks))
    {
        std::cout << "Full Moons!" << std::endl;
        std::cout << std::endl;
    }
}

void changeTemp(Clock c[], unsigned numberOfClocks)
{
    std::cout << "Change the temperature: " << std::endl;
    std::cout << "0 - Celsius; " << std::endl;
    std::cout << "1 - Kelvin; " << std::endl;
    std::cout << "2 - Fahrenheit; " << std::endl;

    int input;
    std::cin >> input;

    while (input > 2 || input < 0)
    {
        std::cout << std::endl;
        std::cout << "Please enter a valid number!" << std::endl;
        std::cin >> input;
    }

    for (unsigned i = 0; i < numberOfClocks; i++)
    {
        switch (c[i].tempType)
        {
        case CELSIUS:
            switch (input)
            {
            case 1:
                c[i].tempType = TempType::KELVIN;
                c[i].temperature += 273.15;
                break;
            case 2:
                c[i].tempType = TempType::FAHRENHEIT;
                c[i].temperature = c[i].temperature * 1.8 + 32;
                break;
            }
            break;
        case KELVIN:
            switch (input)
            {
            case 0:
                c[i].tempType = TempType::CELSIUS;
                c[i].temperature -= 273.15;
                break;
            case 2:
                c[i].tempType = TempType::FAHRENHEIT;
                c[i].temperature -= 457.87;
                break;
            }
            break;
        case FAHRENHEIT:
            switch (input)
            {
            case 0:
                c[i].tempType = TempType::CELSIUS;
                c[i].temperature = c[i].temperature * (double)(5 / 9) - 32;
                break;
            case 1:
                c[i].tempType = TempType::KELVIN;
                c[i].temperature += 457.87;
                break;
            }
            break;
        }
    }
}

void changeMoonPhase(Clock c[], unsigned numberOfClocks)
{
    std::cout << "Change the moon phase: " << std::endl;
    std::cout << "0 - Full Moon; " << std::endl;
    std::cout << "1 - First Quarter; " << std::endl;
    std::cout << "2 - New Moon; " << std::endl;
    std::cout << "3 - Third Quarter; " << std::endl;

    int input;
    std::cin >> input;

    while (input > 3 || input < 0)
    {
        std::cout << std::endl;
        std::cout << "Please enter a valid number!" << std::endl;
        std::cin >> input;
    }

    for (unsigned i = 0; i < numberOfClocks; i++)
    {
        switch (c[i].tempType)
        {
        case FULL_MOON:
            switch (input)
            {
            case 0:
                c[i].moonPhase = MoonPhase::FULL_MOON;
                break;
            case 1:
                c[i].moonPhase = MoonPhase::FIRST_QUARTER;
                break;
            case 2:
                c[i].moonPhase = MoonPhase::NEW_MOON;
                break;
            case 3:
                c[i].moonPhase = MoonPhase::THIRD_QUARTER;
                break;
            }
            break;
        case FIRST_QUARTER:
            switch (input)
            {
            case 0:
                c[i].moonPhase = MoonPhase::FULL_MOON;
                break;
            case 1:
                c[i].moonPhase = MoonPhase::FIRST_QUARTER;
                break;
            case 2:
                c[i].moonPhase = MoonPhase::NEW_MOON;
                break;
            case 3:
                c[i].moonPhase = MoonPhase::THIRD_QUARTER;
                break;
            }
            break;
        case NEW_MOON:
            switch (input)
            {
            case 0:
                c[i].moonPhase = MoonPhase::FULL_MOON;
                break;
            case 1:
                c[i].moonPhase = MoonPhase::FIRST_QUARTER;
                break;
            case 2:
                c[i].moonPhase = MoonPhase::NEW_MOON;
                break;
            case 3:
                c[i].moonPhase = MoonPhase::THIRD_QUARTER;
                break;
            }
            break;
        case THIRD_QUARTER:
            switch (input)
            {
            case 0:
                c[i].moonPhase = MoonPhase::FULL_MOON;
                break;
            case 1:
                c[i].moonPhase = MoonPhase::FIRST_QUARTER;
                break;
            case 2:
                c[i].moonPhase = MoonPhase::NEW_MOON;
                break;
            case 3:
                c[i].moonPhase = MoonPhase::THIRD_QUARTER;
                break;
            }
            break;
        }
    }

}

int main()
{
    Date date[4];
    date[0] = { 11, 1, 2001 };
    date[1] = { 12, 2, 2002 };
    date[2] = { 13, 3, 2003 };
    date[3] = { 14, 4, 2004 };

    Hour hour[4];
    hour[0] = { 12, 20 };
    hour[1] = { 13, 30 };
    hour[2] = { 14, 40 };
    hour[3] = { 15, 50 };

    Clock clock[4];
    unsigned numberOfClocks = 4;
    clock[0] = { date[0], hour[0], 0, CELSIUS, FULL_MOON };
    clock[1] = { date[1], hour[1], 10, KELVIN, FIRST_QUARTER };
    clock[2] = { date[2], hour[2], 200, FAHRENHEIT, NEW_MOON };
    clock[3] = { date[3], hour[3], 3000, CELSIUS, THIRD_QUARTER };

    changeTemp(clock, numberOfClocks);
    changeMoonPhase(clock, numberOfClocks);
    printClocks(clock, numberOfClocks);
}
