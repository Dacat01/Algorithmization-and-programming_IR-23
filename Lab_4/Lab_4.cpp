#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


class Fantazer
{
public:
    std::vector< string > binary_exponent_values;

    string sequence;
    int number;
    int result = 0;


    void check_string(void)
    {
        int id = binary_exponent_values.size() - 1;                                    // Set to highest value in vector 
   
        while (sequence.length() != 0)       
        {
            if (sequence.compare(0, binary_exponent_values[id].length(), binary_exponent_values[id]) == 0) // If first X characters is equal
            {
                result++;                                         

                sequence.erase(0, binary_exponent_values[id].length());                // delete first X characters 

                id = binary_exponent_values.size() - 1;                                // Set to highest value in vector 
            }
            else
            {
                id--;           

                if (id == -1)                                                       // If string can't be cutted in pieces
                {
                    result = -1;
                    return;
                }
            }
        }
    }


    void count_power( int length)
    {
        long long value=0;
        int counter = 0;
       
        string binary_string;
        bool bin;

        while (value < UINT_MAX)
        {
            value = pow(number, counter);
            counter++;

//            if (tmp > UINT_MAX)     
//               return;

            if (value < UINT_MAX)
            {
                while (value > 0)                                        // Decimal to Binary conversion start
                {
                    bin = value % 2;
                    binary_string += to_string(bin);
                    value /= 2;
                }
                reverse(binary_string.begin(), binary_string.end());    // Decimal to Binary conversion end

                if (sequence.find(binary_string) != std::string::npos)  // If bin_string is in given string
                    binary_exponent_values.push_back(binary_string);        

                binary_string = "";
            }
        }
    }


    void read_file(string path)
    {
        int  position = 0;

        std::string line;
        std::ifstream in(path);
        std::string delimiter = " ";

        if (in.is_open())
        {
            getline(in, line);

            if ((position = line.find(delimiter)) != std::string::npos)
            {
                sequence = line.substr(0, position);
                line.erase(0, position + delimiter.length());
                number = stoi(line);
            }

            in.close();
        }
    }


    void fantazer(string path)
    {
        read_file(path);
        count_power(sequence.length());
        check_string();

        std::cout << "result = " << result << endl << endl;
    }

};



int main()
{
    string path = "fantazer.txt";

    Fantazer myObj;
    
    myObj.fantazer(path);
   
}
