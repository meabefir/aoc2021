/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<int> numbers;
vector<vector<vector<int>>> boards;

void markNumber(int nr, vector<vector<int>>& board)
{
    for (auto& row: board)
    {
        for (auto& el: row)
            if (el == nr)
                el = -1;
    }
}

bool boardWon(vector<vector<int>>& board)
{
    // rows
    for (int i = 0; i < 5; i++)
    {
        bool all_picked = true;
        for (int j = 0; j < 5; j++)
            if (board[i][j] != -1)
            {
                all_picked = false;
                break;
            }
        if (all_picked)
            return true;
    }

    for (int i = 0; i < 5; i++)
    {
        bool all_picked = true;
        for (int j = 0; j < 5; j++)
            if (board[j][i] != -1)
            {
                all_picked = false;
                break;
            }
        if (all_picked)
            return true;
    }
    return false;
}

int getAnswer(vector<vector<int>>& board, int nr)
{
    cout << nr << '\n';
    int s = 0;
    for (auto& row: board)
    {
        for (auto& el: row)
            if (el != -1)
                s += el;
    }
    return s * nr;
}

int main()
{
    string line;
    getline(in, line);
    stringstream ss(line);

    for (int i; ss >> i;)
    {
        numbers.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    while (true)
    {
        bool double_break = false;
        getline(in, line);

        vector<vector<int>> new_board;

        for (int i = 1; i <= 5; i ++)
        {
            getline(in, line);
            if (line.size() == 0)
            {
                double_break = true;
                break;
            }
            vector<int> row;
            stringstream ss_row(line);
            for (int i; ss_row >> i;)
            {
                row.push_back(i);
            }
            new_board.push_back(row);
        }
        if (double_break)
            break;
        boards.push_back(new_board);
    }

    for (int number: numbers)
    {
        for (auto& board: boards)
        {
            markNumber(number, board);
            if (boardWon(board))
            {
                cout << getAnswer(board, number);
                return 0;
            }
        }
    }

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

vector<int> numbers;
vector<vector<vector<int>>> boards;
int nrBoardWon = 0;
int boardAlreadyWon[1000];

void markNumber(int nr, vector<vector<int>>& board)
{
    for (auto& row: board)
    {
        for (auto& el: row)
            if (el == nr)
                el = -1;
    }
}

bool boardWon(vector<vector<int>>& board)
{
    // rows
    for (int i = 0; i < 5; i++)
    {
        bool all_picked = true;
        for (int j = 0; j < 5; j++)
            if (board[i][j] != -1)
            {
                all_picked = false;
                break;
            }
        if (all_picked)
            return true;
    }

    for (int i = 0; i < 5; i++)
    {
        bool all_picked = true;
        for (int j = 0; j < 5; j++)
            if (board[j][i] != -1)
            {
                all_picked = false;
                break;
            }
        if (all_picked)
            return true;
    }
    return false;
}

int getAnswer(vector<vector<int>>& board, int nr)
{
    int s = 0;
    for (auto& row: board)
    {
        for (auto& el: row)
            if (el != -1)
                s += el;
    }
    return s * nr;
}

int main()
{
    string line;
    getline(in, line);
    stringstream ss(line);

    for (int i; ss >> i;)
    {
        numbers.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    while (true)
    {
        bool double_break = false;
        getline(in, line);

        vector<vector<int>> new_board;

        for (int i = 1; i <= 5; i ++)
        {
            getline(in, line);
            if (line.size() == 0)
            {
                double_break = true;
                break;
            }
            vector<int> row;
            stringstream ss_row(line);
            for (int i; ss_row >> i;)
            {
                row.push_back(i);
            }
            new_board.push_back(row);
        }
        if (double_break)
            break;
        boards.push_back(new_board);
    }

    for (int number: numbers)
    {
        for (int k = 0; k < boards.size(); k++)
        {
            auto& board = boards[k];

            markNumber(number, board);
            if (!boardAlreadyWon[k] && boardWon(board))
            {
                boardAlreadyWon[k] = 1;
                nrBoardWon ++;
                if (nrBoardWon == boards.size())
                {
                    cout << number << '\n';
                    cout << getAnswer(board, number);
                    return 0;
                }
            }
        }
    }

    return 0;
}
