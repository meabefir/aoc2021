/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

unordered_map<char, string> hexaToBin = {
    { '0', "0000" },
    { '1', "0001" },
    { '2', "0010" },
    { '3', "0011" },
    { '4', "0100" },
    { '5', "0101" },
    { '6', "0110" },
    { '7', "0111" },
    { '8', "1000" },
    { '9', "1001" },
    { 'A', "1010" },
    { 'B', "1011" },
    { 'C', "1100" },
    { 'D', "1101" },
    { 'E', "1110" },
    { 'F', "1111" },
};

string getBin(string hexa)
{
    string bin;
    for (char c: hexa)
        bin += hexaToBin[c];
    return bin;
}

int binToInt(string bin)
{
    int nr = 0;
    int powa = 0;
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        if (bin[i] == '1') nr += pow(2, powa);
        powa++;
    }
    return nr;
}

int IsStringOOO(const string& s)
{
    for (auto c: s)
        if (c != '0')
            return false;
    return true;
}

class packet
{
public:
    string bin;
    int version;
    int type;
    int value = -1;
    vector<packet*> packets;
    int level;

    void printPackets(int level = 0)
    {
        for (int i = 0; i < level; i++)
                cout << " ";
            cout << packets.size() << '\n';
        for (auto& packet: packets)
        {
            packet->printPackets(level + 4);
        }
    }

    int getVersionSum()
    {
        int sum = version;
        for (auto& packet: packets)
            sum += packet->getVersionSum();
        return sum;
    }

    void printLevel()
    {
        for (int i = 0; i < level*4; i++)
            cout << " ";
    }

    packet(string& _bin, int& pointer, int level = 0)
    {
        cout << '\n';
        this->level = level;
        printLevel(); cout << "packet \n";
        int initial_pointer = pointer;
        version = binToInt(_bin.substr(pointer, 3));
        printLevel(); cout << "version " << _bin.substr(pointer, 3) << '\n';
        pointer+=3;
        type = binToInt(_bin.substr(pointer, 3));
        printLevel(); cout << "type " << _bin.substr(pointer, 3) << '\n';
        pointer+=3;
        if (type == 4)
        {
            printLevel(); cout << "literal \n";
            string value_bin;
            while (_bin[pointer] == '1')
            {
                pointer++;
                value_bin += _bin.substr(pointer, 4);
                printLevel(); cout << "4 bits " << _bin.substr(pointer, 4) << '\n';
                pointer+=4;
            }
            pointer++;
            value_bin += _bin.substr(pointer, 4);
            printLevel(); cout << "4 bits " << _bin.substr(pointer, 4) << '\n';
            pointer+=4;
            value = binToInt(value_bin);
            printLevel(); cout << "literal value " << value << '\n';
            bin = _bin.substr(initial_pointer, pointer-initial_pointer);
        }
        else
        {
            printLevel(); cout << "operator \n";
            char length_type = _bin[pointer];
            pointer++;
            if (length_type == '0')
            {
                string bin_length_in_bits = _bin.substr(pointer, 15);
                pointer += 15;
                int pointer_subpacket_pos = pointer;
                int length = binToInt(bin_length_in_bits);
                while (pointer_subpacket_pos != pointer - length && !IsStringOOO(_bin.substr(pointer, 99999)))
                {
                    packet* new_packet = new packet(_bin, pointer, level + 1);
                    packets.push_back(new_packet);
                }
            }
            else
            {
                string bin_nr_of_subpackets = _bin.substr(pointer, 11);
                pointer += 11;
                int nr_of_subpackets = binToInt(bin_nr_of_subpackets);
                while (nr_of_subpackets--)
                {
                    packet* new_packet = new packet(_bin, pointer, level + 1);
                    packets.push_back(new_packet);
                }
            }
        }
    }
};

int main()
{
    string hexa;
    in >> hexa;
    string bin = getBin(hexa);
    cout << bin << '\n';
    int i = 0;
    packet main_packet(bin, i);

    main_packet.printPackets();

    cout << main_packet.getVersionSum();

    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream in("in.in");

unordered_map<char, string> hexaToBin = {
    { '0', "0000" },
    { '1', "0001" },
    { '2', "0010" },
    { '3', "0011" },
    { '4', "0100" },
    { '5', "0101" },
    { '6', "0110" },
    { '7', "0111" },
    { '8', "1000" },
    { '9', "1001" },
    { 'A', "1010" },
    { 'B', "1011" },
    { 'C', "1100" },
    { 'D', "1101" },
    { 'E', "1110" },
    { 'F', "1111" },
};

string getBin(string hexa)
{
    string bin;
    for (char c: hexa)
        bin += hexaToBin[c];
    return bin;
}

unsigned long long binToInt(string bin)
{
    unsigned long long nr = 0;
    int powa = 0;
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        if (bin[i] == '1') nr += pow(2, powa);
        powa++;
    }
    return nr;
}

