/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

unordered_map<string, vector<string>> la;
unordered_map<string, int> viz;
int ret;

pair<string, string> splitStringAt(string s, char c)
{
    string from, to;
    string* mod = &from;
    for (char cc: s)
    {
        if (cc == c)
        {
            mod = &to;
            continue;
        }
        *mod += cc;
    }
    return {from ,to};
}

void dfs(string from)
{
    viz[from] ++;

    for (auto& to: la[from])
    {
        if (to == "end")
        {
            ret ++;
            continue;
        }
        // daca nu e in viz sau daca e uppercase cave
        if (viz.find(to) == viz.end() || ((int)to[0] >= 65 && (int)to[0] <= 90))
        {
            dfs(to);
        }
    }
    viz[from] --;
    if (viz[from] == 0)
        viz.erase(from);
}

int main()
{
    string line;
    getline(in, line);
    while (line.size())
    {
        auto [from, to] = splitStringAt(line, '-');
        la[from].push_back(to);
        la[to].push_back(from);

        getline(in, line);
    }

    dfs("start");

    cout << ret;

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

unordered_map<string, vector<string>> la;
unordered_map<string, int> viz;
unordered_map<string, int> doubleUsed;
bool doubleUsingNow = false;
int ret;
stack<string> st;

pair<string, string> splitStringAt(string s, char c)
{
    string from, to;
    string* mod = &from;
    for (char cc: s)
    {
        if (cc == c)
        {
            mod = &to;
            continue;
        }
        *mod += cc;
    }
    return {from ,to};
}

void printStack(stack<string>& st)
{
    stack<string> st2 = st;
    vector<string> v;
    while (st2.size())
    {
        v.push_back(st2.top());
        st2.pop();
    }
    reverse(v.begin(), v.end());
    for (auto el: v)
        cout << el << ' ';
    cout << '\n';
}

void dfs(string from)
{
    viz[from] ++;
    st.push(from);

    for (auto& to: la[from])
    {
        if (to == "end")
        {
            ret ++;
            // printStack(st);
            continue;
        }
        // daca nu e in viz sau daca e uppercase cave sau daca e lowercase cave si inca nu a fost folosita pe post de double small cave
        if (viz.find(to) == viz.end() || ((int)to[0] >= 65 && (int)to[0] <= 90))
        {
            dfs(to);
        }

        if (to != "start" && viz.find(to) != viz.end() && !((int)to[0] >= 65 && (int)to[0] <= 90) && !doubleUsingNow && viz[to] == 1)
        {
            doubleUsingNow = true;
            dfs(to);
            doubleUsingNow = false;
        }
    }

    st.pop();
    viz[from] --;
    if (viz[from] == 0)
        viz.erase(from);
}

int main()
{
    string line;
    getline(in, line);
    while (line.size())
    {
        auto [from, to] = splitStringAt(line, '-');
        la[from].push_back(to);
        la[to].push_back(from);

        getline(in, line);
    }

    dfs("start");

    cout << ret;

    return 0;
}

