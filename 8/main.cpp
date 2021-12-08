/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

int main()
{
    int ans = 0;
    string s;
    while (in >> s)
    {
        for (int i = 1; i <= 10; i++)
            in >> s;
        for (int i = 1; i <= 4; i++)
        {
            in >> s;
            if (s.size() == 2 || s.size() == 4 || s.size() == 7 || s.size() == 3)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<vector<int>> digits = { { 1, 1, 1, 0, 1, 1, 1 },
                          { 0, 0, 1, 0, 0, 1, 0 },
                          { 1, 0, 1, 1, 1, 0, 1 },
                          { 1, 0, 1, 1, 0, 1, 1 },
                          { 0, 1, 1, 1, 0, 1, 0 },
                          { 1, 1, 0, 1, 0, 1, 1 },
                          { 1, 1, 0, 1, 1, 1, 1 },
                          { 1, 0, 1, 0, 0, 1, 0 },
                          { 1, 1, 1, 1, 1, 1, 1 },
                          { 1, 1, 1, 1, 0, 1, 1 },
                           };

unordered_map<char, int> char_count;
unordered_map<char, int> char_pos;


char getUniqueChar(string& s1, string& s2)
{
    unordered_map<char, int> m;
    for (auto c: s1)
        m[c] ++;
    for (auto c: s2)
        m[c] ++;
    for (auto& per: m)
    {
        if (per.second == 1)
            return per.first;
    }
}

vector<int> createDigitArray(string s)
{
    vector<int> arr(7, 0);
    for (char c: s)
    {
        arr[char_pos[c]] = 1;
    }
    return arr;
}

int getNumberFromDigitArray(vector<int>& d_array)
{
    for (int i = 0; i < digits.size(); i++)
    {
        if (digits[i] == d_array)
            return i;
    }
    return -1;
}

int main()
{
    int ans = 0;
    string row;
    getline(in, row);
    while (row.size())
    {
        char_pos.clear();
        char_count.clear();

        vector<string> code;
        vector<string> decode;
        stringstream ss(row);
        for (int i = 1; i <= 10; i++)
        {
            string s;
            ss >> s;
            code.push_back(s);

            for (auto c: s)
            {
                char_count[c] ++;
            }
        }
        ss.ignore();
        ss.ignore();
        for (int i = 1; i <= 4; i++)
        {
            string s;
            ss >> s;
            decode.push_back(s);
        }

        // for 6, 4 and 9 we can directly link them to their respective position
        for (auto& per: char_count)
        {
            // cout << per.first << ' ' << per.second << '\n';
            switch (per.second)
            {
            case 4:
                char_pos[per.first] = 4;
                break;
            case 6:
                char_pos[per.first] = 1;
                break;
            case 9:
                char_pos[per.first] = 5;
                break;
            case 8:
                {
                    // if already computed break
                    if (char_pos.find(per.first) != char_pos.end())
                        break;
                    // in this case we have 2 values that are encountered 7 times
                    // we need the string with length 2 and the string with length 3 aka 1 and 7
                    string s1;
                    string s7;
                    for (auto s: code)
                    {
                        if (s.size() == 2)
                            s1 = s;
                        else if (s.size() == 3)
                            s7 = s;
                    }
                    char unique_char = getUniqueChar(s1, s7);
                    // cout << " unique " << unique_char << " " << per.first << '\n';
                    char_pos[unique_char] = 0;
                    // set the other one with the same value of aparitions to index 2
                    for (auto& per2: char_count)
                    {
                        if (per2.second == per.second && per2.first != unique_char)
                            char_pos[per2.first] = 2;
                    }
                    break;
                }
            case 7:
                {
                    // if already computed break
                    if (char_pos.find(per.first) != char_pos.end())
                        break;
                    // we can check if this char appears in the representation of 4, if it does, it's the middle segment
                    string s4;
                    for (auto s: code)
                    {
                        if (s.size() == 4)
                            s4 = s;
                    }
                    int found_in_4 = 0;
                    for (auto c: s4)
                        if (c == per.first)
                        {
                            found_in_4 = 1;
                            // means that is the middle segment
                            char_pos[per.first] = 3;
                            // set the other one with the same value of aparitions to index 6
                            for (auto& per2: char_count)
                            {
                                if (per2.second == per.second && per2.first != per.first)
                                    char_pos[per2.first] = 6;
                            }
                            break;
                        }
                    if (!found_in_4)
                    {
                        char_pos[per.first] = 6;
                        // set the other one with the same value of aparitions to index 6
                        for (auto& per2: char_count)
                        {
                            if (per2.second == per.second && per2.first != per.first)
                                char_pos[per2.first] = 3;
                        }
                    }

                    break;
                }

            }
        }

        //for (auto per: char_count)
        //    cout << per.first << ' ' << per.second << '\n';

        int current_nr = 0;
        for (auto& s: decode)
        {
            //cout << s << ' ';
            vector<int> digit_array = createDigitArray(s);
            //for (int ii: digit_array)
            //    cout << ii << ' ';
            //cout << '\n';
            int nr = getNumberFromDigitArray(digit_array);
            current_nr = current_nr * 10 + nr;
        }
        //cout << '\n';
        cout << current_nr << '\n';
        //cout << "\n\n";
        ans += current_nr;

        getline(in, row);
    }

    cout << ans;

    return 0;
}

