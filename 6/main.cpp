/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");
vector<int> fish;
// int justSpawned[100000];

int main()
{
    string line;
    getline(in, line);
    stringstream ss(line);

    for (int x; ss >> x;)
    {
        fish.push_back(x);
        ss.ignore();
    }

    int nrdays = 80;
    // int totalFish = 0;
    while (nrdays)
    {
        int fish_to_add = 0;
        for (int i = 0; i < fish.size(); i++)
        {
            fish[i]--;
            if (fish[i] < 0)
            {
                fish[i] = 6;
                fish_to_add ++;
            }
        }
        while (fish_to_add)
        {
            fish.push_back(8);
            fish_to_add --;
        }
        nrdays--;
    }

    cout << fish.size();

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");
vector<int> fish;
long long ans;

unordered_map<int, long long> m;

long long spanws_in_x_days(int total_days)
{
    if (total_days <= 0)
        return 0;

    if (m.find(total_days) != m.end())
        return m[total_days];

    long long ret = 0;
    int initial_days_cpy = total_days;
    while (total_days > 0)
    {
       ret += 1 + spanws_in_x_days(total_days - 9);
       total_days -= 7;
    }
    m[initial_days_cpy] = ret;

    return ret;
}

int main()
{
    string line;
    getline(in, line);
    stringstream ss(line);

    for (int x; ss >> x;)
    {
        fish.push_back(x);
        ss.ignore();
    }

    int nrdays = 256;
    // int totalFish = 0;
    for (int i = 0; i < fish.size(); i++)
    {
        ans += spanws_in_x_days(nrdays - fish[i]);
    }

    cout << ans + fish.size();

    return 0;
}
