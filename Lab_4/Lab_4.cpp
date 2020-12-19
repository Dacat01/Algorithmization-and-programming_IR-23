#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <list>
#include <iterator>
#include <vector>
using namespace std;


class Fantazer
{
public:
    std::vector< string > result;

 //   string result[100];
    int counter = 0;

    int final_result = 0;
    /*
        if (str.compare(0, length, bin_str) == 0)  //Чи співпадає 
        std::cout << "123" << endl;

    std::cout << str << endl;

    str = str.substr(length);               //Обрізати str
    std::cout << str << endl;

    */

 //   std::cout << myObj.result.size() << endl;

    void check_string(string STR)
    {

/*
        for (int i = result.size() - 1; i < 0; i--)
        {
            std::size_t found = STR.find(result[i]);
            if (found = std::string::npos)
                result.pop_back();
        }
*/

        int tmp = result.size()-1;
//        cout << "STR =  " << STR << endl;
//        cout <<"STR.length() =  "<< STR.length() << endl;

 //       cout << "result 0 = " << result[0] << endl;
 //       cout << "result 1 = " << result[1] << endl;
/*
        cout << "result 1 = " << result[tmp] << endl;
        cout << "result[tmp].length() = " << result[tmp].length() << endl;

        if (STR.compare(0, result[tmp].length(), result[tmp])==0)
            cout << "------------- = " << STR.length() << endl;
 */




        while (STR.length() != 0)
        {
 

            if (STR.compare(0, result[tmp].length(), result[tmp]) == 0)  //Чи співпадає 
            {
                cout << "-------------"  << endl;

                final_result++;

                cout << "Str = " << STR << endl;

                STR.erase(0, result[tmp].length());

 //               cout << "result[tmp].length() = " << result[tmp].length() << endl;

                cout << "Str = " << STR << endl;

                cout << "STR.length() =  " << STR.length() << endl;
                tmp = result.size() - 1;
            }
            else
            {
                tmp--;
            }

            








/*
            if (tmp == -1)
                return;
            cout << "counter = " << counter << endl;
            cout << "tmp = " << tmp << endl;

            if (STR.compare(0, result[tmp].length(), result[tmp]) == 0)  //Чи співпадає 
            {
                final_result++;
                tmp = counter;
                cout << "Str = " << STR << endl;
                STR = STR.substr(0, result[tmp].length());
                cout << "result[tmp].length() = " << result[tmp].length() << endl;
                cout << "Str = " << STR << endl;
            }
   */



 //           tmp --;
        }
    }


    void count_power(int length, int N)
        {
            int tmp;
            int pow_len = 0;
            int bin;
            string bin_str;


            int a = 0;
            while (length >= pow_len)
            {
                a++;
                if (a == 5)
                    return;
                tmp = pow(N, counter);

                while (tmp > 0)
                {
                    bin = tmp % 2;
                    bin_str += to_string(bin);
                    tmp /= 2;
                }
                pow_len = bin_str.length();
                 
                if (length >= pow_len)
                {

                    reverse(bin_str.begin(), bin_str.end());

                    result.push_back(bin_str);        //Занести bin_str у масив

                    bin_str = "";

                    //               cout << "counter = " << counter << endl;

                    counter++;
                }
            }
        }

    };



int main()
{
    string input_data = "111111011101";
    //  1, 1111101, 1, 101,
    int N = 5;
    
    Fantazer myObj;
    
    input_data = "11111010001111101000110010011001001100100110010011001001111101000"; //2
    N = 10;

    myObj.count_power(input_data.length(), N);


      myObj.check_string(input_data);
    std::cout <<"result = "<< myObj.final_result << endl << endl;


   
    std::cout << myObj.result[0] << endl;
    std::cout << myObj.result[1] << endl;

    /*
    std::cout << myObj.result[2] << endl;
    std::cout << myObj.result[3] << endl;
    std::cout << myObj.result[4] << endl;
    std::cout << myObj.result[5] << endl;
    std::cout << myObj.result[6] << endl;
    */
/*

    if (str.compare(0, length, bin_str) == 0)  //Чи співпадає 
        std::cout << "123" << endl;

    std::cout << str << endl;

    str = str.substr(length);               //Обрізати str
    std::cout << str << endl;

    */
    //        std::cout << "reversed:  " << bin_str << endl;

     //  }


     //   std::string str2 = str.substr(0, 1);     // "think"

    //    std::cout << str2;

}
