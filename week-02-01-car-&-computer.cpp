#include <iostream>

struct Car
{
    double mileage;
    double avgFuelUsage;
    char modelName[32];
    char description[256];
    enum brandType
    {
        CAMARO,
        MUSTANG,
        LADA,
    };
    enum engineType
    {
        ESS,
        DSL,
        HEV,
    };
    enum fuelType
    {
        GAS,
        BENZIN,
        DIESEL,
    };
};


struct Computer
{
    double batteryCapacity;
    double screenSize; //in inches
    char modelName[32];
    char description[256];
    enum VideoCard
    {
        GDDR2SDRAM,
        GDDR3SDRAM,
        GDDR4SDRAM,
    };
    enum ProcessorType
    {
        SINGLECORE,
        DUALCORE,
        QUADCORE,
    };
    enum NumberOfCore
    {
        ONE,
        TWO,
        THREE,
    };
};

int main()
{
    
}
