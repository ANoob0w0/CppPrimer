#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Sales_Data.hpp"

using namespace std;

void printStr(const vector<string> &str)
{
    for(auto &s : str)
        cout << s << " ";
    cout << endl;
}
void elimDups(vector<string> &strvec)
{
    //printStr(strvec);
    sort(strvec.begin(),strvec.end());
    //printStr(strvec);
    auto unique_end = unique(strvec.begin(),strvec.end());
    strvec.erase(unique_end,strvec.end());
    //printStr(strvec);
}

bool isShorter(const string &s1, const string &s2){
    return s1.size()<s2.size();
}

bool compareIsbn(const Sales_Data &sd1, const Sales_Data &sd2){
    return sd1.isbn() < sd2.isbn();
}

bool sizeAboveFive(const string& str){
    return str.size() > 4;
}

void biggies(vector<string> &str, vector<string>::size_type sz){

}

int main(int argc, char *argv[])
{
    //10.16
    vector<string> strvec;
    string buf;
    while(cin>>buf)
        strvec.push_back(buf);

    // //10.17
    // vector<Sales_Data> sdvec;
    // Sales_Data buf;
    // while(buf.read(cin))
    //     sdvec.push_back(buf);
    // stable_sort(sdvec.begin(),sdvec.end(),[](const Sales_Data &sd1, const Sales_Data &sd2){return sd1.isbn() < sd2.isbn();});

    // //10.14&10.15
    // int i = 42;
    // auto f = [](const int &i1,const int &i2){return i1+i2;};
    // auto f1 = [i](const int &i1){return i1+i;};
    // cout << f(1,2) << endl;
    // cout << f1(1) << endl;

    // //10.13
    // vector<string> strvec;
    // string buf;
    // while(cin>>buf)
    //     strvec.push_back(buf);
    // partition(strvec.begin(),strvec.end(),sizeAboveFive);
    // printStr(strvec);

    // //10.12
    // vector<Sales_Data> sdvec;
    // Sales_Data buf;
    // while(buf.read(cin))
    //     sdvec.push_back(buf);
    // stable_sort(sdvec.begin(),sdvec.end(),compareIsbn);

    // //10.9
    // vector<string> strvec;
    // string buf;
    // while(cin>>buf)
    //     strvec.push_back(buf);
    // elimDups(strvec);
    // //10.11
    // stable_sort(strvec.begin(),strvec.end(),isShorter);
    // printStr(strvec);

    // //10.6
    // vector<int> ivec;
    // ivec.resize(10);
    // fill_n(ivec.begin(),ivec.size(),10);
    // auto bi = back_inserter(ivec);

    return 0;
}
