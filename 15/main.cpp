/*
#include <iostream>
#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

ifstream in("in.in");

vector<vector<int>> m;
vector<pair<int, int>> la[10000];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dist[10000];
int viz[10000];

int main()
{
    string line;
    getline(in, line);
    while (line.size())
    {
        vector<int> new_line;
        for (char c: line)
        {
            new_line.push_back((int)c - 48);
        }
        m.push_back(new_line);

        getline(in, line);
    }

    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m.size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                pair<int, int> neigh = {i+dy[k], j+dx[k]};
                if (neigh.first < 0 || neigh.first >= m.size() || neigh.second < 0 || neigh.second >= m.size())
                    continue;
                int my_idx = i * m.size() + j;
                int neigh_idx = neigh.first * m.size() + neigh.second;

                la[my_idx].push_back({neigh_idx, m[neigh.first][neigh.second]});
            }
        }
    }

    for (int i = 1; i < m.size() * m.size(); i++)
        dist[i] = inf;
    priority_queue<pair<int, int>> q;
    q.push({0, 0});

    while (q.size())
    {
        int from = q.top().second;
        q.pop();

        if (viz[from])
            continue;
        viz[from] = 1;

        for (auto& per: la[from])
        {
            auto [to, cost] = per;
            if (dist[from] + cost < dist[to])
            {
                dist[to] = dist[from] + cost;
                q.push({-dist[to], to});
            }
        }
    }

    cout << dist[m.size() * m.size() - 1] << ' ';

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

ifstream in("in.in");

vector<vector<int>> m;
vector<pair<int, int>> la[250000];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dist[250000];
int viz[250000];

int main()
{
    string line;
    getline(in, line);
    while (line.size())
    {
        vector<int> new_line;
        for (char c: line)
        {
            new_line.push_back((int)c - 48);
        }
        m.push_back(new_line);

        getline(in, line);
    }

    for (int mrow = 0; mrow < 5; mrow++)
    {
        for (int mcol = 0; mcol < 5; mcol++)
        {
            for (int i = 0; i < m.size(); i++)
            {
                for (int j = 0; j < m.size(); j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        pair<int, int> neigh = {i+dy[k], j+dx[k]};
                        if (neigh.first < 0 || neigh.first >= m.size() * 5 || neigh.second < 0 || neigh.second >= m.size() * 5)
                            continue;
                        int my_idx = (mrow * m.size() + i) * (m.size() * 5) + j + mcol * m.size();
                        int neigh_idx = (mrow * m.size() + neigh.first) * (m.size() * 5) + neigh.second + mcol * m.size();

                        // took me a while
                        // we have to check if we cross a "border"
                        int neigh_row = mrow, neigh_col = mcol;
                        if (dy[k] == 1 && neigh.first % m.size() < i)
                            neigh_row++;
                        if (dy[k] == -1 && neigh.first % m.size() > i)
                            neigh_row--;
                        if (dx[k] == 1 && neigh.second % m.size() < j)
                            neigh_col++;
                        if (dx[k] == -1 && neigh.second % m.size() > j)
                            neigh_col--;

                        int neigh_val = m[neigh.first % m.size()][neigh.second % m.size()] + neigh_row + neigh_col;
                        if (neigh_val > 9)
                            neigh_val -= 9;
                        // cout << neigh_val << ' ';
                        la[my_idx].push_back({neigh_idx, neigh_val});
                    }
                }
            }
        }
    }

    for (int i = 1; i < m.size() * m.size() * 5 * 5; i++)
        dist[i] = inf;
    priority_queue<pair<int, int>> q;
    q.push({0, 0});

    while (q.size())
    {
        int from = q.top().second;
        q.pop();

        if (viz[from])
            continue;
        viz[from] = 1;

        for (auto& per: la[from])
        {
            auto [to, cost] = per;
            if (dist[from] + cost < dist[to])
            {
                dist[to] = dist[from] + cost;
                q.push({-dist[to], to});
            }
        }
    }

    cout << dist[m.size() * m.size() * 5 * 5 - 1] << ' ';

    return 0;
}