int IsStringOOO(const string& s)
{
    for (auto c: s)
        if (c != '0')
            return false;
    return true;
}

class packet
{
public:
    string bin;
    int version;
    int type;
    unsigned long long value = 0;
    vector<packet*> packets;
    int level;

    void printPackets(int level = 0)
    {
        for (int i = 0; i < level; i++)
                cout << " ";
        cout << value << ' ';
        if (type == 0)
        {
            cout << "sum ";
        }
        else if (type == 1)
        {
            cout << "prod ";
        }
        else if (type == 2)
        {
             cout << "mini ";
        }
        else if (type == 3)
        {
             cout << "maxi ";
        }
        else if (type == 5)
        {
             cout << "> ";
        }
        else if (type == 6)
        {
             cout << "< ";
        }
        else if (type == 7)
        {
             cout << "== ";
        }
        cout << '\n';
        for (auto& packet: packets)
        {
            packet->printPackets(level + 4);
        }
    }

    int getVersionSum()
    {
        int sum = version;
        for (auto& packet: packets)
            sum += packet->getVersionSum();
        return sum;
    }

    void printLevel()
    {
        for (int i = 0; i < level*4; i++)
            cout << " ";
    }

    packet(string& _bin, int& pointer, int level = 0)
    {
        //cout << '\n';
        this->level = level;
        //printLevel(); cout << "packet \n";
        int initial_pointer = pointer;
        version = binToInt(_bin.substr(pointer, 3));
        //printLevel(); cout << "version " << _bin.substr(pointer, 3) << '\n';
        pointer+=3;
        type = binToInt(_bin.substr(pointer, 3));
        //printLevel(); cout << "type " << _bin.substr(pointer, 3) << '\n';
        pointer+=3;
        if (type == 4)
        {
            //printLevel(); cout << "literal \n";
            string value_bin;
            while (_bin[pointer] == '1')
            {
                pointer++;
                value_bin += _bin.substr(pointer, 4);
                //printLevel(); cout << "4 bits " << _bin.substr(pointer, 4) << '\n';
                pointer+=4;
            }
            pointer++;
            value_bin += _bin.substr(pointer, 4);
            //printLevel(); cout << "4 bits " << _bin.substr(pointer, 4) << '\n';
            pointer+=4;
            value = binToInt(value_bin);
            //printLevel(); cout << "literal value " << value << '\n';
            bin = _bin.substr(initial_pointer, pointer-initial_pointer);
        }
        else
        {
            //printLevel(); cout << "operator \n";
            char length_type = _bin[pointer];
            pointer++;
            if (length_type == '0')
            {
                string bin_length_in_bits = _bin.substr(pointer, 15);
                pointer += 15;
                int pointer_subpacket_pos = pointer;
                int length = binToInt(bin_length_in_bits);
                while (pointer_subpacket_pos != pointer - length && !IsStringOOO(_bin.substr(pointer, 99999)))
                {
                    packet* new_packet = new packet(_bin, pointer, level + 1);
                    packets.push_back(new_packet);
                }
            }
            else
            {
                string bin_nr_of_subpackets = _bin.substr(pointer, 11);
                pointer += 11;
                int nr_of_subpackets = binToInt(bin_nr_of_subpackets);
                while (nr_of_subpackets--)
                {
                    packet* new_packet = new packet(_bin, pointer, level + 1);
                    packets.push_back(new_packet);
                }
            }

            // after finishing its children
            if (type == 0)
            {
                unsigned long long sum = 0;
                for (auto& packet: packets)
                    sum += packet->value;
                value = sum;
            }
            else if (type == 1)
            {
                unsigned long long prod = 1;
                for (auto& packet: packets)
                    prod *= packet->value;
                value = prod;
            }
            else if (type == 2)
            {
                unsigned long long mini = 1e12;
                for (auto& packet: packets)
                    if (mini > packet->value)
                        mini = packet->value;
                value = mini;
            }
            else if (type == 3)
            {
                unsigned long long maxi = 0;
                for (auto& packet: packets)
                    if (maxi < packet->value)
                        maxi = packet->value;
                value = maxi;
            }
            else if (type == 5)
            {
                if (packets[0]->value > packets[1]->value)
                    value = 1;
                else
                    value = 0;
            }
            else if (type == 6)
            {
                if (packets[0]->value < packets[1]->value)
                    value = 1;
                else
                    value = 0;
            }
            else if (type == 7)
            {
                if (packets[0]->value == packets[1]->value)
                    value = 1;
                else
                    value = 0;
            }
        }
    }
};

int main()
{
    string hexa;
    in >> hexa;
    string bin = getBin(hexa);
    cout << bin << '\n';
    int i = 0;
    packet main_packet(bin, i);

    main_packet.printPackets();

    cout << main_packet.value;
    return 0;
}
