/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define inf 100000

ifstream in("in.in");

int main()
{
    int prev = inf;
    int current;
    int cnt = 0;
    while (in >> current)
    {
        if (current > prev)
            cnt++;
        prev = current;
    }

    cout << cnt;

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define inf 100000

ifstream in("in.in");

int a, b, c, x;

int main()
{
    int cnt = 0;
    in >> a >> b >> c;
    int prevSum = a + b + c;
    int currentSum;
    while (in >> x)
    {
        currentSum = prevSum - a + x;
        if (currentSum > prevSum)
            cnt ++;
        currentSum = prevSum;
        a = b;
        b = c;
        c = x;
    }

    cout << cnt;

    return 0;
}
