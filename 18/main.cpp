/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

void explodeAt(string& acc, int pointer)
{
    int left_pointer = pointer;
    while (acc[left_pointer] != '[')
        left_pointer --;
    int left, right;
    stringstream ss(acc.substr(left_pointer+1, pointer - left_pointer - 1));
    ss >> left;
    ss.ignore();
    ss >> right;
    //cout << left << ' ' << right << '\n';
    acc = acc.substr(0, left_pointer) + "0" + acc.substr(pointer+1, 999999);
    //cout << acc << '\n';
    //cout << acc << '\n';
    //cout << acc[left_pointer] << '\n';
    int right_pointer = left_pointer + 1;
    left_pointer --;

    int acc_size = acc.size();
    while (left_pointer >= 0 && !isdigit(acc[left_pointer]))
    {
        left_pointer--;
    }
    if (left_pointer >= 0)
    {
        int to = left_pointer;
        while (isdigit(acc[left_pointer]))
        {
            //cout << acc[left_pointer];
            left_pointer--;
        }
        //cout << '\n';
        int from = left_pointer;
        int nr = 0;
        for (int i = from + 1; i <= to; i++)
        {
            nr = nr*10 + (int)acc[i] - 48;
        }
        //cout << nr << '\n';
        //cout << from << ' ' << to << " aici\n";
        // cout << acc.substr(0, from+1) << nr + left << acc.substr(to+1, 99999) << '\n';
        acc = acc.substr(0, from+1) + to_string(nr + left) + acc.substr(to+1, 99999);
    }
    right_pointer += acc.size() - acc_size;
    while (right_pointer < acc.size() && !isdigit(acc[right_pointer]))
    {
        right_pointer++;
    }
    if (right_pointer < acc.size())
    {
        int from = right_pointer;
        int nr = 0;
        while (isdigit(acc[right_pointer]))
        {
            nr = nr * 10 + (int)acc[right_pointer] - 48;
            //cout << acc[right_pointer];
            right_pointer++;
        }
        //cout << '\n';
        int to = right_pointer;
        //cout << nr << '\n';
        //cout << from << ' ' << to << " aici\n";
        // cout << acc.substr(0, from+1) << nr + left << acc.substr(to+1, 99999) << '\n';
        acc = acc.substr(0, from) + to_string(nr + right) + acc.substr(to, 99999);
    }
}

int tryExplode(string& acc)
{
    int stk = 0;
    string explode_content;
    for (int pointer = 0; pointer < acc.size(); pointer++)
    {
        if (acc[pointer] == '[')
        {
            stk ++;
            if (stk >= 5)
            {
                explode_content = "";
            }
        }
        else if (acc[pointer] == ']')
        {
            if (stk >= 5)
            {
                // do stuff
                // cout << explode_content << '\n';
                explodeAt(acc, pointer);
                return 1;
            }
            stk--;
        }
        else
        {
            if (stk >= 5)
            {
                explode_content += acc[pointer];
            }
        }
    }
    return 0;
}

void splitAt(string& acc, int pointer)
{
    pointer--;
    while (isdigit(acc[pointer]))
    {
        pointer--;
    }
    pointer++;
    int from = pointer;
    int nr = 0;
    while (isdigit(acc[pointer]))
    {
        nr = nr * 10 + (int)acc[pointer] - 48;
        pointer++;
    }
    int to = pointer;
    acc = acc.substr(0, from) + "[" + to_string(nr / 2) + "," + to_string(nr / 2 + nr%2) + "]" + acc.substr(to, 99999);
}

int trySplit(string& acc)
{
    int pointer = 0;
    int current_nr = 0;
    while (pointer < acc.size())
    {
        if (!isdigit(acc[pointer]))
        {
            if (current_nr > 9)
            {
                splitAt(acc, pointer);
                return 1;
            }
            current_nr = 0;
        }
        else
        {
            current_nr = current_nr * 10 + (int)acc[pointer] - 48;
        }
        pointer ++;
    }
    if (current_nr > 9)
    {
        splitAt(acc, pointer);
        return 1;
    }
    return 0;
}

int getMagnitude(string& acc, int& pointer)
{
    if (isdigit(acc[pointer]))
    {
        int nr = 0;
        while (isdigit(acc[pointer]))
        {
            nr = nr * 10 + (int)acc[pointer] - 48;
            pointer++;
        }

        return nr;
    }

    pointer++;
    int left = getMagnitude(acc, pointer);
    while (!isdigit(acc[pointer]) && acc[pointer] != '[')
        pointer++;
    int right = getMagnitude(acc, pointer);
    return 3 * left + 2 * right;
}

