/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> char_value = { {')', 3}, {']', 57}, {'}', 1197}, {'>', 25137} };
unordered_map<char, char> char_map = { {')', '('}, {']', '['}, {'}', '{'}, {'>', '<'} };

ifstream in("in.in");

int main()
{
    string line;
    getline(in, line);
    int ans = 0;
    while (line.size())
    {
        stack<char> st;
        for (auto c: line)
        {
            if (char_map.find(c) != char_map.end())
            {
                // legal
                if (st.top() == char_map[c])
                    st.pop();
                else
                {
                    // primul caracter ilegal
                    ans += char_value[c];
                    goto escape;
                }
            }
            else
                st.push(c);
        }

        escape:
        getline(in, line);
    }
    cout << ans;

    return 0;
}
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> char_value = { {')', 3}, {']', 57}, {'}', 1197}, {'>', 25137} };
unordered_map<char, char> char_map = { {')', '('}, {']', '['}, {'}', '{'}, {'>', '<'} };
unordered_map<char, char> char_map_reversed = { {'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'} };

ifstream in("in.in");

int main()
{
    vector<unsigned long long> nrs;
    string line;
    getline(in, line);
    int ans = 0;
    while (line.size())
    {
        unsigned long long current_score;
        stack<char> st;
        for (auto c: line)
        {
            if (char_map.find(c) != char_map.end())
            {
                // legal
                if (st.top() == char_map[c])
                    st.pop();
                else
                {
                    goto escape;
                }
            }
            else
                st.push(c);
        }

        // if here all went good
        current_score = 0;
        while (st.size())
        {
            current_score *= 5;
            char matching_char = char_map_reversed[st.top()];
            switch(matching_char)
            {
                case ')':
                   current_score += 1;
                   break;
                case ']':
                   current_score += 2;
                   break;
               case '}':
                   current_score += 3;
                   break;
               case '>':
                   current_score += 4;
                   break;
            }
            st.pop();
        }
        nrs.push_back(current_score);
        cout << current_score << '\n';

        escape:
        getline(in, line);
    }
    sort(nrs.begin(), nrs.end());
    cout << nrs[nrs.size() / 2];

    return 0;
}
