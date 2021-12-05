/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<string> strings;
string s_curent;

string gamma, epsilon;

int makeIntFromBinary(string s)
{
    int pow_2 = 0;
    int nr = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            nr += pow(2, pow_2);
        pow_2 ++;
    }
    return nr;
}

int main()
{
    while (in >> s_curent)
    {
        strings.push_back(s_curent);
    }

    for (int i = 0; i < s_curent.size(); i++)
    {
        int nr1 = 0, nr0 = 0;
        for (string s: strings)
        {
            if (s[i] == '1')
                nr1 ++;
            else
                nr0 ++;
        }

        if (nr1 > nr0)
        {
            gamma += "1";
            epsilon += "0";
        }
        else
        {
            gamma += "0";
            epsilon += "1";
        }

    }

    int gamma_int = makeIntFromBinary(gamma);
    int eps_int = makeIntFromBinary(epsilon);

    cout << gamma_int * eps_int;

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<string> strings;
vector<string> strings2;
string s_curent;

string o2, co2;

int makeIntFromBinary(string s)
{
    int pow_2 = 0;
    int nr = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            nr += pow(2, pow_2);
        pow_2 ++;
    }
    return nr;
}

int main()
{
    while (in >> s_curent)
    {
        strings.push_back(s_curent);
        strings2.push_back(s_curent);
    }

    for (int i = 0; i < s_curent.size(); i++)
    {
        int nr1_o2 = 0, nr0_o2 = 0, nr1_co2 = 0, nr0_co2 = 0;
        for (string s: strings)
        {
            if (s[i] == '1')
                nr1_o2 ++;
            else
                nr0_o2 ++;
        }
        for (string s: strings2)
        {
            if (s[i] == '1')
                nr1_co2 ++;
            else
                nr0_co2 ++;
        }

        char most_wanted_bit_o2;
        char most_wanted_bit_co2;
        if (nr0_o2 > nr1_o2)
            most_wanted_bit_o2 = '0';
        else
            most_wanted_bit_o2 = '1';

        if (nr1_co2 >= nr0_co2)
            most_wanted_bit_co2 = '0';
        else
            most_wanted_bit_co2 = '1';

        if (strings.size() > 1)
            strings.erase(remove_if(strings.begin(), strings.end(), [=](string s){ return (s[i] != most_wanted_bit_o2);} ), strings.end());
        if (strings2.size() > 1)
            strings2.erase(remove_if(strings2.begin(), strings2.end(), [=](string s){ return (s[i] != most_wanted_bit_co2);} ), strings2.end());

        cout << strings.size() << ' ' << strings2.size() << '\n';
    }

    cout << strings[0] << ' ' << strings2[0] << '\n';
    cout << makeIntFromBinary(strings[0]) * makeIntFromBinary(strings2[0]);

    return 0;
}


