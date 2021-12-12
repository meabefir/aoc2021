/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<vector<int>> board;
int total_flashes = 0;

int main()
{
    string line;
    getline(in, line);
    while (line.size())
    {
        vector<int> row;
        for (char c: line)
            row.push_back((int)c - 48);
        board.push_back(row);

        getline(in, line);
    }

    vector<vector<int>> flashed(board.size(), vector<int>(board[0].size(), 0));

    int steps = 100;
    while (steps --)
    {
        flashed = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        for (auto& row: board)
        {
            for (auto& el: row)
                el++;
        }
        vector<pair<int, int>> to_check;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] > 9)
                {
                    to_check.push_back({i, j});
                    flashed[i][j] = 1;
                }
        }

        for (int k = 0; k < to_check.size(); k++)
        {
            auto current = to_check[k];

            for (int ii = -1; ii <= 1; ii++)
            {
                for (int jj = -1; jj <= 1; jj++)
                {
                    pair<int, int> neigh = {current.first + ii, current.second + jj};
                    if (jj == 0 && ii == 0)
                        continue;
                    if (neigh.first < 0 || neigh.first >= board.size() || neigh.second < 0 || neigh.second >= board[0].size())
                        continue;

                    board[neigh.first][neigh.second] ++;
                    if (board[neigh.first][neigh.second] > 9 && !flashed[neigh.first][neigh.second])
                    {
                        to_check.push_back(neigh);
                        flashed[neigh.first][neigh.second] = 1;
                    }
                }
            }
        }

        total_flashes += to_check.size();

        for (auto& per: to_check)
        {
            board[per.first][per.second] = 0;
        }

        #if 0
        for (auto& row: board)
        {
            for (auto el: row)
                cout << el << ' ';
            cout << '\n';
        }
        cout << "\n\n";
        #endif // 0
    }

    cout << total_flashes;

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<vector<int>> board;

int main()
{
    string line;
    getline(in, line);
    while (line.size())
    {
        vector<int> row;
        for (char c: line)
            row.push_back((int)c - 48);
        board.push_back(row);

        getline(in, line);
    }

    vector<vector<int>> flashed(board.size(), vector<int>(board[0].size(), 0));

    int step = 0;
    while (++ step)
    {
        flashed = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        for (auto& row: board)
        {
            for (auto& el: row)
                el++;
        }
        vector<pair<int, int>> to_check;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] > 9)
                {
                    to_check.push_back({i, j});
                    flashed[i][j] = 1;
                }
        }

        for (int k = 0; k < to_check.size(); k++)
        {
            auto current = to_check[k];

            for (int ii = -1; ii <= 1; ii++)
            {
                for (int jj = -1; jj <= 1; jj++)
                {
                    pair<int, int> neigh = {current.first + ii, current.second + jj};
                    if (jj == 0 && ii == 0)
                        continue;
                    if (neigh.first < 0 || neigh.first >= board.size() || neigh.second < 0 || neigh.second >= board[0].size())
                        continue;

                    board[neigh.first][neigh.second] ++;
                    if (board[neigh.first][neigh.second] > 9 && !flashed[neigh.first][neigh.second])
                    {
                        to_check.push_back(neigh);
                        flashed[neigh.first][neigh.second] = 1;
                    }
                }
            }
        }

        if (to_check.size() == board.size() * board.size())
        {
            cout << step;
            return 0;
        }

        for (auto& per: to_check)
        {
            board[per.first][per.second] = 0;
        }
    }

    return 0;
}
