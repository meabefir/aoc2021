/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

int horizontal, depth;
string dir;
int dist;

int main()
{
    while (in >> dir >> dist)
    {
        if (dir == "forward")
            horizontal += dist;
        else if (dir == "up")
            depth -= dist;
        else if (dir == "down")
            depth += dist;
    }

    cout << horizontal * depth;

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

int horizontal, depth, aim;
string dir;
int dist;

int main()
{
    while (in >> dir >> dist)
    {
        if (dir == "forward")
        {
            horizontal += dist;
            depth += aim * dist;
        }
        else if (dir == "up")
            aim -= dist;
        else if (dir == "down")
            aim += dist;
    }

    cout << horizontal * depth;

    return 0;
}
