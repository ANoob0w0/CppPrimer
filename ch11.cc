#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

string wordProc(string s)
{
    for (auto &c : s)
    {
        if (ispunct(c))
            c = '\0';
        else
            tolower(c);
    }
    return s;
}

istream &recordKids(istream &is, map<string, vector<pair<string, string>>> &fami)
{
    string buf;
    while (getline(is, buf))
    {
        istringstream iss(buf);
        string first, last, birth;
        iss >> first >> last >> birth;
        fami[last].push_back({first, birth});
    }
    return is;
}

istream &recordKids_multi(istream &is, multimap<string, string> &fami)
{
    string buf;
    while (getline(is, buf))
    {
        istringstream iss(buf);
        string first, last, birth;
        iss >> first >> last >> birth;
        fami.insert({last, first});
    }
    return is;
}

istream &recordAuthor(istream &is, multimap<string, string> &a)
{
    string buf;
    while (getline(is, buf))
    {
        istringstream iss(buf);
        string name, work;
        iss >> name >> work;
        a.insert({name, work});
    }
    return is;
}

void buildTransMap(map<string, string> &transmap){
    ifstream is("D:/Codes/Cpp_Primer_GCC_4_7_0/11/data/rules");
    if (!is.is_open())
    {
        cout << "file open failed";
        return;
    }
    string word_short, word;
    while (is>>word_short && getline(is, word))
    {
        if(word.size() > 1)
            transmap[word_short] = word.substr(1);//跳过空格
        else
            throw runtime_error("no rules for " + word_short);
    }
}

string wordTrans(const string &word, map<string, string> &transmap){
    auto res = transmap.find(word);
    if(res!=transmap.end())
        return res->second;
    return word;
}

int main(int argc, const char *argv[])
{
    //11.38
    ifstream infile("D:/Codes/Cpp_Primer_GCC_4_7_0/11/data/word_count");
    if (!infile.is_open())
    {
        cout << "file open failed";
        return -1;
    }
    unordered_map<string, size_t> word_count;
    string word;
    while (infile >> word)
        ++word_count[wordProc(word)];
    for (const auto &w : word_count)
        cout << w.first << "\t" << w.second << endl;

    // //11.33
    // map<string,string> trans;
    // buildTransMap(trans);
    // string line;
    // while (getline(cin, line))
    // {
    //     istringstream wordstream(line);
    //     string word;
    //     while(wordstream >> word)
    //         cout << wordTrans(word,trans) << " ";
    //     cout << endl;
    // }

    // //11.31&32
    // ifstream infile("D:/Codes/cpp/author");
    // if (!infile.is_open())
    // {
    //     cout << "file open failed";
    //     return -1;
    // }
    // multimap<string, string> author;
    // recordAuthor(infile, author);
    // pair<string,string> del = {"鲁迅","华盖集"};
    // for (auto pos = author.equal_range(del.first); pos.first != pos.second; ++pos.first)
    // {
    //     if(pos.first->second == del.second)
    //         {author.erase(pos.first);break;}
    //     //cout << pos.first->second << endl;
    // }
    // for (auto pos = author.equal_range(del.first); pos.first != pos.second; ++pos.first)
    //     cout << pos.first->second << endl;


    // //11.23
    // ifstream infile("D:/Codes/cpp/family");
    // if (!infile.is_open())
    // {
    //     cout << "file open failed";
    //     return -1;
    // }
    // multimap<string, string> family;
    // recordKids_multi(infile, family);

    // //11.20
    // ifstream infile("D:/Codes/Cpp_Primer_GCC_4_7_0/11/data/word_count");
    // if (!infile.is_open())
    // {
    //     cout << "file open failed";
    //     return -1;
    // }
    // map<string, size_t> word_count;
    // string word;
    // while (infile >> word)
    // {
    //     auto ret = word_count.insert({word, 1});
    //     if(!ret.second)
    //         ++ret.first->second;
    // }
    // for (const auto &w : word_count)
    //     cout << w.first << "\t" << w.second << endl;

    // //11.14
    // ifstream infile("D:/Codes/cpp/family");
    // if (!infile.is_open())
    // {
    //     cout << "file open failed";
    //     return -1;
    // }
    // map<string, vector<pair<string,string>>> family;
    // recordKids(infile, family);

    // //11.12
    // vector<string> strvec{"1","2","3","4","5","6"};
    // vector<int> ivec{1,2,3,4,5,6};
    // vector<pair<string,int>> pvec;
    // auto it2 = ivec.begin();
    // for(auto it1 = strvec.begin(); it1 != strvec.end();++it1,++it2)
    // {
    //     //pvec.push_back({*it1,*it2});
    //     //pvec.push_back(make_pair(*it1,*it2));
    //     pvec.push_back(pair<string,int>{*it1,*it2});
    // }

    // //11.7
    // ifstream infile("D:/Codes/cpp/family");
    // if (!infile.is_open())
    // {
    //     cout << "file open failed";
    //     return -1;
    // }
    // map<string, vector<string>> family;
    // recordKids(infile, family);

    // //11.3&11.4
    // ifstream infile("D:/Codes/Cpp_Primer_GCC_4_7_0/11/data/word_count");
    // if (!infile.is_open())
    // {
    //     cout << "file open failed";
    //     return -1;
    // }
    // map<string, size_t> word_count;
    // string word;
    // while (infile >> word)
    //     ++word_count[wordProc(word)];
    // for (const auto &w : word_count)
    //     cout << w.first << "\t" << w.second << endl;
    // //cout << w.first << " occurs " << w.second << ((w.second > 1) ? "times" : "time") << endl;

    return 0;
}