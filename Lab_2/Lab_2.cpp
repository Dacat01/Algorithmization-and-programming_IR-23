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

    int  id(int a)                     //Знаходження розташування елемента
    {
        return a / 2 - 1;
    }

    int Largest(int arr[], int counter) //Знаходження найбільшого елемента
    {

        int largest = arr[0], k = 2;

        for (int i = 1; i < counter; i++)
        {
            if (largest <= arr[i])
            {
                largest = arr[i];
                k += 2;
            }
        }

        return k;
    }


    int Quantity(int arr[])
    {

        int S = arr[0]; //ЗАПАС ЇЖІ
        int C = arr[1]; //КІЛЬКІСТЬ ХОМ'ЯКІВ

        int i,j,x = 0, counter = C;
     
        for (i = 2; i < C * 2 + 2; i += 2)      // Чи можу прогодувати "C" хом'ячків
            x += arr[i] + arr[i + 1] * (counter - 1);
        if (x <= S)
            return counter;

        x = 0;
        counter--;

        while (counter > 1)                     // Чи можу прогодувати від "C - 1" до 2 хом'ячків
        {
            int* tmp_array = new int[counter];
            j = 2;

            for (i = 0; i < C; i++)
            {
                if (i < counter)
                    tmp_array[i] = arr[j] + arr[j + 1] * (counter-1);

                else
                {
                    int tmp = Largest(tmp_array, counter);
                    int food = arr[j] + arr[j + 1] * (counter-1);

                    if (arr[tmp] + arr[tmp + 1] * (counter - 1) > food)
                        tmp_array[id(tmp)] = food;
                    
                }
                j += 2;
            }

/*
            cout << "-----------" << endl;
            for (i = 0; i < counter; i++)
            {
                cout << tmp_array[i] << endl;
            }
            cout << "-----------" << endl;
*/


            for (i = 0; i < counter; i++)
                x += tmp_array[i];
            if (x <= S)
                return counter;

            x = 0;
            counter--;
            delete[] tmp_array;

        }

        for (i = 2; i < C * 2 + 2; i += 2)      // Чи можу прогодувати 1 хом'ячка
        {
            x = arr[i];
            if (x <= S)
                return counter;
        }

        return 0;                               // Якщо не можу прогодувати ні 1 хом'ячка
    }
};
//------------------------------------------------------------------


int main()
{
    Hamstr myObj;

    string path = "hamstr_in.txt";

    std::string line;

    std::ifstream in(path);

    int i = 0, j, length_;
    int mas1[2];

    string tmp;

    if (in.is_open())
    {
        while (i < 2)
        {
            getline(in, line);


            mas1[i] = stoi(line);       //Зчитування перших двох рядків у масив 
            i++;
        }
    }
    in.close();

    int mas_length = mas1[1] * 2 + 2;

    int* array = new int[mas_length];
    array[0] = mas1[0];
    array[1] = mas1[1];
    i = 0;


    std::ifstream in_2(path);
    if (in_2.is_open())
    {
        while (getline(in_2, line))
        {

            if (i < 2)
            {
            }
            else {
                length_ = line.length();
                j = 0;


                while (j < length_)
                {


                    if (line[j] != ' ')
                        tmp += line[j];
                    else {
                        array[i] = stoi(tmp);
                        tmp.clear();
                    }

                    j++;
                }
                i++;
                array[i] = stoi(tmp);
                tmp.clear();
            }
            i++;
        }

    }
    in_2.close();
    //---------------------------------------------------------------------



    int x = myObj.Quantity(array);

    delete[] array;

    ofstream hamstr_out("hamstr_out.txt");

    hamstr_out << x;
    hamstr_out.close();
}
