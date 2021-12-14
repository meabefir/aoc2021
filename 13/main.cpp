#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, int, hash_pair> m;

template<class T>
void test(T t){
    cout << typeid(t).name();
}

int main()
{
    string line;
    getline(in, line);
    while (line.size())
    {
        int row, col;
        stringstream ss(line);
        ss >> col;
        ss.ignore();
        ss >> row;

        m[{row, col}] = 1;

        getline(in, line);
    }

    getline(in, line);
    while (line.size())
    {
        stringstream ss(line);
        ss >> line >> line;
        char dir;
        int poz;
        ss >> dir;
        ss.ignore();
        ss >> poz;

        if (dir == 'y')
        {
            for (auto& per: m)
            {
                if (per.second == -1)
                    continue;
                auto [row, col] = per.first;
                if (row < poz)
                    continue;
                pair<int, int> mirror = {poz - (row - poz), col};
                m[mirror] ++;
                per.second = -1;
            }
        }
        else if (dir == 'x')
        {
            for (auto& per: m)
            {
                if (per.second == -1)
                    continue;
                auto [row, col] = per.first;
                if (col < poz)
                    continue;
                pair<int, int> mirror = {row, poz - (col - poz)};
                m[mirror] ++;
                per.second = -1;
            }
        }
        getline(in, line);
    }

    int max_row = 0, max_col = 0;
    for (auto& per: m)
    {
        if (per.second == -1)
            continue;
        auto [row, col] = per.first;
        if (row > max_row)
            max_row = row;
        if (col > max_col)
            max_col = col;
    }
    int mat[max_row+1][max_col+1];
    for (auto& per: m)
    {
        if (per.second == -1)
            continue;
        auto [row, col] = per.first;
        if (row < 0 || col < 0)
            continue;
        mat[row][col] = 1;
    }
    for (int i = 0; i < max_row+1; i ++)
    {
        for (int j = 0; j < max_col+1; j ++)
        {
            if (mat[i][j] == 1)
                cout << "$";
            else
                cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
