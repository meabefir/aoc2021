/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<vector<int>> mapp;

bool isLowPoint(int row, int col)
{
    int val = mapp[row][col];

    if (row - 1 != -1)
        if (mapp[row-1][col] <= val)
            return false;
    if (row + 1 != mapp.size())
        if (mapp[row+1][col] <= val)
            return false;
    if (col - 1 != -1)
        if (mapp[row][col-1] <= val)
            return false;
    if (col + 1 != mapp[0].size())
        if (mapp[row][col+1] <= val)
            return false;
    return true;
}

int main()
{
    string row;
    getline(in, row);

    while (row.size())
    {
        vector<int> mapp_row;
        for (char c: row)
        {
            mapp_row.push_back((int)c - 48);
        }
        mapp.push_back(mapp_row);

        getline(in, row);
    }

    int ans = 0;
    for (int row = 0; row < mapp.size(); row++)
    {
        for (int col = 0; col < mapp[0].size(); col++)
        {
            if (isLowPoint(row, col))
            {
                ans += 1 + mapp[row][col];
            }
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

vector<vector<int>> mapp;

bool isLowPoint(int row, int col)
{
    int val = mapp[row][col];

    if (row - 1 != -1)
        if (mapp[row-1][col] <= val)
            return false;
    if (row + 1 != mapp.size())
        if (mapp[row+1][col] <= val)
            return false;
    if (col - 1 != -1)
        if (mapp[row][col-1] <= val)
            return false;
    if (col + 1 != mapp[0].size())
        if (mapp[row][col+1] <= val)
            return false;
    return true;
}

int d_row[] = {-1, 0, 1, 0};
int d_col[] = {0, -1, 0, 1};

int getBasinSize(int row, int col)
{
    int nr = 0;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (q.size())
    {
        pair<int, int> poz_curenta = q.front();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> poz_vecin({poz_curenta.first + d_row[i], poz_curenta.second + d_col[i]});
            if (poz_vecin.first < 0 || poz_vecin.first >= mapp.size() || poz_vecin.second < 0 || poz_vecin.second >= mapp[0].size())
                continue;
            if (mapp[poz_vecin.first][poz_vecin.second] == 9)
                continue;
            nr ++;
            mapp[poz_vecin.first][poz_vecin.second] = 9;
            q.push({poz_vecin.first, poz_vecin.second});
        }

        q.pop();
    }
    return nr;
}

int main()
{
    string row;
    getline(in, row);

    while (row.size())
    {
        vector<int> mapp_row;
        for (char c: row)
        {
            mapp_row.push_back((int)c - 48);
        }
        mapp.push_back(mapp_row);

        getline(in, row);
    }

    vector<int> basin_size;
    for (int row = 0; row < mapp.size(); row++)
    {
        for (int col = 0; col < mapp[0].size(); col++)
        {
            if (isLowPoint(row, col))
            {
                basin_size.push_back(getBasinSize(row, col));
            }
        }
    }
    sort(basin_size.begin(), basin_size.end());
    reverse(basin_size.begin(), basin_size.end());
    int p = basin_size[0] * basin_size[1] * basin_size[2];
    cout << p;

    return 0;
}
