// Lab_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iterator> 
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <chrono> 
#include <vector> 
#include <string>
using namespace std;
using namespace std::chrono;


//------------------------------------------------------------------
class Hamstr
{
public:

    int FoodForOneHamster(int DailyNorm, int greed, int neighbours)     // Розрахунок споживання їжі хом'яком
    {
        return DailyNorm + greed * neighbours;
    }

    int Largest(int array[], int HamstersTaken)           //Знаходження найбільшого елемента
    {
        int largest = array[0], index = 0;

        for (int i = 1; i < HamstersTaken; i++)
        {
            if (largest <= array[i])
            {
                largest = array[i];
                index = i;
            }
        }
        return index;
    }


    int AmountOfHamsters(int InputArray[])
    {
        int FoodAmount = InputArray[0],         //ЗАПАС ЇЖІ
         HamstersQuantity = InputArray[1],      //КІЛЬКІСТЬ ХОМ'ЯКІВ
         HamsterLocation = 2,
         FoodEaten = 0, 
         HamstersTaken = HamstersQuantity,
         InputArrayLength = HamstersQuantity * 2 + 2;;

        for (int i = 2; i < InputArrayLength; i += 2)        // Чи можу прогодувати "C" хом'ячків
            FoodEaten += FoodForOneHamster(InputArray[i], InputArray[i + 1], (HamstersTaken - 1));
        if (FoodEaten <= FoodAmount)
            return HamstersTaken;


        FoodEaten = 0;
        HamstersTaken--;

        while (HamstersTaken > 1)                       // В межах від  HamstersQuantity-1 до 1 
        {
            int* AmountPerHamster = new int[HamstersTaken];

            for (int i = 0; i < HamstersQuantity; i++)
            {
                if (i < HamstersTaken)
                    AmountPerHamster[i] = FoodForOneHamster(InputArray[HamsterLocation], InputArray[HamsterLocation + 1], (HamstersTaken - 1));
                else
                {
                    int LargestElementId = Largest(AmountPerHamster, HamstersTaken);
                    int food = FoodForOneHamster(InputArray[HamsterLocation], InputArray[HamsterLocation + 1], (HamstersTaken - 1));

                    if (AmountPerHamster[LargestElementId] > food)
                        AmountPerHamster[LargestElementId] = food;
                }
                HamsterLocation += 2;
            }

            for (int i = 0; i < HamstersTaken; i++)
                FoodEaten += AmountPerHamster[i];
            if (FoodEaten <= FoodAmount)
                return HamstersTaken;


            HamstersTaken--;
            FoodEaten = 0;          //Reset value
            HamsterLocation = 2;    //Reset value

            delete[] AmountPerHamster;
        }

        for (int i = 2; i < InputArrayLength; i += 2)      // Чи можу прогодувати 1 хом'ячка
        {
            FoodEaten = InputArray[i];
            if (FoodEaten <= FoodAmount)
                return HamstersTaken;
        }

        return 0;                                         // Якщо не можу прогодувати ні 1 хом'ячка
    }
};
//------------------------------------------------------------------

int*   read_file(string path)
{
    std::string line;
    std::ifstream in_1(path);

    int HamstersQuantity = 0, FoodAmount = 0, counter = 0, ArrayLength;
    string TemporaryString;

    while (in_1.is_open())
    {
        getline(in_1, line);

        switch (counter)
        {
        case 0:
            FoodAmount = stoi(line);
            break;
        case 1:
            HamstersQuantity = stoi(line);
            break;
        default:
            in_1.close();
            break;
        }
        counter++;
    }

    ArrayLength = HamstersQuantity * 2 + 2;
    int* HamstersArray = new int[ArrayLength];

    HamstersArray[0] = FoodAmount;
    HamstersArray[1] = HamstersQuantity;

    std::ifstream in_2(path);
    counter = 0;

    if (in_2.is_open())
    {
        while (getline(in_2, line))
        {
            if (counter >= 2) {
                int LineIndex = 0;             
                while (LineIndex < line.length())
                {
                    if (line[LineIndex] != ' ')
                        TemporaryString += line[LineIndex];
                    else
                    {
                        HamstersArray[counter] = stoi(TemporaryString);
                        TemporaryString.clear();
                    }
                    LineIndex++;
                }
                counter++;
                HamstersArray[counter] = stoi(TemporaryString);
                TemporaryString.clear();
            }
            counter++;
        }
    }
    in_2.close();

    return HamstersArray;
}

int main()
{
    Hamstr HamstersQuantity;            //об'єкт класу Hamstr

    string path = "hamstr_in.txt";

    int hamsters = HamstersQuantity.AmountOfHamsters(read_file(path));


    ofstream hamstr_out("hamstr_out.txt");
    hamstr_out << hamsters;
    hamstr_out.close();
}
