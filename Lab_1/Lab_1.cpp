// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
class Zoo
{
public:
    int count_compare = 0, count_change = 0;

    void insertionSort(int arr[], int n, string name[])
    {
        int i, key, j;
        string key_1;

        for (i = 1; i < n; i++)
        {
            key = arr[i];
            key_1 = name[i];
            j = i - 1;

            /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                name[j + 1] = name[j];
                count_compare++;
                count_change++;
                j--;
            }
            arr[j + 1] = key;
            name[j + 1] = key_1;
            count_change++;
        }


    }

};

//---------------------------------
int main()
{
    Zoo myObj;      // Creating object of class Zoo
    // Get starting timepoint 
    auto start = high_resolution_clock::now();

    int visitors[50];
    int quantity[50];
    string name[50];


    int i = 0, j = 0;
    string tmp;
    char ch = ' ';

    string path = "data.csv";   //Name 
    ifstream fin;
    fin.open(path);             //Open file

    if (!fin.is_open())         //If file is not opened
    {
        std::cout << "File open error";
        return 0;
    }

    while (!fin.eof())		//While we don't reach the end of file 
    {
        fin.get(ch);		//Get one char

        if (ch != ',')		//If char is not  "dividing" symbol
        {
            if (!fin.eof()) //if we don't reach the end of file 
                tmp += ch;

            if (fin.eof())  //If we reach the end of file put last value in last array (to protect from duplicating)
                quantity[j] = stoi(tmp);

        }
        else
        {
            if (i == 0)		//String --> array1
            {
                visitors[j] = stoi(tmp);
                i++;

            }
            else if (i == 1)//String --> array2
            {
                name[j] = tmp;
                i++;

            }
            else if (i == 2)//String --> array3
            {
                quantity[j] = stoi(tmp);
                i = 0;
                j++;

            }

            tmp.clear();	//Clear string 
        }

    }
    j++;                    // values counter in array 
    fin.close();            //Close file
    //---------------END---------------
    /*
    for (char i = 0; i < j; i++)
        std::cout << visitors[i] << "\n";
    */


    myObj.insertionSort(visitors, j, name);


    // Get ending timepoint 
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Algorithm name : Inserion\n";
    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
    cout << "Quantity of comparison operations: " << myObj.count_compare << endl;
    cout << "Quantity of change operations: " << myObj.count_change << endl;
    cout << "Results: \n";
    /*
    for (char i = 0; i < j; i++)
        std::cout << visitors[i] << "\n";
    */
    for (char i = 0; i < j; i++)
        std::cout << name[i] << "\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
