#include <iostream>

struct FullName
{
    char firstName[32];
    char secondName[32];
    char lastName[32];
};

enum Gender
{
    MALE,
    FEMALE,
    OTHER,
};

struct Doctor
{
    FullName fullname;
    unsigned yearsOfExp;
    char hospital[32];
    Gender gender;
};

void printDoctor(Doctor &d)
{
    std::cout << "-NAME-" << std::endl;
    std::cout << d.fullname.firstName << " " << d.fullname.secondName << " " << d.fullname.lastName << std::endl;
    std::cout << std::endl;
    std::cout << "-YEARS OF EXPERIENCE-" << std::endl;
    std::cout << d.yearsOfExp << std::endl;
    std::cout << std::endl;
    std::cout << "-HOSPITAL-" << std::endl;
    std::cout << d.hospital << std::endl;
    std::cout << std::endl;
    std::cout << "-GENDER-" << std::endl;
    switch (d.gender)
    {
    case MALE:
        std::cout << "Male" << std::endl;
        break;
    case FEMALE:
        std::cout << "Female" << std::endl;
        break;
    case OTHER:
        std::cout << "Undefined" << std::endl;
        break;
    }
    std::cout << std::endl;
}

void changeLastName(Doctor d[])
{
    unsigned counter = 0;

    std::cout << "Choose a doctor: ";
    unsigned index;
    std::cin >> index;

    std::cout << "Choose a new last name: ";
    char * newLastName = new char[strlen(d[index].fullname.lastName) + 128];
    std::cin >> newLastName;
    unsigned newSize = strlen(newLastName);

    for (unsigned i = 0; newLastName[i] != '\0'; i++)
    {
        d[index].fullname.lastName[counter++] = newLastName[i];
    }

    for (unsigned i = newSize; i < strlen(d[index].fullname.lastName); i++)
    {
        d[index].fullname.lastName[counter++] = ' ';
    }

    delete[] newLastName;
    std::cout << std::endl;
    printDoctor(d[index]);
}

void changeHospitalName(Doctor d[])
{
    unsigned counter = 0;

    std::cout << "Choose a doctor: ";
    unsigned index;
    std::cin >> index;

    std::cout << "Choose a new hospital name: ";
    char* newHospitalName = new char[strlen(d[index].hospital) + 128];
    std::cin >> newHospitalName;
    unsigned newSize = strlen(newHospitalName);

    for (unsigned i = 0; newHospitalName[i] != '\0'; i++)
    {
        d[index].hospital[counter++] = newHospitalName[i];
    }

    for (unsigned i = newSize; i < strlen(d[index].hospital); i++)
    {
        d[index].hospital[counter++] = ' ';
    }

    delete[] newHospitalName;
    std::cout << std::endl;
    printDoctor(d[index]);
}

void swap(int& num1, int& num2)
{
    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) 
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = start + count;

    swap(arr[pivotIndex], arr[start]);

    while (start < pivotIndex && end > pivotIndex)
    {

        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot) 
        {
            end--;
        }

        if (start < pivotIndex && end > pivotIndex)
        {
            swap(arr[start++], arr[end--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void sortByYearsOfExp(Doctor d[], unsigned numberOfDoctors)
{
    unsigned counter = 0;
    int* array = new int[numberOfDoctors];

    for (unsigned i = 0; i < numberOfDoctors; i++)
    {
        array[counter++] = d[i].yearsOfExp;
    }
    
    quickSort(array, 0, numberOfDoctors - 1);

    std::cout << "Doctors sorted by years of experience: " << std::endl;
    std::cout << std::endl;
    for (unsigned i = 0; i < numberOfDoctors; i++)
    {
        for (unsigned j = 0; j < numberOfDoctors; j++)
        {
            if (d[j].yearsOfExp == array[i]) 
            {
                printDoctor(d[j]);
            }
        }
    }

    delete[] array;
}

int main()
{
    Doctor doctors[10];
    unsigned numberOfDoctors = 10;

    doctors[0] = { "Angel", "Angelov", "Angelov", 9, "Hospital 1", MALE };
    doctors[1] = { "Bngel", "Bngelov", "Bngelov", 8, "Hospital 2", MALE };
    doctors[2] = { "Cngel", "Cngelov", "Cngelov", 7, "Hospital 3", MALE };
    doctors[3] = { "Dngel", "Dngelov", "Dngelov", 6, "Hospital 4", FEMALE };
    doctors[4] = { "Engel", "Engelov", "Engelov", 5, "Hospital 5", FEMALE };
    doctors[5] = { "Fngel", "Fngelov", "Fngelov", 4, "Hospital 6", FEMALE };
    doctors[6] = { "Gngel", "Gngelov", "Gngelov", 3, "Hospital 7", OTHER };
    doctors[7] = { "Hngel", "Hngelov", "Hngelov", 2, "Hospital 8", OTHER };
    doctors[8] = { "Ingel", "Ingelov", "Ingelov", 1, "Hospital 9", OTHER };
    doctors[9] = { "Jngel", "Jngelov", "Jngelov", 0, "Hospital 0", OTHER };

    changeLastName(doctors);
    std::cout << std::endl;
    changeHospitalName(doctors);
    std::cout << std::endl;
    sortByYearsOfExp(doctors, numberOfDoctors);
}
