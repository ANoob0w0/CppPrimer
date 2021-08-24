#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstring>
#include <fstream>
#include <sstream>
#include <deque>
#include <list>
#include <forward_list>
#include <queue>

using namespace std;

void strFlistInsert(forward_list<string> &fl, const string &str1, const string &str2)
{
    for (auto it = fl.begin(); it != fl.end(); ++it)
    {
        if (*it == str1)
            fl.insert_after(it, str2);
    }
}

void replaceShortIter(string &s, const string &oldVal, const string &newVal)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (*it == oldVal.front())
        {
            if (s.substr(it - s.begin(), oldVal.size()) == oldVal)
            {
                it = s.erase(it, it + oldVal.size());
                it = s.insert(it, newVal.begin(), newVal.end());
                it += newVal.size() - 1;
            }
        }
    }
}

void replaceShortIdx(string &s, const string &oldVal, const string &newVal)
{
    for (decltype(s.size()) i = 0; i < s.size(); i++)
    {
        if (s[i] == oldVal.front())
        {
            if (s.substr(i, oldVal.size()) == oldVal)
            {
                s.replace(i, oldVal.size(), newVal);
                i += newVal.size() - 1;
            }
        }
    }
}

string addFix(string name, const string &pre, const string &suf)
{
    name.insert(name.begin(), pre.cbegin(), pre.cend());
    name.append(suf);
    return name;
}

string addFix_Idx(string name, const string &pre, const string &suf)
{
    name.insert(0, pre);
    name.insert(name.size(), suf);
    return name;
}

class Date
{
private:
    unsigned y = 0;
    unsigned m = 0;
    unsigned d = 0;

public:
    Date(const string &str) { read(str); };
    ~Date(){};
    void read(const string &);

private:
    void format1(const string &str);
    void format2(const string &str);
    void format3(const string &str);
    unsigned monthToUn(const string &);
};

void Date::read(const string &str)
{
    if (str.find_first_of(",") != string::npos)
        format1(str);
    else if (str.find_first_of("/") != string::npos)
        format2(str);
    else
        format3(str);
}

void Date::format1(const string &str)
{
    m = monthToUn(str);
    d = stoi(str.substr(str.find(" "), str.find(",")));
    y = stoi(str.substr(str.find(",") + 2));
}

void Date::format2(const string &str)
{
    d = stoi(str.substr(0, str.find("/")));
    m = stoi(str.substr(str.find("/") + 1, str.find_last_of("/")));
    y = stoi(str.substr(str.find_last_of("/") + 1));
}

void Date::format3(const string &str)
{
    m = monthToUn(str);
    d = stoi(str.substr(str.find(" ") + 1, str.find_last_of(" ")));
    y = stoi(str.substr(str.find_last_of(" ") + 1));
}

unsigned Date::monthToUn(const string &month)
{
    string monthShort("JanFebMarAprMayJunJulAugSepOctNovDec");
    unsigned un = monthShort.find(month.substr(0, 3));
    un = un / 3 + 1;
    return un;
}

bool myCompare(int &l, int &r)
{
    return l > r;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2, 3, 4, 1, 3, 1};
    priority_queue<int, vector<int>, decltype(myCompare) *> pq(myCompare);
    int k = 3;
    for (int i : nums)
    {
        if (pq.size() >= k)
        {
            pq.push(i);
            pq.pop();
        }
        else
            pq.push(i);
    }

    return 0;
    // //9.51
    // Date d1("January 23, 2021");
    // Date d2("7/5/2021");
    // Date d3("Dec 1 1900");

    // //9.50
    // vector<string> numstr = {"0","1","2","3","4","5","6"};
    // int sum = 0;
    // for(auto &str : numstr)
    // {
    //     sum += stoi(str);
    // }
    // cout << sum << endl;

    //9.47

    // //9.45&9.46
    // string name("John");
    // cout << addFix(name, "Mr", "Jr");

    // //9.43&9.44
    // string s("he walks thru the door");
    // replaceShortIdx(s, "thru", "through");
    // cout << s << endl;

    // //9.11
    // vector<int> v1;
    // const vector<int> v2{1, 2, 3, 4};
    // vector<int> v3(10);
    // vector<int> v4(v2);
    // vector<int> v5(v2.begin(), v2.end());
    // vector<int> v6(10, 1);

    // //9.14
    // list<const char *> lc = {"string1", "string2"};
    // vector<string> vs;

    // vs.assign(lc.begin(), lc.end());

    // for(auto &i : vs)
    //     cout << i;

    // //9.18&9.19
    // string filename = "D:/Codes/cpp/people";
    // ifstream in(filename);
    // string line;

    // list<string> ds;

    // while (getline(in, line))
    // {
    //     ds.push_back(line);
    // }

    // for(auto it = ds.cbegin();it!= ds.cend();++it){
    //     cout << *it << endl;
    // }

    // //9.20
    // list<int> li = {12,234,324,13,45,134,234,123,41,4,3};
    // deque<int> even, odd;

    // for(auto &i : li){
    //     if(i%2)
    //         odd.push_back(i);
    //     else
    //         even.push_back(i);
    // }

    // auto i = li.front();

    // //9.24
    // vector<int> testv;
    // //auto i = testv.at(0);
    // //auto i = testv.front();
    // //auto i = testv[0];
    // //auto i = *testv.begin();
    // testv.pop_back();

    // //9.26
    // int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    // vector<int> iv(begin(ia),end(ia));
    // list<int> il(begin(ia),end(ia));

    // for(auto iterv = iv.begin();iterv!= iv.end();)
    // {
    //     if(!(*iterv%2))
    //         iterv = iv.erase(iterv);
    //     else
    //         iterv++;
    // }

    // for(decltype(il.begin()) iterl = il.begin();iterl!= il.end();)
    // {
    //     if(*iterl%2)
    //         iterl = il.erase(iterl);
    //     else
    //         iterl++;
    // }

    // //9.27
    // forward_list<int> fli = {0,1,1,2,3,5,8,13,21,55,89};
    // auto prev = fli.before_begin();
    // auto curr = fli.begin();
    // while(curr != fli.end())
    // {
    //     if(*curr%2)
    //         curr = fli.erase_after(prev);
    //     else
    //     {
    //         prev = curr;
    //         ++curr;
    //     }
    // }

    // //9.28
    // forward_list<string> fli = {"oh", "oh", "oh", "oh", "oh", "ok"};
    // strFlistInsert(fli, "ok", "fine");
    // for (auto &str : fli)
    //     cout << str;

    // //9.40
    // vector<int> iv = {};
    // cout << iv.capacity() << endl;
    // iv.reserve(1024);
    // for (int i = 0; i < 1048; ++i)
    // {
    //     iv.push_back(i);
    //     //cout << iv.capacity() << endl;
    // }
    // //iv.shrink_to_fit();
    // iv.resize(iv.size() + iv.size()/2);
    // cout << iv.capacity() << endl;

    // //9.41
    // vector<char> cv = {'h','e','l','l','o'};
    // string str(cv.begin(),cv.end());
}