int main()
{
    string acc;
    getline(in, acc);

    string new_nr;
    getline(in, new_nr);
    while (new_nr.size())
    {
        acc = "[" + acc + "," + new_nr + "]";

        while (true)
        {
            if (tryExplode(acc))
                continue;
            if (trySplit(acc))
                continue;
            break;
        }
        cout << acc << '\n';

        getline(in, new_nr);
    }

    cout << acc << '\n';

    int pointer = 0;
    cout << getMagnitude(acc, pointer);

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

void explodeAt(string& acc, int pointer)
{
    int left_pointer = pointer;
    while (acc[left_pointer] != '[')
        left_pointer --;
    int left, right;
    stringstream ss(acc.substr(left_pointer+1, pointer - left_pointer - 1));
    ss >> left;
    ss.ignore();
    ss >> right;
    //cout << left << ' ' << right << '\n';
    acc = acc.substr(0, left_pointer) + "0" + acc.substr(pointer+1, 999999);
    //cout << acc << '\n';
    //cout << acc << '\n';
    //cout << acc[left_pointer] << '\n';
    int right_pointer = left_pointer + 1;
    left_pointer --;

    int acc_size = acc.size();
    while (left_pointer >= 0 && !isdigit(acc[left_pointer]))
    {
        left_pointer--;
    }
    if (left_pointer >= 0)
    {
        int to = left_pointer;
        while (isdigit(acc[left_pointer]))
        {
            //cout << acc[left_pointer];
            left_pointer--;
        }
        //cout << '\n';
        int from = left_pointer;
        int nr = 0;
        for (int i = from + 1; i <= to; i++)
        {
            nr = nr*10 + (int)acc[i] - 48;
        }
        //cout << nr << '\n';
        //cout << from << ' ' << to << " aici\n";
        // cout << acc.substr(0, from+1) << nr + left << acc.substr(to+1, 99999) << '\n';
        acc = acc.substr(0, from+1) + to_string(nr + left) + acc.substr(to+1, 99999);
    }
    right_pointer += acc.size() - acc_size;
    while (right_pointer < acc.size() && !isdigit(acc[right_pointer]))
    {
        right_pointer++;
    }
    if (right_pointer < acc.size())
    {
        int from = right_pointer;
        int nr = 0;
        while (isdigit(acc[right_pointer]))
        {
            nr = nr * 10 + (int)acc[right_pointer] - 48;
            //cout << acc[right_pointer];
            right_pointer++;
        }
        //cout << '\n';
        int to = right_pointer;
        //cout << nr << '\n';
        //cout << from << ' ' << to << " aici\n";
        // cout << acc.substr(0, from+1) << nr + left << acc.substr(to+1, 99999) << '\n';
        acc = acc.substr(0, from) + to_string(nr + right) + acc.substr(to, 99999);
    }
}

int tryExplode(string& acc)
{
    int stk = 0;
    string explode_content;
    for (int pointer = 0; pointer < acc.size(); pointer++)
    {
        if (acc[pointer] == '[')
        {
            stk ++;
            if (stk >= 5)
            {
                explode_content = "";
            }
        }
        else if (acc[pointer] == ']')
        {
            if (stk >= 5)
            {
                // do stuff
                // cout << explode_content << '\n';
                explodeAt(acc, pointer);
                return 1;
            }
            stk--;
        }
        else
        {
            if (stk >= 5)
            {
                explode_content += acc[pointer];
            }
        }
    }
    return 0;
}

void splitAt(string& acc, int pointer)
{
    pointer--;
    while (isdigit(acc[pointer]))
    {
        pointer--;
    }
    pointer++;
    int from = pointer;
    int nr = 0;
    while (isdigit(acc[pointer]))
    {
        nr = nr * 10 + (int)acc[pointer] - 48;
        pointer++;
    }
    int to = pointer;
    acc = acc.substr(0, from) + "[" + to_string(nr / 2) + "," + to_string(nr / 2 + nr%2) + "]" + acc.substr(to, 99999);
}

int trySplit(string& acc)
{
    int pointer = 0;
    int current_nr = 0;
    while (pointer < acc.size())
    {
        if (!isdigit(acc[pointer]))
        {
            if (current_nr > 9)
            {
                splitAt(acc, pointer);
                return 1;
            }
            current_nr = 0;
        }
        else
        {
            current_nr = current_nr * 10 + (int)acc[pointer] - 48;
        }
        pointer ++;
    }
    if (current_nr > 9)
    {
        splitAt(acc, pointer);
        return 1;
    }
    return 0;
}

int getMagnitude(string acc, int& pointer)
{
    if (isdigit(acc[pointer]))
    {
        int nr = 0;
        while (isdigit(acc[pointer]))
        {
            nr = nr * 10 + (int)acc[pointer] - 48;
            pointer++;
        }

        return nr;
    }

    pointer++;
    int left = getMagnitude(acc, pointer);
    while (!isdigit(acc[pointer]) && acc[pointer] != '[')
        pointer++;
    int right = getMagnitude(acc, pointer);
    return 3 * left + 2 * right;
}

string getSum(string acc, string new_nr)
{
    acc = "[" + acc + "," + new_nr + "]";

    while (true)
    {
        if (tryExplode(acc))
            continue;
        if (trySplit(acc))
            continue;
        break;
    }
    return acc;
}

int main()
{
    string line;
    getline(in, line);

    vector<string> lines;
    while (line.size())
    {
        lines.push_back(line);

        getline(in, line);
    }

    int maxi = 0;
    string s1, s2;
    for (int i = 0; i < lines.size(); i++)
    {
        for (int j = 0; j < lines.size(); j++)
        {
            if (i == j)
                continue;
            int pointer = 0;
            int mag = getMagnitude(getSum(lines[i], lines[j]), pointer);
            if (mag > maxi)
            {
                maxi = mag;
                s1 = lines[i];
                s2 = lines[j];
            }
        }
    }

    cout << maxi << '\n' << s1 << '\n' << s2;
    return 0;
}

