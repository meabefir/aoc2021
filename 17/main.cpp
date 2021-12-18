/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool intersects(pair<int, int>& who, pair<int, int>& tl, pair<int, int>& br)
{
    if (who.first >= tl.first && who.first <= br.first && who.second >= tl.second && who.second <= br.second)
        return true;
    return false;
}

int main()
{
    int bounds[2] = {-123, -86};
    int yvel = 0;
    int current_y_vel;
    int depth = 0;
    int max_height = 0;
    int max_height_legit = 0;
    while (yvel < 400)
    {
        current_y_vel = ++yvel;
        depth = 0;
        int check = 1;
        while (true)
        {
            depth += current_y_vel;
            if (depth >= max_height)
                max_height = depth;
            if (depth >= bounds[0] && depth <= bounds[1])
            {
                break;
            }
            else if (depth < bounds[0])
            {
                check = 0;
                break;
            }

            current_y_vel -= 1;
        }
        if (check)
            if (max_height_legit < max_height)
                max_height_legit = max_height;
    }
    //out:
    cout << max_height_legit;

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool intersects(pair<int, int>& who, pair<int, int>& tl, pair<int, int>& br)
{
    if (who.first >= tl.first && who.first <= br.first && who.second <= tl.second && who.second >= br.second)
        return true;
    return false;
}

int gaus(int x)
{
    return (x * (x+1)) / 2;
}

int sign(int x)
{
    return x >= 0 ? 1 : -1;
}

int main()
{
    pair<int, int> top_left = {124,   -86};
    pair<int, int> bot_right = {174, -123};

    int res = 0;
    for (int x_vel = 0; x_vel <= 174; x_vel ++)
    {
        for (int y_vel = -123; y_vel <= 123; y_vel ++)
        {
            pair<int, int> current_vel = {x_vel, y_vel};
            pair<int, int> poz = {0, 0};
            while (true)
            {
                poz.first += current_vel.first;
                poz.second += current_vel.second;

                current_vel.second -= 1;
                if (current_vel.first != 0)
                    current_vel.first -= 1;
                if (intersects(poz, top_left, bot_right))
                {
                    // cout << poz.first << ' ' << poz.second << '\n';
                    res++;
                    // cout << x_vel << ' ' << y_vel << '\n';
                    break;
                }
                else if (poz.first > bot_right.first || poz.second < bot_right.second)
                    break;
            }
        }
    }

    cout << res;

    return 0;
}
