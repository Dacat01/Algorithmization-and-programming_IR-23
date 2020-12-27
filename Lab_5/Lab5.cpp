#include <iostream>
#include <vector>
using namespace std;

vector<int> KMP(string line, string pattern)
{
    vector<int> table(pattern.size() + 1, -1);
    vector<int> matches;
    int line_position = 0;          //the position of the current character in line
    int pattern_position = 0;       //the position of the current character in pattern
    int pos;

    if (pattern.size() == 0)
    {
        matches.push_back(-1);
        return matches;
    }


    for (int i = 1; i <= pattern.size(); i++)
    {
        pos = table[i - 1];

        while (pos != -1 && pattern[pos] != pattern[i - 1])
            pos = table[pos];

        table[i] = pos + 1;     

 //       cout << "T[i]: " << table[i] << endl;
    }

    while (line_position < line.size())
    {
        if (pattern[pattern_position] == line[line_position])
        {
            line_position++;
            pattern_position++;
      
            if (pattern_position == pattern.size())
            {
                matches.push_back(line_position - pattern_position);
                pattern_position = table[pattern_position];   
            }
        }
        else 
        {
            pattern_position = table[pattern_position];
            if (pattern_position < 0)
            {
                line_position++;
                pattern_position++;
            }
        }

    }

    return matches;
}

int main()
{
    string str = "abcabcdAAAABAAAAabcabcdABBBAAAABabcabcd";
    string patt = "abcabcd";

    vector<int> results = KMP(str, patt);

    for (int i = 0; i < results.size(); i++) {
        cout << "Pattern found at location: " << results[i] << endl;
    }
}