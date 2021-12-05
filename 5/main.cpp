/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string linie_curenta;
ifstream in("in.in");
pair <int, int> p1;
pair <int, int> p2;

int mat[1000][1000];
int main()
{
    while( getline(in, linie_curenta))
    {
        stringstream ss(linie_curenta);

        ss >> p1.first;
        ss.ignore();
        ss >> p1.second;


        ss.ignore();
        ss.ignore();
        ss.ignore();

        ss >> p2.first;
        ss.ignore();
        ss >> p2.second;
        cout<<p1.first<<' '<<p1.second<<" -> ";
        cout<<p2.first<<' '<<p2.second<<'\n';


        if(!(p1.first == p2.first || p1.second == p2.second ))
            continue;

        if(p1.first == p2.first)
        {
            for(int i = min(p1.second, p2.second); i <= max(p1.second, p2.second); ++i)
            {
                mat[i][p1.first] ++;
            }
        }

        if(p1.second == p2.second)
        {
            for(int i = min(p1.first, p2.first); i <= max(p1.first, p2.first); ++i)
            {
                mat[p1.second][i] ++;
            }
        }
    }
    int nr;

    for(int i = 0; i<1000; ++i)
    {
        for(int j = 0; j<1000; ++j)
        {
            if( mat[i][j] > 1 )
            {
                nr++;
            }
        }
    }
    cout<<nr;
    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string linie_curenta;
ifstream in("in.in");
pair <int, int> p1;
pair <int, int> p2;
template <typename T> int sign(T val)
{
    return (T(0) < val) - (val < T(0));
}
int mat[1000][1000];
int main()
{
    while( getline(in, linie_curenta))
    {
        stringstream ss(linie_curenta);

        ss >> p1.first;
        ss.ignore();
        ss >> p1.second;


        ss.ignore();
        ss.ignore();
        ss.ignore();
        //string st;
        //getline(ss,st);
        //cout<<st<<'\n';
        // continue;
        ss >> p2.first;
        ss.ignore();
        ss >> p2.second;

        if(p1.first == p2.first)
        {
            for(int i = min(p1.second, p2.second); i <= max(p1.second, p2.second); ++i)
            {
                mat[i][p1.first] ++;
            }
        }

        else if(p1.second == p2.second)
        {
            for(int i = min(p1.first, p2.first); i <= max(p1.first, p2.first); ++i)
            {
                mat[p1.second][i] ++;
            }
        }

        else
        {
            pair<int,int> p_curent = p1;
            while(p_curent!=p2)
            {
                mat[p_curent.second][p_curent.first] ++;
                p_curent.first += sign(p2.first - p_curent.first);
                p_curent.second += sign(p2.second - p_curent.second);

            }
            mat[p2.second][p2.first] ++;
        }


    }
    int nr;

    for(int i = 0; i<1000; ++i)
    {
        for(int j = 0; j<1000; ++j)
        {
            if( mat[i][j] > 1 )
            {
                nr++;
            }
        }
    }
    cout<<nr;
    return 0;
}
