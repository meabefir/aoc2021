/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<int> nrs;

int main()
{
    string line;
    in >> line;
    stringstream ss(line);
    for (int i; ss >> i;)
    {
        nrs.push_back(i);
        ss.ignore();
    }

    sort(nrs.begin(), nrs.end());

    int mediana = nrs[nrs.size() / 2];
    if (nrs.size() % 2 == 0)
        mediana = (mediana + nrs[(nrs.size() + 1) / 2]) / 2;
    int cost = 0;

    for (int nr: nrs)
        cost += abs(mediana - nr);
    cout << cost;

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<int> nrs;

int main()
{
    string line;
    in >> line;
    stringstream ss(line);
    for (int i; ss >> i;)
    {
        nrs.push_back(i);
        ss.ignore();
    }

    sort(nrs.begin(), nrs.end());

    int cost_minim = 999999999;
    for (int i = nrs[0]; i <= nrs[nrs.size() - 1]; i++)
    {
        int cost_curent = 0;
        for (int nr: nrs)
        {
            int dif = abs(i - nr);
            cost_curent += (dif * (dif+1)) / 2;
        }
        if (cost_curent < cost_minim)
            cost_minim = cost_curent;
    }

    cout << cost_minim;

    return 0;
}
