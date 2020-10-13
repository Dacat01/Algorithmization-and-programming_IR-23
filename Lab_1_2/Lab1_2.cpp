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

    void heapify(int arr[], int n, int i, string name[])
    {
        int smallest = i; // Initialize smalles as root 
        int l = 2 * i + 1; // left = 2*i + 1 
        int r = 2 * i + 2; // right = 2*i + 2 

        count_compare++;
        // If left child is smaller than root 
        if (l < n && arr[l] < arr[smallest])
            smallest = l;

        count_compare++;
        // If right child is smaller than smallest so far 
        if (r < n && arr[r] < arr[smallest])
            smallest = r;

        count_compare++;
        // If smallest is not root 
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            swap(name[i], name[smallest]);
            count_change++;
            // Recursively heapify the affected sub-tree 
            heapify(arr, n, smallest, name);         
        }
    }


    void heapSort(int arr[], int n, string name[])
    {
        // Build heap 
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, name);

        // One by one extract an element from heap 
        for (int i = n - 1; i >= 0; i--) {
            // Move current root to end 
            swap(arr[0], arr[i]);
            swap(name[0], name[i]);
            count_change++;
            // call max heapify on the reduced heap 
            heapify(arr, i, 0, name);
        }
    }

};
//*------------------------


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

    myObj.heapSort(quantity, j, name);


    // Get ending timepoint 
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Algorithm name : HeapSort\n";
    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
    cout << "Quantity of comparison operations: " << myObj.count_compare << endl;
    cout << "Quantity of change operations: " << myObj.count_change << endl;
    cout << "Results: \n";
    /*
    for (char i = 0; i < j; i++)
        std::cout << quantity[i] << "\n";
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
