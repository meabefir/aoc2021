/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

unordered_map<string, string> m;

int main()
{
    char first, last;
    string start;
    in >> start;
    first = start[0];
    last = start[start.size() - 1];
    string line;
    getline(in, line);
    getline(in, line);
    getline(in, line);

    while (line.size())
    {
        stringstream ss(line);
        string from, to;
        ss >> from >> to >> to;
        m[from] = to;

        getline(in, line);
    }

    vector<string> current_pairs;
    for (int i = 0; i < start.size() - 1; i++)
    {
        current_pairs.push_back(start.substr(i, 2));
    }

    int steps = 10;
    while (steps--)
    {
        vector<string> next_pairs;

        for (auto& s: current_pairs)
        {
            string middle = m[s];
            next_pairs.push_back(string(s[0] + middle));
            next_pairs.push_back(string(middle + s[1]));
        }
        current_pairs.swap(next_pairs);
    }

    unordered_map<char, unsigned long long> cnt;
    cnt[first] ++;
    cnt[last] ++;
    for (auto& s: current_pairs)
    {
        cnt[s[0]] ++;
        cnt[s[1]] ++;
    }

    int maxi = 0, mini = 10000000;

    for (auto& per: cnt)
    {
        if (per.second / 2 > maxi)
             maxi = per.second / 2;
        if (per.second / 2 < mini)
            mini = per.second / 2;
    }
    cout << maxi - mini;

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

unordered_map<string, string> m;

int main()
{
    char first, last;
    string start;
    in >> start;
    first = start[0];
    last = start[start.size() - 1];
    string line;
    getline(in, line);
    getline(in, line);
    getline(in, line);

    while (line.size())
    {
        stringstream ss(line);
        string from, to;
        ss >> from >> to >> to;
        m[from] = to;

        getline(in, line);
    }

    unordered_map<string, unsigned long long> current_m;
    for (int i = 0; i < start.size() - 1; i++)
    {
        current_m[start.substr(i, 2)] ++;
    }

    int steps = 40;
    while (steps--)
    {
        unordered_map<string, unsigned long long> next_m;

        for (auto& per: current_m)
        {
            string middle = m[per.first];
            next_m[string(per.first[0] + middle)] += per.second;
            next_m[string(middle + per.first[1])] += per.second;
        }
        current_m.swap(next_m);
    }

    unordered_map<char, unsigned long long> cnt;
    cnt[first] ++;
    cnt[last] ++;
    for (auto& per: current_m)
    {
        cnt[per.first[0]] += per.second;
        cnt[per.first[1]] += per.second;
    }

    unsigned long long maxi = 0, mini = 1e12;

    for (auto& per: cnt)
    {
        if (per.second / 2 > maxi)
             maxi = per.second / 2;
        if (per.second / 2 < mini)
            mini = per.second / 2;
    }
    cout << maxi - mini;

    return 0;
}
