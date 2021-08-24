#include <iostream>
#include <memory>

#include "StrBlob.h"
#include "TextQuery.h"

using namespace std;

void writeVec(istream &is, vector<int> &ivec)
{
    int i;
    while (is >> i)
        ivec.push_back(i);
}

void printVec(const vector<int> &ivec)
{
    for (auto &i : ivec)
        cout << i << " ";
}

struct connection
{
    string ip;
    int port;
    connection(const string &s, const int &p) : ip(s), port(p) {}
};

struct destination
{
    string ip;
    int port;
    destination(const string &s, const int &p) : ip(s), port(p) {}
};

connection connect(destination *dest)
{
    cout << "connect to: " << dest->ip << ":" << dest->port << endl;
    return connection(dest->ip, dest->port);
}

void disconnect(connection connect)
{
    cout << "disconnect to: " << connect.ip << ":" << connect.port << endl;
}

void end_connection(connection *connect)
{
    disconnect(*connect);
}

void f(destination &dest)
{
    connection c = connect(&dest);
    //shared_ptr<connection> p(&c, [](connection *c){disconnect(*c);});
    //shared_ptr<connection> p(&c, end_connection);
    unique_ptr<connection, decltype(end_connection) *> p(&c, end_connection);
}

void useSharedPtr(const shared_ptr<string> &p){
    cout << *p;
}

void useSharedPtr(string *p){
    cout << *p;
}

int main()
{
    //12.27
    ifstream infile("D:/Codes/Cpp_Primer_GCC_4_7_0/12/data/storyDataFile");
    if (!infile.is_open())
    {
        cout << "file open failed";
        return -1;
    }
    const TextQuery tq(infile);
    while(true)
    {
        cout << "enter word to look for, or -q to quit: ";
        string s;
        if(!(cin >> s)||s == "-q") break;
        //tq.query(cout, s);
        print(cout, tq.query(s)) << endl;
    }

    // auto p1 = make_shared<string>("p1");
    // useSharedPtr(make_shared<string>("p2"));
    // useSharedPtr(new string("p3"));

    // //12.22
    // const StrBlob csb({"this is", "a const", "StrBlob"});
    // cout << csb.getCount() << endl;
    // for (auto p = csb.cbegin(); !p.equal(csb.cend()); p.incr())
    // {
    //     cout << csb.getCount() << endl;
    //     cout << p.deref() << endl;
    // }
    // {
    //     StrBlob sb = csb;
    //     cout << sb.getCount() << endl;
    //     for (auto p = sb.cbegin(); !p.equal(sb.cend()); p.incr())
    //     {
    //         cout << csb.getCount() << endl;
    //         cout << p.deref() << endl;
    //     }
    // }
    // cout << csb.getCount() << endl;

    // //12.19&12.20
    // StrBlob sb;
    // string buf;
    // //cout << sb.front();
    // while(getline(cin, buf))
    // {
    //     sb.push_back(buf);
    // }
    // for(auto p = sb.begin(); !p.equal(sb.end()); p.incr()){
    //     cout << p.deref() << endl;
    // }

    //12.1.5
    // auto p1 = make_shared<int>(42);
    // weak_ptr<int> wp(p1);
    // cout << "count p1: " << p1.use_count() << endl;
    // if (shared_ptr<int> tp = wp.lock())
    // {
    //     cout << "count p1: " << p1.use_count() << endl;
    //     cout << "count wp: " << wp.use_count() << endl;
    // }

    //12.17
    // int ix = 1024, *pi = &ix;
    // int* pi1 = new int(2048);
    // unique_ptr<int> p1(pi1);
    // unique_ptr<int> p2(p1.release());

    // //12.14&12.15
    // destination d("192.168.1.2",2121);
    // f(d);

    // //12.7
    // auto ivp = make_shared<vector<int>>();
    // writeVec(cin, *ivp);
    // printVec(*ivp);

    // //12.6
    // auto *ivp = new vector<int>;
    // writeVec(cin, *ivp);
    // printVec(*ivp);
    // delete ivp;

    return 0;
}