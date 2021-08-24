#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstring>
#include <fstream>
#include <sstream>

#include "Sales_Data.hpp"

using namespace std;

struct PeopleInfo
{
    string name;
    vector<string> number;
};

istream &func(istream &is)
{
    string data;
    //auto old_state = is.rdstate();
    while (is >> data)
        cout << data << std::ends;
    is.clear();
    return is;
}

bool valid(const string &num)
{
    if (num.size() != 10)
        return false;
    else
        return true;
}

string format(const string &in)
{
    string num = in;
    num.insert(num.begin()+3, 1, '-');
    num.insert(num.begin()+7, 1, '-');
    return num;
}

int main(int argc, char *argv[])
{
    // //8.8
    // ifstream input(argv[1]);
    // ofstream output(argv[2], ofstream::app);
    // Sales_Data total, trans;
    // if (total.read(input))
    // {
    //     while (trans.read(input))
    //     {
    //         if (trans.isbn() == total.isbn())
    //         {
    //             total.combine(trans);
    //         }
    //         else
    //         {
    //             total.print(output) << endl;
    //             total = trans;
    //         }
    //     }
    //     total.print(output) << endl;
    // }
    // else
    // {
    //     cout << "no data" << endl;
    // }

    // //8.4
    // string filename = "D:/Codes/cpp/infile";
    // ifstream in(filename);
    // string temp;
    // vector<string> vstr = {};
    // cout << in.good();
    // if (in)
    // {
    //     while(in>>temp)
    //         vstr.push_back(temp);
    // }

    // //8.9
    // string content = "this is content";
    // istringstream istrs(content);
    // func(istrs);

    // //8.10
    // string filename = "D:/Codes/cpp/people";
    // ifstream in(filename);
    // string temp;
    // vector<string> vstr = {};
    // cout << in.good();
    // if (in)
    // {
    //     while(in>>temp)
    //         vstr.push_back(temp);
    // }
    // //8.10&8.11
    // istringstream iss;
    // for(auto &line : vstr)
    // {
    //     iss.clear();
    //     iss.str(line);
    //     while(iss >> temp)
    //         cout << temp;
    // }

    //8.13
    vector<PeopleInfo> people;
    string line, word;
    string filename = "D:/Codes/cpp/people";
    ifstream in(filename);
    while (getline(in, line))
    {
        if (line.empty())
            continue;
        PeopleInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.number.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &numbers : entry.number)
        {
            if (!valid(numbers))
                badNums << " " << numbers;
            else
                formatted << " " << format(numbers);
        }
        cout << entry.name << endl;
        cout << "good: " << formatted.str() << endl;
        cout << "bad: " << badNums.str() << endl;
    }

    return 0;
}
